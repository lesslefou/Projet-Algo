#include "hVisionSpatiale.h"

int gWinningSquareID;

static struct Coord
{
	int xD;
	int yD;
	int xF;
	int yF;	
}
Coord[]= {{740, 660, 890, 510},{910, 660, 1060, 510},{910, 490, 1060, 340},{740, 490, 890, 340}};



static struct Mcolor2
{
	int c1;
	int c2;
	int c3;
}
Mcolor2[4][4] ={0};

//Dessine les 5 carrées
void VisionSpatial(int SquareIDOriginal)
{
	int SquareID=0;
	
	for(SquareID=0; SquareID<4; SquareID++)
	{
		DessineCarreMultiColorRandom(SquareID);
	}
	
	//TODO mettre valeur random pour SquareID
	gWinningSquareID=SquareIDOriginal;
	DessineCarreMultiColorOriginal(SquareIDOriginal);

}

//Dessine carré noir de droite
void DessineCarreNoir(int SquareID)
{
	couleurCourante(0, 0, 0);
	rectangle(Coord[SquareID].xD, Coord[SquareID].yD, Coord[SquareID].xF, Coord[SquareID].yF);
}

//Dessine carré noir de gauche
void DessineCarreNoirOriginal()
{
	couleurCourante(0, 0, 0);
	rectangle(100, 640, 400, 340);
}



//Initialise les couleurs de toutes les cellules des 4 carrés
void initMcolor2()
{
	int i;
	//Initialise les couleurs des cellules du premier carré
	for(i=0;i<4;i++)
	{
		Mcolor2[0][i].c1=rand()%255;
		Mcolor2[0][i].c2=rand()%255;
		Mcolor2[0][i].c3=rand()%255;
	}
	//Associe des combinaisons de couleurs au carré 2
	Mcolor2[1][0].c1= Mcolor2[0][1].c1;
	Mcolor2[1][0].c2= Mcolor2[0][1].c2;
	Mcolor2[1][0].c3= Mcolor2[0][1].c3;
	
	Mcolor2[1][1].c1= Mcolor2[0][0].c1;
	Mcolor2[1][1].c2= Mcolor2[0][0].c2;
	Mcolor2[1][1].c3= Mcolor2[0][0].c3;
		
	Mcolor2[1][2].c1= Mcolor2[0][2].c1;
	Mcolor2[1][2].c2= Mcolor2[0][2].c2;
	Mcolor2[1][2].c3= Mcolor2[0][2].c3;
		
	Mcolor2[1][3].c1= Mcolor2[0][3].c1;
	Mcolor2[1][3].c2= Mcolor2[0][3].c2;
	Mcolor2[1][3].c3= Mcolor2[0][3].c3;
		
	//Associe des combinaisons de couleurs au carré 3
	Mcolor2[2][0].c1= Mcolor2[0][0].c1;
	Mcolor2[2][0].c2= Mcolor2[0][0].c2;
	Mcolor2[2][0].c3= Mcolor2[0][0].c3;
	
	Mcolor2[2][1].c1= Mcolor2[0][1].c1;
	Mcolor2[2][1].c2= Mcolor2[0][1].c2;
	Mcolor2[2][1].c3= Mcolor2[0][1].c3;
		
	Mcolor2[2][2].c1= Mcolor2[0][3].c1;
	Mcolor2[2][2].c2= Mcolor2[0][3].c2;
	Mcolor2[2][2].c3= Mcolor2[0][3].c3;
		
	Mcolor2[2][3].c1= Mcolor2[0][2].c1;
	Mcolor2[2][3].c2= Mcolor2[0][2].c2;
	Mcolor2[2][3].c3= Mcolor2[0][2].c3;
		
	//Associe des combinaisons de couleurs au carré 4
	Mcolor2[3][0].c1= Mcolor2[0][0].c1;
	Mcolor2[3][0].c2= Mcolor2[0][0].c2;
	Mcolor2[3][0].c3= Mcolor2[0][0].c3;

	Mcolor2[3][1].c1= Mcolor2[0][2].c1;
	Mcolor2[3][1].c2= Mcolor2[0][2].c2;
	Mcolor2[3][1].c3= Mcolor2[0][2].c3;
	
	Mcolor2[3][2].c1= Mcolor2[0][1].c1;
	Mcolor2[3][2].c2= Mcolor2[0][1].c2;
	Mcolor2[3][2].c3= Mcolor2[0][1].c3;
	
	Mcolor2[3][3].c1= Mcolor2[0][3].c1;
	Mcolor2[3][3].c2= Mcolor2[0][3].c2;
	Mcolor2[3][3].c3= Mcolor2[0][3].c3;
}


