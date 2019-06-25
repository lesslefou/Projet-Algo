#ifndef HTESTFB_H_ 
#define HTESTFB_H_

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800

/**
 * \file hTestFB.h
 * \author : Lisa DUTERTE
 * \brief Bibliotheque pour utiliser les fonctions permettant de faire fonctionner le testFB\n
 * # Affichage enigme : 
 * \n2 enigmes vont s'afficher l'une après l'autre à l'écran
 *
 */



/**
 * \brief      Toutes la variables du testFB
 */
typedef struct testFB
{
	int suite;
	int chiffre1;
	int chiffre2;
	int lock;
	int resultat;
	int test1;
	int test2;
	int delay;
	int tempo;
	int cpt;
	int start;
	int temps;
	int erreur;
	int a;
	FILE *fichier;
	DonneesImageRGB *test1FB;
    DonneesImageRGB *test2FB;	

    char prenom[20];
}test;


void initStructTESTFB (test *fb);
void testFB (test * const fb);
void afficheResultat(test * const fb);
#endif  /* !HTESTFB_H_ */