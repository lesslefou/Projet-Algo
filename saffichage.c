#include "haffichage.h"
#include "hTestFB.h"
#include "hMemory.h"
#include "hCouleur.h"

menu initMenu(menu m)
{
	memset(&m, 0, sizeof(m));
	
	return m;
}

/*
menu gereClicStart(menu m)
{
	if (abs>=900 && abs<=1100 && ord>=60 && ord<=120)	
	{
		if (m.start == 0) m.start = 1;
		else if (m.start == 3)
		{
			m = initStructTESTFB(m);
		}
		else;
	}
}
*/



menu choixMenu(menu m, test * const fb, memory *me, kona *const mi,coule *const ur,carte tableau[12],int p,int abs, int ord)
{
	switch (m.choix)
	{
		case MenuPrincipal: 
			m = initMenu(m);
			affichage1();
			break;

		case Memoire:
			affichageMemoire();
			switch (m.choix1)
			{
				case Boule:
					break;

				case Mnemonique:
					break;

				case Memory:
					if (m.retour == 0) 
					{
						m.bloqueur = 1;
						affichageMemory(p,me,tableau);
					}
					else
					{
						m.choix = 1;
						m.bloqueur = 0;
					}
					break;

			}
			break;

		case Analyse:
			affichageAnalyse();
			switch (m.choix2)
			{
				case Calcul:
					break;

				case TestFB:
					if (m.retour == 0) 
					{
						testFB(fb);
						m.bloqueur = 1;
					}
					else	
					{
						m.choix = 2;
						m.bloqueur = 0;
					}
					break;

				case Couleur:
					if (m.retour == 0) 
					{
						affichageCouleur(ur);
						m.bloqueur = 1;
					}
					else	
					{
						m.choix = 2;
						m.bloqueur = 0;
					}
					break;

				case Hector: 
					break;

			}
			break;

		case Lateralite: 
			affichageLateralite();
			switch (m.choix3)
			{
				case Vision:
					break;

				case Evite:
					break;

				case Konami:
					if (m.retour == 0) 
					{
						affichageKonami(mi);
						m.bloqueur = 1;
					}
					else	
					{
						m.choix = 3;
						m.bloqueur = 0;
					}
					break;
			}
			break;

		case General:
			break;

		case Resultat:
			if (m.demande == 0) 
			{
				epaisseurDeTrait(3);
				couleurCourante(0,0,0);
				afficheChaine("Entrer votre prenom :",30,400,440);
			}
			else if (m.demande == 1)   affichageResultat();
			
			if (m.bloqueur == 1) 
			{
				m = afficheEcranResultat(m);
				if (m.retour == 1) 
				{
					m.demande = 1;
					m.bloqueur=0;
				}
			}
			else	
			{
				m.choix = 5;
			}
			break;
			
	}
	return m;
}

void affichage1(void)
{
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("CogniNB",50,500,720);
	couleurCourante(125,125,125);
	rectangle(170,470,340,630);
	rectangle(510,470,680,630);
	rectangle(850,470,1020,630);

	rectangle(340,160,850,320);
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);

	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Memoire",30,195,540);
	afficheChaine("Analyse",30,540,540);
	afficheChaine("Lateralite",30,875,540);
	afficheChaine("TEST GENERAL",30,460,230);
	afficheChaine("Resultat",30,20,40);
	afficheChaine("Quitter",30,1080,40);	
}

void affichageMemoire(void)
{
	couleurCourante(125,125,125);
	rectangle(490,220,720,390);
	rectangle(240,480,480,640);
	rectangle(720,480,960,640);
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("MEMOIRE",40,510,720);
	ligne(505,710,695,710);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Mnemonique",30,270,550);
	afficheChaine("Memory",30,780,550);
	afficheChaine("Boules",30,550,290);
	afficheChaine("Resultat",30,20,40);
	afficheChaine("Retour",30,1080,40);
}

void affichageAnalyse(void)
{
	couleurCourante(125,125,125);
	rectangle(240,160,480,320);
	rectangle(720,160,960,320);
	rectangle(240,480,480,640);
	rectangle(720,480,960,640);
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);
	
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("ANALYSE",40,510,720);
	ligne(505,710,700,710);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Couleur",30,300,550);
	afficheChaine("Hector",30,775,550);
	afficheChaine("Calcul Mental",30,260,230);
	afficheChaine("Test FB",30,770,230);
	afficheChaine("Resultat",30,20,40);
	afficheChaine("Retour",30,1080,40);
}

