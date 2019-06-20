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
	int temps;
	int start;
	int erreur;
	FILE *fichier;
}test;


test initStructTESTFB (test fb);
test testFB (test fb,DonneesImageRGB *test1FB,DonneesImageRGB *test2FB);
test afficheResultat(test fb);