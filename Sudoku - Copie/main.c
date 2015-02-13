#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "sudoku.h"
#include "generation.h"
#include "resolution.h"
#include "files.h"
#include "displaying.h"
#include <string.h>
#include <time.h>

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
    int i=0; double old=0; double d=0;
    for(i=0;i<100;i++) {
        randomGeneration(0);
        d += (((double) clock()) - d - 1000);
        _sleep(1000);
    }

    printf("%f", d/100/100);
    return 0;
}
