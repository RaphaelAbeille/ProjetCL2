#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>


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

void print_list(t_list l, int level) {
    if (isLevelListEmpty(l, level)) {
        printf("[list head_%d]--> NULL\n",level);
    } else {
        t_cell * cur = l.head[level];
        while (cur != NULL) {
            printf("[%d|@]-->",cur->value);
            cur = cur->next[level];
        }
        printf(" NULL\n");
    }
}

void print_level_list(t_list l) {
    for (int i = 0; i < l.max_level; ++i) {
        print_list(l, i);
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

