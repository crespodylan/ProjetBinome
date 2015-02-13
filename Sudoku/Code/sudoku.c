#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Sudoku newSudoku() {
    Sudoku res = (int**) malloc(sizeof(int*)*9);

    int i=0;
    for(i=0; i<9; i++){
        res[i] = (int*) malloc(sizeof(int)*9);
    }

    int c,l = 0;
    for(l=0; l<9; l++) {
        for(c=0;c<9;c++) {
            res[l][c] = VIDE;
        }
    }

    return res;
}
void deleteSudoku(Sudoku s) {
    int i;
    for (i=0;i<9;i++) {
        free(s[i]);
    }
    free(s);
}

int* initCountTab() {
    int* res = (int*) malloc(sizeof(int)*9);
    int i = 0;
    for(i=0;i<9;i++) {
        res[i] =0;
    }
    return res;
}

bool isGoodLine(int line, Sudoku s) {
    int* tab = initCountTab();
    int i = 0;

    for(i=0;i<9;i++) {
        int val = s[line][i];
        if(val > 0) { // Si ce n'est pas une case vide
            tab[val-1]++;
            if(tab[val-1] > 1){ // Dès qu'il y a plus qu'une fois le nombre dans la ligne, la règle n'est plus respecté
                free(tab);
                return FALSE;
            }
        }
    }
    free(tab);
    return TRUE;
}

bool isGoodColumn(int column, Sudoku s) {
    int* tab = initCountTab();
    int i = 0;

    for(i=0;i<9;i++) {
        int val = s[i][column];
        if(val > 0) { // Si ce n'est pas une case vide
            tab[val-1]++;
            if(tab[val-1] > 1){ // Dès qu'il y a plus qu'une fois le nombre dans la ligne, la règle n'est plus respecté
                free(tab);
                return FALSE;
            }
        }
    }
    free(tab);
    return TRUE;
}

bool isGoodBloc(int bloc, Sudoku s) {
    int* tab = initCountTab();
    int line = (bloc/3)*3;
    int column = (bloc%3)*3;
    int i = 0;
    int j = 0;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            int val = s[line+i][column+j];
            if(val > 0) { // Si ce n'est pas une case vide
                tab[val-1]++;
                if(tab[val-1] > 1){ // Dès qu'il y a plus qu'une fois le nombre dans la ligne, la règle n'est plus respecté
                    free(tab);
                    return FALSE;
                }
            }
        }
    }
    free(tab);
    return TRUE;
}

bool isGoodSudoku(Sudoku s) {
    int i=0;
    bool res = TRUE;

    // Ligne
    for(i=0;i<9 && res == TRUE;i++){
        res = isGoodLine(i, s);
    }

    // Colonne
    for(i=0;i<9 && res == TRUE;i++){
        res = isGoodColumn(i, s);
    }

    // Bloc
    for(i=0;i<9 && res == TRUE;i++){
        res = isGoodBloc(i, s);
    }

    return res;
}

bool isFilled(Sudoku s) {
    int c = 0 ,l = 0;
    bool res = TRUE;

    for(l=0; l<9 && res == TRUE; l++) {
        for(c=0;c<9 && res == TRUE;c++) {
            if(s[l][c] <= VIDE)
            {
                res = FALSE;
            }
        }
    }
    return res;
}

bool isFinished(Sudoku s) {
    return isFilled(s) && isGoodSudoku(s);
}

Liste possibleValues(int l, int c, Sudoku s) {
    Liste res = nouvListe();
    int i=1;
    int bloc = ((l/3)*3) + (c/3);
    int old = s[l][c]; // Pour ne pas perdre la véritable valeur de la case

    for(i=1;i<=9;i++) { // Test par tatonnement.
        s[l][c] = i;

        if(isGoodLine(l, s) && isGoodColumn(c, s) && isGoodBloc(bloc, s)) {
            adjt(i, res);
        }
    }

    s[l][c] = old; // /!\ Important ! cf. au dessus.
    return res;
}

void deleteNValues(int n, Sudoku s) {
    if(n > 81) {
        printf("Impossible de supprimer autant de valeurs");
        return;
    }
    srand((unsigned)time(NULL));

    int i=0, l=0, c=0, alea=0;
    for(i=0;i<n;i++){
        alea = rand() % 81;
        l = (alea/9);// Ligne
        c = (alea%9);// Colonne

        if(s[l][c] != VIDE){
            s[l][c] = VIDE;
        } else {
            i--;
        }
    }
}


