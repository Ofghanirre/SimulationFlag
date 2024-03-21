#ifndef __GEO_H__
#define __GEO_H__

typedef struct _pos3 {
    double x, y, z;
} Pos3d, Vec3d;

typedef struct _rgb {
    float r, g, b;
} RGB;

Pos3d Pos3d_add(Pos3d a, Pos3d b);

Pos3d Pos3d_add3d(Pos3d a, Pos3d b);

Pos3d Pos3d_mul(Pos3d a, double s);

Pos3d Pos3d_mul3d(Pos3d a, Pos3d b);

Pos3d Pos3d_sub(Pos3d a, Pos3d b);

Pos3d Pos3d_sub3d(Pos3d a, Pos3d b);

Pos3d Pos3d_div(Pos3d a, double s);

Pos3d Pos3d_div3d(Pos3d a, Pos3d b);

double Pos3d_distance(Pos3d a, Pos3d b);

double Pos3d_dot(Pos3d a, Pos3d b);

#define Vec3d_add(a, b) Pos3d_add(a, b)
#define Vec3d_add3d(a, b) Pos3d_add3d(a, b)
#define Vec3d_mul(a, s) Pos3d_mul(a, s)
#define Vec3d_mul3d(a, b) Pos3d_mul3d(a, b)
#define Vec3d_sub(a, b) Pos3d_sub(a, b)
#define Vec3d_sub3d(a, b) Pos3d_sub3d(a, b)
#define Vec3d_div(a, s) Pos3d_div(a, s)
#define Vec3d_div3d(a, b) Pos3d_div3d(a, b)
#define Vec3d_distance(a, b) Pos3d_distance(a, b)
#define Vec3d_dot(a, b) Pos3d_dot(a, b)


#endif