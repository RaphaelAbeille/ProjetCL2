#include"cell.h"

typedef struct t_list1
{
    t_cell ** head;
    int max_level;
}t_list;

t_list * creationListe(int nb_max_niveaux);
t_list * insererCellTete(t_list * l,t_cell * c,int niveau2);
void afficherUnNiveau(t_list l,int niveau);
void afficherTousNiveaux(t_list l);
int isListEmpty(t_list l);
int isLevelListEmpty(t_list l, int niveau3);
