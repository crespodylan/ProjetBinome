#ifndef FILES
#define FILES

#include "sudoku.h"
#include <stdlib.h>
#include <stdio.h>

Sudoku fileToSudoku(char* filepath);
void SudokuToFile(Sudoku sudoku, char* filepath);

#endif
