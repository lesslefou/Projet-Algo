#include "algo.h" 





int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	


	


return 0;
}

int a=0;

int carrex=580;
int carrey=480;


int rectx1=900;
int recty1=100;

int rectx2=837;
int recty2=701;

int rectx3=161;
int recty3=627;

int rectx4=1017;
int recty4=413;

int rectx5=360;
int recty5=145;

int rectx6=182;
int recty6=472;


int rectx7=475;
int recty7=685;

int rectx8=672;
int recty8=258;



/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
        static coordonnees C;
	
	
	switch (evenement)
	{
		case Initialisation:
			
			image = lisBMPRGB("ISEN.bmp");
			/* Le message "Initialisation" est envoye une seule fois, au debut du
			programme : il permet de fixer "image" a la valeur qu'il devra conserver
			jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
			pas pu etre lue, soit "image" pointera sur une structure contenant
			les caracteristiques de l'image "imageNB.bmp" */
			
			
			
			C.Vrectx1=0;
			C.Vrecty1=0;
			

			C.Vrectx2=0;
			C.Vrecty2=0;

			C.Vrectx3=0;
			C.Vrecty3=0;

			C.Vrectx4=0;
			C.Vrecty4=0;
			
			C.Vrectx5=0;
			C.Vrecty5=0;
			
			C.Vrectx6=0;
			C.Vrecty6=0;		
			
			C.Vrectx7=0;
			C.Vrecty7=0;

			C.Vrectx8=0;
			C.Vrecty8=0;



// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			
			rectx1+=C.Vrectx1;
			recty1+=C.Vrecty1;
		
			rectx2+=C.Vrectx2;
			recty2+=C.Vrecty2;

			
			rectx3+=C.Vrectx3;
			recty3+=C.Vrecty3;

			rectx4+=C.Vrectx4;
			recty4+=C.Vrecty4;
			
			rectx5+=C.Vrectx5;
			recty5+=C.Vrecty5;
			
			rectx6+=C.Vrectx6;
			recty6+=C.Vrecty6;

			rectx7+=C.Vrectx7;
			recty7+=C.Vrecty7;
			
			rectx8+=C.Vrectx8;
			recty8+=C.Vrecty8;
			
			if (rectx1 <= 180 || rectx1 >= 1100)
				C.Vrectx1 = -C.Vrectx1;
			if (recty1 < 0    || recty1 >= 700)
				C.Vrecty1 = -C.Vrecty1;

		


if (rectx2 <0|| rectx2 > largeurFenetre()-1){
				C.Vrectx2 = -C.Vrectx2;
			if (recty2 < 0 || recty2 > hauteurFenetre()-1){
				C.Vrecty2 = -C.Vrecty2;}}

if (rectx3 < 0 || rectx3 > 1100){
				C.Vrectx3 = -C.Vrectx3;
			if (recty3 < 0 || recty3 >= 700){
				C.Vrecty3 = -C.Vrecty3;}}


if (rectx4 < 0 || rectx4 > 1100)
				C.Vrectx4 = -C.Vrectx4;
			if (recty4 < 0 || recty4 >= 700)
				C.Vrecty4 = -C.Vrecty4;


			
if (rectx5 < 0 || rectx5 >= 1100)
				C.Vrectx5 = -C.Vrectx5;
			if (recty5 < 0 || recty5 >= 730)
				C.Vrecty5 = -C.Vrecty5;


if (rectx6 < 0 || rectx6 >= 1100)
				C.Vrectx6 = -1.1*C.Vrectx6;
			if (recty6 < 0 || recty6 >= 700)
				C.Vrecty6 = -1.2*C.Vrecty6;

if (rectx7 < 0 || rectx7 >= 1100)
				C.Vrectx7 = -1.1*C.Vrectx7;
			if (recty7 < 0 || recty7 >= 700)
				C.Vrecty7 = -1.2*C.Vrecty7;

if (rectx8 < 0 || rectx8 >= 1100)
				C.Vrectx8 = -1.1*C.Vrectx8;
			if (recty8 < 0 || recty8 >= 700)
				C.Vrecty8 = -1.2*C.Vrecty8;
	


rafraichisFenetre();
			break;
			
		case Affichage:
			




			// On part d'un fond d'ecran blanc
			effaceFenetre (0, 0, 0);
			
			// Affichage d'un rectangle a bouger 
			couleurCourante(255, 0, 0);
			rectangle(carrex-25, carrey+25, carrex+25, carrey-25);
			
			// Affichage d'un rectangle  obstacle1 
			couleurCourante(0, 0, 255);
			rectangle(rectx1-150, recty1+23, rectx1+150, recty1-23);
			
			
			// Affichage d'un rectangle obstacle2
			couleurCourante(0, 0, 255);
			rectangle(rectx2-107, recty2+59, rectx2+107, recty2-59);
			
			// Affichage d'un rectangle obstacle3 
			couleurCourante(0, 0, 255);
			rectangle(rectx3-57, recty3+17, rectx3+57, recty3-17);


			// Affichage d'un rectangle obstacle4 
			couleurCourante(0, 0, 255);
			rectangle(rectx4-79, recty4+39, rectx4+79, recty4-39);


			// Affichage d'un rectangle obstacle5
			couleurCourante(0, 0, 255);
			rectangle(rectx5-84, recty5+41, rectx5+84, recty5-41);



			// Affichage d'un rectangle obstacle6
			couleurCourante(0, 0, 255);
			rectangle(rectx6-98, recty6+72, rectx6+98, recty6-72);


			// Affichage d'un rectangle obstacle7
			couleurCourante(0, 0, 255);
			rectangle(rectx7-125, recty7+87, rectx7+125, recty7-87);

			// Affichage d'un rectangle obstacle8
			couleurCourante(0, 0, 255);
			rectangle(rectx8-124, recty8+74, rectx8+124, recty8-74);

// Affichage d'un texte vert sombre avec ombrage en police de taille 20
			// L'effet d'ombrage vient tout simplement du dessin du texte en gris clair
			// sous le texte voulu, avec un léger décalage
			couleurCourante(210, 210, 210);
			epaisseurDeTrait(3);
			afficheChaine("", 20, 77, 13);
			couleurCourante(0, 128, 0);
			epaisseurDeTrait(2);
			afficheChaine("", 20, 75, 15);

			// Affichage d'une image
			if (image != NULL) // Si l'image a pu etre lue
			{
			// On affiche l'image
				

ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);	



			}
			if (){}
			// si (COORD = 0 && a==1) => effaceFenetre avec afficheChaine Fin de la partie
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
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
				// Si le bouton gauche de la souris est appuye, faire repartir
				
