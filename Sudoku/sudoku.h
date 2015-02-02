#ifndef _SUDOKU_
#define _SUDOKU_

#include "liste.h"
#include "utils.h"

#define VIDE 0

typedef int** Sudoku;

/// Cr�er un Sudoku
/// Le sudoku est une grille repr�sent� par un tableau de tableau.
/// La grille respecte la forme int[ligne][colonne] � travers tous le programme.
/// Une case remplie par -1 dans la grille sera consid�r� comme vide dans le sudoku.
Sudoku newSudoku();

/// V�rifie si une ligne est conforme au r�gle du sudoku.
/// Ne prend pas en compte les cases vides
bool isGoodLine(int,Sudoku);

/// V�rifie si une colonne est conforme au r�gle du sudoku
/// Ne prend pas en compte les cases vides
bool isGoodColumn(int, Sudoku);

/// V�rifie si un bloc est conforme au r�gle du sudoku
/// Les blocs sont num�rot�s de 0 � 8 dans le sudoku
/// Sch�ma des bloc     0 1 2
///                     3 4 5
///                     6 7 8
/// La fonction commence par la case la plus en haut � gauche
/// Puis se d�cale vers la droite et le bas de deux cran pour faire tout le bloc
bool isGoodBloc(int, Sudoku);

/// V�rifie si tout le sudoku est conforme au r�gles du jeu
/// Ne prend pas en compte les cases vides
bool isGoodSudoku(Sudoku);

/// V�rifie si le sudoku est enti�rement rempli
bool isFilled(Sudoku);

/// V�rifie si le sudoku est fini et conforme au r�gle
bool isFinished(Sudoku);

/// Renvoie un tableau contenant les valeurs possibles pour une case.
/// Astuce : Pour palier le besoin de conna�tre la longueur d'un tableau
/// pour le parcourir, et les valeurs possibles n'�xc�dant pas la dizaine,
/// on renvoie un char* ('\0' fini le "tableau" ce qui permet de connaitre facilement
/// sa longueur) qui a chaque position i � une valeur possible.
/// Param : ligne, colonne, sudoku
Liste possibleValues(int, int, Sudoku);


/// Supprime n valeurs al�atoires dans le sudoku
void deleteNValues(int n, Sudoku s);

#endif // SUDOKU
