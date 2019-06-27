#include "hMnemonique.h"

/**
 *\file mnemonique.c
 *\author : Laetitia COllodet
 *\brief toutes les fonctions pour f aire fonctionner mneonique
 *
 */
 
 /**
 \brief appel des fonctions du nemonique 

 \param ni->tab2 pour enrgistrer les mots choisis (10 au hasard)
* \param score pour retoruner le score 
* \param validebouton pour que la personne clic lorsquelle a retaper tout les mots dont elle se rappelle 
* \"for(j=0;j<5;j++)" pour afficher les mots a retenir a l'ecran et les stocker dans un tableau
* \"for(k=0;k<10;k++)" pour comparer les mots ecrit et les mots du tableau
* \"if(x>=400 && x<=600 && y<=230 && y>=170)" la perosnne clic pour valider ses mots et finir le jeu 


**/

void initStructMNEMONIQUE(mnemo *const ni)
{
	memset(ni, 0, sizeof(*ni));	
}

void affichageMnemonique(mnemo *const ni)
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
	afficheChaine("mot juste : ",20,580,80);
	afficheChaine("S T A R T",20,930,80);
	afficheChaine("Retour",20,20,760);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("M N E M O N I Q U E",40,400,725);


	if (ni->start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	if (ni->start == 2)	
	{
		ni->delay ++;
		if (ni->tempo >= 2) ni->tempo++;
		if (ni->delay == 45)	
		{
			ni->temps++;
			ni->delay=0;
		}
		
		if (ni->suite >= 0) 
		{
			if (ni->minuteur == 0)
			{
				ni->tempo = 2;
				ni->minuteur = 1;
			}
			
			if (ni->tempo < 40 && ni->lockeurMn == 0) mnemonique(ni);
			else 
			{
				if (ni->stop == 0)		ni->lockeurMn = 1;
			}

			if (ni->lockeurMn == 1 || ni->lockeurMn == 2) 
			{
				ni->stop = 1;
				ni->tempo = 0;
				rentretesmots(ni);
				
				
				if (ni->validebouton == 1)
				{
					ni->a = 1;
					
				}
				if (ni->a == 1) 
				{
					ni->tempo = 2;
					ni->a = 2;
				}

				if (ni->a == 2)
				{
					couleurCourante(120,120,120);
					rectangle(200,200,1000,700);
					couleurCourante(0,0,0);
					afficheChaine("N E X T ",30,320,430);
					if (ni->tempo > 30)	
					{
						ni->suite = 2;
						ni->tempo = 0;
						ni->cpt = 0;
						//ni->lockeurMn = 0;
						ni->a=0;
						ni->minuteur = 1;
					}
				}
				

				if (ni->tempo > 30)	
				{
					ni->suite = 1;
					ni->tempo = 2;
					//ni->lockeurMn = 0;
				}
			}
		}
	}



	char chrono[5] ;	
	memset(chrono,0,sizeof(chrono));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(chrono,"%d s",ni->temps);
	afficheChaine(chrono,20,350,80);


	char pourcentage[3];
	memset(pourcentage,0,sizeof(pourcentage));
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(pourcentage,"%d",ni->score);
	afficheChaine(pourcentage,20,730,80);

	
	if (ni->start == 3)
	{
		char nom[30];
		strcpy(nom,ni->prenom);
		strcat(nom,"Mnemonique.txt");
		ni->fichier4=fopen(nom,"at");
		fprintf(ni->fichier4, "TEST du DATE\nChrono : %d\nNombre d'erreur : %d\n\n",ni->temps,ni->erreur);
		fclose(ni->fichier4);
		ni->start = 4;
	}	

	if (ni->start == 4)
	{
		couleurCourante(120,120,120);
		rectangle(200,200,1000,700);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,320,430);
	}
}



void mnemonique(mnemo *const ni)
{
	couleurCourante(128,0,64);
	epaisseurDeTrait(1);
	int i,j;
	char tab[90][20]={"chat","mystere","boulon","humour","sac","parapluie","verre","vert","poulet","carotte","papier","fenetre",
		"etoile","prise","bague","voiture","montre","huitre","boite","toile","souris","lunette","chaine","trousse","style","cuillere",
		"mer","poignet","electricite","croix","vie","femme","homme","dent","noisette","ecran","abeille","coque","sous","argent","ciel",
		"plafond","ceinture","rideau","eau","frite","fer","oiseau","bus","chaine","bande","bouteille","livre","classeur",
		"lion","lit","arme","musique","sol","paire","piscine","herbe","tele","ordinateur","photo","vitrine","loup","croque","jupe",
		"brioche","or","loutre","voix","voie","chargeur","pile","rire","pousser","loi","dos","robe","chaussure","talon","bracelet","lettre"
		,"toile","route","nombre","clavier","million"};
	
	couleurCourante(0,0,0);
	char txt[20]={0};
	int ordo=500;

	if (ni->debut == 0)
	{
		for(j=0;j<5;j++)
		{
			i=rand()%90;
			strcpy(ni->tab2[j],tab[i]);
		}

		for(j=5;j<10;j++)
		{
			i=rand()%90;
			strcpy(ni->tab2[j],tab[i]);
		}
		ni->debut = 1;
	}
	for(j=0;j<5;j++)
	{
		afficheChaine(ni->tab2[j],25,250,ordo);
		ordo-=50;
	}
	ordo = 500;
	for(j=5;j<10;j++)
	{
		afficheChaine(ni->tab2[j],25,450,ordo);
		ordo-=50;
	}
	couleurCourante(128,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Tu as 30 secondes ",25,650,455);
	afficheChaine("pour retenir le plus de mots !",25,650,400);
} 

 
void rentretesmots(mnemo * const ni)
{
	int k;
	couleurCourante(128,0,64);
	epaisseurDeTrait(1);
	afficheChaine("Liste les mots que tu as retenu : ",25,250,550);
	couleurCourante(0,255,128);
	rectangle(400,170,600,230);
	couleurCourante(255,255,255);
	epaisseurDeTrait(2);
	afficheChaine("VALIDER",25,450,190);
	char txt[20]={0};
	if (ni->lockeurMn == 2)
	{
		for(k=0;k<10;k++)
		{
			if(strcmp(ni->mot,ni->tab2[k]) == 0)
			{
				ni->score ++;
			}
		}
		for (int g=0; g<20; g++)	ni->mot[g]= '\0';
		ni->lockeurMn = 1;
	}
}


void valide(mnemo *const ni,int abs,int ord)
{
	if(abs>=400 && abs<=600 && ord>=170 && ord<=230)
	{
		ni->validebouton=1;
	}
}