C= verif(C,carrex,carrey);

			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			
C= verif(C,carrex,carrey);

}


			break;
		
		
		break;







		case Souris: // Si la souris est deplacee

		       if (etatBoutonSouris() == GaucheAppuye && abscisseSouris() >= (carrex-25) && abscisseSouris() <= (carrex +25)  && ordonneeSouris() >= (carrey-25) && ordonneeSouris() <= (carrey+25))
			 {
		  		carrex=abscisseSouris();
				carrey=ordonneeSouris();
			
			C.Vrectx1=1;
			C.Vrecty1=1;
			
      
		        C.Vrectx2=2;
			C.Vrecty2=2;

			C.Vrectx3=3;
			C.Vrecty3=3;

			C.Vrectx4=2;
			C.Vrecty4=3;
			
			C.Vrectx5=3;
			C.Vrecty5=6;
			a=1;
			
	
} 
			
C= verif(C,carrex,carrey);

break;
		
		       
			

case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			



break;
	}
}




coordonnees verif(coordonnees C, int carrex, int carrey){

if  (abscisseSouris()==rectx1 || ordonneeSouris()==recty1 || abscisseSouris()==rectx2 || ordonneeSouris()==recty2  || abscisseSouris()==rectx3 || ordonneeSouris()==recty3 || abscisseSouris()==rectx4 || ordonneeSouris()==recty4 || abscisseSouris()==rectx5 || ordonneeSouris()==recty5 || abscisseSouris()==rectx6 || ordonneeSouris()==recty6 || abscisseSouris()==rectx7 || ordonneeSouris()==recty7 || abscisseSouris()==rectx8 || ordonneeSouris()==recty8){

			printf("GAME OVER");

		      	carrex=580;
			carrey=480;
			
			
		        C.Vrectx1=0;
			C.Vrecty1=0;
			
			C.Vrectx2=0;
			C.Vrecty2=0;

			C.Vrectx3=0;
			C.Vrecty3=0;

			C.Vrectx4=0;
			C.Vrecty4=0;
			
			C.Vrectx5=0;
			C.Vrecty5=0;
			
			C.Vrectx6=0;
			C.Vrecty6=0;
	





}
return C;	
}





