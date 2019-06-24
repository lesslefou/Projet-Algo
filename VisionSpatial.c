#include "VisionSpatial.h"
	

void VisionSpatial()
{
	int SquareID=0;
	
	couleurCourante(0, 0, 0);
	ligne(600, 750, 600, 150);
	couleurCourante (200,200,200);
	rectangle(170,60,420,120);
	rectangle(540,60,810,120);
	rectangle(900,60,1100,120);
	rectangle(0,0,100,70);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Chronometre : ",20,190,80);
	afficheChaine("nb d'erreur : ",20,580,80);
	afficheChaine("S T A R T",20,930,80);
	afficheChaine("Retour",20,20,30);
	couleurCourante(255,0,0);
	epaisseurDeTrait(4);
	afficheChaine("Vision Spatial",40,410,760);
	for(SquareID=0; SquareID<4; SquareID++)
	{
		DessineCarreMultiColorRandom(SquareID);
	}
	
	SquareID=ChoisirPatternSol();
	
	
	DessineCarreMultiColorOriginal(SquareID);
}

void DessineCarreNoir(int SquareID)
{
	couleurCourante(0, 0, 0);
	rectangle(Coord[SquareID].xD, Coord[SquareID].yD, Coord[SquareID].xF, Coord[SquareID].yF);
}


//Initialise les couleurs de toutes les cellules des 4 carrés
void initMcolor2(){
	int j,i;
	for(j=0;j<4;j++){
		for(i=0;i<4;i++){
		Mcolor2[j][i].c1=rand()%255;
		Mcolor2[j][i].c2=rand()%255;
		Mcolor2[j][i].c3=rand()%255;
	}
	}
}


void DessineCellules(int SquareID)
{	
	//Dessine la cellule 1
	
	couleurCourante(Mcolor2[SquareID][1].c1, Mcolor2[SquareID][1].c2, Mcolor2[SquareID][1].c3);
	rectangle(Coord[SquareID].xD+20, Coord[SquareID].yD-20, Coord[SquareID].xF+65, Coord[SquareID].yF-65);
	
	//Dessine la cellule 2
	
	couleurCourante(Mcolor2[SquareID][2].c1, Mcolor2[SquareID][2].c2, Mcolor2[SquareID][2].c3);
	rectangle(Coord[SquareID].xD+85, Coord[SquareID].yD-20, Coord[SquareID].xF+130, Coord[SquareID].yF-65);

	//Dessine la cellule 3
	
	couleurCourante(Mcolor2[SquareID][3].c1, Mcolor2[SquareID][3].c2, Mcolor2[SquareID][3].c3);
	rectangle(Coord[SquareID].xD+85, Coord[SquareID].yD-85, Coord[SquareID].xF+130, Coord[SquareID].yF-130);

	//Dessine la cellule 4
	
	couleurCourante(Mcolor2[SquareID][4].c1, Mcolor2[SquareID][4].c2, Mcolor2[SquareID][4].c3);
	rectangle(Coord[SquareID].xD+20, Coord[SquareID].yD-85, Coord[SquareID].xF+65, Coord[SquareID].yF-130);
}




void DessineCarreMultiColorRandom(int SquareID)
{
	initMcolor2();
	DessineCarreNoir(SquareID);
	
	DessineCellules(SquareID);
	
	
}

int ChoisirPatternSol()
{
	int R;
	R=rand()%4;
	return R;
}


void DessineCarreMultiColorOriginal(int SquareID)
{
	
	
	DessineCarreNoir(SquareID);
	
	DessineCellulesOriginal(SquareID);
	
	
}



void DessineCellulesOriginal(int SquareID)
{
	//Dessine la cellule 1
	couleurCourante(Mcolor2[SquareID][3].c1, Mcolor2[SquareID][3].c2, Mcolor2[SquareID][3].c3);
	rectangle(Coord[4].xD+10, Coord[4].yD-10, Coord[4].xF+40, Coord[4].yF-40);

	//Dessine la cellule 2
	couleurCourante(Mcolor2[SquareID][4].c1, Mcolor2[SquareID][4].c2, Mcolor2[SquareID][4].c3);
	rectangle(Coord[4].xD+50, Coord[4].yD-10, Coord[4].xF+80, Coord[4].yF-40);

	//Dessine la cellule 3
	couleurCourante(Mcolor2[SquareID][1].c1, Mcolor2[SquareID][1].c2, Mcolor2[SquareID][1].c3);
	rectangle(Coord[4].xD+50, Coord[4].yD-50, Coord[4].xF+80, Coord[4].yF-80);

	//Dessine la cellule 4
	couleurCourante(Mcolor2[SquareID][2].c1, Mcolor2[SquareID][2].c2, Mcolor2[SquareID][2].c3);
	rectangle(Coord[4].xD+10, Coord[4].yD-50, Coord[4].xF+40, Coord[4].yF-80);
}













