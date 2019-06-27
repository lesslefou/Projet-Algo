//MACHINE A ETAT

//probleme de RESULTAT

#include "hTestFB.h"
#include "hMemory.h"
#include "haffichage.h"
#include "hKonami.h"
#include "hCouleur.h"
#include "hMnemonique.h"
#include "hVisionSpatiale.h"

//AFFICHAGE RESULTAT COULEUR NOPE...
static carte tableau[12];

int main(int argc, char **argv)
{
 	srand(time(NULL));
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
   
 	static int abs=0;
	static int ord=0;
	static int i=0;
	static int a=0;
	abs=abscisseSouris();
	ord=ordonneeSouris();

	//MENU
	static menu m;

    //MEMORY
    static memory me;
    static memory *const pt = &me;
    static int p=0;
    
    //TEST FB
    static test fb;
    static test * const pt1 = &fb;

    //Konami
    static kona mi;
    static kona *const pt2 = &mi;

    //Couleur
    static coule ur;
    static coule *const pt3 = &ur;

    //Mnemonique
    static mnemo ni;
    static mnemo *const pt4 = &ni;

    //Vision Spatiale
    static visi on;
    static visi *const pt5 = &on;

    static int SelectedSquareID=0;  //Carre selectionné par l'utilisateur
	static int reponse;
	static int SquareIDOriginal;

	
	
	switch (evenement)
	{
		case Initialisation:
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);

			//Menu
			m = initMenu(m);

			//TEST FB
			initStructTESTFB(pt1);

			//MEMORY
			initStructMemory(pt);
			initPosition(tableau);

			//KONAMI
			initStructKONAMI(pt2);

			//Couleur
			initStructCOULEUR(pt3);

			//Mnemonique
			initStructMNEMONIQUE(pt4);

			//Vision Spatiale
			reponse = -1;
			SquareIDOriginal=rand()%4;
			initMcolor2();
			
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);

			//m = choixMenu(m,pt1,pt,pt2,pt3,pt4,tableau,p,abs,ord);

			//Vision Spatiale
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
				case 'Q': /* Pour sortir
			{ quelque peu proprement du programme */
					termineBoucleEvenements();

					//TEST FB
					libereDonneesImageRGB(&pt1->test1FB);
					libereDonneesImageRGB(&pt1->test2FB);

					//MEMORY
					libereDonneesImageRGB(&pt->chien);
					libereDonneesImageRGB(&pt->chat);
					libereDonneesImageRGB(&pt->poulain);
					libereDonneesImageRGB(&pt->canard);
					libereDonneesImageRGB(&pt->lapin);
					libereDonneesImageRGB(&pt->oiseau);
					libereDonneesImageRGB(&pt->carte);
					libereDonneesImageRGB(&pt->image1);
					libereDonneesImageRGB(&pt->image2);

					//KONAMI
					libereDonneesImageRGB(&pt2->imkonami);


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

					//MEMORY
					if (pt->start == 0)
					{
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (pt->prenom[i] == 0) 
								{
									pt->prenom[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}

					//TESTFB
					if (pt1->start == 0)
					{
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (pt1->prenom[i] == 0) 
								{
									pt1->prenom[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}


					//KONAMI
					if (pt2->start == 0)
					{
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (pt2->prenom[i] == 0) 
								{
									pt2->prenom[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}

					//MNEMONIQUE
					if (pt4->start == 0)
					{
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (pt4->prenom[i] == 0) 
								{
									pt4->prenom[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}

					if (pt4->lockeurMn == 1)
					{
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (pt4->mot[i] == 0) 
								{
									pt4->mot[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}
					
					//Couleur
					if (pt3->start == 0)
					{
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (pt3->prenom[i] == 0) 
								{
									pt3->prenom[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}

					//RESULTAT
					if (m.demande == 0)
					{
						puts ("coucou");
						for (i=0; i<20; i++)
						{
							if (a == 0)
							{
								if (m.prenom[i] == 0) 
								{
									m.prenom[i] = caractereClavier();
									a++;
								}
							}
						}
						a=0;
					}

					break;

				case 13:
					if (pt->start == 0) 	pt->start = 1;
					if (pt1->start == 0)    pt1->start = 1;
					if (pt2->start == 0)    pt2->start = 1;
					if (pt3->start == 0)    pt3->start = 1;
					if (pt4->start == 0)    pt4->start = 1;
					if (pt4->lockeurMn == 1)	pt4->lockeurMn = 2;
					if (m.choix == 5)	m.demande = 1;
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
					if (pt1->lock == 3)
					{
						pt1->chiffre1 = caractereClavier()-48;
						pt1->lock =1;
					}
					else if (pt1->lock == 1)
					{
						pt1->chiffre2 = caractereClavier()-48;
						pt1->lock=0;
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


				//MENU
				if (m.choix == MenuPrincipal)
				{
					m = gereClicMenu(m,abs,ord);
				}
				else if (m.choix == Memoire)
				{
					m = gereClicMemoire(m,abs,ord);
				}
				else if (m.choix == Analyse)
				{
					m = gereClicAnalyse(m,abs,ord);
				}
				else if (m.choix == Lateralite)
				{
					m = gereClicLateralite(m,abs,ord);
				}
				/*else if (m.choix == General)
				{
					m = gereClicGeneral(m,abs,ord);
				}*/
				else if (m.choix == Resultat)
				{
					m = gereClicResultat(m,abs,ord);
				}

				if (abs>=0 && abs<=100 && ord>=730 && ord<=800) 
				{
					m.retour=1;
					initStructMemory(pt);
					initStructTESTFB(pt1);
					initStructKONAMI(pt2);
					initStructCOULEUR(pt3);
					initStructMNEMONIQUE(pt4);
					if (m.choix == 5)
					{
						m.bloqueur=0;
						m.retour=0;
						m.demande=1;
					}
				}

				//m = gereClicStart(m);
				else if (abs>=900 && abs<=1100 && ord>=60 && ord<=120)	
				{
					//TEST FB
					if (pt1->start == 1) 		
					{
						pt1->start = 2;
					}
					else if (pt1->start == 4)
					{
						initStructTESTFB(pt1);
					}
					else;

					//MEMORY
					if (pt->start == 1) 		
					{
						pt->start = 2;
					}
					else if (pt->start == 4)
					{
						initStructMemory(pt);
					}
					else;

					//KONAMI
					if (pt2->start == 1) 		
					{
						pt2->start = 2;
					}
					else if (pt2->start == 4)
					{
						initStructKONAMI(pt2);
					}
					else;

					//Couleur
					if (pt3->start == 1) 		
					{
						pt3->start = 2;
					}
					else if (pt3->start == 4)
					{
						initStructCOULEUR(pt3);
					}
					else;

					//Mnemonique
					if (pt4->start == 1) 		
					{
						pt4->start = 2;
					}
					else if (pt4->start == 4)
					{
						initStructMNEMONIQUE(pt4);
					}
					else;
				}

				

				//MEMORY
				if (pt->lockeur == 0 && pt->delay > 0) 
				{
					gereClicCarte(pt,abs,ord);
					pt->clic2 = 0;
					pt->lockeur = 1;
				}
				else if (pt->lockeur ==1)
				{
					gereClicCarte(pt,abs,ord);
					pt->lockeur = 0;
					pt->stop=1;
				}


				//KONAMI
				if (pt2->delay > 0)
				{
					gereClicCode(pt2,abs,ord);
					pt2->lockeurMi++;
				}
				
				//Couleur
				if (pt3->delay > 0)
				{	
					gereClicCouleur(pt3,abs,ord);
					pt3->lockeurCo=1;
				}

				//Mnemonique
				if (pt4->lockeurMn == 1 || pt4->lockeurMn == 2) valide(pt4,abs,ord);


				//Vision Spatiale
				SelectedSquareID = gereClicVision(SelectedSquareID);
				if(SelectedSquareID != gWinningSquareID)
				{
					printf("Mauvaise Reponse");
					reponse = 0;
					rafraichisFenetre();
				}
				else 
				{
					printf("Bonne Reponse");
					reponse = 1; 
					rafraichisFenetre();
				}
				
				if( abscisseSouris()>899 && ordonneeSouris()>59 && abscisseSouris()<1101 && ordonneeSouris()<121)
				{
					reponse=-1;
					SquareIDOriginal=NextConfiguration(SquareIDOriginal,pt5);
				}
			}
				
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