#include <stdio.h>
#include"list.h"

int main() {
    t_cell * a, * b, * c;
    a = creationCell(1, 3);
    b = creationCell(2, 2);
    c = creationCell(3, 1);

    // liste vide
    t_list * l = creationListe(3);
    // print_level_list(*l);

    insert_head(l, a, a->nb_niveau - 1);
    insert_head(l, b, b->nb_niveau - 1);
    insert_head(l, c, c->nb_niveau - 1);

    print_level_list(*l);
    



    return 0;
}
