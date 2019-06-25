#include "hTestFB.h"

/**
 * \file hTestFB.c
 * \author : Lisa DUTERTE
 * \brief Toutes les fonctions permettant de faire fonctionner le tesFB
 *
 */

/** 
	\brief 		Appel des fonctions du testFB avec emploie du chrono, du nombre d'erreur.
	\details 	Enregistrement des résultats dans un fichier avec le nom du patient.
	\param test-*fb 	Appel de toutes les variables servant à faire fonctionner le programme
	
	\details
				Description détaillée du code suivant la condition.
	
				"memset(fb, 0, sizeof(*fb))"  
				Initialise toute la structure à 0

**/
void initStructTESTFB(test *fb)
{
	memset(fb, 0, sizeof(*fb));
	fb->lock=3;
	fb->test1=15;
	fb->test2=11;
	fb->test1FB = lisBMPRGB("test1FB.bmp");
	fb->test2FB = lisBMPRGB("test2FB.bmp");
	
}

void testFB(test * const fb)
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
	afficheChaine("T E S T  F B",40,380,720);

	
	if (fb->start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	if (fb->start == 2)	
	{
		couleurCourante (200,200,200);
		rectangle(895,355,1090,400);
		couleurCourante(0,0,0);
		epaisseurDeTrait(1);
		afficheChaine("Reponse : ",20,905,370);

		afficheResultat(fb);
	
		fb->delay ++;
		if (fb->tempo >= 2) fb->tempo++;

		if (fb->delay == 45)	
		{
			fb->temps++;
			fb->delay=0;
		}

		if (fb->suite == 0)
		{
			if (fb->a == 0)		ecrisImage(50, 180, fb->test1FB->largeurImage, fb->test1FB->hauteurImage, fb->test1FB->donneesRGB);
			
			if (fb->lock ==0) 
			{
				if (fb->a == 0)
				{
					fb->tempo = 2;
					fb->a = 1;
				}

				if (fb->resultat == fb->test1 && fb->a == 1)		
				{

					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(255,255,255);
					rectangle(1000,300,1100,400);
					couleurCourante(0,0,0);
					afficheChaine("B R A V O !  N E X T ",30,320,430);
					
					if (fb->tempo > 30)	
					{
						fb->lock=3;
						fb->tempo = 0;
						fb->temps -=2;
						fb->suite = 1;
						fb->cpt = 1;
						fb->a=0;
					}
				}
				else if (fb->resultat == 2 && fb->a == 1) 
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("P E R D U . . . ",30,320,430);
					
					if (fb->tempo > 30)	
					{
						fb->erreur++;
						fb->lock=3;
						fb->tempo = 0;
						fb->temps -=2;
						fb->a=0;

					}
				}
			}	
		}
		else if (fb->suite == 1)
		{
			if (fb->a == 0)		ecrisImage(50, 180, fb->test2FB->largeurImage, fb->test2FB->hauteurImage, fb->test2FB->donneesRGB);
			
			if (fb->lock ==0 ) 
			{
				if (fb->resultat == fb->test2) 	
				{
					if (fb->cpt==1)
					{
						fb->tempo=2;
						fb->cpt=2;
					}
					fb->lock=3;
				}
				if (fb->resultat == 2) 
				{
					fb->erreur++;
					fb->lock=3;
				}
			}
			if (fb->tempo > 30)	
			{
				fb->suite = 2;
				fb->tempo=0;
			}
				
		}
		else 
		{
			fb->start=3;
		}
	}
	


	char chrono[7] ;	
	memset(chrono,0,sizeof(chrono));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(chrono,"%d s",fb->temps);
	epaisseurDeTrait(2);
	afficheChaine(chrono,20,350,80);


	char pourcentage[5];
	memset(pourcentage,0,sizeof(pourcentage));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(pourcentage,"%d",fb->erreur);
	epaisseurDeTrait(2);
	afficheChaine(pourcentage,20,730,80);


	if (fb->start == 3)
	{
		char nom[30];
		strcpy(nom,fb->prenom);
		strcat(nom,".txt");
		fb->fichier=fopen(nom,"at");
		fprintf(fb->fichier, "TEST testFB du DATE\nChrono : %d\nNombre d'erreur : %d\n\n",fb->temps,fb->erreur);
		fclose(fb->fichier);
		fb->start = 4;
	}	

	if (fb->start == 4)
	{
		couleurCourante(120,120,120);
		rectangle(200,200,1000,700);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,320,430);
	}
}

void afficheResultat(test * const fb)
{
	char txt[3] = {0};
	memset(txt,0,sizeof(txt));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(txt,"%1d%1d",fb->chiffre1,fb->chiffre2);
	epaisseurDeTrait(2);
	afficheChaine(txt,20,1030,370);

	if (fb->suite == 0)
	{
		if (fb->chiffre1 == 1 && fb->chiffre2 == 5)		
		{
			afficheChaine("BRAVO",20,950,300);
			fb->resultat = 15;
		}
		else 
		{
			afficheChaine("FAUX",20,950,300);
			fb->resultat = 2;
		}
	}
	else if (fb->suite == 1)
	{
		if (fb->chiffre1 == 1 && fb->chiffre2 == 1)		
		{
			afficheChaine("BRAVO",20,905,270);
			fb->resultat = 11;
		}
		else 
		{
			afficheChaine("FAUX",20,950,300);
			fb->resultat = 2;
		}
	}
}

