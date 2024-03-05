#include <geometry.h>

Pos3d Pos3d_add(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

Pos3d Pos3d_mul(Pos3d a, double s) {
    return (Pos3d){
        .x = a.x * s,
        .y = a.y * s,
        .z = a.z * s,
    };
}