#ifndef __LINKS_H__
#define __LINKS_H__

#include <atom.h>
#include <stdProject.h>

typedef struct _links {
    Atom* fst, *snd;
    cdouble length;
    cdouble elasticity;
    cdouble mass;
    cdouble rigidity;
} Link;


int new_link(Link* result, Atom* first, Atom* second, cdouble length, cdouble elasticity, cdouble mass, cdouble rigidity);

#endif