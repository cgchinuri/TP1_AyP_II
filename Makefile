CC = g++
CFLAGS= -Wall --std=c++98 -pedantic -ansi -Wextra

all:juegoDeLaVida

juegoDeLaVida: principal.o celula.o interacciones.o juegodelavida.o tablero.o
	$(CC) $(CFLAG) -o juegoDeLaVida principal.o celula.o interacciones.o juegodelavida.o tablero.o
principal.o: principal.cpp interacciones.h
	$(CC) $(CFLAG) -o principal.o -c principal.cpp
celula.o: celula.cpp celula.h 
	$(CC) $(CFLAG) -o celula.o -c celula.cpp
interacciones.o: interacciones.cpp interacciones.h
	$(CC) $(CFLAG) -o interacciones.o -c interacciones.cpp
juegodelavida.o: juegodelavida.cpp juegodelavida.h 
	$(CC) $(CFLAG) -o juegodelavida.o -c juegodelavida.cpp
tablero.o: tablero.cpp tablero.h
	$(CC) $(CFLAG) -o tablero.o -c tablero.cpp
clean:
	rm *.o
