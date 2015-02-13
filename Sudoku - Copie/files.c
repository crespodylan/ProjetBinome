#include "files.h"

Sudoku fileToSudoku(char* filepath)
{
    char _null[50];
    FILE* file = NULL;
    file = fopen(filepath, "r+");
    Sudoku sudoku = newSudoku();
    if(file==NULL)
    {
        return sudoku;
    }
    else
    {
        int i,l;
        for(l=0;l<9;l++)
        {
            for(i=0;i<9;i++)
            {
                char buffer = fgetc(file); // lit un char
                sudoku[l][i] = buffer-'0'; //cast char à int
            }
            fgets(_null, 50, file); // Retour à la ligne sur WINDOWS et LINUX
        }
        fclose(file);
    }
    printf("Sudoku importé");
    return sudoku;
}

void SudokuToFile(Sudoku sudoku, char* filepath)
{
    FILE* file = NULL;
    file = fopen(filepath, "w+");
    if(file==NULL)
    {
        return;
    }
    else
    {
        int i,l;
        for(l=0;l<9;l++)
        {
            for(i=0;i<9;i++)
            {
                fputc(sudoku[l][i]+'0', file); // écrit un char
            }
            fputc('\n', file); // passe à la ligne
        }
        fclose(file);
    }
}
