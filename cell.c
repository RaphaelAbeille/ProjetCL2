#include"cell.h"
#include<stdio.h>
#include<stdlib.h>

t_cell * creationCell(int val,int nbniveaux)
{
    t_cell * t = (t_cell *)malloc(sizeof(t_cell));
    t->value = val;
    t->nb_niveau = nbniveaux;
    t->next = (t_cell **)malloc(nbniveaux * sizeof(t_cell*));
    for(int i=0;i<nbniveaux;i++)
    {
        t->next[i] = NULL;
    }
    return t;
}
void afficherCell(t_cell c)
{
    printf("[value: %d, nb niveau : %d ]\n", c.value,c.nb_niveau);
}
