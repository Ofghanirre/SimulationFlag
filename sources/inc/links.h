#ifndef __LINKS_H__
#define __LINKS_H__

#include <atom.h>
#include <stdProject.h>

typedef struct _links {
    // Properties
    Atom* fst, *snd;                       // Atoms linked
    double rest_length;                    // Initial length of link
    double elasticity;                     // Elasticity of link    
    double damping;                        // Coefficient d'amortissement
    // Methods
    void (*next)(struct _links*);          // next state of link
} Link;


int new_link(Link* result, Atom* first, Atom* second, cdouble elasticity, cdouble damping);
#endif