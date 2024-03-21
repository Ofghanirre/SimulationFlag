#include <stdlib.h>
#include <links.h>

static void next_link(Link* link) {
    Vec3d direction = Pos3d_sub(link->fst->position, link->snd->position);
    double current_length = Pos3d_distance(link->fst->position, link->snd->position);
    double displacement = current_length - link->rest_length;

    Vec3d elastic_force = Pos3d_mul(Pos3d_div(direction, current_length), displacement * link->elasticity);
    Vec3d relative_velocity = Pos3d_sub3d(link->snd->velocity, link->fst->velocity);
    
    double velocity_normal = Pos3d_dot(relative_velocity, direction) / current_length;
    Vec3d damping_force;
    if (current_length == 0) {
        damping_force = (Vec3d){0, 0, 0};
    } else {
        damping_force = Pos3d_mul(Pos3d_div(direction, current_length), -link->damping * velocity_normal);
    }

    link->fst->force = Vec3d_add3d(link->fst->force, Vec3d_add(elastic_force, damping_force));
    link->snd->force = Vec3d_sub3d(link->snd->force, Vec3d_add(elastic_force, damping_force));
}

int new_link(Link* result, Atom* first, Atom* second, cdouble elasticity, cdouble damping) {
    if (result == NULL) return MEMERROR;

    result->fst = first;
    result->snd = second;
    result->rest_length = Pos3d_distance(first->position, second->position);
    result->elasticity = elasticity;
    result->damping = damping;
    return NOERROR;
}
