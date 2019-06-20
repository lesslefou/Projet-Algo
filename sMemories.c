#include "hMemories.h"




void melangeColonne (int colonne[])
{
	int i=0,j=0,tampon=0;

	for (i=0; i<3; i++)
	{
 		j= i + rand() % (3-i);
        tampon = colonne[i];
        colonne[i] = colonne[j];
        colonne[j] = tampon;
	}
}

void melangeLigne (int ligne[])
{
	int i=0,j=0,tampon=0;
	for (i=0; i<2; i++)
	{
 		j= i + rand() % (2-i);
        tampon = ligne[i];
        ligne[i] = ligne[j];
        ligne[j] = tampon;
	}
}


int gereClicCarte (int clic,int abs,int ord,int val)
{
	if (abs>=70 && abs<=320 && ord>=180 && ord<=340) clic=1;	
	if (abs>=340 && abs<=590 && ord>=180 && ord<=340) clic=2;
	if (abs>=610 && abs<=860 && ord>=180 && ord<=340) clic=3;
	if (abs>=880 && abs<=1130 && ord>=180 && ord<=340) clic=4;

	if (abs>=70 && abs<=320 && ord>=360 && ord<=520) clic=5;
	if (abs>=340 && abs<=590 && ord>=360 && ord<=520) clic=6;
	if (abs>=610 && abs<=860 && ord>=360 && ord<=520) clic=7;
	if (abs>=880 && abs<=1130 && ord>=360 && ord<=520) clic=8;

	if (abs>=70 && abs<=320 && ord>=540 && ord<=700) clic=9;
	if (abs>=340 && abs<=590 && ord>=540 && ord<=700) clic=10;
	if (abs>=610 && abs<=860 && ord>=540 && ord<=700) clic=11;
	if (abs>=880 && abs<=1130 && ord>=540 && ord<=700) clic=12;

	return clic;
}





/*

void attributionEmplacementCarte (carte c,DonneesImageRGB *image)
{



	if (abs>=70 && abs<=320 && ord>=180 && ord<=340) 
	{
		clic=1;
		lisImage(70,210,250,160,image1->donneesRGB);
		c.position=1;
	}
	if (abs>=340 && abs<=590 && ord>=180 && ord<=340) 
	{
		clic=2;
		lisImage(340,210,250,160,image1->donneesRGB);
	}
	if (abs>=610 && abs<=860 && ord>=180 && ord<=340) clic=3;
	if (abs>=880 && abs<=1130 && ord>=180 && ord<=340) clic=4;

	if (abs>=70 && abs<=320 && ord>=360 && ord<=520) clic=5;
	if (abs>=340 && abs<=590 && ord>=360 && ord<=520) clic=6;
	if (abs>=610 && abs<=860 && ord>=360 && ord<=520) clic=7;
	if (abs>=880 && abs<=1130 && ord>=360 && ord<=520) clic=8;

	if (abs>=70 && abs<=320 && ord>=540 && ord<=700) clic=9;
	if (abs>=340 && abs<=590 && ord>=540 && ord<=700) clic=10;
	if (abs>=610 && abs<=860 && ord>=540 && ord<=700) clic=11;
	if (abs>=880 && abs<=1130 && ord>=540 && ord<=700) clic=12;

*/