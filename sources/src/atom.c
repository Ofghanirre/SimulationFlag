#include <stdlib.h>
#include <stdProject.h>

void anchor_draw(Atom* self, int metadata) {

}

void node_draw(Atom* self, int metadata) {
    
}

void anchor_next(Atom* self, Vec3d mouvement) {

}

void node_next(Atom* self, Vec3d mouvement) {
    
}

int new_atom(Atom* result, EAtomType type, Pos3d position, RGB color, void (*draw)(Atom*, int), void (*nextFunction)(Atom*, Vec3d)) {
    if (result == NULL) return MEMERROR;
    result->position = position;
    result->color = color;
    result->type = type;
    result->draw = draw;
    result->next = nextFunction;
    return NOERROR;
}

int new_atom_anchor(Atom* result, Pos3d position, RGB color) {
    return new_atom(result, ANCHOR, position, color, anchor_draw, anchor_next);
}

int new_atom_node(Atom* result, Pos3d position, RGB color) {
    return new_atom(result, NODE, position, color, node_draw, node_next);
}