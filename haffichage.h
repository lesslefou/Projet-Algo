#ifndef HAFFICHAGE_H_
#define HAFFICHAGE_H_

#define TAILLE (256)
#define NBLIGNES (16)

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
#include "hCouleur.h"
#include "hMnemonique.h"
#include "hVisionSpatiale.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800

typedef enum {MenuPrincipal=0, Memoire=1, Analyse=2, Lateralite=3,Quitter=4,Resultat=5,General=6}
	Etats;

typedef enum {Boule=0,Mnemonique=1,Memory=2}
	ChoixMemoire;

typedef enum {Calcul=0,TestFB=1,Couleur=2,Hector=3}
	ChoixAnalyse;

typedef enum {Vision=1,Evite=2,Konami=3}
	ChoixLateralite;

typedef struct gereClicMenu
{
	char nom[100];
	int choix;
	int choix1;
	int choix2;
	int choix3;
	int choix4;
	int choix5;
	int bloqueur;
	int start;
	int retour;
	int demande;
	char prenom[20];
	
}menu;

static struct CoordTest
{
	int x1, y1, x2, y2;
} coordTest[] = { 	
					{100, 340, 480, 640},
					{360, 600, 480, 640},
					{620, 840, 480, 640},
					{860, 1100, 480, 640},

					{100, 340, 310, 460},
					{360, 600, 310, 460},
					{620, 840, 310, 460},
					{860, 1100, 310, 460},


					{100, 340, 130, 290},
					{360, 600, 130, 290},
					{620, 840, 130, 290},
					{860, 1100, 130, 290}
				};


void gestionEvenement(EvenementGfx evenement);

menu initMenu(menu m);
menu choixMenu(menu m, test *const fb, memory *me, kona *const mi,coule *const ur,mnemo *const ni,carte tableau[12],int p,int abs, int ord);
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
menu afficheEcranResultat(menu m);
#endif  /* !HAFFICHAGE_H_ */
