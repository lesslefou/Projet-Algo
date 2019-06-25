#ifndef HAFFICHAGE_H_
#define HAFFICHAGE_H_

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"
#include "hTestFB.h"
#include "hMemory.h"
#include "hKonami.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800

typedef enum {MenuPrincipal=0, Memoire=1, Analyse=2, Lateralite=3,General=4,Resultat=5}
	Etats;

typedef enum {Boule=0,Mnemonique=1,Memory=2}
	ChoixMemoire;

typedef enum {Calcul=0,TestFB=1,Couleur=2,Hector=3}
	ChoixAnalyse;

typedef enum {Vision=1,Evite=2,Konami=3}
	ChoixLateralite;

typedef struct gereClicMenu
{
	int choix;
	int choix1;
	int choix2;
	int choix3;
	int choix4;
	int choix5;
	int bloqueur;
	int start;
	int retour;
	
}menu;


void gestionEvenement(EvenementGfx evenement);

menu initMenu(menu m);
menu choixMenu(menu m, test * const fb, memory *me, kona *const mi,carte tableau[12],int p,int abs, int ord);
void affichage1(void);
void affichageMemoire(void);
void affichageAnalyse(void);
void affichageLateralite(void);
void affichageResultat(void);
menu gereClicMenu(menu m,int abs,int ord);
menu gereClicMemoire(menu m,int abs,int ord);
menu gereClicAnalyse(menu m,int abs,int ord);
menu gereClicLateralite(menu m,int abs,int ord);
menu gereClicResultat(menu m,int abs,int ord);

menu gereClicStart(menu m);

#endif  /* !HAFFICHAGE_H_ */
