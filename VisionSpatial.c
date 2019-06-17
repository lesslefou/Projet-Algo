
void VisionSpatial(){
	int i;
	srand(time(0));
	i=rand()%4;
	
	if(i==0){
	fig1();
	}
	else if(i==1){
	fig2();	
	}
	else if(i==2){
	fig3();	
	}
	else if(i==3){
	fig4();
	}
	else if(i==4){
	fig5();	
	}
	
	
	
}


void fig1{
	couleurCourante(0, 0, 0);
	rectangle(100, 400, 300, 200);
	couleurCourante(255, 255, 255);
	rectangle(105, 395, 295, 205);
	
	couleurCourante(0, 255, 255);
	rectangle(106, 394, 196, 304);
	
	couleurCourante(255, 0, 255);
	rectangle(204, 394, 294, 304);
	
	couleurCourante(0, 0, 255);
	rectangle(106, 296, 196, 206);
	
	couleurCourante(255, 0, 255);
	rectangle(204, 296, 294, 206);
}
void fig2{
	
}
void fig3{
	
}
void fig4{
	
}
void fig5{
	
}
