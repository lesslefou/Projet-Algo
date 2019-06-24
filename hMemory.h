#ifndef HMEMORY_H_
#define HMEMORY_H_ 

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

/**
 * \file hMemory.h
 * \author : Lisa DUTERTE
 * \brief Bibliotheque pour utiliser les fonctions permettant de faire fonctionner le Memory\n
 * # Affichage tableau : 
 * \n12 images vont s'afficher face caché à l'écran
 *
 */


/**
 * \brief      Toutes la variables du test Memory
 */
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
	int stop;
	char prenom[20];

	FILE *fichier2;

	DonneesImageRGB *chien ;
    DonneesImageRGB *chat ;
    DonneesImageRGB *poulain ;
    DonneesImageRGB *lapin ;
    DonneesImageRGB *canard ;
    DonneesImageRGB *oiseau ;
    DonneesImageRGB *carte ;
    DonneesImageRGB *image1 ;
    DonneesImageRGB *image2 ;
}memory;

/**
 * \brief      Attribution d'un numéro de position des cartes
 * \details   La table de correspondance de couleurs est disponible en modification par les accesseurs.
 */
typedef struct carte
{
	int position;
}carte;

/**
 * \brief      Coordonnées des cartes (premier point +largeur/hauteur)
 * \details   La table de correspondance de couleurs est disponible en modification par les accesseurs.
 */
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
void placementCarte(carte tableau[12],memory me);
memory affichageMemory(int p,memory me,carte tableau[12]);
memory initStructMemory(memory m);
void initPosition(carte tableau[12]);
void testCarte(carte tableau[12],int p,DonneesImageRGB *image);
memory placementDosDeCarte(memory me);
memory gereClicCarte (memory me,int abs,int ord);

#endif  /* !HMEMORY_H_ */
