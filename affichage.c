void affichage1(void)
{
	couleurCourante(125,125,125);
	rectangle(170,480,340,640);

	rectangle(510,480,680,640);
	rectangle(850,480,1200,640);

	rectangle(340,160,850,320);
	rectangle(0,0,100,130);
	rectangle(1100,0,1200,130);

	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Memoire",20,200,560);
	afficheChaine("Analyse",20,540,560);
	afficheChaine("Lateralite",20,880,560);
	afficheChaine("Test general",40,3800,240);
	afficheChaine("score",15,40,65);
	afficheChaine("quitter",15,1120,65);
			
}

void affichageMemoire(void){

	couleurCourante(125,125,125);
	rectangle(400,160,800,320);
	rectangle(240,480,480,640);
	rectangle(720,480,960,640);
	rectangle(0,0,100,130);
	rectangle(1100,0,1200,130);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Memory",20,740,560);
	afficheChaine("Mnémonique",20,260,560);
	afficheChaine("tri tes nombres !",20,360,180);
	afficheChaine("score",15,40,65);
	afficheChaine("quitter",15,1120,65);

}

void affichageAnalyse(void){
couleurCourante(125,125,125);
	rectangle(240,160,480,320);
	rectangle(720,160,960,320);
	rectangle(240,480,480,640);
	rectangle(720,480,960,640);
	rectangle(0,0,100,130);
	rectangle(1100,0,1200,130);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Couleur",20,260,560);
	afficheChaine("Syllabène",20,740,560);
	afficheChaine("calcul mental",20,260,240);
	afficheChaine("Test FB",20,740,240);
	afficheChaine("score",15,40,65);
	afficheChaine("quitter",15,1120,65);


}


void affichageLateralite(void){

	couleurCourante(125,125,125);
	rectangle(240,260,480,520);
	rectangle(720,260,960,520);
	
	rectangle(0,0,100,130);
	rectangle(1100,0,1200,130);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("ecrit moi",20,740,390);
	afficheChaine("Vision Spaciale",20,260,390);
	
	afficheChaine("score",15,40,65);
	afficheChaine("quitter",15,1120,65);


}
