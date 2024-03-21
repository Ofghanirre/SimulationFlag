#ifndef __ATOM_H__
#define __ATOM_H__

#include <geometry.h>

typedef enum EAtomType {
    ANCHOR,
    NODE
} EAtomType;

typedef struct _atom {
    // Properties
    // Physics properties
    double mass;                        // mass of atom
    EAtomType type;                     // type of atom
    Pos3d position;                     // position of atom
    Vec3d velocity;                     // velocity of atom
    Vec3d force;                        // force of atom
    // Display properties
    RGB color;                          // color of atom
    // Methods
    void (*next)(struct _atom*, Vec3d); // next state of atom
    void (*draw)(struct _atom*, int);   // draw atom
} Atom;

int new_atom(Atom* result, double mass, EAtomType type, Pos3d position, Vec3d velocity, RGB color, void (*draw)(Atom*, int), void (*next)(Atom*, Vec3d));
int new_atom_anchor(Atom* result, double mass, Pos3d position, RGB color);
int new_atom_node(Atom* result, double mass, Pos3d position, Vec3d velocity, RGB color);

#endif