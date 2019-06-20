#include "hMemories.h"

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
   

    static DonneesImageRGB *chien = NULL;
    static DonneesImageRGB *chat = NULL;
    static DonneesImageRGB *poulain = NULL;
    static DonneesImageRGB *lapin = NULL;
    static DonneesImageRGB *canard = NULL;
    static DonneesImageRGB *oiseau = NULL;
    static DonneesImageRGB *carte = NULL;


    static DonneesImageRGB *image1 = NULL;
    static DonneesImageRGB *image2 = NULL;
    
    static int colonne[4] = {70,340,610,880};
	static int ligne[3] = {180,360,540};


	static int abs=0;
	static int ord=0;
	abs=abscisseSouris();
	ord=ordonneeSouris();
	static int clic1=0;
	static int clic2=0;
	static int lock=0;


	switch (evenement)
	{
		case Initialisation:
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			chien = lisBMPRGB("chien.bmp");
			poulain = lisBMPRGB("poulain.bmp");
			chat = lisBMPRGB("chat.bmp");
			canard = lisBMPRGB("canard.bmp");
			lapin = lisBMPRGB("lapin.bmp");
			oiseau = lisBMPRGB("oiseau.bmp");
			carte = lisBMPRGB("carte.bmp");

			image1 = lisBMPRGB("chien.bmp");
			image2 = lisBMPRGB("chien.bmp");

			//Attribution des valeurs aléatoire des lignes/colonnesx
			melangeColonne(colonne);
			melangeLigne(ligne);

			
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);

			//Mise en place des images
			ecrisImage(colonne[0], ligne[0], chien->largeurImage, chien->hauteurImage, chien->donneesRGB);
			ecrisImage(colonne[1], ligne[0], chat->largeurImage, chat->hauteurImage, chat->donneesRGB);
			ecrisImage(colonne[2], ligne[0], poulain->largeurImage, poulain->hauteurImage, poulain->donneesRGB);
			ecrisImage(colonne[3], ligne[0], canard->largeurImage, canard->hauteurImage, canard->donneesRGB);

			ecrisImage(colonne[0], ligne[1], lapin->largeurImage, lapin->hauteurImage, lapin->donneesRGB);
			ecrisImage(colonne[1], ligne[1], chien->largeurImage, chien->hauteurImage, chien->donneesRGB);
			ecrisImage(colonne[2], ligne[1], chat->largeurImage, chat->hauteurImage, chat->donneesRGB);
			ecrisImage(colonne[3], ligne[1], oiseau->largeurImage, oiseau->hauteurImage, oiseau->donneesRGB);

			ecrisImage(colonne[0], ligne[2], canard->largeurImage, canard->hauteurImage, canard->donneesRGB);
			ecrisImage(colonne[1], ligne[2], lapin->largeurImage, lapin->hauteurImage, lapin->donneesRGB);
			ecrisImage(colonne[2], ligne[2], oiseau->largeurImage, oiseau->hauteurImage, oiseau->donneesRGB);
			ecrisImage(colonne[3], ligne[2], poulain->largeurImage, poulain->hauteurImage, poulain->donneesRGB);


			//Mise en place du dos des carte
			if (lock ==0)
			{
			ecrisImage(70, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(340, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(610, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(880, 180, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);

			ecrisImage(70, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(340, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(610, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(880, 360, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);

			ecrisImage(70, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(340, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(610, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			ecrisImage(880, 540, carte->largeurImage, carte->hauteurImage, carte->donneesRGB);
			}/*
			else if (lock ==1)
			{
				for (i=0; i<LONGUEUR*HAUTEUR*3;i++)
				{
					if (image1->donneesRGB[i] == image2->donneesRGB)
					{

					}
				}
			}*/ 
			
			//Chrono, nombre d'essais et titre
			couleurCourante (200,200,200);
			rectangle(170,70,420,130);
			rectangle(540,70,810,130);
			rectangle(900,70,1100,130);
			couleurCourante(0,0,0);
			epaisseurDeTrait(1);
			afficheChaine("Chronometre : ",20,190,90);
			afficheChaine("nb d'erreur : ",20,580,90);
			afficheChaine("S T A R T",20,930,90);
			couleurCourante(255,0,0);
			epaisseurDeTrait(5);
			afficheChaine("M E M O R I E S",40,380,720);
			
			

			 
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir
			{ quelque peu proprement du programme */
				case 'q':
					termineBoucleEvenements();
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
				}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());

				if (lock == 0) 
				{
					clic1 = gereClicCarte(clic1,abs,ord,image1);
					lock = 1;
				}
				else if (lock ==1)
				{
					clic2 = gereClicCarte(clic2,abs,ord,image2);
					lock = 0;
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

