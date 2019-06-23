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
Coord[]= {{100, 400, 400, 200},{100, 400, 400, 200},{100, 400, 400, 200},{100, 400, 400, 200},{100, 400, 400, 200}};

static struct Mcolor
{
	int c1;
	int c2;
	int c3;
}
Mcolor[] = {{rand()%255,rand()%255, rand()%255},{rand()%255,rand()%255, rand()%255},{rand()%255,rand()%255, rand()%255},{rand()%255,rand()%255, rand()%255}};
	

int VisionSpatial(void);
//int figure1(void);
//int figure2(void);
//int figure3(void);
//int figure4(void);
//int figure5(void);
//int validation(void);
int DessineCarre(Coord[], Mcolor[]);
int DessineCellule1(Coord[], Mcolor[]);
int DessineCellule2(Coord[], Mcolor[]);
int DessineCellule3(Coord[], Mcolor[]);
int DessineCellule4(Coord[], Mcolor[]);
int DessineCarreMulticolorRandom(Coord[], Mcolor[]);
int DessineCellule1OG(Coord[], Mcolor[]);
int DessineCellule2OG(Coord[], Mcolor[]);
int DessineCellule3OG(Coord[], Mcolor[]);
int DessineCellule4OG(Coord[], Mcolor[]);



