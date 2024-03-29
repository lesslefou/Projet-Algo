CFLAGS=-Wall -g -c
LDFLAGS=-g

.PHONY: run clean
	
run: projet
	@./projet

test: projet
	@valgrind ./projet

projet: main.o sMemory.o sTestFB.o sKonami.o sCouleur.o sMnemonique.o sVisionSpatiale.o saffichage.o Librairie/libisentlib.a
	gcc $(LDFLAGS) $^ -o $@ -lm -lglut -lGL -lX11


main.o: main.c Librairie/BmpLib.h Librairie/GfxLib.h hMemory.h hTestFB.h haffichage.h hKonami.h hCouleur.h hMnemonique.h hVisionSpatiale.h
	gcc $(CFLAGS) $<

sMemory.o: sMemory.c hMemory.h
	gcc $(CFLAGS) sMemory.c

sTestFB.o: sTestFB.c hTestFB.h
	gcc $(CFLAGS) sTestFB.c

sKonami.o : sKonami.c hKonami.h
	gcc $(CFLAGS) sKonami.c

sCouleur.o: sCouleur.c hCouleur.h
	gcc $(CFLAGS) sCouleur.c

sMnemonique.o: sMnemonique.c hMnemonique.h
	gcc $(CFLAGS) sMnemonique.c

sVisionSpatiale.o: sVisionSpatiale.c hVisionSpatiale.h
	gcc $(CFLAGS) sVisionSpatiale.c


saffichage.o: saffichage.c haffichage.h
	gcc $(CFLAGS) saffichage.c

clean: 
	rm -f main.o sMemory.o sTestFB.o saffichage.o sKonami.o sCouleur.o sMnemonique.o sVisionSpatiale.o projet
	