void affichageLateralite(void)
{
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("LATERALITE",40,510,720);
	ligne(505,710,750,710);
	couleurCourante(125,125,125);
	rectangle(490,220,720,390);
	rectangle(240,480,480,640);
	rectangle(720,480,960,640);
	
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Vision",30,270,570);
	afficheChaine("Spaciale",30,310,530);
	afficheChaine("Evite",30,770,570);
	afficheChaine("blocs",30,810,530);
	afficheChaine("Konami",30,560,290);
	afficheChaine("Resultat",30,20,40);
	afficheChaine("Retour",30,1080,40);
}
 

void affichageResultat(void)
{
	
	couleurCourante(125,125,125);
	rectangle(100,130,340,290);
	rectangle(360,130,600,290);
	rectangle(620,130,840,290);
	rectangle(860,130,1100,290);

	rectangle(100,310,340,460);
	rectangle(360,310,600,460);
	rectangle(620,310,840,460);
	rectangle(860,310,1100,460);

	rectangle(100,480,340,640);
	rectangle(360,480,600,640);
	rectangle(620,480,840,640);
	rectangle(860,480,1100,640);

	rectangle(1050,0,1200,100);
	
	couleurCourante(255,0,0);
	epaisseurDeTrait(4);
	afficheChaine("Resultats",40,510,720);
	ligne(505,710,690,710);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Mnemonique",30,130,550);
	afficheChaine("Memory",30,410,550);
	afficheChaine("Boules",30,670,550);
	afficheChaine("Couleur",30,910,550);

	afficheChaine("Hector",30,130,380);
	afficheChaine("Calcul",30,410,400);
	afficheChaine("Mental",30,450,350);
	afficheChaine("Test FB",30,670,380);

	afficheChaine("Vision",30,900,400);
	afficheChaine("Spaciale",30,930,350);
	afficheChaine("Evite",30,160,220);
	afficheChaine("Blocs",30,200,170);
	afficheChaine("Konami",30,400,200);

	afficheChaine("Retour",30,1080,40);
}

menu gereClicMenu (menu m,int abs,int ord)
{
	if (m.choix == 0)
	{
		if (abs>=170 && abs<=340 && ord>=470 && ord<=630) m.choix = 1;
		else if (abs>=510 && abs<=680 && ord>=470 && ord<=630) m.choix = 2;
		else if (abs>=850 && abs<=1020 && ord>=470 && ord<=630) m.choix = 3;
		else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 4;
		else if (abs>=0 && abs<=150 && ord>=0 && ord<=100) m.choix = 5;
	}
 	printf("choix5 = %d\n",m.choix5);
	return m;	
}

menu gereClicMemoire (menu m,int abs,int ord)
{
	if (m.choix == 1 && m.bloqueur == 0)
	{
		m.retour=0;
		if (abs>=490 && abs<=720 && ord>=220 && ord<=390) m.choix1 = Boule;
		else if (abs>=240 && abs<=480 && ord>=480 && ord<=640) m.choix1 = Mnemonique;
		else if (abs>=720 && abs<=960 && ord>=480 && ord<=640) m.choix1 = Memory;
		else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = MenuPrincipal;
	}
	return m;
}

menu gereClicAnalyse (menu m,int abs,int ord)
{
	if (m.choix == 2 && m.bloqueur == 0)		
	{
		m.retour=0;
		if (abs>=240 && abs<=480 && ord>=160 && ord<=320) m.choix2 = Calcul;
		else if (abs>=720 && abs<=960 && ord>=160 && ord<=320) m.choix2 = TestFB;
		else if (abs>=240 && abs<=480 && ord>=480 && ord<=640) m.choix2 = Couleur;
		else if (abs>=720 && abs<=960 && ord>=480 && ord<=640) m.choix2 = Hector;
		else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = MenuPrincipal;
	}
	return m;
}

