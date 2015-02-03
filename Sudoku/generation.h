#ifndef _GENERATION_
#define _GENERATION_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "sudoku.h"
#include "displaying.h"
#include <time.h>

/// On rempli aléatoirement un sudoku ligne par ligne.
/// A chaque case remplie on vérifie que le sudoku respecte toujours les règles.
/// Si il ne les respecte pas, on change la valeur mise dans la case
Sudoku randomGeneration(int i);



#endif // GENERATION
