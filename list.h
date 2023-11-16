#include"cell.h"

typedef struct t_list1
{
    t_cell ** head;
    int max_level;
}t_list;

t_list * creationListeVide(int nb_max_niveaux);
int* insererValeurTete(int val,t_list * l,t_cell * c);
void afficherUnNiveau(t_list l,int niveau);
void afficherTousNiveaux(t_list l);
