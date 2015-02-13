#include "displaying.h"

void disArray(int* tab, int size) {
    int i=0;
    printf("[");
    for(i=0;i<size;i++){
        printf(" %d ", tab[i]);
    }
    printf("]");
}

void simpleDisplay(Sudoku s)
{
    int c =0;
    int l =0;
    for(l=0; l<9; l++)
    {
        for(c=0; c<9; c++)
        {
            printf("%d ,", s[l][c]);
        }
        printf("\n");
    }
}

void Display(Sudoku s)
{
    int c =0;
    int l =0;

    for(l=0; l<9; l++)
    {
        if(l%3 == 0){
            printf("+-----------------------------+\n");
        }

        for(c=0; c<9; c++)
        {
            if(c%3 == 0){
                printf("|");
            }
            int val = s[l][c];
            if(val == VIDE){
                printf(" . ");
            } else {
                printf(" %d ", s[l][c]);
            }
        }

        printf("|\n");
    }
    printf("+-----------------------------+\n");
}
