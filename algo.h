#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../ESLib.h" // Pour utiliser valeurAleatoire()

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1200
#define HauteurFenetre 800





typedef struct coordonne{


  int Vrectx1;
  int Vrecty1;

  int Vrectx2;
  int Vrecty2;

  int Vrectx3;
  int Vrecty3;

  int Vrectx4;
  int Vrecty4;


  int Vrectx5;
  int Vrecty5;

  int Vrectx6;
  int Vrecty6;

  int Vrectx7;
  int Vrecty7;

  int Vrectx8;
  int Vrecty8;


}coordonnees;

coordonnees verif(coordonnees C, int carrex, int carrey);
void gestionEvenement(EvenementGfx evenement);
