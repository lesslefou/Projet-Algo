#include "hKonami.h"

void initStructKONAMI(kona *const mi)
{
	int i=0;
	mi->suite=0;
	for (i=0; i<6; i++) 	mi->clic[i]=0;


	//mi->ordre1[] = {2,7,6,4,5,3};
	mi->ordre1[0]=2;
	mi->ordre1[1]=7;
	mi->ordre1[2]=6;
	mi->ordre1[3]=4;
	mi->ordre1[4]=5;
	mi->ordre1[5]=3;
	
	//mi->ordre2[]= {6,2,1,5,4,3};
	mi->ordre2[0]=6;
	mi->ordre2[1]=2;
	mi->ordre2[2]=1;
	mi->ordre2[3]=5;
	mi->ordre2[4]=4;
	mi->ordre2[5]=3;


	mi->lockeurMi=0;
	mi->resultat=0;
	mi->delay=0;
	mi->tempo=0;
	mi->cpt=0;
	mi->start=0;
	mi->temps=0;
	mi->erreur=0;
	FILE *fichier=NULL;
	
	mi->imkonami = lisBMPRGB("konamiCode.bmp");


	memset(mi->prenom,0,20);
}

void affichageKonami(kona *const mi)
{
	int i=0;
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
	afficheChaine("K O N A M I",40,420,725);

	
	if (mi->start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	if (mi->start == 2)	
	{
		ecrisImage(200, 200, mi->imkonami->largeurImage, mi->imkonami->hauteurImage, mi->imkonami->donneesRGB);
		mi->delay ++;
		if (mi->tempo >= 2) mi->tempo++;
		if (mi->delay == 45)	
		{
			mi->temps++;
			mi->delay=0;
		}
		epaisseurDeTrait(2);
		
		if (mi->suite == 0) 
		{
			afficheChaine("Start/Droite/Gauche/Haut/Bas/A",30,380,150);
			if (mi->lockeurMi == 6) 
			{
				if (mi->a == 0)
				{
					for (i=0; i<6; i++)
					{
						if (mi->clic[i] == mi->ordre1[i]) mi->cpt++;
						mi->clic[i] = 0;
						mi->a=1;
					}
				}
				if (mi->a == 1) 
				{
					mi->tempo = 2;
					mi->a = 2;
				}

				if (mi->cpt == 6 && mi->a == 2)
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("B R A V O !  N E X T ",30,320,430);
					if (mi->tempo > 30)	
					{
						mi->suite = 1;
						mi->tempo = 0;
						mi->temps -=2;
						mi->cpt = 0;
						mi->lockeurMi = 0;
					}
				}
				else if (mi->a == 2)
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("P E R D U . . . ",30,320,430);
					
					if (mi->tempo > 30)	
					{
						for (i=0; i<6; i++) mi->clic[i] = 0;
						mi->erreur ++;
						mi->lockeurMi = 0;
						mi->tempo = 0;
						mi->temps -=2;
						mi->cpt = 0;
						mi->a=0;
					}
				}

				if (mi->tempo > 30)	
				{
					mi->suite = 1;
					mi->tempo = 2;
					mi->lockeurMi = 0;
				}
			}

		}
		else if (mi->suite == 1)
		{
			afficheChaine("Gauche/Start/B/Bas/Haut/A",30,380,150);
			if (mi->lockeurMi == 6) 
			{
				for (i=0; i<6; i++)
				{
					if (mi->clic[i] == mi->ordre2[i]) mi->cpt++;
					mi->clic[i] = 0;
				}
				if (mi->cpt == 6) 
				{
					mi->tempo=2;
					mi->cpt=0;
				}
				if (mi->tempo > 30)	
				{
					mi->start = 3;
					mi->tempo = 0;
					mi->lockeurMi = 0;
				}
			}

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

	
	if (mi->start == 3)
	{
		char nom[30];
		strcpy(nom,mi->prenom);
		strcat(nom,".txt");
		mi->fichier3=fopen(nom,"at");
		fprintf(mi->fichier3, "TEST KONAMI du DATE\nChrono : %d\nNombre d'erreur : %d\n\n",mi->temps,mi->erreur);
		fclose(mi->fichier3);
		mi->start = 4;
	}	

	if (mi->start == 4)
	{
		couleurCourante(120,120,120);
		rectangle(200,200,1000,700);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,320,430);
	}
}

void gereClicCode(kona *const mi,int abs,int ord)
{
	int clic=0,i=0;
	if      (abs>=227 && abs<=427 && ord>=230 && ord<=430) clic = 1; //B
	else if (abs>=447 && abs<=980 && ord>=230 && ord<=430) clic = 2; // START
	else if (abs>=227 && abs<=427 && ord>=460 && ord<=660) clic = 3; //A
	else if (abs>=435 && abs<=565 && ord>=500 && ord<=660) clic = 4; //haut
	else if (abs>=580 && abs<=700 && ord>=500 && ord<=660) clic = 5; //haut
	else if (abs>=720 && abs<=840 && ord>=500 && ord<=660) clic = 6; //haut
	else if (abs>=860 && abs<=980 && ord>=500 && ord<=660) clic = 7; //haut

	for (i=0; i<6; i++)
	{
		if (mi->lockeurMi == i) mi->clic[i] = clic ;
	}
}
