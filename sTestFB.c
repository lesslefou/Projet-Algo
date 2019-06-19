#include "hTestFB.h"
/*
void afficheTEST (int suite)
{
	couleurCourante (200,200,200);
	rectangle(170,70,420,130);
	rectangle(540,70,810,130);
	rectangle(900,70,1100,130);
	rectangle(900,300,1100,350);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Chronometre : ",20,190,90);
	afficheChaine("% d'erreur : ",20,580,90);
	afficheChaine("S T A R T",20,930,90);
	afficheChaine("Reponse : ",20,905,370);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("T E S T  F B",40,380,720);	
	if (suite == 0)
	{
		ecrisImage(50, 180, test1FB->largeurImage, test1FB->hauteurImage, test1FB->donneesRGB);
		suite = 1;
	}
	else if (suite ==1)
	{
		ecrisImage(50, 180, test2FB->largeurImage, test2FB->hauteurImage, test2FB->donneesRGB);
		suite = 2;
	}
	else 
	{
		couleurCourante(120,120,120);
		rectangle(50,180,850,680);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,230,400);
	}
	if (lock ==0 ) 
	{
		afficheResultat(chiffre1,chiffre2,suite);
		if (suite ==0 && resultat == test1)		
		{
			afficheResultat(chiffre1,chiffre2,suite);
			suite == 1;
		}
		if (suite ==1 && resultat == test2) 	
		{
			afficheResultat(chiffre1,chiffre2,suite);
			suite == 2;
		}
	}	
}
*/
int afficheResultat(int chiffre1,int chiffre2,int suite,int resultat)
{
	char txt[]="0";
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(txt,"%d%d",chiffre1,chiffre2);
	epaisseurDeTrait(2);
	afficheChaine(txt,20,1030,370);

	if (suite == 0)
	{
		if (chiffre1 == 1 && chiffre2 == 5)		
		{
			afficheChaine("BRAVO",20,950,300);
			resultat = 15;
		}
		else 
		{
			afficheChaine("FAUX",20,950,300);
			resultat = 2;
		}
	}
	else if (suite == 1)
	{
		if (chiffre1 == 1 && chiffre2 == 4)		
		{
			afficheChaine("BRAVO",20,905,270);
			resultat = 14;
		}
		else 
		{
			afficheChaine("FAUX",20,950,300);
			resultat = 2;
		}
	}
	return resultat;
}

