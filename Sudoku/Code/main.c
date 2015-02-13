#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "sudoku.h"
#include "generation.h"
#include "resolution.h"
#include "files.h"
#include "displaying.h"
#include <string.h>

void helpMenu() {
    printf("%s\n", "- random : Genere un sudoku");
    printf("%s\n", "- easy : Genere un sudoku facile (45 cases en moins)");
    printf("%s\n","- medium : Genere un sudoku moyen (55 cases en moins)");
    printf("%s\n","- hard : Genere un sudoku difficile (65 cases en moins)");
    printf("%s\n","- resolve : Resoue le sudoku en memoire (si il y en a un)");
    printf("%s\n", "- open $chemin: Ouvrir un fichier et l'importer comme sudoku");
    printf("%s\n", "- save $chemin: Sauvegarde le dernier sudoku en memoire");
    printf("%s\n", "- print : Affiche le dernier sudoku en memoire");
    printf("%s\n", "- delete $n: Supprimer des cases du sudoku");
    printf("%s\n\n", "- exit : Sortir du jeu");
}

int main()
{
    printf("%s\n\n", "  -- SU DO KU --");


    printf("%s\n", "+-----+-----+-----+");
    printf("%s\n", "|5 1 3|6 8 7|2 4 9|");
    printf("%s\n", "|8 4 9|5 2 1|6 3 7|");
    printf("%s\n", "|2 6 7|3 4 9|5 8 1|");
    printf("%s\n", "+-----+-----+-----+");
    printf("%s\n", "|1 5 8|4 6 3|9 7 2|");
    printf("%s\n", "|9 7 4|2 1 8|3 6 5|");
    printf("%s\n", "|3 2 6|7 9 5|4 1 8|");
    printf("%s\n", "+-----+-----+-----+");
    printf("%s\n", "|7 8 2|9 3 4|1 5 6|");
    printf("%s\n", "|6 3 5|1 7 2|8 9 4|");
    printf("%s\n", "|4 9 1|8 5 6|7 2 3|");
    printf("%s\n\n", "+-----+-----+-----+");

    char c[1024] = "";
    Sudoku s = NULL;

    helpMenu();
    while(strcmp(c, "exit")) {
        scanf("%s", &c);
        printf("\n");

        if(strcmp(c, "help") == 0) {
            helpMenu();
        }
        else if(strcmp(c, "random")  == 0) {
            s = randomGeneration(0);
        }
        else if(strcmp(c, "easy")  == 0) {
            s = randomGeneration(0);
            deleteNValues(45, s);
            Display(s);
        }
        else if(strcmp(c, "medium")  == 0) {
            s = randomGeneration(0);
            deleteNValues(55, s);
            Display(s);
        }
        else if(strcmp(c, "hard")  == 0) {
            s = randomGeneration(0);
            deleteNValues(65, s);
            Display(s);
        }
        else if(strcmp(c, "resolve")  == 0) {
            if(s != NULL) {
                backtracking(s);
                Display(s);
            } else {
                printf("Aucun sudoku en memoire\n");
            }
        }
        else if(strcmp(c, "open")  == 0) {
            scanf("%s", c);
            s = fileToSudoku(c);
        }
        else if(strcmp(c, "save")  == 0) {
            scanf("%s", c);
            SudokuToFile(s, c);
        }
        else if(strcmp(c, "print")  == 0) {
            if(s != NULL) {
                Display(s);
            } else { printf("Il n'y a pas de sudoku en mémoire"); }
        }
        else if(strcmp(c, "delete")  == 0){
            if(s != NULL) {
                int n=0;
                scanf("%d",&n);
                deleteNValues(n,s);
            }
        }
        else {
            printf("COMMANDE INCONNUE\n");
            helpMenu();
        }

        printf("\n");
    }
    return 0;
}
