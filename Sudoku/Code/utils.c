#include "utils.h"

/// toString de Boolean.
char* boolean(bool b) {
    if(b == TRUE){
        return "TRUE";
    } else {
        return "FALSE";
    }
    return "VIDE";
}

/// Transforme les 9 valeurs en paramètre en tableau
int* toArray(int un, int deux, int trois, int quat, int cinq, int six, int sept, int huit, int neuf){
    int * res = (int*) malloc(sizeof(int)*9);

    res[0] = un;
    res[1] = deux;
    res[2] = trois;
    res[3] = quat;
    res[4] = cinq;
    res[5] = six;
    res[6] = sept;
    res[7] = huit;
    res[8] = neuf;

    return res;
}

/// Renvoie un tableau de liste de 81 cases
Liste* initTvp () {
    Liste* res = (Liste*) malloc(sizeof(struct larray)*81);

    int i=0;
    for(i=0;i<81;i++) {
        res[i] = nouvListe();
    }
    return res;
}
