#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "../../Documents/GfxLib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../../Documents/GfxLib/BmpLib.h"
#include "../../Documents/GfxLib/ESLib.h"
#include <time.h>



// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 600

typedef struct Chaine{
	
int valeur1;
int valeur2;
int choix;
int scorecalcul;
int resultat;
int rep;
}chaine;


void gestionEvenement(EvenementGfx evenement);

chaine resultat(chaine c);
chaine calculMentalAffichage(chaine c);
chaine verif(chaine c);
/*
