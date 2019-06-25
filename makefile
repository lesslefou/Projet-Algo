CFLAGS=-Wall -g -c
LDFLAGS=-g

run: projet
	@./projet

test: projet
	@valgrind ./projet

projet: main.o sMemory.o sTestFB.o sKonami.o saffichage.o Librairie/libisentlib.a
	gcc $(LDFLAGS) main.o sMemory.o sTestFB.o sKonami.o saffichage.o -o projet   Librairie/libisentlib.a -lm -lglut -lGL -lX11


main.o: main.c Librairie/BmpLib.h Librairie/GfxLib.h hMemory.h hTestFB.h haffichage.h hKonami.h
	gcc $(CFLAGS) main.c

sMemory.o: sMemory.c hMemory.h
	gcc $(CFLAGS) sMemory.c

sTestFB.o: sTestFB.c hTestFB.h
	gcc $(CFLAGS) sTestFB.c

sKonami.o : sKonami.c hKonami.h
	gcc $(CFLAGS) sKonami.c

saffichage.o: saffichage.c haffichage.h
	gcc $(CFLAGS) saffichage.c

clean: 
	rm -f main.o sMemory.o sTestFB.o saffichage.o sKonami.o projet
	
