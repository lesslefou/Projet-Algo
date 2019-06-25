#include "hCouleur.h"


void affichage(void){
	
couleurCourante(0,0,0);
rectangle(150,200,200,250);
rectangle(250,200,300,250);
rectangle(350,200,400,250);
rectangle(450,200,500,250);
rectangle(550,200,600,250);
rectangle(650,200,700,250);
rectangle(750,200,800,250);
couleurCourante(255,255,255);
afficheChaine("BLEU",15,160,225);
afficheChaine("ROUGE",15,260,225);
afficheChaine("NOIR",15,360,225);
afficheChaine("TURQUOISE",460,120,225);
afficheChaine("ORANGE",15,560,225);
afficheChaine("MAUVE",15,660,225);
afficheChaine("ROSE",15,760,225);
	
}


int couleur(int choix){
	
if(choix==0){
	couleurCourante(255,0,0);
	rectangle(200,100,400,300);
	couleurCourante(0,0,255);
	afficheChaine("VERT",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
}
else if(choix==1){ 
	
	couleurCourante(0,128,0);
	rectangle(200,100,400,300);
	couleurCourante(255,0,0);
	afficheChaine("BLEU",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
}
	else if(choix==2){
		
	couleurCourante(0,128,0);
	rectangle(200,100,400,300);
	couleurCourante(0,0,0);
	afficheChaine("GRIS",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	
	}
	
	else if(choix==3){
	
	couleurCourante(128,0,128);
	rectangle(200,100,400,300);
	couleurCourante(128,0,0);
	afficheChaine("ORANGE",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	
}
else if(choix==4){
	
	couleurCourante(255,128,128);
	rectangle(200,100,400,300);
	couleurCourante(0,255,128);
	afficheChaine("JAUNE",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	}
	
	else if(choix==5){
	
	couleurCourante(0,128,255);
	rectangle(200,100,400,300);
	couleurCourante(255,128,0);
	afficheChaine("ROSE",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	}
	
	else if(choix==6){
	
	couleurCourante(128,128,128);
	rectangle(200,100,400,300);
	couleurCourante(128,64,64);
	afficheChaine("NOIR",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	
}
else if(choix==7){
	
	couleurCourante(255,128,0);
	rectangle(200,100,400,300);
	couleurCourante(64,0,128);
	afficheChaine("MARRON",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	
}
else if (choix==8){
	couleurCourante(64,128,128);
	rectangle(200,100,400,300);
	couleurCourante(128,0,128);
	afficheChaine("ROUGE",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	}
	
	else if(choix==9){
	
	couleurCourante(128,128,192);
	rectangle(200,100,400,300);
	couleurCourante(255,128,128);
	afficheChaine("KAKI",25,290,100);
	afficheChaine("de quelle couleur est le mot ?",20,600,500);
	
	}
	
	return choix;
}

int gereclic(int choix, int absc, int ord,int scorecouleur)
{
	absc=abscisseSouris();
	ord=ordonneeSouris();
	
switch (choix)
{
		case 0:
		{
			if(x<=200 && x>=150 && y<=250 && y>=200){
			scorecouleur++;
			}
			
			
		break;
		}
		case 1:{
			if(x<=300 && x>=250 && y<=250 && y>=200){
			scorecouleur++;
			}
			
			break;}
		case 2:
		{
			if(x<=400 && x>=250 && y<=350 && y>=200){
			scorecouleur++;
			}
			break;
		}
		case 3:
		{if(x<=300 && x>=250 && y<=250 && y>=200){
			scorecouleur++;
			}
			
			break;}
		case 4:
		{
			if(x<=500 && x>=250 && y<=450 && y>=200){
			scorecouleur++;
			}
			
			break;}
			
		case 5:{
			if(x<=600 && x>=250 && y<=550 && y>=200){
			scorecouleur++;
			}
			
			
		break;}
		
		case 6:{
			if(x<=700 && x>=650 && y<=250 && y>=200){
			scorecouleur++;
			}
			
			
		break;}
	
	 case 7:{
		
		if(x<=200 && x>=150 && y<=250 && y>=200){
			scorecouleur++;
			}
		 
		 break;
		 }
	
	case 8: {
	
		if(x<=700 && x>=650 && y<=250 && y>=200){
			scorecouleur++;
			}
		break;
	}
	case 9: {
		
		if(x<=800 && x>=650 && y<=750 && y>=200){
			scorecouleur++;
			}
		
		break;}
		
		default;}
		
	return scorecouleur;
}