//Place les cellules dans les carrés noirs de droite
void DessineCellules(int SquareID)
{	
	//Dessine la cellule 1
	
	couleurCourante(Mcolor2[SquareID][0].c1, Mcolor2[SquareID][0].c2, Mcolor2[SquareID][0].c3);
	rectangle(Coord[SquareID].xD+10, Coord[SquareID].yD-10, Coord[SquareID].xF-80, Coord[SquareID].yF+80);
	
	//Dessine la cellule 2
	
	couleurCourante(Mcolor2[SquareID][1].c1, Mcolor2[SquareID][1].c2, Mcolor2[SquareID][1].c3);
	rectangle(Coord[SquareID].xD+80, Coord[SquareID].yD-10, Coord[SquareID].xF-10, Coord[SquareID].yF+80);

	//Dessine la cellule 3
	
	couleurCourante(Mcolor2[SquareID][2].c1, Mcolor2[SquareID][2].c2, Mcolor2[SquareID][2].c3);
	rectangle(Coord[SquareID].xD+80, Coord[SquareID].yD-80, Coord[SquareID].xF-10, Coord[SquareID].yF+10);

	//Dessine la cellule 4
	
	couleurCourante(Mcolor2[SquareID][3].c1, Mcolor2[SquareID][3].c2, Mcolor2[SquareID][3].c3);
	rectangle(Coord[SquareID].xD+10, Coord[SquareID].yD-80, Coord[SquareID].xF-80, Coord[SquareID].yF+10);
}



// Affiche le fond noir + les 4 carrés de droite
void DessineCarreMultiColorRandom(int SquareID)
{
	
	DessineCarreNoir(SquareID);
	
	DessineCellules(SquareID);	
}

//  Affiche le fond noir + le carré de gauche
void DessineCarreMultiColorOriginal(int SquareIDOriginal)
{
		
	DessineCarreNoirOriginal();
	
	DessineCellulesOriginal(SquareIDOriginal);
}


//Place les cellules dans le carré noir de gauche
void DessineCellulesOriginal(int SquareIDOriginal)
{
	//Dessine la cellule 1
	couleurCourante(Mcolor2[SquareIDOriginal][2].c1, Mcolor2[SquareIDOriginal][2].c2, Mcolor2[SquareIDOriginal][2].c3);
	rectangle(100+20, 640-20, 400-160, 340+160);

	//Dessine la cellule 2
	couleurCourante(Mcolor2[SquareIDOriginal][3].c1, Mcolor2[SquareIDOriginal][3].c2, Mcolor2[SquareIDOriginal][3].c3);
	rectangle(100+160, 640-20, 400-20, 340+160);

	//Dessine la cellule 3
	couleurCourante(Mcolor2[SquareIDOriginal][0].c1, Mcolor2[SquareIDOriginal][0].c2, Mcolor2[SquareIDOriginal][0].c3);
	rectangle(100+160, 640-160, 400-20, 340+20);

	//Dessine la cellule 4
	couleurCourante(Mcolor2[SquareIDOriginal][1].c1, Mcolor2[SquareIDOriginal][1].c2, Mcolor2[SquareIDOriginal][1].c3);
	rectangle(100+20, 640-160, 400-160, 340+20);
}






//Affiche le resultat du clique (bon ou mauvais)
void DisplayResult(int SelectedSquareID, int Result)
{
	if(Result==0)
	{
		couleurCourante(255, 0, 0);
		epaisseurDeTrait(7);
		ligne(Coord[SelectedSquareID].xD, Coord[SelectedSquareID].yD, Coord[SelectedSquareID].xF, Coord[SelectedSquareID].yF);
		ligne(Coord[SelectedSquareID].xD, Coord[SelectedSquareID].yD-150, Coord[SelectedSquareID].xF, Coord[SelectedSquareID].yF+150);		
	}
	else if(Result==1)
	{
		couleurCourante(0, 255, 0);
		epaisseurDeTrait(7);
		ligne(Coord[SelectedSquareID].xD, Coord[SelectedSquareID].yD-75, Coord[SelectedSquareID].xF-75, Coord[SelectedSquareID].yF);
		ligne(Coord[SelectedSquareID].xD+75, Coord[SelectedSquareID].yD-150, Coord[SelectedSquareID].xF, Coord[SelectedSquareID].yF+150);	
		couleurCourante (200,200,200);
			rectangle(900,60,1100,120);
			epaisseurDeTrait(1);
			couleurCourante(0,0,0);
			afficheChaine("Suivant",20,920,80);	
	}
}

//Créer une nouvelle configuration
int NextConfiguration(int SquareIDOriginal,visi *const on)
{
	if (on->suite < 5)
	{
		initMcolor2(); //créer de nouvelles couleurs
		printf("configuration = %d",SquareIDOriginal);
		SquareIDOriginal=rand()%4; //choisi une nouvelle solution
		printf("configuration = %d",SquareIDOriginal);
	    rafraichisFenetre();
	}
	else on->start =3;
	return SquareIDOriginal;
	
}

//Determine où tu as cliqué
int gereClicVision(int SelectedSquareID)
{
	//Délimite Carré 1
	if( abscisseSouris()>739 && ordonneeSouris()>509 && abscisseSouris()<891 && ordonneeSouris()<661)
	{
		SelectedSquareID=0;
	}
	//Délimite Carré 2
	else if( abscisseSouris()>909 && ordonneeSouris()>509 && abscisseSouris()<1061 && ordonneeSouris()<661)
	{
		SelectedSquareID=1;
	}
	//Délimite Carré 3
	else if( abscisseSouris()>909 && ordonneeSouris()>339 && abscisseSouris()<1061 && ordonneeSouris()<491)
	{
		SelectedSquareID=2;
	}
	//Délimite Carré 4
	else if( abscisseSouris()>739 && ordonneeSouris()>339 && abscisseSouris()<891 && ordonneeSouris()<491)
	{
		SelectedSquareID=3;
	}
	return SelectedSquareID;
}

