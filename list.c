#include"list.h"
#include<stdio.h>
#include <stddef.h>


t_list * creationListeVide(int nb_max_niveaux)
{
    t_list * l;
    l->max_level = nb_max_niveaux;
    l->head = NULL;
    return l;
}
int* insererValeurTete(int val,t_list * l,t_cell * c)
{
    l->head = c;
};
void afficherUnNiveau(t_list l, int niveau)
{
    printf("[list_head_%d @-]--> %d",niveau,l.head);
};
void afficherTousNiveaux(t_list l)
{
    for(int i=0;i<l.max_level-1;i++)
    {
        afficherUnNiveau(l,i);
    }
};
