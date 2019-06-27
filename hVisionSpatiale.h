#ifndef HVISIONSPATIALE_H_
#define HVISIONSPATIALE_H_


#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h"
#include "time.h"

extern int gWinningSquareID;

typedef struct VISIONSPATIAL
{
	int suite;
	int start;
}visi;

void initStructVISION(visi *const on);
void VisionSpatial(int SquareIDOriginal);
void DessineCarreNoir(int SquareID);
void DessineCellules(int SquareID);
void DessineCarreMultiColorRandom(int SquareID);
void DessineCellulesOriginal(int SquareID);
void DessineCarreMultiColorOriginal(int PatternID);
void initMcolor2(void);
//int ChoisirPatternSol();
void DessineCarreNoirOriginal();
void DisplayResult(int SelectedSquareID, int Result);
int NextConfiguration(int SquareIDOriginal,visi *const on);

int gereClicVision(int SelectedSquareID);

#endif  /* !HVISIONSPATIALE_H_ */