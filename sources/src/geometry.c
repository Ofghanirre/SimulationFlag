#include <geometry.h>

static Pos3d Pos3d_add(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

static Pos3d Pos3d_add3d(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

static Pos3d Pos3d_mul(Pos3d a, double s) {
    return (Pos3d){
        .x = a.x * s,
        .y = a.y * s,
        .z = a.z * s,
    };
}

static Pos3d Pos3d_mul3d(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x * b.x,
        .y = a.y * b.y,
        .z = a.z * b.z,
    };
}

static Pos3d Pos3d_sub(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

static Pos3d Pos3d_sub3d(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

static Pos3d Pos3d_div(Pos3d a, double s) {
    return (Pos3d){
        .x = a.x / s,
        .y = a.y / s,
        .z = a.z / s,
    };
}

static Pos3d Pos3d_div3d(Pos3d a, Pos3d b) {
    return (Pos3d){
        .x = a.x / b.x,
        .y = a.y / b.y,
        .z = a.z / b.z,
    };
}

static double Pos3d_distance(Pos3d a, Pos3d b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

static double Pos3d_dot(Pos3d a, Pos3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}