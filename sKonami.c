#include "hKonami.h"

void initStructKONAMI(kona *mi)
{
	int i=0;
	mi->suite=0;
	for (i=0; i<5; i++) 	mi->clic[i]=0;
	mi->lock=3;
	mi->resultat=0;
	mi->delay=0;
	mi->tempo=0;
	mi->cpt=0;
	mi->start=0;
	mi->temps=0;
	mi->erreur=0;
	FILE *fichier=NULL;
	mi->imkonami = lisBMPRGB("konami.bmp");


	memset(mi->prenom,0,20);
}

void affichageKonami(kona *mi)
{
	effaceFenetre (255, 255, 255);
	couleurCourante (200,200,200);
	rectangle(170,60,420,120);
	rectangle(540,60,810,120);
	rectangle(900,60,1100,120);
	rectangle(0,730,100,800);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Chronometre : ",20,190,80);
	afficheChaine("nb d'erreur : ",20,580,80);
	afficheChaine("S T A R T",20,930,80);
	afficheChaine("Retour",20,20,760);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("K O N A M I",40,380,720);

	
	if (mi->start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	if (mi->start == 2)	
	{
		ecrisImage(50, 180, mi->imkonami->largeurImage, mi->imkonami->hauteurImage, mi->imkonami->donneesRGB);
			
		mi->delay ++;
		if (mi->tempo >= 2) mi->tempo++;
		if (mi->delay == 45)	
		{
			mi->temps++;
			mi->delay=0;
		}
		if (mi->suite == 0) 
		{
			afficheChaine("Start/Droite/Gauche/Haut/Bas/A",20,50,150);
		}
		else if (mi->suite == 1)
		{

			afficheChaine("Gauche/Start/B/Bas/Haut/A",20,50,150);
		}

	}
	


	char chrono[5] ;	
	memset(chrono,0,sizeof(chrono));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(chrono,"%d s",mi->temps);
	afficheChaine(chrono,20,350,80);


	char pourcentage[3];
	memset(pourcentage,0,sizeof(pourcentage));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(pourcentage,"%d",mi->erreur);
	afficheChaine(pourcentage,20,730,80);

	/*
	
	*/
	if (mi->start == 3)
	{
		char nom[30];
		strcpy(nom,mi->prenom);
		strcat(nom,".txt");
		mi->fichier3=fopen(nom,"at");
		fprintf(mi->fichier3, "TEST Konami du DATE\nChrono : %d\nNombre d'erreur : %d\n\n",mi->temps,mi->erreur);
		fclose(mi->fichier3);
		mi->start = 4;
	}	

	if (mi->start == 4)
	{
		couleurCourante(120,120,120);
		rectangle(50,180,850,680);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,230,400);
	}
}

kona gereClicCode(kona *mi,int abs,int ord)
{
	int clic=0;
	if      (abs>=100 && abs<=340 && ord>=130 && ord<=290) clic = 1;
	else if (abs>=360 && abs<=600 && ord>=130 && ord<=290) clic = 2;
	else if (abs>=620 && abs<=840 && ord>=130 && ord<=290) clic = 3;
	else if (abs>=860 && abs<=1100 && ord>=130 && ord<=290) clic = 4;

	else if (abs>=100 && abs<=340 && ord>=310 && ord<=460) clic = 5;
	else if (abs>=360 && abs<=600 && ord>=310 && ord<=460) clic = 6;

	/*if (mi->lockeur == 0) mi->clic1 = clic1 ;
	else if (mi.lockeur == 1) mi->clic2 = clic1;
	else if (mi.)
		*/
}