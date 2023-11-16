
typedef struct t_cell1
{
    int value;
    int nblevel;
    struct t_cell1 ** values;
}t_cell ;

t_cell * creationCell(int val,int nbniveaux);
