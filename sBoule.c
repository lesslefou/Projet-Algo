#include "hBoule.h"
void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;
	
	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
	
}

posi affichage(int choix, posi p,int absc,int ord){
	
				
	effaceFenetre (255, 255, 255);	
	couleurCourante (200,200,200);
	rectangle(170,60,420,120);
	rectangle(540,60,810,120);
	rectangle(900,60,1100,120);
	rectangle(0,0,100,70);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Chronometre : ",20,190,80);
	afficheChaine("nb d'erreur : ",20,580,80);
	afficheChaine("S T A R T",20,930,80);
	afficheChaine("Retour",20,20,30);
	couleurCourante(255,0,0);
	epaisseurDeTrait(5);
	afficheChaine("B O U L E S",40,380,720);

	if (p.start == 0)
	{
		epaisseurDeTrait(3);
		couleurCourante(0,0,0);
		afficheChaine("Entrer votre nom :",30,400,440);
	}
	
	if (p.start == 2)
	{
		p.delay ++;
		if (p.delay == 45)	
		{
			p.temps++;
			p.delay=0;
		}

		p.tempo++;
		if (p.tempo < 110)	
		{
			choix=affichageboule(choix);
		}
		else 
		{   do{p=replace(choix,p);
			do{
			p=deplacement1(choix,absc,ord,p);
			p=deplacement1(choix,absc,ord,p);
			p=affich2(choix,absc,ord, p);
		}while(p.valide!=1);
			p=verif(p,choix);
			choix++;}while(choix!=4);
		}
	}
	
	
	
	
	if (p.start == 3)
	{
		
		p.start = 4;
	}	
	
	if (p.start ==4)
	{
		couleurCourante(120,120,120);
		rectangle(100,180,1100,680);
		couleurCourante(0,0,0);
		afficheChaine("F I N  D U  T E S T",30,430,400);
	}

	char chrono[] = "00";
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(chrono,"%d s",p.temps);
	epaisseurDeTrait(2);
	afficheChaine(chrono,20,350,80);

	char pourcentage[] = "00";
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	sprintf(pourcentage,"%d",p.erreur);
	epaisseurDeTrait(2);
	afficheChaine(pourcentage,20,730,80);

	return p;
}
int affichageboule(int choix){
	
		if (choix==1)
		{
			couleurCourante(0,255,0);
			cercle(200,400,30);
			couleurCourante(255,0,0);
			cercle(300,400,30);
		}
	
	else if(choix==2)
	{
	couleurCourante(128,128,128);
    cercle(200,400,30);
    couleurCourante(255,255,0);
	cercle(300,400,30);
	couleurCourante(64,64,64);
	cercle(400,400,30);
	
	}
	else if(choix==3){
	couleurCourante(255,0,255);
	cercle(200,400,30);
	couleurCourante(0,128,0);
	cercle(300,400,30);
	couleurCourante(128,64,0);
	cercle(400,400,30);
	couleurCourante(255,128,128);
	cercle(500,400,30);
	
	}
	else if(choix==4){
	couleurCourante(255,0,128);
	cercle(200,400,30);
	couleurCourante(128,0,0);
	cercle(300,400,30);
	couleurCourante(174,82,0);
	cercle(400,400,30);
	couleurCourante(65,95,84);
	cercle(500,400,30);
	couleurCourante(125,125,125);
	cercle(600,400,30);
	
	
}

return choix;
}

