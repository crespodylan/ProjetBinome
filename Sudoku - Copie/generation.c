#include "generation.h"

// Toujours appell� cette fonction avec i=0 !!!! Sinon elle ne fonctionnera pas
Sudoku randomGeneration(int i) {
    // Initialisation des variables
    Sudoku s = newSudoku();
    if(i==0) { // Eviter l'appel de srand dans la m�me seconde - Pour ne l'appeler qu'un fois
        srand(time(0));
    }
    int l=0;
    int c=0;
    int alea = 0;
    Liste tpv = NULL;

    for(l=0;l<9;l++) {
        for(c=0;c<9;c++){
            tpv = possibleValues(l, c, s); // Attention que tabPos ne soit pas NULL
            alea = 0;

            // Evite la division (%) par 0
            if(tpv->nb_elements != 0) {
                alea = rand() % (tpv->nb_elements);
                s[l][c] = elt(alea, tpv);
            }
            fermeList(tpv);
        }
    }

    if(!isFinished(s)){
        deleteSudoku(s);
        return randomGeneration(i+1);
    }
    printf("Solution trouvee en %d iterations\n", i);
    return s;
}

