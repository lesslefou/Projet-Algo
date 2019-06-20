run: projet
	@./projet


projet: main.o sMemory.o sTestFB.o Librairie/libisentlib.a
	gcc main.o sMemory.o  sTestFB.o -o projet   Librairie/libisentlib.a -lm -lglut -lGL -lX11


main.o: main.c Librairie/BmpLib.h Librairie/GfxLib.h hMemory.h hTestFB.h
	gcc -Wall -c main.c

sMemories.o: sMemory.c hMemory.h
	gcc -Wall -c sMemory.c

sTestFB.o: sTestFB.c hTestFB.h
	gcc -Wall -c sTestFB.c

clean: 
	rm main.o sMemory.o sTestFB.o projet
	