posi replace(int choix,posi p){
	
	if (choix==1)
{
	effaceFenetre(255,255,255);
	couleurCourante(0,0,0);
	epaisseurDeTrait(10);
	afficheChaine("replace l'ordre d'affichage",25,350,400);
	couleurCourante(255,0,0);
	cercle(200,200,30);
	couleurCourante(0,255,0);
	cercle(300,200,30);
	epaisseurDeTrait(10);
	afficheChaine("valide",25,510,225);
	rectangle(500,200,550,250);
	couleurCourante(0,0,0);
	epaisseurDeTrait(10);
	point(200,400);
	point(300,400);
}

else if(choix==2)
{
	effaceFenetre(255,255,255);
	couleurCourante(0,0,0);
	afficheChaine("replace l'ordre d'affichage",25,350,400);
	couleurCourante(255,255,0);
	cercle(200,100,30);
	couleurCourante(128,128,128);
	cercle(300,100,30);
	couleurCourante(64,64,64);
    cercle(400,100,30);
    epaisseurDeTrait(10);
	afficheChaine("valide",25,510,225);
	rectangle(500,200,550,250);
	couleurCourante(0,0,0);
	epaisseurDeTrait(10);
	point(200,400);
	point(300,400);
	point(400,400);
	}
    
    else if(choix==3){
	effaceFenetre(255,255,255);
	couleurCourante(0,0,0);
	afficheChaine("replace l'ordre d'affichage",25,350,400);
	couleurCourante(128,64,0);
	cercle(200,100,30);
	couleurCourante(255,128,128);
	cercle(300,100,30);
	couleurCourante(255,0,255);
	cercle(400,100,30);
	couleurCourante(0,128,0);
	cercle(500,100,30);
	epaisseurDeTrait(10);
	afficheChaine("valide",25,510,225);
	rectangle(500,200,550,250);
	couleurCourante(0,0,0);
	epaisseurDeTrait(10);
	point(200,400);
	point(300,400);
	point(400,400);
	point(500,400);
		
	}
	
	else if(choix==4){
		
	effaceFenetre(255,255,255);
	couleurCourante(0,0,0);
	afficheChaine("replace l'ordre d'affichage",25,350,400);
	couleurCourante(65,95,84);
	cercle(200,100,30);
	couleurCourante(128,0,0);
	cercle(300,100,30);
	couleurCourante(174,82,0);
	cercle(400,100,30);
	couleurCourante(255,0,128);
	cercle(500,100,30);
	couleurCourante(125,125,125);
	cercle(600,100,30);	
	epaisseurDeTrait(10);
	afficheChaine("valide",25,510,225);
	rectangle(500,200,550,250);
	couleurCourante(0,0,0);
	epaisseurDeTrait(10);
	point(200,400);
	point(300,400);
	point(400,400);
	point(500,400);
	point(600,400);
	}
	
	
	return p; 
}


