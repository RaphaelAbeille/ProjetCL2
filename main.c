#include <stdio.h>
#include"list.h"

int main() {
    int reponse, val, nbniveau, nbMaxNiveau,niveau1,niveau2;
    t_cell * t;
    t_list * l;
    do {
        printf("Que voulez-vous faire ? !\n");
        printf("1 - Creer une cellule a niveaux \n");
        printf("2 - Creer une liste a niveaux vide \n");
        printf("3 - Inserer cell tete liste \n");
        printf("4 - Afficher l'ensemble des cellules de la liste pour un niveau particulier\n");
        printf("5 - Afficher tous les niveaux de la liste\n");
        printf("6 - Quitter\n");
        scanf("%d", &reponse);
        switch (reponse) {
            case 1 :
                printf("Choisissez une valeur :");
                scanf("%d", &val);
                printf("Choisissez le nombre de niveaux :");
                scanf("%d", &nbniveau);
                t = creationCell(val,nbniveau);
                printf("La cellule suivante a bien ete cree : \n");
                afficherCell(*t);
                break;
            case 2:
                printf("Choisissez le nombre maximal de niveaux : ");
                scanf("%d", &nbMaxNiveau);
                l = creationListe(nbMaxNiveau);
                printf("La liste suivante a bien ete cree : \n");
                afficherTousNiveaux(*l);
                break;
            case 3:
                printf("A quel niveau de la liste voulez-vous ajouter une cellule : ");
                scanf("%d",&niveau2);
                insererCellTete(l,t,niveau2);
                break;
            case 4:
                printf("Choisir le niveau a afficher : ");
                scanf("%d", &niveau1);
                afficherUnNiveau(*l,niveau1);
                break;
            case 5:
                afficherTousNiveaux(*l);
                break;

            case 6:
                printf("Au revoir !  ");
                break;
            default:
                printf("Choix invalide ");
        }

    } while (reponse != 6);

    return 0;
}
