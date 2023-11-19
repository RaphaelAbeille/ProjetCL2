
typedef struct t_cell1
{
    int value;
    int nb_niveau;
    struct t_cell1  ** next;
}t_cell ;

t_cell * creationCell(int val,int nbniveaux);
void afficherCell(t_cell c);
