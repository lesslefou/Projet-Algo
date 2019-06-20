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

typedef struct carte
{
	int position;
	int numero;
}carte;

void gestionEvenement(EvenementGfx evenement);

void initPosition (carte tableau[12]);
void placementCarte (int p,carte tableau[12],DonneesImageRGB *chien,DonneesImageRGB *chat,DonneesImageRGB *poulain,DonneesImageRGB *canard,DonneesImageRGB *oiseau,DonneesImageRGB *lapin);
void testCarte(carte tableau[12],int p,DonneesImageRGB *image);

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