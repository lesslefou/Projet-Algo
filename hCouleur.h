#ifndef HCOULEUR_H_
#define HCOULEUR_H_

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800


typedef struct COULEUR
{
	int suite;
	int clic[6];
	int lockeurCo;
	int ordre1[6];
	int ordre2[6];
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
	FILE *fichier4;
	
    char prenom[20];
}coule;




static struct BOUTON
{
	int x1,y1,x2,y2;
}Bouton[] = {
					{71,180,205,250},
					{225,180,359,250},
					{379,180,513,250},
					{533,180,667,250},
					{687,180,821,250},
					{841,180,975,250},
					{995,180,1129,250}
			   };


void gestionEvenement(EvenementGfx evenement);

void miseEnPlaceBouton(void);
void affichageCouleur(coule *const ur);
void initStructCOULEUR(coule *const ur);

void couleur(coule *const ur);
void gereClicCouleur(coule *const ur,int abs, int ord);

#endif  /* !HCOULEUR_H_ */