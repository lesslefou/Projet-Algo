#include <stdio.h>
#include <string.h>

#define TAILLE (256)
#define NBLIGNES (8)


int main(int argc, char *argv[])
{
	if (argc == 2)	// Si nom du programme + un paramètre
	{
		char tabLignes[NBLIGNES][TAILLE] = {0};
		int ligneCourante = 0;

		FILE *fichier = fopen(argv[1], "rt");
		if (fichier != NULL)
		{
			char buffer[TAILLE] = {0};
			//Tant que La Ligne Lue est différente de 0 (soit possède des caractères) 
			while (fgets(buffer, TAILLE, fichier) != NULL)
			{
				//Alors on la copie dans tabLignes
				strcpy(tabLignes[ligneCourante], buffer);
				//Buffer tournant (permet de fcopier que les NBLIGNES)
				ligneCourante = (ligneCourante+1)%NBLIGNES;
			}
			fclose(fichier);

			printf("Affichage des %d dernières lignes\n", NBLIGNES);
			for (int ligneAAfficher = 0; ligneAAfficher < NBLIGNES; ++ligneAAfficher)
			{
				//Affiche le continue de la ligne sur le terminal
				printf("Ligne lue : %s\n", tabLignes[ligneCourante]);
				//Affiche le continue de la ligne à l'écran
				afficheChaine(tabLigne[ligneCourante],20,100,300);
				ligneCourante = (ligneCourante+1)%NBLIGNES;
			}
		}
		else
			printf("Fichier %s impossible à ouvrir\n", argv[1]);
	}
	else
		puts("Veuillez ajouter un seul et unique nom de fichier en paramètre");
	return 0;
}