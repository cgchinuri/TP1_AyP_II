#include "tablero.h"
#include <iostream>

using namespace std;

Tablero inicializarTablero() {
  Tablero tablero;

  for (int i = 0; i < FILAS_MAXIMAS; i++) {
    for (int j = 0; j < COLUMNAS_MAXIMAS; j++) {
      tablero.celulas[i][j].estadoCelula = inicializarCelula();
    }
  }

  return tablero;
}

void mostrarTableroInicial(Tablero tablero) {
  int cantidadCelulasVivas = 0;
  Estado estadoAux = Viva;
  cout
      << "\n::::: Inicio del juego, estado inicial del tablero de celulas :::::"
      << endl;
  cout << "M = Muerta       V = Viva \n" << endl;
  for (int i = 0; i < FILAS_MAXIMAS; i++) {
    for (int j = 0; j < COLUMNAS_MAXIMAS; j++) {
      cout << imprimirEstadoCelula(tablero.celulas[i][j].estadoCelula);
      if (tablero.celulas[i][j].estadoCelula == estadoAux) {
        cantidadCelulasVivas++;
      }
    }
    cout << endl;
  }

  cout << "- Cantidad de celulas vivas: " << cantidadCelulasVivas << endl;
}

int mostrarTablero(Tablero tablero) {

  int cantidadCelulasVivas = 0;
  Estado estadoAux = Viva;
  cout << "\nEstado del tablero:\n" << endl;
  for (int i = 0; i < FILAS_MAXIMAS; i++) {
    for (int j = 0; j < COLUMNAS_MAXIMAS; j++) {
      cout << imprimirEstadoCelula(tablero.celulas[i][j].estadoCelula);
      if (tablero.celulas[i][j].estadoCelula == estadoAux) {
        cantidadCelulasVivas++;
      }
    }
    cout << endl;
  }

  return cantidadCelulasVivas;
}

Tablero ingresarCelulas() {
  Tablero tablero;
  tablero = inicializarTablero();
  int fila = 1;
  int columna = 1;
  int contador = 0;

  while (fila != 0 && columna != 0 && contador < CELULAS_MAXIMAS) {
    cout << "Ingreso de celulas vivas, para terminar el ingreso presione 0"
         << endl;
    cout << "Ingrese la fila" << endl;
    cin >> fila;
    if (fila != 0) {
      cout << "Ingrese la columna" << endl;
      cin >> columna;
    }

    if (fila != 0 && columna != 0) {

      (tablero.celulas[fila - 1][columna - 1]).estadoCelula = cambiarEstado();
    }

    contador++;
  }

  return tablero;
}
