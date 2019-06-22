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


typedef struct MEMORY
{
    int lockeur;
    int clic1;
    int clic2;
    int validation[12];
    int start;
    int cpt;
	int delay;
	int temps;
	int tempo;
	int erreur;
	FILE *fichier2;
	int stop;
}memory;


typedef struct carte
{
	int position;
}carte;


static struct CoordCarte 
{
	int x, y, l, h;
} CoordCarte[] = { 	{70, 170, 250, 160},
					{340, 170, 250, 160},
					{610, 170, 250, 160},
					{880, 170, 250, 160},
					{70, 350, 250, 160},
					{340, 350, 250, 160},
					{610, 350, 250, 160},
					{880, 350, 250, 160},
					{70, 530, 250, 160},
					{340, 530, 250, 160},
					{610, 530, 250, 160},
					{880, 530, 250, 160}
				};




void gestionEvenement(EvenementGfx evenement);
memory affichageMemory(int p,memory me,carte tableau[12],DonneesImageRGB *chien,DonneesImageRGB *chat,DonneesImageRGB *poulain,DonneesImageRGB *canard,DonneesImageRGB *oiseau,DonneesImageRGB *lapin,DonneesImageRGB *carte,DonneesImageRGB *image1,DonneesImageRGB *image2);
memory initStructMemory(memory m);
void initPosition(carte tableau[12]);
void placementCarte(carte tableau[12],DonneesImageRGB *chien,DonneesImageRGB *chat,DonneesImageRGB *poulain,DonneesImageRGB *canard,DonneesImageRGB *oiseau,DonneesImageRGB *lapin);
void testCarte(carte tableau[12],int p,DonneesImageRGB *image);
memory placementDosDeCarte(DonneesImageRGB *carte,DonneesImageRGB *image1,DonneesImageRGB *image2,memory me);
memory gereClicCarte (memory me,int abs,int ord);

/*
chien = 1
chat = 2
poulain = 3
canard = 4 
oiseau = 5
lapin = 6

chien1 = 7
chat1 = 8
poulain1 = 9
canard1 = 10
oiseau1 = 11
lapin1 = 12
*/