#ifndef TABLERO_H
#define TABLERO_H

#include "celula.h"

static const int FILAS_MAXIMAS = 20;
static const int COLUMNAS_MAXIMAS = 80;
static const int CELULAS_MAXIMAS = FILAS_MAXIMAS * COLUMNAS_MAXIMAS;

typedef struct {
  Celula celulas[FILAS_MAXIMAS][COLUMNAS_MAXIMAS];
} Tablero;

Tablero inicializarTablero();
void mostrarTableroInicial(Tablero tablero);
int mostrarTablero(Tablero tablero);
Tablero ingresarCelulas();

#endif
