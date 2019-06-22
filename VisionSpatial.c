#include "VisionSpatial.h"
	static int c1=0;
	static int c2=0;
	static int c3=0;
	static int c4=0;
	static int c5=0;
	static int c6=0;
	static int c7=0;
	static int c8=0;
	static int c9=0;
	static int c10=0;
	static int c11=0;
	static int c12=0;
	static int resultat=0;
	static int i=0;
	
int VisionSpatial(void){
	int i;
	
		i=rand()%4;
		
		if(i==0)
		{
			figure1();
		}
		else if(i==1)
		{
			figure2();	
		}
		else if(i==2)
		{
			figure3();	
		}
		else if(i==3)
		{
			figure4();
		}
		else;
	
}


int figure1(void){
	
	
	
	c1=rand()%254;
	c2=rand()%254;
	c3=rand()%254;
	
	c4=rand()%254;
	c5=rand()%254;
	c6=rand()%254;
	
	c7=rand()%254;
	c8=rand()%254;
	c9=rand()%254;
	
	c10=rand()%254;
	c11=rand()%254;
	c12=rand()%254;
	
	epaisseurDeTrait(3);
	couleurCourante(0, 0, 0);
	ligne(400, 600, 400,0);

	//figure d'origine
	couleurCourante(0, 0, 0);
	rectangle(100, 400, 300, 200);
	
	couleurCourante(c1, c2, c3); //1
	rectangle(105, 395, 195, 305);
	
	couleurCourante(c4, c5, c6);  //2
	rectangle(205, 395, 295, 305);
	
	couleurCourante(c7, c8, c9);  //3
	rectangle(105, 295, 195, 205);
	
	couleurCourante(c10, c11, c12); //4
	rectangle(205, 295, 295, 205);
	
	
	//première figure
	couleurCourante(0, 0, 0);
	rectangle(450, 445, 600, 305);
	
	couleurCourante(c7, c8, c9);  //1
	rectangle(455, 440, 520, 380);
	
	couleurCourante(c1, c2, c3); //2
	rectangle(530, 440, 595, 380);
	
	couleurCourante(c10, c11, c12); //3
	rectangle(455, 370, 520, 310);
	
	couleurCourante(c4, c5, c6); //4
	rectangle(530, 370, 595, 310);
	

	//deuxième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 445, 745, 305);
	
	couleurCourante(c4, c5, c6);   //1
	rectangle(610, 440, 670, 380);
	
	couleurCourante(c7, c8, c9); //2
	rectangle(680, 440, 740, 380);
	
	couleurCourante(c1, c2, c3); //3
	rectangle(610, 370, 670, 310);
	
	couleurCourante(c10, c11, c12); //4
	rectangle(680, 370, 740, 310);
	
	
	//troisième figure
	couleurCourante(0, 0, 0);
	rectangle(450, 295, 600, 150);
		
	couleurCourante(c10, c11, c12); //1
	rectangle(455, 290, 520, 230);
	
	couleurCourante(c1, c2, c3);   //2
	rectangle(530, 290, 595, 230);
	
	couleurCourante(c4, c5, c6); //3
	rectangle(455, 220, 520, 155);
	
	couleurCourante(c7, c8, c9); //4
	rectangle(530, 220, 595, 155);
	
	
	//quatrième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 295, 745, 150);
	
	couleurCourante(c4, c5, c6); //1
	rectangle(610, 290, 670, 230);
	
	couleurCourante(c1, c2, c3);  //2
	rectangle(680, 290, 740, 230);
	
	couleurCourante(c10, c11, c12); //3
	rectangle(610, 220, 670, 155);
	
	couleurCourante(c7, c8, c9); //4
	rectangle(680, 220, 740, 155);
	
	 couleurCourante(0, 0, 0);
	 epaisseurDeTrait(3);
	 afficheChaine("Trouvez la figure correspondante", 14, 500, 100);
	 
	 if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>304 && abscisseSouris()<601 && ordonneeSouris()<446){
		 couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 375, 525, 305);
		 epaisseurDeTrait(10);
		 ligne(525, 305, 600, 445);
		 
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
		
		 if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>499 && ordonneeSouris()>9 && abscisseSouris()<61 && ordonneeSouris()<701){
			 resultat=1;
		 }
		 
	 }
	 
	 if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>304 && abscisseSouris()<744 && ordonneeSouris()<446){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 375, 525, 305);
		 epaisseurDeTrait(10);
		 ligne(525, 305, 600, 445);
		 
		  couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(605, 445, 745, 305);
		 epaisseurDeTrait(10);
		 ligne(605, 305, 745, 445);
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>149 && abscisseSouris()<601 && ordonneeSouris()<296){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 375, 525, 305);
		 epaisseurDeTrait(10);
		 ligne(525, 305, 600, 445);
		 
		   couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(450, 150, 600, 295);
		 epaisseurDeTrait(10);
		 ligne(450, 295, 600, 150);
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>149 && abscisseSouris()<744 && ordonneeSouris()<296){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 375, 525, 305);
		 epaisseurDeTrait(10);
		 ligne(525, 305, 600, 445);
		 
		   couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(605, 150, 745, 295);
		 epaisseurDeTrait(10);
		 ligne(605, 295, 745, 150);
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	 
}
int figure2(void){
	
	
	
	c1=rand()%254;
	c2=rand()%254;
	c3=rand()%254;
	
	c4=rand()%254;
	c5=rand()%254;
	c6=rand()%254;
	
	c7=rand()%254;
	c8=rand()%254;
	c9=rand()%254;
	
	c10=rand()%254;
	c11=rand()%254;
	c12=rand()%254;
	
	epaisseurDeTrait(3);
	couleurCourante(0, 0, 0);
	ligne(400, 600, 400,0);
	
	//figure d'origine
	couleurCourante(0, 0, 0);
	rectangle(100, 400, 300, 200);
	
	couleurCourante(c1, c2, c3);
	rectangle(105, 395, 195, 305);
	
	couleurCourante(c4, c5, c6);
	rectangle(205, 395, 295, 305);
	
	couleurCourante(c7, c8, c9);
	rectangle(105, 295, 195, 205);
		
	couleurCourante(c10, c11, c12);
	rectangle(205, 295, 295, 205);
	
	
	//première figure
	couleurCourante(0, 0, 0);
	rectangle(450, 445, 600, 305);
	
	couleurCourante(c1, c2, c3);
	rectangle(455, 440, 520, 380);
	
	couleurCourante(c4, c5, c6);
	rectangle(530, 440, 595, 380);
	
	couleurCourante(c10, c11, c12);
	rectangle(455, 370, 520, 310);
	
	couleurCourante(c7, c8, c9);
	rectangle(530, 370, 595, 310);
	
	
	//deuxième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 445, 745, 305);
	
	couleurCourante(c4, c5, c6);
	rectangle(610, 440, 670, 380);
	
	couleurCourante(c10, c11, c12);
	rectangle(680, 440, 740, 380);
	
	couleurCourante(c1, c2, c3);
	rectangle(610, 370, 670, 310);
	
	couleurCourante(c7, c8, c9);
	rectangle(680, 370, 740, 310);
	
	
	//troisième figure
	couleurCourante(0, 0, 0);
	rectangle(450, 295, 600, 150);
		
	couleurCourante(c1, c2, c3);
	rectangle(455, 290, 520, 230);
	
	couleurCourante(c10, c11, c12);
	rectangle(530, 290, 595, 230);
	
	couleurCourante(c7, c8, c9);
	rectangle(455, 220, 520, 155);
	
	couleurCourante(c4, c5, c6);
	rectangle(530, 220, 595, 155);
	
		
	//quatrième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 295, 745, 150);
	
	couleurCourante(c4, c5, c6);
	rectangle(610, 290, 670, 230);
	
	couleurCourante(c10, c11, c12);
	rectangle(680, 290, 740, 230);
	
	couleurCourante(c7, c8, c9);
	rectangle(610, 220, 670, 155);
	
	couleurCourante(c1, c2, c3);
	rectangle(680, 220, 740, 155);
	
	 couleurCourante(0, 0, 0);
	 epaisseurDeTrait(3);
	 afficheChaine("Trouvez la figure correspondante", 14, 500, 100);
	 
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>304 && abscisseSouris()<601 && ordonneeSouris()<446){
		 couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(450, 445, 600, 305);
		 epaisseurDeTrait(10);
		 ligne(450, 305, 600, 445);
		 
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 375, 675, 305);
		 epaisseurDeTrait(10);
		 ligne(675, 305, 745, 445);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	 if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>304 && abscisseSouris()<746 && ordonneeSouris()<446){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 375, 675, 305);
		 epaisseurDeTrait(10);
		 ligne(675, 305, 745, 445);
		resultat=2;
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>149 && abscisseSouris()<601 && ordonneeSouris()<296){
		
		   couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 375, 675, 305);
		 epaisseurDeTrait(10);
		 ligne(675, 305, 745, 445);
		 
		   couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(450, 150, 600, 295);
		 epaisseurDeTrait(10);
		 ligne(450, 295, 600, 150);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>149 && abscisseSouris()<744 && ordonneeSouris()<296){
		
		
		   couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(605, 150, 745, 295);
		 epaisseurDeTrait(10);
		 ligne(605, 295, 745, 150);
		 
		   couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 375, 675, 305);
		 epaisseurDeTrait(10);
		 ligne(675, 305, 745, 445);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
}
int figure3(void){
	

	
	c1=rand()%254;
	c2=rand()%254;
	c3=rand()%254;
	
	c4=rand()%254;
	c5=rand()%254;
	c6=rand()%254;
	
	c7=rand()%254;
	c8=rand()%254;
	c9=rand()%254;
	
	c10=rand()%254;
	c11=rand()%254;
	c12=rand()%254;
	
	epaisseurDeTrait(3);
	couleurCourante(0, 0, 0);
	ligne(400, 600, 400,0);
	
	//figure d'origine
	couleurCourante(0, 0, 0);
	rectangle(100, 400, 300, 200);
	
	couleurCourante(c1, c2, c3);
	rectangle(105, 395, 195, 305);
	
	couleurCourante(c4, c5, c6);
	rectangle(205, 395, 295, 305);
	
	couleurCourante(c7, c8, c9);
	rectangle(105, 295, 195, 205);
	
	couleurCourante(c10, c11, c12);
	rectangle(205, 295, 295, 205);
	
	
	//première figure
	couleurCourante(0, 0, 0);
	rectangle(450, 445, 600, 305);
	
	couleurCourante(c7, c8, c9);
	rectangle(455, 440, 520, 380);
	
	couleurCourante(c10, c11, c12);
	rectangle(530, 440, 595, 380);
	
	couleurCourante(c4, c5, c6);
	rectangle(455, 370, 520, 310);
	
	couleurCourante(c1, c2, c3);
	rectangle(530, 370, 595, 310);
	
	
	//deuxième figure
	couleurCourante(0, 0, 0);
	rectangle(450, 295, 600, 150);
		
	couleurCourante(c10, c11, c12);
	rectangle(455, 290, 520, 230);
	
	couleurCourante(c4, c5, c6);
	rectangle(530, 290, 595, 230);
	
	couleurCourante(c7, c8, c9);
	rectangle(455, 220, 520, 155);
	
	couleurCourante(c1, c2, c3);
	rectangle(530, 220, 595, 155);
	
	
	//troisième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 445, 745, 305);
	
	couleurCourante(c10, c11, c12);
	rectangle(610, 440, 670, 380);
	
	couleurCourante(c7, c8, c9);
	rectangle(680, 440, 740, 380);
	
	couleurCourante(c4, c5, c6);
	rectangle(610, 370, 670, 310);
	
	couleurCourante(c1, c2, c3);
	rectangle(680, 370, 740, 310);
	
	
	//quatrième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 295, 745, 150);
	
	couleurCourante(c10, c11, c12);
	rectangle(610, 290, 670, 230);
	
	couleurCourante(c7, c7, c8);
	rectangle(680, 290, 740, 230);
	
	couleurCourante(c1, c2, c3);
	rectangle(610, 220, 670, 155);
	
	couleurCourante(c4, c5, c6);
	rectangle(680, 220, 740, 155);
	
	 couleurCourante(0, 0, 0);
	 epaisseurDeTrait(3);
	 afficheChaine("Trouvez la figure correspondante", 14, 500, 100);
	 
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>304 && abscisseSouris()<601 && ordonneeSouris()<446){
		
		 couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 225, 525, 150);
		 epaisseurDeTrait(10);
		 ligne(525, 150, 600, 295);
		 
	    couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(450, 445, 600, 305);
		 epaisseurDeTrait(10);
		 ligne(450, 305, 600, 445);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	 if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>304 && abscisseSouris()<744 && ordonneeSouris()<446){
		
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 225, 525, 150);
		 epaisseurDeTrait(10);
		 ligne(525, 150, 600, 295);
		 	 
		  couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(605, 445, 745, 305);
		 epaisseurDeTrait(10);
		 ligne(605, 305, 745, 445);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
		 
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>149 && abscisseSouris()<601 && ordonneeSouris()<296){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 225, 525, 150);
		 epaisseurDeTrait(10);
		 ligne(525, 150, 600, 295);
		resultat=3;
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>149 && abscisseSouris()<744 && ordonneeSouris()<296){
		
		    couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(605, 150, 745, 295);
		 epaisseurDeTrait(10);
		 ligne(605, 295, 745, 150);
		
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(450, 225, 525, 150);
		 epaisseurDeTrait(10);
		 ligne(525, 150, 600, 295);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
}
int figure4(void){
	
	
	
	c1=rand()%254;
	c2=rand()%254;
	c3=rand()%254;
	
	c4=rand()%254;
	c5=rand()%254;
	c6=rand()%254;
	
	c7=rand()%254;
	c8=rand()%254;
	c9=rand()%254;
	
	c10=rand()%254;
	c11=rand()%254;
	c12=rand()%254;
	
	epaisseurDeTrait(3);
	couleurCourante(0, 0, 0);
	ligne(400, 600, 400,0);
	
	//figure d'origine
	couleurCourante(0, 0, 0);
	rectangle(100, 400, 300, 200);
	
	couleurCourante(c1, c2, c3);
	rectangle(105, 395, 195, 305);
	
	couleurCourante(c4, c5, c6);
	rectangle(205, 395, 295, 305);
	
	couleurCourante(c7, c8, c9);
	rectangle(105, 295, 195, 205);
	
	couleurCourante(c10, c11, c12);
	rectangle(205, 295, 295, 205);
	
	
	//première figure
	couleurCourante(0, 0, 0);
	rectangle(450, 445, 600, 305);
	
	couleurCourante(c7, c8, c9);
	rectangle(455, 440, 520, 380);
	
	couleurCourante(c10, c11, c12);
	rectangle(530, 440, 595, 380);
	
	couleurCourante(c4, c5, c6);
	rectangle(455, 370, 520, 310);
	
	couleurCourante(c1, c2, c3);
	rectangle(530, 370, 595, 310);
	
	
	//deuxième figure
	couleurCourante(0, 0, 0);
	rectangle(450, 295, 600, 150);
		
	couleurCourante(c4, c5, c6);
	rectangle(455, 290, 520, 230);
	
	couleurCourante(c10, c11, c12);
	rectangle(530, 290, 595, 230);
	
	couleurCourante(c7, c8, c9);
	rectangle(455, 220, 520, 155);
	
	couleurCourante(c1, c2, c3);
	rectangle(530, 220, 595, 155);
	
	
	//troisième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 445, 745, 305);
	
	couleurCourante(c10, c11, c12);
	rectangle(610, 440, 670, 380);
	
	couleurCourante(c4, c5, c6);
	rectangle(680, 440, 740, 380);
	
	couleurCourante(c7, c8, c9);
	rectangle(610, 370, 670, 310);
	
	couleurCourante(c1, c2, c3);
	rectangle(680, 370, 740, 310);
	
	
	//quatrième figure
	couleurCourante(0, 0, 0);
	rectangle(605, 295, 745, 150);
	
	couleurCourante(c10, c11, c12);
	rectangle(610, 290, 670, 230);
	
	couleurCourante(c7, c8, c9);
	rectangle(680, 290, 740, 230);
	
	couleurCourante(c4, c5, c6);
	rectangle(610, 220, 670, 155);
	
	couleurCourante(c1, c2, c3);
	rectangle(680, 220, 740, 155);
	
	 couleurCourante(0, 0, 0);
	 epaisseurDeTrait(3);
	 afficheChaine("Trouvez la figure correspondante", 14, 500, 100);
	
	if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>304 && abscisseSouris()<601 && ordonneeSouris()<446){
		 couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(450, 445, 600, 305);
		 epaisseurDeTrait(10);
		 ligne(450, 305, 600, 445);
		 resultat=1;
		 
		   couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 220, 675, 150);
		 epaisseurDeTrait(10);
		 ligne(675, 150, 745, 295);
		 
		  couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	 if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>304 && abscisseSouris()<744 && ordonneeSouris()<446){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 220, 675, 150);
		 epaisseurDeTrait(10);
		 ligne(675, 150, 745, 295);
		 
		 
		  couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(605, 445, 745, 305);
		 epaisseurDeTrait(10);
		 ligne(605, 305, 745, 445);
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>449 && ordonneeSouris()>149 && abscisseSouris()<601 && ordonneeSouris()<296){
		   couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 220, 675, 150);
		 epaisseurDeTrait(10);
		 ligne(675, 150, 745, 295);
		 
		 
		   couleurCourante(255, 0, 0);
		epaisseurDeTrait(10);
		 ligne(450, 150, 600, 295);
		 epaisseurDeTrait(10);
		 ligne(450, 295, 600, 150);
	
	 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }
	 
	  if(etatBoutonSouris() == GaucheAppuye && abscisseSouris()>604 && ordonneeSouris()>149 && abscisseSouris()<746 && ordonneeSouris()<296){
		  couleurCourante(0, 255, 0);
		epaisseurDeTrait(10);
		 ligne(605, 220, 675, 150);
		 epaisseurDeTrait(10);
		 ligne(675, 150, 745, 295);
		resultat=4;
		
		 couleurCourante(150, 150, 150);
		 rectangle(500, 60, 700, 10);		 
		 couleurCourante(0, 0, 0);
		 epaisseurDeTrait(2);
		 afficheChaine("SUIVANT", 20, 555, 25);
	 }	
}


int validation(void){
	int i;
	if(resultat==1){
		i=rand()%4;
		
		if(i==0)
		{
			figure1();
		}
		else if(i==1)
		{
			figure2();	
		}
		else if(i==2)
		{
			figure3();	
		}
		else if(i==3)
		{
			figure4();
		}
		else;
	}	
		if(resultat==2){
		i=rand()%4;
		
		if(i==0)
		{
			figure1();
		}
		else if(i==1)
		{
			figure2();	
		}
		else if(i==2)
		{
			figure3();	
		}
		else if(i==3)
		{
			figure4();
		}
		else;
	}	
		if(resultat==3){
		i=rand()%4;
		
		if(i==0)
		{
			figure1();
		}
		else if(i==1)
		{
			figure2();	
		}
		else if(i==2)
		{
			figure3();	
		}
		else if(i==3)
		{
			figure4();
		}
		else;
	}	
		if(resultat==4){
		i=rand()%4;
		
		if(i==0)
		{
			figure1();
		}
		else if(i==1)
		{
			figure2();	
		}
		else if(i==2)
		{
			figure3();	
		}
		else if(i==3)
		{
			figure4();
		}
		else;
}
}
