#ifndef __LISTE_H
#define __LISTE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct larray {
    int *tab;		// elements
    int current_nb_blocks;
    int nb_elements;
} *Liste;

Liste nouvListe();			// nouvelle liste
void adjt(int, Liste);   	// adjonction en tête
void adjq(int, Liste);		// adjonction en queue
int taille(Liste); 	        // rend la taille de la liste

void insert(int, Liste, int); // insertion de e dans l a la place ind (0 <= ind <= taille(l))
int tete(Liste);           	// rend la tête de la liste
int queue(Liste); 	   	// rend la fin de la liste
void supt(Liste);	       	// suppression en tête
void supq(Liste);        	// suppression en queue
int estVide(Liste);    		// 1 liste vide, 0 sinon
int elt(int ind, Liste);    // rend un élément (0 <= ind < taille(l))
void fermeList(Liste);		// clos la liste
void suprIndex(int x, Liste l); // Supprime index


#endif
