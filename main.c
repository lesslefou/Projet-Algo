#include "hTestFB.h"
#include "hMemory.h"
#include "haffichage.h"

static carte tableau[12];

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
 	srand(time(NULL));
 	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
   
 	static int abs=0;
	static int ord=0;
	static int block=0;
	static int i=0;
	abs=abscisseSouris();
	ord=ordonneeSouris();

	//MENU
	static menu m;

    //TEST FB
    static test fb;

    //MEMORY
    static memory me;
    static int p=0;
    
    //SI TABLEAU D'IMAGES
	//static DonneesImageRGB *Images[12];


	
	switch (evenement)
	{
		case Initialisation:
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);

			//Menu
			m = initMenu(m);

			//TEST FB
			fb = initStructTESTFB (fb);

			//MEMORY
			me = initStructMemory(me);
			initPosition (tableau);

			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);

			//m = choixMenu(m,fb,me,tableau,p,abs,ord);

			me = affichageMemory(p,me,tableau);		
						
			

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir
			{ quelque peu proprement du programme */
					termineBoucleEvenements();

					//TEST FB
					libereDonneesImageRGB(&fb.test1FB);
					libereDonneesImageRGB(&fb.test2FB);

					//MEMORY
					libereDonneesImageRGB(&me.chien);
					libereDonneesImageRGB(&me.chat);
					libereDonneesImageRGB(&me.poulain);
					libereDonneesImageRGB(&me.canard);
					libereDonneesImageRGB(&me.lapin);
					libereDonneesImageRGB(&me.oiseau);
					libereDonneesImageRGB(&me.carte);
					libereDonneesImageRGB(&me.image1);
					libereDonneesImageRGB(&me.image2);


					break;

			
				case 'F':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
				case 'h':
				case 'i':
				case 'j':
				case 'k':
				case 'l':
				case 'm':
				case 'n':
				case 'o':
				case 'p':
				case 'q':
				case 'r':
				case 's':
				case 't':
				case 'u':
				case 'v':
				case 'w':
				case 'x':
				case 'y':
				case 'z':

					if (me.start == 0)
					{
						for (i=0; i<20; i++)
						{
							printf ("me.prenom[%d] = %s\n",i,me.prenom[i]);
							
							if (me.prenom[i] == 0) me.prenom[i] = caractereClavier();
							else 
							{
								while (me.prenom[i] != 0)
								{
									i++;
									printf ("me.prenom[%d] = %s\n",i,me.prenom[i]);
									 if (me.prenom[i] == 0) me.prenom[i] = caractereClavier();
								}
							}
						}
					}
					
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
					if (fb.lock==3)
					{
						fb.chiffre1 = caractereClavier()-48;
						fb.lock =1;
					}
					else if (fb.lock==1)
					{
						fb.chiffre2 = caractereClavier()-48;
						fb.lock=0;
					}
				break;
				}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			if (caractereClavier() == 13) me.start = 1;
			break;

		case BoutonSouris:
			
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());

				//MENU
				m = gereClicMenu(m,abs,ord);
				m = gereClicMemoire(m,abs,ord);
				m = gereClicAnalyse(m,abs,ord);
				m = gereClicLateralite(m,abs,ord);

				//m = gereClicStart(m);
				if (abs>=900 && abs<=1100 && ord>=60 && ord<=120)	
				{
					//TEST FB
					if (fb.start == 0) fb.start = 1;
					else if (fb.start == 3)
					{
						fb = initStructTESTFB(fb);
					}
					else;

					//MEMORY
					if (me.start == 1) 
					{
						me.start = 2;
					}
					else if (me.start == 4)
					{
						me = initStructMemory(me);
					}
					else;
				}

				


				//MEMORY
				if (me.lockeur == 0) 
				{
					me = gereClicCarte(me,abs,ord);
					me.clic2 = 0;
					me.lockeur = 1;
				}
				else if (me.lockeur ==1)
				{
					me = gereClicCarte(me,abs,ord);
					me.lockeur = 0;
					me.stop=1;
				}

				
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