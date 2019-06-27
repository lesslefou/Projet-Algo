#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "Projet-Algo/Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Projet-Algo/Librairie/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "hVisionSpatial.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);

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
	
	switch (evenement)
	{
		case Initialisation:
			reponse = -1;
			srand(time(NULL));
			SquareIDOriginal=rand()%4;

			initMcolor2();
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;
		
		case Temporisation:
		  
			rafraichisFenetre();
			break;
			
		case Affichage:
			
			// On part d'un fond d'ecran blanc
			effaceFenetre (240, 240, 240);
			epaisseurDeTrait(1);
			couleurCourante(0, 0, 0);
			ligne(600, 750, 600, 150);
			couleurCourante (200,200,200);
			rectangle(170,60,420,120);
			rectangle(540,60,810,120);
			rectangle(0,0,100,70);
			couleurCourante(0,0,0);
			epaisseurDeTrait(1);
			afficheChaine("Chronometre : ",20,190,80);
			afficheChaine("nb d'erreur : ",20,580,80);
			afficheChaine("Retour",20,20,30);
			couleurCourante(255,0,0);
			epaisseurDeTrait(4);
			afficheChaine("VISION SPATIALE",40,410,760);
			
			
            VisionSpatial(SquareIDOriginal); 
				
				if (reponse >= 0)
			{
				DisplayResult(SelectedSquareID, reponse);
			}
    
 
      
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					termineBoucleEvenements();
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
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			
			
			
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				
				//Permet de lancer le programme
			
				
				
				//Délimite Carré 1
				if( abscisseSouris()>739 && ordonneeSouris()>509 && abscisseSouris()<891 && ordonneeSouris()<661){
					SelectedSquareID=0;
	
				
				}
				//Délimite Carré 2
				if( abscisseSouris()>909 && ordonneeSouris()>509 && abscisseSouris()<1061 && ordonneeSouris()<661){
					SelectedSquareID=1;
		
			
				}
				//Délimite Carré 3
				if( abscisseSouris()>909 && ordonneeSouris()>339 && abscisseSouris()<1061 && ordonneeSouris()<491){
					SelectedSquareID=2;
		
				
				}
				//Délimite Carré 4
				if( abscisseSouris()>739 && ordonneeSouris()>339 && abscisseSouris()<891 && ordonneeSouris()<491){
					SelectedSquareID=3;
				}
			
				if(SelectedSquareID != gWinningSquareID){
					printf("Mauvaise Reponse");
					reponse = 0;
					rafraichisFenetre();
				}
				else if(SelectedSquareID == gWinningSquareID){
					printf("Bonne Reponse");
					reponse = 1; 
					rafraichisFenetre();
				}
				
				if( abscisseSouris()>899 && ordonneeSouris()>59 && abscisseSouris()<1101 && ordonneeSouris()<121){
					reponse=-1;
					SquareIDOriginal=NextConfiguration();
					
					
				}
			 
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\n", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;}
}
