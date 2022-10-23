#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"

static const char EJECUTAR_TURNO = 'a';
static const char REINICIO = 'b';
static const char TERMINAR = 'c';
static const int NACE = 3;
static const int CONGELADO = 2;

typedef struct {
  Tablero tablero;
  Tablero porNacer;
  int celulasVivasActuales;
  int celulasNacidasTurno;
  int celulasMuertasTurno;
  int nacimientosTotales;
  int muertesTotales;
  int turnosSinCambios;
  int turnoLimite;
  int turnoActual;
} JuegoDeLaVida;

JuegoDeLaVida inicializarJuegoDeLaVida();
void mostrarJuegoDeLaVida(JuegoDeLaVida juegoDeLaVida);
JuegoDeLaVida inicioDelJuego();
JuegoDeLaVida juegoTurno(JuegoDeLaVida juegoDeLaVida);
JuegoDeLaVida juegoTransicion(JuegoDeLaVida juegoDeLaVida);
int cantidadCelulasVecinasVivas(Tablero tablero, int fila, int columna);

#endif
