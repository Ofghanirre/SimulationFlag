#include <stdlib.h>
#include <stdProject.h>

static void anchor_draw(Atom* self, int metadata) {

}

static void node_draw(Atom* self, int metadata) {
    
}

static void anchor_next(Atom* self, Vec3d movement) {
    // Anchor is not moving
    self->force = (Vec3d){0., 0., 0.}; // Security measure
}

static void node_next(Atom* self, Vec3d movement) {
    double dt = 0.1; // Pas de temps
    Vec3d acceleration = Vec3d_div(self->force, self->mass);
    // Calcul de la nouvelle position à l'aide de la méthode LeapFrog
    self->position.x += (self->velocity.x + 0.5 * acceleration.x * dt) * dt + movement.x;
    self->position.y += (self->velocity.y + 0.5 * acceleration.y * dt) * dt + movement.y;
    self->position.z += (self->velocity.z + 0.5 * acceleration.z * dt) * dt + movement.z;

    // Mise à jour de la vitesse à mi-chemin entre les anciennes et les nouvelles accélérations
    self->velocity.x += 0.5 * (acceleration.x + self->force.x / self->mass) * dt;
    self->velocity.y += 0.5 * (acceleration.y + self->force.y / self->mass) * dt;
    self->velocity.z += 0.5 * (acceleration.z + self->force.z / self->mass) * dt;

    // Réinitialisation de la force après avoir été utilisée
    self->force.x = 0.0;
    self->force.y = 0.0;
    self->force.z = 0.0;
}

int new_atom(Atom* result, double mass, EAtomType type, Pos3d position, Vec3d velocity, RGB color, void (*drawFunction)(Atom*, int), void (*nextFunction)(Atom*, Vec3d)) {
    if (result == NULL) return MEMERROR;
    result->type = type;
    result->mass = mass;
    result->position = position;
    result->velocity = velocity;
    result->force = (Vec3d){0., 0., 0.}; // Security Rule
    result->color = color;
    result->draw = drawFunction;
    result->next = nextFunction;
    return NOERROR;
}

int new_atom_anchor(Atom* result, double mass, Pos3d position, RGB color) {
    return new_atom(result, ANCHOR, mass, position, (Vec3d){0., 0., 0.}, color, anchor_draw, anchor_next);
}

int new_atom_node(Atom* result, double mass, Pos3d position, Vec3d velocity, RGB color) {
    return new_atom(result, NODE, mass, position, velocity, color, node_draw, node_next);
}