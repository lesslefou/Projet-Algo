#include "hMemory.h"

/**
 * \file CMemory.C
 * \author : Lisa DUTERTE
 * \brief Toutes les fonctions permettant de faire fonctionner le Memory
 *
 */

/** 
	\brief Appel des fonctions du Memory avec emploie du chrono, du nombre d'erreur.
	\details Enregistrement des résultats dans un fichier avec le nom du patient.
	\param memory-me 	Appel de toutes les variables servant à faire fonctionner le programme
	\param carte-tableau[12]	Permet d'attribuer des positions aux cartes
	\return La structure memory me

	\details
				Description détaillée du code suivant la condition.


				"if (me.start == 0)"
				Condition obligeant l'utilisateur d'entrer son prénom avant d'appuyer sur le bouton star

				"if (me.start == 2)
				Condition permettant au chrono de commencer uniquement quand le patient clique sur start.
				A ce moment là le tableau de carte apparait.

				"me.delay ++"
				Incrémentation du chrono en ms
				
				"if (me.delay == 45)"
				Lorsque delay = 45, 1 seconde c'est écoulée

				"if (me.cpt == 12)"	
				Permet d'arreter le chrono lorsque les 6 paires d'images a été découverte
				Laisse les images un micro temps avant l'affichage de fin

				"if (me.start == 3)"
				Enregistrer les données dans un fichier 1 seule fois.

				"if (me.start == 4)"
				Affiche l'affichage de fin
	
**/

memory affichageMemory(int p,memory me,carte tableau[12])
{
	int i=0;					
	effaceFenetre (255, 255, 255);	
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
	epaisseurDeTrait(5);
	afficheChaine("M E M O R I E S",40,380,720);

	if (me.start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	
	if (me.start == 2)
	{
		me.delay ++;
		if (me.delay == 45)	
		{
			me.temps++;
			me.delay=0;
		}

		placementCarte(tableau,me);

		if (me.cpt == 12)
		{
			me.tempo++;
			if (me.tempo > 50)	
			{
				me.start = 3;
				me.tempo=0;
			}
		}
		else me = placementDosDeCarte(me);
	}
	if (me.start == 3)
	{
		me.fichier2=fopen("ResultatMemory.txt","r+");
		fseek(me.fichier2,0,SEEK_END);
		fprintf(me.fichier2, "TEST de %s :\nChrono : %d\nNombre d'erreur : %d\n\n",me.prenom,me.temps,me.erreur);
		fclose(me.fichier2);
		me.start = 4;
	}	
	
	if (me.start ==4)
	{
		couleurCourante(120,120,120);
		rectangle(100,180,1100,680);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,430,400);
	}

	char chrono[] = "00";
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(chrono,"%d s",me.temps);
	epaisseurDeTrait(2);
	afficheChaine(chrono,20,350,80);

	char pourcentage[] = "00";
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(pourcentage,"%d",me.erreur);
	epaisseurDeTrait(2);
	afficheChaine(pourcentage,20,730,80);

	return me;
}


memory initStructMemory(memory me)
{
	int i=0;
    me.lockeur=0;
    me.clic1=0;
    me.clic2=0;
    for (i=0; i<12; i++)   me.validation[i] = 0;
    me.start=0;
	me.cpt=0;
	me.delay=0;
	me.temps=0;
	me.tempo=0;
	me.erreur=0;
	FILE *fichier2=NULL;
	me.stop=0;

	memset(me.prenom,0,20);


	//SI TABLEAU D'IMAGES
	//Images[0] = chien = lisBMPRGB("chien.bmp");
	me.chien = lisBMPRGB("chien.bmp");
	me.poulain = lisBMPRGB("poulain.bmp");
	me.chat = lisBMPRGB("chat.bmp");
	me.canard = lisBMPRGB("canard.bmp");
	me.lapin = lisBMPRGB("lapin.bmp");
	me.oiseau = lisBMPRGB("oiseau.bmp");
	me.carte = lisBMPRGB("carte.bmp");

	me.image1 = lisBMPRGB("chien.bmp");
	me.image2 = lisBMPRGB("chien.bmp");
    return me;
}
/**
	\brief Initialise la position des cartes de manière aléatoire
	\param carte-tableau[12]	Permet d'attribuer des positions aux cartes
	\return La structure memory me

	\details
				"première boucle for"
				Initialise un tableau de 12 cases de 0 à 12 et la variable position d'un tableau de structure à 0.

				"deuxième boucle for"
				Parcours ce tableau de 12 cases aléatoirement
				Si la valeur est différente de 40 alors on l'attribue à la position et on la remplace par 40
				Sinon on parcourt la case d'après.
				Dans le cas de la dernière case, on retourne au début du tableau.
	
**/
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



