#include <links.h>

int new_link(Link* result, Atom* first, Atom* second, cdouble length, cdouble elasticity, cdouble mass, cdouble rigidity) {
    result->fst = first;
    result->snd = second;
}
