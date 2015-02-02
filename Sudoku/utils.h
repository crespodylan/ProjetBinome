#ifndef _UTILS_
#define _UTILS_

#include "liste.h"

typedef int bool;
enum { FALSE, TRUE };

/// Renvoie un tableau de 9 cases avec des valeurs initials � 0
/// Il permet dans isGoodLine, isGoodColumn, isGoodBloc
/// de compter le nombre de fois qu'apparait un nombre.
int* initCountTab();

/// cast boolean to string
char* boolean(bool);

/// Renvoie un tableau � 9 valeurs
/// Ces 9 valeurs sont les param�tres dans l'ordre de leur entr�e dans la fonction
int* toArray(int,int,int,int,int,int,int,int,int);

/// Initialise un tableau qui contiendra les valeurs possibles d'une case
Liste* initTvp();

#endif // UTILS
