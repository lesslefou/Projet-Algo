#ifndef HKONAMI_H_ 
#define HKONAMI_H_

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
 * \file hKonami.h
 * \author : Lisa DUTERTE
 * \brief Bibliotheque pour utiliser les fonctions permettant de faire fonctionner le Konami\n
 * # Affichage du plateau de test : 

 *
 */



/**
 * \brief      Toutes la variables du Konami
 */
typedef struct KONAMI
{
	int suite;
	int clic[6];
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
	FILE *fichier3;
	DonneesImageRGB *imkonami;

    char prenom[20];
}kona;


void initStructKONAMI (kona *mi);
void affichageKonami(kona *mi);
#endif  /* !HTESTFB_H_ */