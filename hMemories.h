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


void gestionEvenement(EvenementGfx evenement);


void melangeColonne (int colonne[]);
void melangeLigne (int ligne[]);
int gereClicCarte (int clic, int abs,int ord,DonneesImageRGB *donneesImage);