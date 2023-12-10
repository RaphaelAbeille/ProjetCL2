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
void insert_head(t_list * l, t_cell * c, int level);
void print_level_list(t_list l, int level);
void print_list(t_list l);
void insererCellBonEndroit(t_list* liste, t_cell* cellule, int niveau);
void print_aligned_list(t_list l);
t_list * creationListPartie2();
int dichotomie_research_cell(t_list * lst, t_cell * cell, int value);
int level_0_research_list(t_list * list, int val);
int level_0_research_cell(t_cell * cell, int val);

