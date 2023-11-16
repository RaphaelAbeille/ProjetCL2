#include"cell.h"

t_cell * creationCell(int val,int nbniveaux)
{
    t_cell * t;
    t->value = val;
    t->nblevel = nbniveaux;
    return t;
}