void placementCarte (carte tableau[12],memory me)
{
	int i=0;
	for (i=0; i<12; i++)
	{
		switch (i+1) 
		{
			case 1:	
				testCarte(tableau,i,me.chien);
				break;
			case 2:
				testCarte(tableau,i,me.chat);
				break;
			case 3:	
				testCarte(tableau,i,me.poulain);
				break;
			case 4:
				testCarte(tableau,i,me.canard);
				break;
			case 5:	
				testCarte(tableau,i,me.oiseau);
				break;
			case 6:
				testCarte(tableau,i,me.lapin);
				break;
			case 7:	
				testCarte(tableau,i,me.chien);
				break;
			case 8:
				testCarte(tableau,i,me.chat);
				break;
			case 9:	
				testCarte(tableau,i,me.poulain);
				break;
			case 10:
				testCarte(tableau,i,me.canard);
				break;
			case 11:	
				testCarte(tableau,i,me.oiseau);
				break;
			case 12:
				testCarte(tableau,i,me.lapin);
				break;
		}
	}
}


void testCarte(carte tableau[12],int p,DonneesImageRGB *image)
{
	int n = tableau[p].position;
	ecrisImage(CoordCarte[n-1].x, CoordCarte[n-1].y,  CoordCarte[n-1].l,  CoordCarte[n-1].h, image->donneesRGB);
}


/**
	\brief Affiche ou non les dos de cartes
	\param memory-me 	Appel de toutes les variables servant à faire fonctionner le programme
	\return La structure memory me

	\details
				"première boucle for"
				Analyse de l'image sélectionnée et enregistrement d'un tableau RGB
				Si validation =0 et pas de clique sur l'image alors la carte reste retournée

				"deuxième boucle for"
				Une fois les deux clics effectués, la variable me.stop = 1.
				Ainsi on parcourt les deux tableaux RGB des deux images sélectionnées.
				Si identique alors les images ne peuvent plus se retourner.
**/
memory placementDosDeCarte(memory me)
{
	int i=0,c=0,j=0,n=0;
	DonneesImageRGB *image;

	for (j=0; j<12; j++)
	{
		if ((me.clic1 == j+1 || me.clic2 == j+1) && me.validation[j] == 0)	
		{
			if (me.clic1 == j+1) 
			{
				image = me.image1;
			}
			if (me.clic2 == j+1) 
			{
				image = me.image2;
			}
			if (me.clic1 == j+1 || me.clic2 == j+1)
			{
				lisImage( CoordCarte[j].x,  CoordCarte[j].y, CoordCarte[j].l,  CoordCarte[j].h,image->donneesRGB);
			}
		}
		else if (me.validation[j] == 0)	
		{
			ecrisImage( CoordCarte[j].x,  CoordCarte[j].y, me.carte->largeurImage, me.carte->hauteurImage, me.carte->donneesRGB);
		}
		else;
	}

if (me.clic1 !=0 && me.clic2 != 0 && me.stop == 1)
	{
		for (i=0; i<(image->largeurImage)*(image->hauteurImage)*3; i++)
		{
			if (me.image1->donneesRGB[i] == me.image2->donneesRGB[i]) c++;
		}
		if (c == (image->largeurImage)*(image->hauteurImage)*3) 
		{
			for (n=0; n<12; n++)
			{
				if (me.clic1 == n+1 || me.clic2 == n+1)
				{
					me.validation[n] = 1;
					me.cpt++;
				}
			}
		}
		else me.erreur++;
		me.stop=0;
	}
	return me;
}


memory gereClicCarte (memory me,int abs,int ord)
{
	int clic1=0;
	if (abs>=70 && abs<=320 && ord>=170 && ord<=330) clic1=1;	
	if (abs>=340 && abs<=590 && ord>=170 && ord<=330) clic1=2;
	if (abs>=610 && abs<=860 && ord>=170 && ord<=330) clic1=3;
	if (abs>=880 && abs<=1130 && ord>=170 && ord<=330) clic1=4;

	if (abs>=70 && abs<=320 && ord>=350 && ord<=510) clic1=5;
	if (abs>=340 && abs<=590 && ord>=350 && ord<=510) clic1=6;
	if (abs>=610 && abs<=860 && ord>=350 && ord<=510) clic1=7;
	if (abs>=880 && abs<=1130 && ord>=350 && ord<=510) clic1=8;

	if (abs>=70 && abs<=320 && ord>=530 && ord<=690) clic1=9;
	if (abs>=340 && abs<=590 && ord>=530 && ord<=690) clic1=10;
	if (abs>=610 && abs<=860 && ord>=530 && ord<=690) clic1=11;
	if (abs>=880 && abs<=1130 && ord>=530 && ord<=690) clic1=12;

	if (me.lockeur == 0) me.clic1 = clic1 ;
	else me.clic2 = clic1;
			
	return me;
}
