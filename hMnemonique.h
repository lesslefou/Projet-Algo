#ifndef HMNEMONIQUE_H_
#define HMNEMONIQUE_H_

#define TAILLE (256)
#define NBLIGNES (16)

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"

typedef struct MNEMONIQUE
{

	char tab2[90][20];
	char mot[20];
    char prenom[20];
    int debut;
    int validebouton;
    int score;
    int minuteur;
    int suite;
	int lockeurMn;
	int delay;
	int tempo;
	int start;
	int temps;
	int a;
	int stop;

	int clic[20];
	int resultat;
	int test1;
	int test2;
	int cpt;
	int erreur;
	FILE *fichier4;

}mnemo;

void gestionEvenement(EvenementGfx evenement);

void initStructMNEMONIQUE(mnemo *const ni);
void affichageMnemonique(mnemo *const ni);


void mnemonique(mnemo *const ni);
void rentretesmots(mnemo *const ni);
void valide(mnemo *const ni,int abs,int ord);


#endif  /* !HMNEMONIQUE_H_ */
