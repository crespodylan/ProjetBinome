#ifndef _SUDOKU_
#define _SUDOKU_

#include "liste.h"
#include "utils.h"

#define VIDE 0

typedef int** Sudoku;

/// Créer un Sudoku
/// Le sudoku est une grille représenté par un tableau de tableau.
/// La grille respecte la forme int[ligne][colonne] à travers tous le programme.
/// Une case remplie par -1 dans la grille sera considéré comme vide dans le sudoku.
Sudoku newSudoku();

/// Vérifie si une ligne est conforme au règle du sudoku.
/// Ne prend pas en compte les cases vides
bool isGoodLine(int,Sudoku);

/// Vérifie si une colonne est conforme au règle du sudoku
/// Ne prend pas en compte les cases vides
bool isGoodColumn(int, Sudoku);

/// Vérifie si un bloc est conforme au règle du sudoku
/// Les blocs sont numérotés de 0 à 8 dans le sudoku
/// Schéma des bloc     0 1 2
///                     3 4 5
///                     6 7 8
/// La fonction commence par la case la plus en haut à gauche
/// Puis se décale vers la droite et le bas de deux cran pour faire tout le bloc
bool isGoodBloc(int, Sudoku);

/// Vérifie si tout le sudoku est conforme au règles du jeu
/// Ne prend pas en compte les cases vides
bool isGoodSudoku(Sudoku);

/// Vérifie si le sudoku est entièrement rempli
bool isFilled(Sudoku);

/// Vérifie si le sudoku est fini et conforme au règle
bool isFinished(Sudoku);

/// Renvoie un tableau contenant les valeurs possibles pour une case.
/// Astuce : Pour palier le besoin de connaître la longueur d'un tableau
/// pour le parcourir, et les valeurs possibles n'éxcédant pas la dizaine,
/// on renvoie un char* ('\0' fini le "tableau" ce qui permet de connaitre facilement
/// sa longueur) qui a chaque position i à une valeur possible.
/// Param : ligne, colonne, sudoku
Liste possibleValues(int, int, Sudoku);


/// Supprime n valeurs aléatoires dans le sudoku
void deleteNValues(int n, Sudoku s);

#endif // SUDOKU