posi deplacement1(int choix,int absc, int ord, posi p){
	 absc=abscisseSouris();
	 ord=ordonneeSouris();
	 
	  if (choix==1)
	  {
		  if (absc>=280 && absc<=320 && ord>=180 && ord<=220 )
		 {
			p.clic1=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=180 && ord<=220)
		  {
			p.clic1=1;
		  }
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
	 
 }
 
 else if(choix==2){
	 if (absc>=280 && absc<=320 && ord>=180 && ord<=220 )
		 {
			p.clic1=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=180 && ord<=220)
		  {
			p.clic1=1;
		  }
		   else if (absc>=380 && absc<=420 && ord>=180 && ord<=220 )
		 {
			p.clic1=3;
		  }
		 
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
 }
	 else if(choix==3){
	 if (absc>=280 && absc<=320 && ord>=180 && ord<=220 )
		 {
			p.clic1=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=180 && ord<=220)
		  {
			p.clic1=1;
		  }
		   else if (absc>=380 && absc<=420 && ord>=180 && ord<=220 )
		 {
			p.clic1=3;
		  }
		   else if (absc>=480 && absc<=520 && ord>=180 && ord<=220 )
		 {
			p.clic1=4;
		  }
		 
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
 } 
 	 else if(choix==4){
	 if (absc>=280 && absc<=320 && ord>=180 && ord<=220 )
		 {
			p.clic1=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=180 && ord<=220)
		  {
			p.clic1=1;
		  }
		   else if (absc>=380 && absc<=420 && ord>=180 && ord<=220 )
		 {
			p.clic1=3;
		  }
		   else if (absc>=480 && absc<=520 && ord>=180 && ord<=220 )
		 {
			p.clic1=4;
		  }
		    else if (absc>=580 && absc<=620 && ord>=180 && ord<=220 )
		 {
			p.clic1=5;
		  }
		 
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
 } 
 }
 
 posi deplacement2(int choix, int absc, int ord, posi p){
	 
	 
	 absc=abscisseSouris();
	 ord=ordonneeSouris();
	 
	  if (choix==1)
	  {
		  if (absc>=280 && absc<=320 && ord>=380 && ord<=420 )
		 {
			p.clic2=1;
		  }
		  else if(absc>=180 && absc<=220 && ord>=380 && ord<=420)
		  {
			p.clic2=2;
		  }
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
	 
 }
	 if (choix==2)
	  {
		  if (absc>=280 && absc<=320 && ord>=380 && ord<=420 )
		 {
			p.clic2=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=380 && ord<=420)
		  {
			p.clic2=1;
		  }
		   else if(absc>=380 && absc<=420 && ord>=380 && ord<=420)
		  {
			p.clic2=3;
		  }
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
	 
 } 
	 if (choix==3)
	  {
		  if (absc>=280 && absc<=320 && ord>=380 && ord<=420 )
		 {
			p.clic2=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=380 && ord<=420)
		  {
			p.clic2=1;
		  }
		   else if(absc>=380 && absc<=420 && ord>=380 && ord<=420)
		  {
			p.clic2=3;
		  }
		   else if(absc>=480 && absc<=520 && ord>=380 && ord<=420)
		  {
			p.clic2=4;
		  }
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
	 
 } 
 if (choix==4)
	  {
		  if (absc>=280 && absc<=320 && ord>=380 && ord<=420 )
		 {
			p.clic2=2;
		  }
		  else if(absc>=180 && absc<=220 && ord>=380 && ord<=420)
		  {
			p.clic2=1;
		  }
		   else if(absc>=380 && absc<=420 && ord>=380 && ord<=420)
		  {
			p.clic2=3;
		  }
		   else if(absc>=480 && absc<=520 && ord>=380 && ord<=420)
		  {
			p.clic2=4;
		  }
		   else if(absc>=580 && absc<=620 && ord>=380 && ord<=420)
		  {
			p.clic2=5;
		  }
		  else if(absc<=550 && absc>=500 && ord<=250 && ord>=200)
		  {
			  p.valide=1;
		  }
	 
 }
 return p; 
 }
 
 posi affich2(int choix, int absc, int ord, posi p)
 {
	if (choix==1)
	{
	if(p.clic1==1 && p.clic2==1)
	{
	couleurCourante(255,0,0);
	cercle(200,400,30);
	
	}
	else if(p.clic1==1 && p.clic2==2){
	couleurCourante(255,0,0);
	cercle(300,400,30);
	p.bienvu1=1;
		
	}
	else if(p.clic1==2 && p.clic2==1){
	couleurCourante(0,255,0);
	cercle(200,400,30);
	p.bienvu2=1;
	}
	else if(p.clic1==2 && p.clic2==2){
	couleurCourante(0,255,0);
	cercle(300,400,30);
	}
		
	} 
	 if (choix==2)
	{
	if(p.clic1==1 && p.clic2==1)
	{
	couleurCourante(64,64,64);
	cercle(200,400,30);
	
	}
	else if(p.clic1==1 && p.clic2==2){
	couleurCourante(64,64,64);
	cercle(300,400,30);
		
	}
	else if(p.clic1==1 && p.clic2==3){
	couleurCourante(64,64,64);
	cercle(400,400,30);
	p.bienvu3=1;
	}
	else if(p.clic1==2 && p.clic2==1){
	couleurCourante(255,255,0);
	cercle(200,400,30);
	}
	else if(p.clic1==2 && p.clic2==2){
		couleurCourante(255,255,0);
	cercle(300,400,30);
	p.bienvu2=1;
	}
	else if(p.clic1==2 && p.clic2==3){
		couleurCourante(255,255,0);
	cercle(400,400,30);
	}
		else if(p.clic1==3 && p.clic2==1){
		couleurCourante(128,128,128);
	cercle(200,400,30);
	p.bienvu1=1;
	}
		else if(p.clic1==3 && p.clic2==2){
		couleurCourante(128,128,128);
	cercle(300,400,30);
	}	
	else if(p.clic1==3 && p.clic2==3){
		couleurCourante(128,128,128);
	cercle(400,400,30);
	}
	} 
	if (choix==3)
	{
	if(p.clic1==1 && p.clic2==1)
	{
	couleurCourante(128,64,0);
	cercle(200,400,30);
	
	}
	else if(p.clic1==1 && p.clic2==2){
	couleurCourante(128,64,0);
	cercle(300,400,30);
		
	}
	else if(p.clic1==1 && p.clic2==3){
	couleurCourante(128,64,0);
	cercle(400,400,30);
	p.bienvu4=1;
	}
	else if(p.clic1==1 && p.clic2==4){
		couleurCourante(128,64,0);
		cercle(500,400,30);
	}
	else if(p.clic1==2 && p.clic2==1){
		couleurCourante(255,128,128);
		cercle(200,400,30);
	}
	else if(p.clic1==2 && p.clic2==2){
		couleurCourante(255,128,128);
		cercle(300,400,30);
	}
		else if(p.clic1==2 && p.clic2==3){
		couleurCourante(128,128,128);
		cercle(400,400,30);
	}
		else if(p.clic1==2 && p.clic2==4){
		couleurCourante(128,128,128);
		cercle(500,400,30);
		p.bienvu3=1;
	}	
	else if(p.clic1==3 && p.clic2==1){
		couleurCourante(255,0,255);
	cercle(200,400,30);
	p.bienvu1=1;
	}
	else if(p.clic1==3 && p.clic2==2){
		couleurCourante(255,0,255);
	cercle(300,400,30);
	}
	else if(p.clic1==3 && p.clic2==3){
		couleurCourante(255,0,255);
	cercle(400,400,30);
	}
	else if(p.clic1==3 && p.clic2==4){
		couleurCourante(255,0,255);
	cercle(500,400,30);
	}
	else if(p.clic1==4 && p.clic2==1){
		couleurCourante(0,128,0);
	cercle(200,400,30);
	}
	else if(p.clic1==4 && p.clic2==2){
		couleurCourante(0,128,0);
	cercle(300,400,30);
	p.bienvu2=1;
	}
	else if(p.clic1==4 && p.clic2==3){
		couleurCourante(0,128,0);
	cercle(400,400,30);
	}
	else if(p.clic1==4 && p.clic2==4){
		couleurCourante(0,128,0);
	cercle(500,400,30);
	}
	}  
	 if (choix==4)
	{
	if(p.clic1==1 && p.clic2==1)
	{
	couleurCourante(65,95,84);
	cercle(200,400,30);
	
	}
	else if(p.clic1==1 && p.clic2==2){
	couleurCourante(65,95,84);
	cercle(300,400,30);
		
	}
	else if(p.clic1==1 && p.clic2==3){
	couleurCourante(65,95,84);
	cercle(400,400,30);
	p.bienvu4=1;
	}
	else if(p.clic1==1 && p.clic2==4){
		couleurCourante(65,95,84);
		cercle(500,400,30);
		p.bienvu5=1;
	}
	else if(p.clic1==1 && p.clic2==5){
		couleurCourante(65,95,84);
		cercle(600,400,30);
	}
	else if(p.clic1==2 && p.clic2==1){
		couleurCourante(128,0,0);
		cercle(200,400,30);
	}
	else if(p.clic1==2 && p.clic2==2){
		couleurCourante(128,0,0);
		cercle(300,400,30);
		p.bienvu4=1;
	}
		else if(p.clic1==2 && p.clic2==3){
		couleurCourante(128,0,0);
		cercle(400,400,30);
	}
		else if(p.clic1==2 && p.clic2==4){
		couleurCourante(128,0,0);
		cercle(500,400,30);
		
	}	
	else if(p.clic1==2 && p.clic2==5){
		couleurCourante(128,0,0);
		cercle(600,400,30);
		
	}
	else if(p.clic1==3 && p.clic2==1){
		couleurCourante(174,82,0);
	cercle(200,400,30);
	
	}
	else if(p.clic1==3 && p.clic2==2){
		couleurCourante(174,82,0);
	cercle(300,400,30);
	}
	else if(p.clic1==3 && p.clic2==3){
		couleurCourante(174,82,0);
	cercle(400,400,30);
	p.bienvu3=1;
	}
	else if(p.clic1==3 && p.clic2==4){
		couleurCourante(174,82,0);
	cercle(500,400,30);
	}
	else if(p.clic1==3 && p.clic2==5){
		couleurCourante(174,82,0);
	cercle(600,400,30);
	}
	else if(p.clic1==4 && p.clic2==1){
		couleurCourante(255,0,128);
		cercle(200,400,30);
		p.bienvu1=1;
	}
	else if(p.clic1==4 && p.clic2==2){
		couleurCourante(255,0,128);
		cercle(300,400,30);
	}
	else if(p.clic1==4 && p.clic2==3){
		couleurCourante(255,0,128);
		cercle(400,400,30);
	}
	else if(p.clic1==4 && p.clic2==4){
		couleurCourante(255,0,128);
		cercle(500,400,30);
	}
	else if(p.clic1==4 && p.clic2==5){
		couleurCourante(255,0,128);
		cercle(600,400,30);
	}
		else if(p.clic1==5 && p.clic2==1){
		couleurCourante(125,125,125);
		cercle(200,400,30);
	}
	else if(p.clic1==5 && p.clic2==2){
		couleurCourante(125,125,125);
		cercle(300,400,30);
	}
	else if(p.clic1==5 && p.clic2==3){
		couleurCourante(125,125,125);
		cercle(400,400,30);
	}
	else if(p.clic1==5 && p.clic2==4){
		couleurCourante(125,125,125);
		cercle(500,400,30);
	}
	else if(p.clic1==5 && p.clic2==5){
		couleurCourante(125,125,125);
		cercle(600,400,30);
		p.bienvu2=1;
	}
	}
return p; 	 
	 
 }


posi verif(posi p, int choix){
	if (choix==1){
		if(p.bienvu1==1 && p.bienvu2==1)
		{
			p.reussite++;
		}
		else
		{
		afficheChaine("pas bon !",20,200,200);	
		}
		
	}
	
	if (choix==2){
		if(p.bienvu1==1 && p.bienvu2==1 && p.bienvu3==1)
		{
			p.reussite++;
		}
		else
		{
		afficheChaine("pas bon !",20,200,200);	
		}
		
	}
	if (choix==3){
		if(p.bienvu1==1 && p.bienvu2==1 && p.bienvu3==1 && p.bienvu4==1 )
		{
			p.reussite++;
		}
		else
		{
		afficheChaine("pas bon !",20,200,200);	
		}
		
	}
	if (choix==4){
		if(p.bienvu1==1 && p.bienvu2==1 && p.bienvu3==1 && p.bienvu4==1 && p.bienvu5==1 )
		{
			p.reussite++;
		}
		else
		{
		afficheChaine("pas bon !",20,200,200);	
		}
		
	}
	return p;
}
