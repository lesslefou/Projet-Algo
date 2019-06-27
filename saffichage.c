#include "haffichage.h"
#include "hTestFB.h"
#include "hMemory.h"
#include "hCouleur.h"
#include "hMnemonique.h"
#include "hVisionSpatiale.h"


menu initMenu(menu m)
{
	memset(&m, 0, sizeof(m));
	
	return m;
}



menu choixMenu(menu m, test *const fb, memory *me, kona *const mi,coule *const ur,mnemo *const ni,visi *const on,carte tableau[12],int p,int abs, int ord)
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
				case Mnemonique:
					if (m.retour == 0) 
					{
						m.bloqueur = 1;
						affichageMnemonique(ni);
					}
					else
					{
						m.choix = 1;
						m.bloqueur = 0;
					}
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

			}
			break;

		case Lateralite: 
			affichageLateralite();
			switch (m.choix3)
			{
				case Vision:
					if (m.retour == 0) 
					{
						affichageVision(on);
						m.bloqueur = 1;
					}
					else	
					{
						m.choix = 3;
						m.bloqueur = 0;
					}
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

		case Quitter:
			termineBoucleEvenements();
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
		case General:
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
	rectangle(240,380,480,540);
	rectangle(720,380,960,540);
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("MEMOIRE",40,510,720);
	ligne(505,710,695,710);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Mnemonique",30,270,450);
	afficheChaine("Memory",30,780,450);
	afficheChaine("Resultat",30,20,40);
	afficheChaine("Retour",30,1080,40);
}

void affichageAnalyse(void)
{
	couleurCourante(125,125,125);
	rectangle(240,380,480,540);
	rectangle(720,380,960,540);
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);
	
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("ANALYSE",40,510,720);
	ligne(505,710,700,710);
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Couleur",30,300,450);
	afficheChaine("Test FB",30,770,450);
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
	rectangle(100,230,340,390);
	rectangle(360,230,600,390);
	rectangle(620,230,840,390);
	rectangle(860,230,1100,390);

	rectangle(100,460,340,610);
	rectangle(360,460,600,610);
	rectangle(620,460,840,610);
	rectangle(860,460,1100,610);


	rectangle(1050,0,1200,100);
	
	couleurCourante(255,0,0);
	epaisseurDeTrait(4);
	afficheChaine("Resultats",40,510,720);
	ligne(505,710,690,710);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Mnemonique",30,130,525);
	afficheChaine("Memory",30,410,525);
	afficheChaine("Test FB",30,670,525);
	afficheChaine("Couleur",30,910,525);

	afficheChaine("Evite",30,670,320);
	afficheChaine("Blocs",30,710,270);
	afficheChaine("Vision",30,160,320);
	afficheChaine("Spatiale",30,180,270);
	afficheChaine("Konami",30,400,300);

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
		else if (abs>=340 && abs<=850 && ord>=160 && ord<=320);
	}
	return m;	
}

menu gereClicMemoire (menu m,int abs,int ord)
{
	if (m.choix == 1 && m.bloqueur == 0)
	{
		m.retour=0;
		if (abs>=240 && abs<=480 && ord>=380 && ord<=540) m.choix1 = Mnemonique;
		else if (abs>=720 && abs<=960 && ord>=380 && ord<=540) m.choix1 = Memory;
		else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = MenuPrincipal;
	}
	return m;
}

menu gereClicAnalyse (menu m,int abs,int ord)
{
	if (m.choix == 2 && m.bloqueur == 0)		
	{
		if (abs>=240 && abs<=480 && ord>=380 && ord<=540) m.choix2 = Couleur;
		else if (abs>=240 && abs<=960 && ord>=380 && ord<=540) m.choix2 = TestFB;
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



menu gereClicResultat(menu m, int abs, int ord)
{
	if (m.choix == 5 && m.bloqueur == 0)		
	{
		printf ("prenom = %s\n",m.prenom);
		strcpy(m.nom,m.prenom);
		for (int i=0; i<8; i++)
		{
			if (abs>=coordTest[i].x1 && abs<=coordTest[i].x2 &&  ord>=coordTest[i].y1 && ord<=coordTest[i].y2) m.choix5 = i+1;
		}

		if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 0;

		if (m.choix5 == 5)	strcat(m.nom,"Mnemonique.txt");
		else if (m.choix5 == 6)	strcat(m.nom,"Memory.txt");
		else if (m.choix5 == 7)	strcat(m.nom,"TestFB.txt");
		else if (m.choix5 == 8)	strcat(m.nom,"Couleur.txt");
		else if (m.choix5 == 1)	strcat(m.nom,"Vision.txt");
		else if (m.choix5 == 2) strcat(m.nom,"Konami.txt");
		else if (m.choix5 == 3)	strcat(m.nom,"Evite.txt");
		m.bloqueur = 1;
 	}
	return m;		
}


menu afficheEcranResultat(menu m)
{
	effaceFenetre(255,255,255);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	if (m.choix5 == 5)			afficheChaine("M N E M O N I Q U E",40,350,725);
	else if (m.choix5 == 6)		afficheChaine("M E M O R Y",40,420,725);
	else if (m.choix5 == 7)		afficheChaine("T E S T  F B",40,420,725);
	else if (m.choix5 == 8)		afficheChaine("C O U L E U R",40,420,725);
	else if (m.choix5 == 1)		afficheChaine("V I S I O N  S P A T I A L E",40,200,725);
	else if (m.choix5 == 2) 	afficheChaine("K O N A M I",40,420,725);
	else if (m.choix5 == 3)		afficheChaine("E V I T E  B L O C S ",40,300,725);


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