#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "Projet-Algo/Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Projet-Algo/Librairie/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "time.h"

static struct Coord
{
	int xD;
	int yD;
	int xF;
	int yF;	
}
Coord[]= {{740, 660, 890, 510},{910, 660, 1060, 510},{910, 490, 1060, 340},{740, 490, 890, 340},{100, 676, 400, 376}};

	

	static struct Mcolor2
{
	int c1;
	int c2;
	int c3;
}
Mcolor2[4][4] =  {{{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0}}};

void VisionSpatial();
void DessineCarre(void);
void DessineCellules(int SquareID);
void DessineCarreMultiColorRandom(int SquareID);
void DessineCellulesOriginal(int PatternID);
void DessineCarreMultiColorOriginal(int PatternID);
void initMcolor2(void);
int ChoisirPatternSol();
