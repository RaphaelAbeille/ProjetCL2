#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
#include<math.h>


t_list * creationListe(int nb_max_niveaux)
{
    t_list * l = (t_list *)malloc(sizeof(t_list));
    l->max_level = nb_max_niveaux;
    l->head = (t_cell**)malloc(nb_max_niveaux * sizeof(t_cell*));
    for(int i=0;i<nb_max_niveaux;i++)
    {
        l->head[i] = NULL;
    }
    return l;
}
t_list * insererCellTete(t_list * l,t_cell * c,int niveau2)
{
    t_cell * courant;
    int rep2;
    rep2 = isLevelListEmpty(*l,niveau2);
    printf("Le niveau est il vide ? %d\n",rep2);
    if (rep2==1)
    {
        l->head[niveau2] = c;
    }
    else
    {
        courant = l->head[niveau2];
        while(courant->next[niveau2]!=NULL)
        {
            printf("Boucle while inserer tete\n");
            courant = courant->next[niveau2];
        }
        courant->next[niveau2] = c;
        printf("fin bcl while\n");
    }

    printf("La cellule a bien ete ajoutee A la liste \n");
    return l;
}

// dès qu'insère une cellule en dans un niveau i, il faut l'insérer dans tous les autres niveau j tq j < i
void insert_head(t_list * l, t_cell * c, int level) {
    if (level < l->max_level && level >= 0) {
        // si l->head[level] == NULL
        if (isLevelListEmpty(*l, level)) {
            l->head[level] = c;
        } else {
            c->next[level] = l->head[level];
            l->head[level] = c;
        }
        insert_head(l, c, level - 1);
    }
}

void afficherUnNiveau(t_list l, int niveau)
{
    t_cell * courant;
    int rep = isLevelListEmpty(l,niveau);
    printf("Le niveau est il vide ? %d\n",rep);
    if (rep==1)
    {
        printf("[list head_%d]--> NULL\n",niveau);
    }
    else
    {
        courant = l.head[niveau];
        printf("[list head_%d]-->",niveau);
        while(courant->next[niveau]!=NULL)
        {
            printf("[%d|@]-->",courant->value);
            courant = courant->next[niveau];
        }
        printf("[%d|@]--> NULL\n",courant->value);
    }
}

void print_level_list(t_list l, int level) {
    if (isLevelListEmpty(l, level)) {
        printf("[list head_%d]--> NULL\n",level);
    } else {
        t_cell * cur = l.head[level];
        printf("[list head_%d]--> ",level);
        while (cur != NULL) {
            printf("[%d|@]-->",cur->value);
            cur = cur->next[level];
        }
        printf(" NULL\n");
    }
}

void print_list(t_list l) {
    for (int i = 0; i < l.max_level; ++i) {
        print_level_list(l,i);
    }
}

void afficherTousNiveaux(t_list l)
{
    int rep = isListEmpty(l);
    if (rep==1)
    {
        for(int j=0;j<l.max_level;j++)
        {
            printf("[list head_%d]-->NULL\n",j);
        }
    }
    else
    {
        for(int j=0;j<l.max_level;j++)
        {
            afficherUnNiveau(l,j);
        }

    }
};
int isListEmpty(t_list l)
{
    int rep =1;
    for(int i=0;i<l.max_level;i++)
    {
        if(l.head[i]!=NULL)
        {
            rep = 0;
        }
    }
    return rep;
}
int isLevelListEmpty(t_list l, int niveau3)
{
    return l.head[niveau3] == NULL;
}
// ---------------------------------    PARTIE 2 ----------------------
void insererCellBonEndroit(t_list* liste, t_cell* cellule, int niveau) {
   if(niveau >= 0 && niveau < liste->max_level){
       if(isLevelListEmpty(*liste,niveau)){
           liste->head[niveau] = cellule;
       }
       else{
           t_cell * cur = liste->head[niveau];
           t_cell * prev = NULL;
           while(cellule->value > cur->value && cur != NULL){
               prev = cur;
               cur = cur->next[niveau];
               printf("1");
           }
           cellule->next[niveau] = cur;
           prev->next[niveau] = cellule;
       }
       insererCellBonEndroit(liste,cellule,niveau-1);
   }else{
       printf("Fin ou parametre impossible");
   }


}
void print_aligned_list(t_list l) {
    printf("En cours de construction\n");

}
t_list * creationListeUnSurDeux(int n)
{
    t_list * l = creationListe(n);
    double max_value_double = pow(2,n)-1; // ( 2 epxosant n ) -1
    int max_value = (int)max_value_double;
    printf("%d\n",max_value);
    for(int i=1;i<=n;i++){
        printf("Test i = %d\n",i);
        t_cell * courant = l->head[i];
        for(int j=0;j<max_value;j++){
            printf("Test j = %d\n",j);
            t_cell * t1 = creationCell(j,i);
            afficherCell(*t1);
            courant->next[i] = t1;
            courant = courant->next[i];
        }
    }
    return l;
}

t_list * creationListPartie2 (){
    t_list * l = creationListe(3);
    t_cell *a, *b, *c, *d, *e, *f,*g;
    a = creationCell(1,1);
    b = creationCell(2,2);
    c = creationCell(3,1);
    d = creationCell(4,3);
    e = creationCell(5,1);
    f = creationCell(6,2);
    g = creationCell(7,1);
    insert_head(l,g,g->nb_niveau);
    insert_head(l,f,f->nb_niveau);
    insert_head(l,e,e->nb_niveau);
    insert_head(l,d,d->nb_niveau);
    insert_head(l,c,c->nb_niveau);
    insert_head(l,b,b->nb_niveau);
    insert_head(l,a,a->nb_niveau);
    return l;

}
int level_0_research_cell(t_cell * cell, int val){


    while ( cell != NULL){
        if ( cell->value == val){
            return 1;
        }
        cell = cell->next[0];
    }

    return 0;
}

int level_0_research_list(t_list * list, int val){

    return level_0_research_cell(list->head[0], val);

}



int dichotomie_research_cell(t_list * lst, t_cell * cell, int value){
    if(value == cell->value){
        return 1;
    }
    else if ((cell->value < value) && (cell->nb_niveau > 0)){
        for (int i=0; i<lst->max_level; i++){
            t_cell * temp = lst->head[i];
            temp = cell->next[i];
        }
        return dichotomie_research_cell(lst, cell->next[cell->nb_niveau - 1], value) != 0;
    }

    {
        return dichotomie_research_cell(lst,lst->head[cell->nb_niveau - 1], value) != 0;
    }
}
