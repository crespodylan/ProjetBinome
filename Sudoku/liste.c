#include "liste.h"

#define SIZE 1024

/** liste vide
 *  precond :
 */

Liste nouvListe() {
    Liste l = (Liste)malloc(sizeof(struct larray));

    l->tab = NULL;
    l->current_nb_blocks = 0;
    l->nb_elements = 0;

    return l;
}

/** fonction intermédiaire : ajustement de la taille du tableau d'une liste
 *  precond : -
 *
 */

static void adjust_size(Liste l) {
    int nb_blocks_needed = l->nb_elements;

    if (l->nb_elements <= 0) { nb_blocks_needed = 0; }
    else { nb_blocks_needed = 1 + ((l->nb_elements-1)/SIZE); }

    if (nb_blocks_needed != l->current_nb_blocks) {
        l->tab = realloc(l->tab, sizeof(int)*nb_blocks_needed*SIZE);
        l->current_nb_blocks = nb_blocks_needed;
    }
}


/** Ajout d'un élément en tête de la liste
 *  precond : -
 *  retour : - (on travaille dans la même liste)
 */

void adjt(int x, Liste l) {
	int i;
    l->nb_elements++;

    adjust_size(l);

    // on décale tous les éléments
    for(i=l->nb_elements-2; i>=0; --i) {
            l->tab[i+1] = l->tab[i];
    }
    l->tab[0] = x;
    return;
}

/** Ajout d'un élément en fin  de  liste
 *  precond : -
 *  retour : - (attention : on travaille dans la même liste)
 */

void adjq(int x, Liste l) {
    l->nb_elements++;
    adjust_size(l);

    l->tab[l->nb_elements-1] = x;

	return;
}

/** Taille d'une liste
 *  precond : -
 *  retour : le nombre d'éléments présents dans la liste
 */


int taille(Liste l) {
	return l->nb_elements;
}

/** Ajout d'un élément dans une liste à la place ind
 *  precond : 0 <= ind < taille(l)
 *  retour : - (attention : on travaille dans la même liste)
 */

void insert(int e, Liste l, int ind) {
    int i;
    l->nb_elements++;
    adjust_size(l);

    if (ind < 0 || ind > taille(l)) {
		fprintf(stderr, "indice non valide : %d\n", ind);
		return;
	}

    // on décale tous les éléments après ind pour le placer
    for(i=l->nb_elements-1; i >= ind; --i) {
        l->tab[i+1] = l->tab[i];
    }
    l->tab[ind] = e;
    return;
}

/** Renvoie l'element en tete de liste
 *  precond : l existe && taille(l) >= 1
 *  retour : l'élément
 */

int tete(Liste l) { return l->tab[0]; }

/** Renvoie l'element en fin de liste
 *  precond : l existe && taille(l) >= 1
 *  retour : l'élément
 */

int queue(Liste l) { return l->tab[l->nb_elements-1]; }



/** Suppression en tête (aucun effet si la liste est vide)
 *  precond : -
 *  retour : - (attention : on travaille dans la même liste)
 */

void supt(Liste l) {
    int i;
    if (l->nb_elements <= 0) { return; }

    l->nb_elements--;
    for(i=0; i < l->nb_elements; ++i) {
            l->tab[i] = l->tab[i+1];
    }

    adjust_size(l);

	return;
}

/** Suppression en fin (aucun effet si la liste est vide)
 *  precond : -
 *  retour : - (attention : on travaille dans la même liste)
 */

void supq(Liste l) {
    if (l->nb_elements <= 0) { return; }

    l->nb_elements--;

    adjust_size(l);

	return;
}

/** Test de vacuité d'une liste
 *  precond : -
 *  retour : 1 si vide, 0 sinon
 */

int estVide(Liste l) {
	return (l->nb_elements > 0?0:1);
}

/** rend l'element à la place i
 *  precond : 0 <= i < taille(l)
 *  retour : l'element
 */

int elt(int i, Liste l) {
    if (i >= l->nb_elements) { return 0; }

    return l->tab[i];
}


/** Suppression de la première occurence de x dans l
 *  precond : -
 *  retour : la nouvelle liste (attention : on travaille dans la même liste)
 */

/*
liste removeElt(int x, Liste l) {
    if (l->nb_elements <= 0) { return l; }

    int ind=0;
    while (l->tab[ind] != x && ind < l->nb_elements)
        ++ind;

    // x non trouvé
    if (ind == l->nb_elements) { return l; }

    // décalage des éléments
    for(int i=ind; i < l->nb_elements; ++i) {
        l->tab[i] = l->tab[i+1];
    }

    l->nb_elements--;
    adjust_size(l);


	return l;
}
*/

/** Suppression de tous les éléments d'une liste
 *  precond : -
 */


void fermeList(Liste l) {
	l->nb_elements=0;
    adjust_size(l);
    free(l);
}

/** Recherche d'un élément
 *  precond : -
 *  retour : TRUE si l'élément apparait dans la liste FALSE sinon
 */

/*
bool find(int x, Liste l) {
    int ind=0;
    while (l->tab[ind] != x && ind < l->nb_elements)
        ++ind;

    // x non trouvé
    if (ind == l->nb_elements) { return FALSE; }
    return TRUE;
}

 Acces au i-eme élément
 *  precond :  0 <= i < size(l)
 *  retour : le i-eme élément (indefini i precond non vérifiée)
 */

/** Suppresion à l'index x de la liste
 *  precond : -
 */
 void suprIndex(int x, Liste l) {
    int i =0;
    for(i=x; i<l->nb_elements;i++) {
        l->tab[i] = l->tab[i+1];
    }
    l->nb_elements--;
 }

