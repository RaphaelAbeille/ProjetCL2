#include <stdio.h>
#include"list.h"

int main() {
    int reponse, val, nbniveau, nbMaxNiveau,niveau1,niveau2,niveau4;
    t_cell * t;
    t_list * l;
    do {
        printf("Que voulez-vous faire ? !\n");
        printf("1 - Creer une cellule a niveaux \n");
        printf("2 - Creer une liste a niveaux vide \n");
        printf("3 - Inserer cell tete liste \n");
        printf("4 - Afficher l'ensemble des cellules de la liste pour un niveau particulier\n");
        printf("5 - Afficher tous les niveaux de la liste affichage simple \n");
        printf("6 - Afficher tous les niveaux de la liste affichage aligné \n");
        printf("7 - Inserer une Cellule au bon endroit \n");
        printf("8 - Quitter\n");
        scanf("%d", &reponse);
        switch (reponse) {
            case 1 :
                printf("Choisissez une valeur : \n");
                scanf("%d", &val);
                printf("Choisissez le nombre de niveaux : \n");
                scanf("%d", &nbniveau);
                t = creationCell(val,nbniveau);
                printf("La cellule suivante a bien ete cree : \n");
                afficherCell(*t);
                break;
            case 2:
                printf("Choisissez le nombre maximal de niveaux : \n");
                scanf("%d", &nbMaxNiveau);
                l = creationListe(nbMaxNiveau);
                printf("La liste suivante a bien ete cree : \n");
                print_list(*l);
                break;
            case 3:
                insert_head(l, t, t->nb_niveau - 1);
                break;
            case 4:
                printf("Choisir le niveau a afficher : \n");
                scanf("%d", &niveau1);
                print_level_list(*l,niveau1);
                break;
            case 5:
                print_list(*l);
                break;
            case 6:
                print_aligned_list(*l);
                break;
            case 7:
                insererCellBonEndroit(l,t,t->nb_niveau);
                break;
            case 8:
                printf("Au revoir !  \n");
                break;
            default:
                printf("Choix invalide \n");
        }

    } while (reponse != 8);

    return 0;
}
