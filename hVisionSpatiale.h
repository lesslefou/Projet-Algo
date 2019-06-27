#ifndef HVISIONSPATIALE_H_
#define HVISIONSPATIALE_H_


#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"
#include "time.h"

extern int gWinningSquareID;

typedef struct VISIONSPATIAL
{
	int suite;
	int start;
	char prenom[20];
	int result;
	int temps;
	int tempo;
	int erreur;
	int reponse;
	int SquareIDOriginal;
	int SelectedSquareID;
	int Result;
	int PatternID;
	int SquareID;
	int delay;
	int lockeurVI;
	FILE *fichier5;
}visi;

void initStructVISION(visi *const on);
void VisionSpatial(visi *const on);
void DessineCarreNoir(visi *const on);
void DessineCellules(visi *const on);
void DessineCarreMultiColorRandom(visi *const on);
void DessineCellulesOriginal(visi *const on);
void DessineCarreMultiColorOriginal(visi *const on);
void initMcolor2(void);
void DessineCarreNoirOriginal();
void DisplayResult(visi *const on);
void NextConfiguration(visi *const on);

void gereClicVision(visi *const on);
void affichageVision(visi *const on);

#endif  /* !HVISIONSPATIALE_H_ */