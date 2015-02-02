#include "resolution.h"
#include "sudoku.h"
#include "utils.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtracking(Sudoku s) {
    if(!isGoodSudoku(s)){
        printf("La grille ne peut pas etre resolue, car elle n'est pas conforme aux regles du sudoku.\n");
        return;
    }

    // Init variable
    bool back = FALSE;
    Liste* tvp = initTvp(s);
    srand((unsigned)time(NULL));
    int i = 0; // Valeur itérative
    int l = 0; // Ligne
    int c = 0; // Colonne
    char* sequence =  (char*) malloc(82); // '0' case vide, '1' case pleine
    sequence[0] = '\0';
    int alea = 0;


    // Evite de changer les valeurs initiales. On veut résoudre un sudoku .. pas le modifier!
    for(i=0;i<81;i++) {
        l = (i/9) ; c = (i%9);

        if(s[l][c] == VIDE) {
            strcat(sequence, "0");
        } else {
            strcat(sequence, "1");
        }
    }

    // Résolution
    for(i=0;i<81;i++) {
        l = (i/9); c = (i%9);

        // Si le back arrive à -1 .. mauvais signe le sudoku n'a pas de solution
        if(i==-1) {
            printf("Le sudoku n'a pas de solution.\n");
            return;
        }

        // Traitement normal
        if(sequence[i] == '0') { // Case modifiable
            if(back == FALSE) {
                tvp[i] = possibleValues(l,c,s);
            }

            if(tvp[i]->nb_elements == 0) {
                s[l][c] = VIDE;
                back = TRUE;
                i -= 2;
            } else {
                if(back == TRUE) { // Si on recule
                    alea = rand() % tvp[i]->nb_elements;
                    s[l][c] = elt(alea, tvp[i]);
                    suprIndex(alea, tvp[i]);
                    back = FALSE;
                } else {
                    alea = rand() % tvp[i]->nb_elements;
                    s[l][c] = elt(alea, tvp[i]);
                    suprIndex(alea, tvp[i]);
                }
            }
        } else {
            if(back == TRUE) {
                i -= 2;
            }
        }
    }
}
