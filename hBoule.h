#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"




// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 600
typedef struct position{
	int start; 
	int delay;
	int temps;
	int tempo;
	int clic1;
	int clic2;
	int clic3;
	int clic4;
	int clic5;
	int valide;
	int bienvu1;
	int bienvu2;
	int bienvu3;
	int bienvu4;
	int bienvu5;
	int reussite;
	int erreur;
	
}posi;


void gestionEvenement(EvenementGfx evenement);


posi replace(int choix,posi p);
posi deplacement1(int choix,int absc, int ord, posi p);
 posi deplacement2(int choix, int absc, int ord, posi p);
 posi affich2(int choix, int absc, int ord, posi p);
 posi verif(posi p, int choix);
 int affichageboule(int choix);
 posi affichage(int choix, posi p,int absc, int ord);
 
 
