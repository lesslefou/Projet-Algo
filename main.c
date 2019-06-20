#include "hTestFB.h"
#include "hMemory.h"
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
	abs=abscisseSouris();
	ord=ordonneeSouris();

    //TEST FB
	static DonneesImageRGB *test1FB = NULL;
    static DonneesImageRGB *test2FB = NULL;	
    static test fb;

    //MEMORY
    static DonneesImageRGB *chien = NULL;
    static DonneesImageRGB *chat = NULL;
    static DonneesImageRGB *poulain = NULL;
    static DonneesImageRGB *lapin = NULL;
    static DonneesImageRGB *canard = NULL;
    static DonneesImageRGB *oiseau = NULL;
    static DonneesImageRGB *carte = NULL;
    static DonneesImageRGB *image1 = NULL;
    static DonneesImageRGB *image2 = NULL;
    static int p;
    static int lockeur=0;
    static int clic1=0;
    static int clic2=0;
    


	
	switch (evenement)
	{
		case Initialisation:
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);

			//TEST FB
			test1FB = lisBMPRGB("test1FB.bmp");
			test2FB = lisBMPRGB("test2FB.bmp");
			fb = initStructTESTFB (fb);

			//MEMORY
			chien = lisBMPRGB("chien.bmp");
			poulain = lisBMPRGB("poulain.bmp");
			chat = lisBMPRGB("chat.bmp");
			canard = lisBMPRGB("canard.bmp");
			lapin = lisBMPRGB("lapin.bmp");
			oiseau = lisBMPRGB("oiseau.bmp");
			carte = lisBMPRGB("carte.bmp");
			image1 = lisBMPRGB("chien.bmp");
			image2 = lisBMPRGB("chien.bmp");
			initPosition (tableau);

			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);


			//fb = testFB(fb,test1FB,test2FB);
			placementCarte(p,tableau,chien,chat,poulain,canard,oiseau,lapin);
			placementDosDeCarte(carte,clic1,clic2);

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir
			{ quelque peu proprement du programme */
				case 'q':
					termineBoucleEvenements();

					//TEST FB
					libereDonneesImageRGB(&test1FB);
					libereDonneesImageRGB(&test2FB);

					//MEMORY
					libereDonneesImageRGB(&chien);
					libereDonneesImageRGB(&chat);
					libereDonneesImageRGB(&poulain);
					libereDonneesImageRGB(&canard);
					libereDonneesImageRGB(&lapin);
					libereDonneesImageRGB(&oiseau);
					libereDonneesImageRGB(&carte);
					libereDonneesImageRGB(&image1);
					libereDonneesImageRGB(&image2);


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
			break;

		case BoutonSouris:
			
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				if (abs>=900 && abs<=1100 && ord>=70 && ord<=130)	
				{
					if (fb.start == 0) fb.start = 1;
					else if (fb.start == 3)
					{
						fb = initStructTESTFB(fb);
					}
					else;
				}

				if (lockeur == 0) 
				{
					clic1 = gereClicCarte(clic1,abs,ord);
					lockeur = 1;
				}
				else if (lockeur ==1)
				{
					clic2 = gereClicCarte(clic2,abs,ord);
					lockeur = 0;
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