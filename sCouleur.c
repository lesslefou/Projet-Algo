#include "hCouleur.h"


void miseEnPlaceBouton(void)
{
	couleurCourante(200,200,200);
	for (int i=0; i<8; i++)
	{
		rectangle(Bouton[i].x1, Bouton[i].y1, Bouton[i].x2, Bouton[i].y2);
	}
	epaisseurDeTrait(3);
	couleurCourante(0,0,255);
	afficheChaine("BLEU",15,110,210);
	couleurCourante(0,0,0);
	afficheChaine("NOIR",15,270,210);
	couleurCourante(255,0,0);
	afficheChaine("ROUGE",15,420,210);
	couleurCourante(20,148,20);
	afficheChaine("VERT",15,570,210);
	couleurCourante(255,255,255);
	afficheChaine("BLANC",15,715,210);
	couleurCourante(243,214,23);
	afficheChaine("JAUNE",15,875,210);
	couleurCourante(253,108,158);
	afficheChaine("ROSE",15,1020,210);

	couleurCourante(0,0,0);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
}

void initStructCOULEUR(coule *const ur)
{
	memset(ur, 0, sizeof(*ur));	
}

void affichageCouleur(coule *const ur)
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
	afficheChaine("C O U L E U R",40,410,725);
	
	if (ur->start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	if (ur->start == 2)	
	{
		miseEnPlaceBouton();
		ur->delay ++;
		if (ur->tempo >= 2) ur->tempo++;
		if (ur->delay == 45)	
		{
			ur->temps++;
			ur->delay=0;
		}
		
		if (ur->suite >= 0) 
		{
			couleur(ur);
			if (ur->lockeurCo == 1) 
			{
				if (ur->a == 0)
				{
					if (ur->cpt == 1 || ur->cpt == 2)
					{
						ur->a=1;
					}
				}
				if (ur->a == 1) 
				{
					ur->tempo = 2;
					ur->a = 2;
				}

				if (ur->cpt == 2 && ur->a == 2 && ur->suite<9)
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("B R A V O !  N E X T ",30,320,430);
					if (ur->tempo > 25)	
					{
						ur->suite ++;
						ur->tempo = 0;
						ur->cpt = 0;
						ur->lockeurCo = 0;
						ur->a=0;
					}
				}
				else if (ur->cpt == 2 && ur->a == 2 && ur->suite == 9)
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("B R A V O !  N E X T ",30,320,430);
					if (ur->tempo > 25)	
					{
						ur->start=3;
						ur->tempo = 0;
						ur->cpt = 0;
						ur->lockeurCo = 0;
						ur->a=0;
					}
				}
				else if (ur->a == 2)
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("P E R D U . . . ",30,320,430);
					
					if (ur->tempo > 30)	
					{
						for (i=0; i<6; i++) ur->clic[i] = 0;
						ur->erreur ++;
						ur->lockeurCo = 0;
						ur->tempo = 0;
						ur->cpt = 0;
						ur->a=0;
					}
				}

				if (ur->tempo > 30)	
				{
					ur->suite = 1;
					ur->tempo = 2;
					ur->lockeurCo = 0;
				}
			}
		}
	}

	


	char chrono[5] ;	
	memset(chrono,0,sizeof(chrono));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(chrono,"%d s",ur->temps);
	afficheChaine(chrono,20,350,80);


	char pourcentage[3];
	memset(pourcentage,0,sizeof(pourcentage));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(pourcentage,"%d",ur->erreur);
	afficheChaine(pourcentage,20,730,80);

	
	if (ur->start == 3)
	{
		char nom[30];
		printf("preno m = %s\n",ur->prenom);
		strcpy(nom,ur->prenom);
		strcat(nom,"Couleur.txt");
		ur->fichier4=fopen(nom,"at");
		fprintf(ur->fichier4, "TEST du DATE\nChrono : %d\nNombre d'erreur : %d\n\n",ur->temps,ur->erreur);
		fclose(ur->fichier4);
		ur->start = 4;
	}	

	if (ur->start == 4)
	{
		couleurCourante(120,120,120);
		rectangle(200,200,1000,700);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,320,430);
	}
}


void couleur(coule *const ur)
{
	epaisseurDeTrait(4);
	if(ur->suite==0)
	{
		couleurCourante(0,128,0);
		rectangle(350,440,550,575);
		//ROUGE
		couleurCourante(255,0,0);
		afficheChaine("BLEU",25,420,500);
		
	}
	else if(ur->suite==1)
	{ 
		couleurCourante(255,0,0);
		rectangle(350,440,550,575);
		//BLEU
		couleurCourante(0,0,255);
		afficheChaine("VERT",25,420,500);
	}
	else if(ur->suite==2)
	{
		couleurCourante(0,128,0);
		rectangle(350,440,550,575);
		//NOIR
		couleurCourante(0,0,0);
		afficheChaine("GRIS",25,420,500);
	}
	else if(ur->suite==3)
	{
		couleurCourante(128,0,128);
		rectangle(350,440,550,575);
		//vert
		couleurCourante(20,148,20);
		afficheChaine("BLANC",25,400,500);
	}
	else if(ur->suite==4)
	{
		couleurCourante(255,128,128);
		rectangle(340,440,550,575);
		//JAUNE
		couleurCourante(243,214,23);
		afficheChaine("JAUNE",25,410,500);
	}
	else if(ur->suite==5)
	{
		couleurCourante(0,128,255);
		rectangle(340,440,550,575);
		//BLANC
		couleurCourante(255,255,255);
		afficheChaine("ROSE",25,410,500);
	}	
	else if(ur->suite==6)
	{
		couleurCourante(128,128,128);
		rectangle(350,440,550,575);
		//ROSE
		couleurCourante(253,108,158);
		afficheChaine("NOIR",25,420,500);
	}
	else if(ur->suite==7)
	{
		couleurCourante(255,128,0);
		rectangle(350,440,550,575);
		//VERT
		couleurCourante(20,148,20);
		afficheChaine("MARRON",25,400,500);
	}
	else if (ur->suite==8)
	{
		couleurCourante(164,8,28);
		rectangle(350,440,550,575);
		//JAUNE
		couleurCourante(243,214,23);
		afficheChaine("ROUGE",25,410,500);
	}
	else if(ur->suite==9)
	{
		couleurCourante(128,128,192);
		rectangle(350,440,550,575);
		//BLEU
		couleurCourante(0,0,255);
		afficheChaine("KAKI",25,420,500);
	}
	
}


void gereClicCouleur(coule *const ur, int abs, int ord)
{
	int i=0;
	if (ur->suite == 0) i=2;
	else if (ur->suite == 1) i=0;
	else if (ur->suite == 2) i=1;
	else if (ur->suite == 3) i=3;
	else if (ur->suite == 4) i=5;
	else if (ur->suite == 5) i=4;
	else if (ur->suite == 6) i=6;
	else if (ur->suite == 7) i=3;
	else if (ur->suite == 8) i=5;
	else if (ur->suite == 9) i=0;

	if (abs>=Bouton[i].x1 && abs<=Bouton[i].x2 && ord>=Bouton[i].y1 &&ord<=Bouton[i].y2)	ur->cpt = 2;
	else 
	{
		ur->cpt =1;
	}	
}