#ifndef __GEO_H__
#define __GEO_H__

typedef struct _pos3 {
    double x, y, z;
} Pos3d, Vec3d;

typedef struct _rgb {
    float r, g, b;
} RGB;

Pos3d Pos3d_add(Pos3d a, Pos3d b);

Pos3d Pos3d_mul(Pos3d a, double s);

#endif