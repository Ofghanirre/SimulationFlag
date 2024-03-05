#ifndef __ATOM_H__
#define __ATOM_H__

#include <geometry.h>

typedef enum EAtomType {
    ANCHOR,
    NODE
} EAtomType;

typedef struct _atom {
    Pos3d position;
    RGB color;
    EAtomType type;
    void (*draw)(struct _atom*, int);
    void (*next)(struct _atom*, Vec3d);
} Atom;

int new_atom(Atom* result, EAtomType type, Pos3d position, RGB color, void (*draw)(Atom*, int), void (*next)(Atom*, Vec3d));
int new_atom_anchor(Atom* result, Pos3d position, RGB color);
int new_atom_node(Atom* result, Pos3d position, RGB color);

#endif