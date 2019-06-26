#include "HCalcul.h"



chaine calculMentalAffichage(chaine c)
{
	c.valeur1=rand()%50;
	c.valeur2=rand()%50;
	c.choix=rand()%2;
	char txt[20];
	memset(txt,0,20);
	
	if(c.choix==0)
	{
		couleurCourante(0,0,0);
		epaisseurDeTrait(3);
		sprintf(txt,"%d - %d = ?",c.valeur1,c.valeur2);
		afficheChaine(txt,40,350,400);
		c.resultat=(c.valeur1)-(c.valeur2);
	}
	else if(c.choix==1)
	{
		couleurCourante(0,0,0);
		epaisseurDeTrait(3);
		sprintf(txt,"%d + %d = ?",c.valeur1,c.valeur2);
		afficheChaine(txt,40,350,400);
		c.resultat=(c.valeur1)+(c.valeur2);	
	}
	else if (c.choix==2){
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	sprintf(txt,"%d X %d = ?",c.valeur1,c.valeur2);
	afficheChaine(txt,40,350,400);
	c.resultat=((c.valeur1)*(c.valeur2));}
	
	return c;
}

chaine resultat(chaine c)
{
	char reponse[10];
	char txt[20];
	memset(txt,0,20);
	memset(reponse,0,10);
	scanf("%d",&c.rep);
	if(c.rep==c.resultat)
	{
		couleurCourante(0,255,0);
		sprintf(reponse,"%d",c.rep);
		afficheChaine(reponse,40,150,400);
	}
	else 
	{
		couleurCourante(255,0,0);
		sprintf(reponse,"%d",c.reponse);
		afficheChaine(reponse,40,150,400);
	}
	
	
	
	return c;
}


chaine verif(chaine c){
	char txt[20];
	memset(txt,0,20);
	if(c.rep==c.resultat){
	c.scorecalcul++;
	}
	else
	{
	
	}
	return c;
}

