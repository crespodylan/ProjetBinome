#include "files.h"

Sudoku fileToSudoku(char* filepath)
{
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
                sudoku[l][i] = buffer-'0'; //cast char � int
            }
            fseek(file, 2, SEEK_CUR); // passe � la ligne
        }
        fclose(file);
    }
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
                fputc(sudoku[l][i]+'0', file); // �crit un char
            }
            fputc('\n', file); // passe � la ligne
        }
        fclose(file);
    }
}
