#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"
//#include "hTestFB.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800

typedef struct gereClicMenu
{
	int choix;
	int choix1;
	int choix2;
	int choix3;
	int start;
}menu;


void gestionEvenement(EvenementGfx evenement);

menu initMenu(menu m);
menu choixMenu(menu m,test fb, memory me,DonneesImageRGB *test1FB,DonneesImageRGB *test2FB);
void affichage1(void);
void affichageMemoire(void);
void affichageAnalyse(void);
void affichageLateralite(void);
menu gereClicMenu(menu m,int abs,int ord);
menu gereClicMemoire(menu m,int abs,int ord);
menu gereClicAnalyse(menu m,int abs,int ord);
menu gereClicLateralite(menu m,int abs,int ord);

menu gereClicStart(menu m);