#include "HCalcul.h"

#include "header.h"


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
	srand(time(0));
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
static chaine c;
static int delay=0;
static char time[2]={0};
static int temps=0;
static int step = 0;
			
	switch (evenement)
	{
		case Initialisation:
		
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);

			break;
		
		case Temporisation:
			{
			
delay++;
if (delay==45){
	temps++;
	delay=0;
}


			rafraichisFenetre();
			break;
		}
		case Affichage:
			// On part d'un fond d'ecran blanc
			{  
			effaceFenetre (255, 255, 255);
			sprintf(time,"%d",temps);
			epaisseurDeTrait(2);
			afficheChaine(time,10,50,50);
			
			if(temps<30){
			c=calculMentalAffichage(c);
			c=resultat(c);
			c=verif(c);
			}
			else{
			char score[10];
			sprintf(score,"%d",c.scorecalcul);
			epaisseurDeTrait(2);
			afficheChaine(score,20,300,300);}
			break;
			}
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir
			{ quelque peu proprement du programme */
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

				case 'B':
				case 'b':
				
					break;

				case 'N':
				case 'n':
					
					break;
				case '/':
				
					break;
				case '+':
					
					break;
				case '-':
				
					break;
				case '*':
					
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
			/*do{
			p=deplacement1(choix,absc,ord,p);
			p=affich2(choix,absc,ord,p);
			p=deplacement2(choix,absc,ord,p);
			p=affich2(choix,absc,ord,p);}while(p.valide!=1);
		*/
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

