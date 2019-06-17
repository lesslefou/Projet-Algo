run: projet
	@./projet


projet: main.o sMemories.o Librairie/libisentlib.a
	gcc main.o sMemories.o  -o projet   Librairie/libisentlib.a -lm -lglut -lGL -lX11


main.o: main.c Librairie/BmpLib.h Librairie/GfxLib.h hMemories.h
	gcc -Wall -c main.c

sMemories.o: sMemories.c hMemories.h
	gcc -Wall -c sMemories.c

clean: 
	rm main.o sMemories.o projet
	
