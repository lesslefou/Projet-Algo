#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "../../Documents/GfxLib/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../../Documents/GfxLib/BmpLib.h"
#include "../../Documents/GfxLib/ESLib.h"
#include <time.h>



// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800

void gestionEvenement(EvenementGfx evenement);


int couleur(int choix);
void affichage(void);
int gereclic(int choix, int absc, int ord,int scorecouleur);

