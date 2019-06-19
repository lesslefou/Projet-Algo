#include "hMemories.h"
#include "hTestFB.h"

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	
	return 0;
}



/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
 	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
   

    static DonneesImageRGB *test1FB = NULL;
    static DonneesImageRGB *test2FB = NULL;
    static int abs=0;
	static int ord=0;
	abs=abscisseSouris();
	ord=ordonneeSouris();
	static int suite=0;
	static int chiffre1=0;
	static int chiffre2=0;
	static int lock=3;
	static int resultat=0;
	static int test1=15;
	static int test2=14;
	static int delay=0;
	static int tempo=0;
	static int cpt=0;
	static int temps=0;
	static int start=0;
	static int erreur=0;
	FILE *fichier=NULL;
   
	
	switch (evenement)
	{
		case Initialisation:
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			test1FB = lisBMPRGB("test1FB.bmp");
			test2FB = lisBMPRGB("test2FB.bmp");
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			couleurCourante (200,200,200);
			rectangle(170,70,420,130);
			rectangle(540,70,810,130);
			rectangle(900,70,1100,130);
			rectangle(895,355,1090,400);
			couleurCourante(0,0,0);
			epaisseurDeTrait(1);
			afficheChaine("Chronometre : ",20,190,90);
			afficheChaine("nb d'erreur : ",20,580,90);
			afficheChaine("S T A R T",20,930,90);
			afficheChaine("Reponse : ",20,905,370);
			couleurCourante(255,0,0);
			epaisseurDeTrait(5);
			afficheChaine("T E S T  F B",40,380,720);

			
			if (start == 1)	
			{
				resultat = afficheResultat(chiffre1,chiffre2,suite,resultat);
			
				delay ++;
				if (tempo >= 2) tempo++;
				if (delay == 45)	
				{
					temps++;
					delay=0;
				}
				if (suite == 0)
				{
					ecrisImage(50, 180, test1FB->largeurImage, test1FB->hauteurImage, test1FB->donneesRGB);
				
					if (lock ==0) 
					{
						if (resultat == test1)		
						{
							if (cpt==0)
							{
								tempo=2;
								cpt=1;
							}
							lock=3;
						}
						if (resultat == 2 ) 
						{
							erreur++;
							lock=3;
						}
					}	
					if (tempo > 30)	
					{
						suite = 1;
						tempo=0;
					}
				}
				else if (suite ==1)
				{
					ecrisImage(50, 180, test2FB->largeurImage, test2FB->hauteurImage, test2FB->donneesRGB);
					
					if (lock ==0 ) 
					{
						if (resultat == test2) 	
						{
							if (cpt==1)
							{
								tempo=2;
								cpt=2;
							}
							lock=3;
						}
						if (resultat == 2) 
						{
							erreur++;
							lock=3;
						}
					}

					if (tempo > 30)	
					{
						suite = 2;
						tempo=0;
					}
						
				}
				else 
				{
					start=2;
				}
			}
			

			char chrono[] = "00";
			couleurCourante(0,0,0);
			epaisseurDeTrait(2);
			sprintf(chrono,"%d s",temps);
			epaisseurDeTrait(2);
			afficheChaine(chrono,20,350,90);


			char pourcentage[] = "00";
			couleurCourante(0,0,0);
			epaisseurDeTrait(2);
			sprintf(pourcentage,"%d",erreur);
			epaisseurDeTrait(2);
			afficheChaine(pourcentage,20,730,90);

			if (start == 2)
			{
				fichier=fopen("ResultatTestFb.txt","r+");
				fseek(fichier,0,SEEK_END);
				fprintf(fichier, "TEST :\nChrono : %d\nNombre d'erreur : %d\n\n",temps,erreur);
				fclose(fichier);
				start = 3;
			}	

			if (start ==3)
			{
				couleurCourante(120,120,120);
				rectangle(50,180,850,680);
				couleurCourante(0,0,0);
				afficheChaine("F I N  D U  T E S T",30,230,400);

			}

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir
			{ quelque peu proprement du programme */
				case 'q':
					termineBoucleEvenements();
					libereDonneesImageRGB(&test1FB);
					libereDonneesImageRGB(&test2FB);
					break;

			
				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;

				case 'B':
				case 'b':
					break;

				case 'N':
				case 'n':
					break;

				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					if (lock==3)
					{
						chiffre1 = caractereClavier()-48;
						lock =1;
					}
					else if (lock==1)
					{
						chiffre2 = caractereClavier()-48;
						lock=0;
					}
				break;
				}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				if (abs>=900 && abs<=1100 && ord>=70 && ord<=130)	start=1;

				
			}
			
			if (etatBoutonSouris() == GaucheRelache)	activeGestionDeplacementPassifSouris();
			if (etatBoutonSouris() == DroiteAppuye)
			{
				
			}
			if (etatBoutonSouris() == DroiteRelache)	activeGestionDeplacementPassifSouris();
			
				
				
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}