menu gereClicLateralite (menu m,int abs,int ord)
{
	if (m.choix == 3 && m.bloqueur == 0)		
	{
		m.retour=0;
		if (abs>=490 && abs<=720 && ord>=220 && ord<=390) m.choix3 = Konami;
		else if (abs>=240 && abs<=480 && ord>=480 && ord<=640) m.choix3 = Vision;
		else if (abs>=720 && abs<=960 && ord>=480 && ord<=640) m.choix3 = Evite;
		else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = MenuPrincipal;
	}
	return m;
}



//le prenom est vide alors qu'il ne devrait pas l'etre
menu gereClicResultat(menu m, int abs, int ord)
{
	if (m.choix == 5 && m.bloqueur == 0)		
	{
		strcpy(m.nom,m.prenom);
		for (int i=0; i<12; i++)
		{
			if (abs>=coordTest[i].x1 && abs<=coordTest[i].y1 &&  ord>=coordTest[i].x2 && ord<=coordTest[i].y2) m.choix5 = i+1;
		}

		if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 0;

		if (m.choix5 == 1)	strcat(m.nom,"Mnemonique.txt");
		else if (m.choix5 == 2)	strcat(m.nom,"Memory.txt");
		else if (m.choix5 == 3)	strcat(m.nom,"Boule.txt");
		else if (m.choix5 == 4)	strcat(m.nom,"Couleur.txt");
		else if (m.choix5 == 5)	strcat(m.nom,"Hector.txt");
		else if (m.choix5 == 6)	strcat(m.nom,"Calcul.txt");
		else if (m.choix5 == 7)	strcat(m.nom,"Test.txt");
		else if (m.choix5 == 8)	strcat(m.nom,"Vision.txt");
		else if (m.choix5 == 9)	strcat(m.nom,"Evite.txt");
		else if (m.choix5 == 10) strcat(m.nom,"Konami.txt");
		m.bloqueur = 1;
 	}
	return m;		
}


menu afficheEcranResultat(menu m)
{
	effaceFenetre(255,255,255);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);

	if (m.choix5 == 1)			afficheChaine("M N E M O N I Q U E",40,350,725);
	else if (m.choix5 == 2)		afficheChaine("M E M O R Y",40,420,725);
	else if (m.choix5 == 3)		afficheChaine("B O U L E",40,420,725);
	else if (m.choix5 == 4)		afficheChaine("C O U L E U R",40,420,725);
	else if (m.choix5 == 5)		afficheChaine("H E C T O R",40,420,725);
	else if (m.choix5 == 6)		afficheChaine("C A L C U L  M E N T A L",40,220,725);
	else if (m.choix5 == 7)		afficheChaine("T E S T  F B",40,420,725);
	else if (m.choix5 == 8)		afficheChaine("V I S I O N  S P A T I A L E",40,200,725);
	else if (m.choix5 == 9)		afficheChaine("E V I T E  B L O C S ",40,300,725);
	else if (m.choix5 == 10) 	afficheChaine("K O N A M I",40,420,725);


	epaisseurDeTrait(2);

	couleurCourante (200,200,200);
	rectangle(0,730,100,800);

	couleurCourante(0,0,0);
	afficheChaine("Retour",20,20,760);

	char tabLignes[NBLIGNES][TAILLE] = {0};
	int ligneCourante = 0,y=600,stop=0;

	FILE *fichier = fopen(m.nom, "rt");
	if (fichier != NULL)
	{
		char buffer[TAILLE] = {0};
		//Tant que La Ligne Lue est différente de 0 (soit possède des caractères) 
		while (fgets(buffer, TAILLE, fichier) != NULL)
		{
			//Alors on la copie dans tabLignes
			strcpy(tabLignes[ligneCourante], buffer);
			//Buffer tournant (permet de fcopier que les NBLIGNES)
			ligneCourante = (ligneCourante+1)%NBLIGNES;
		}
		fclose(fichier);

		for (int ligneAAfficher = 0; ligneAAfficher < NBLIGNES; ++ligneAAfficher)
		{
			//Affiche le continu de la ligne à l'écran
			if (stop == 0)
			{
				for (int i=0; i<NBLIGNES; i++)
				{
					afficheChaine(tabLignes[ligneCourante],20,480,y);
					ligneCourante = (ligneCourante+1)%NBLIGNES;
					y-=30;
					stop = 1;
				}
			}
		}
	}
	else
		printf("Fichier %s impossible à ouvrir\n", fichier);

	return m;
}