#include "hMemory.h"

void initPosition (carte tableau[12])
{
	int alea=0,i=0,j=0;
	int tab[12];

	for (j=0; j<12; j++)
	{
		tab[j]=j+1;
		tableau[j].position=0;
	}

	for (i=0; i<12; i++)
	{
		alea = rand()%11;
		while (tableau[i].position == 0)
		{
			if (tab[alea] != 40)
			{
				tableau[i].position = tab[alea];
				tab[alea]=40;
			}
			else 
			{
				alea++;
				if (alea < 12 && tab[alea] != 40)
				{
					tableau[i].position = tab[alea];
					tab[alea]=40;
				}
				else if (alea >= 12) alea=0;
				else;
			}
		}	
			
	}

}



void placementCarte (int p,carte tableau[12],DonneesImageRGB *chien,DonneesImageRGB *chat,DonneesImageRGB *poulain,DonneesImageRGB *canard,DonneesImageRGB *oiseau,DonneesImageRGB *lapin)
{
	int i=0;
	for (i=0; i<12; i++)
	{
		switch (i+1) 
		{
			case 1:	
				testCarte(tableau,i,chien);
				break;
			case 2:
				testCarte(tableau,i,chat);
				break;
			case 3:	
				testCarte(tableau,i,poulain);
				break;
			case 4:
				testCarte(tableau,i,canard);
				break;
			case 5:	
				testCarte(tableau,i,oiseau);
				break;
			case 6:
				testCarte(tableau,i,lapin);
				break;
			case 7:	
				testCarte(tableau,i,chien);
				break;
			case 8:
				testCarte(tableau,i,chat);
				break;
			case 9:	
				testCarte(tableau,i,poulain);
				break;
			case 10:
				testCarte(tableau,i,canard);
				break;
			case 11:	
				testCarte(tableau,i,oiseau);
				break;
			case 12:
				testCarte(tableau,i,lapin);
				break;
		}
	}
}

void testCarte(carte tableau[12],int p,DonneesImageRGB *image)
{
	if (tableau[p].position == 1)
	{
		ecrisImage(70, 180, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 2)
	{
		ecrisImage(340, 180, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 3)
	{
		ecrisImage(610, 180, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 4)
	{
		ecrisImage(880, 180, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 5)
	{
		ecrisImage(70, 360, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 6)
	{
		ecrisImage(340, 360, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 7)
	{
		ecrisImage(610, 360, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 8)
	{
		ecrisImage(880, 360, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 9)
	{
		ecrisImage(70, 540, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 10)
	{
		ecrisImage(340, 540, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 11)
	{
		ecrisImage(610, 540, 250, 160, image->donneesRGB);
	}
	else if (tableau[p].position == 12)
	{
		ecrisImage(880, 540, 250, 160, image->donneesRGB);
	}
	else;
}



void placementDosDeCarte(DonneesImageRGB *carte,int clic1,int clic2)
{
	if (clic1 == 1 || clic2 == 1)	;
	else ecrisImage(70, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 2 || clic2 == 2)	;
	else ecrisImage(340, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 3 || clic2 == 3)	;
	else ecrisImage(610, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 4 || clic2 == 4)	;
	else ecrisImage(880, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);

	if (clic1 == 5 || clic2 == 5)	;
	else ecrisImage(70, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 6 || clic2 == 6)	;
	else ecrisImage(340, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 7 || clic2 == 7)	;
	else ecrisImage(610, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 8 || clic2 == 8)	;
	else ecrisImage(880, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);

	if (clic1 == 9 || clic2 == 9)	;
	else ecrisImage(70, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 10 || clic2 == 10)	;
	else ecrisImage(340, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 11 || clic2 == 11)	;
	else ecrisImage(610, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
	if (clic1 == 12 || clic2 == 12)	;
	else ecrisImage(880, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			
}

int gereClicCarte (int clic1,int abs,int ord)
{
	if (abs>=70 && abs<=320 && ord>=180 && ord<=340) clic1=1;	
	if (abs>=340 && abs<=590 && ord>=180 && ord<=340) clic1=2;
	if (abs>=610 && abs<=860 && ord>=180 && ord<=340) clic1=3;
	if (abs>=880 && abs<=1130 && ord>=180 && ord<=340) clic1=4;

	if (abs>=70 && abs<=320 && ord>=360 && ord<=520) clic1=5;
	if (abs>=340 && abs<=590 && ord>=360 && ord<=520) clic1=6;
	if (abs>=610 && abs<=860 && ord>=360 && ord<=520) clic1=7;
	if (abs>=880 && abs<=1130 && ord>=360 && ord<=520) clic1=8;

	if (abs>=70 && abs<=320 && ord>=540 && ord<=700) clic1=9;
	if (abs>=340 && abs<=590 && ord>=540 && ord<=700) clic1=10;
	if (abs>=610 && abs<=860 && ord>=540 && ord<=700) clic1=11;
	if (abs>=880 && abs<=1130 && ord>=540 && ord<=700) clic1=12;

	return clic1;
}
