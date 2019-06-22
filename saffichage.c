#include "haffichage.h"

menu initMenu(menu m)
{
	m.choix=0;
	m.choix1=0;
	m.choix2=0;
	m.choix3=0;
	m.start=0;
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



menu choixMenu(menu m, test fb, memory me,DonneesImageRGB *test1FB,DonneesImageRGB *test2FB)
{
	switch (m.choix)
	{
		case 0: 
			m = initMenu(m);
			affichage1();
			break;
		case 1:
			affichageMemoire();
			switch (m.choix1)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
			}
			break;
		case 2:
			affichageAnalyse();
			switch (m.choix2)
			{
				case 1:
					break;
				case 2:
					fb = testFB(fb,test1FB,test2FB);
					break;
				case 3:
					break;
			}
			break;
		case 3 : 
			affichageLateralite();
			switch (m.choix3)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
			}
			break;
		case 4:
			break;
	}
	return m;
}
*/
void affichage1(void)
{
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("NOM DE LA PLATEFORME",40,350,720);
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
	afficheChaine("Score",30,35,40);
	afficheChaine("Quitter",30,1080,40);	
}

void affichageMemoire(void)
{
	couleurCourante(125,125,125);
	rectangle(400,170,800,330);
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
	afficheChaine("Tri Tes Nombres !",30,450,240);
	afficheChaine("Score",30,35,40);
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
	afficheChaine("Syllabene",30,775,550);
	afficheChaine("Calcul Mental",30,260,230);
	afficheChaine("Test FB",30,770,230);
	afficheChaine("Score",30,35,40);
	afficheChaine("Retour",30,1080,40);
}

void affichageLateralite(void)
{
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("LATERALITE",40,510,720);
	ligne(505,710,750,710);
	couleurCourante(125,125,125);
	rectangle(230,280,500,520);
	rectangle(710,280,980,520);
	
	rectangle(0,0,150,100);
	rectangle(1050,0,1200,100);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Vision",40,260,430);
	afficheChaine("Spaciale",40,300,350);
	afficheChaine("Points",40,750,430);
	afficheChaine("Relies",40,820,350);
	
	afficheChaine("Score",30,35,40);
	afficheChaine("Retour",30,1080,40);
}

menu gereClicMenu (menu m,int abs,int ord)
{
	if (abs>=170 && abs<=340 && ord>=470 && ord<=630) m.choix = 1;
	else if (abs>=510 && abs<=680 && ord>=470 && ord<=630) m.choix = 2;
	else if (abs>=850 && abs<=1020 && ord>=470 && ord<=630) m.choix = 3;
	else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 4;
	return m;	
}

menu gereClicMemoire (menu m,int abs,int ord)
{
	if (abs>=400 && abs<=800 && ord>=170 && ord<=330) m.choix1 = 1;
	else if (abs>=240 && abs<=480 && ord>=480 && ord<=640) m.choix1 = 2;
	else if (abs>=720 && abs<=480 && ord>=960 && ord<=640) m.choix1 = 3;
	else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 0;
	return m;
}

menu gereClicAnalyse (menu m,int abs,int ord)
{
	if (abs>=240 && abs<=160 && ord>=480 && ord<=320) m.choix2 = 1;
	else if (abs>=720 && abs<=160 && ord>=960 && ord<=320) m.choix2 = 2;
	else if (abs>=240 && abs<=480 && ord>=480 && ord<=640) m.choix2 = 3;
	else if (abs>=720 && abs<=480 && ord>=960 && ord<=640) m.choix2 = 4;
	else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 0;
	return m;
}

menu gereClicLateralite (menu m,int abs,int ord)
{
	if (abs>=230 && abs<=280 && ord>=500 && ord<=520) m.choix3 = 1;
	else if (abs>=710 && abs<=280 && ord>=500 && ord<=520) m.choix3 = 2;
	else if (abs>=1050 && abs<=1200 && ord>=0 && ord<=100) m.choix = 0;
	return m;
}



