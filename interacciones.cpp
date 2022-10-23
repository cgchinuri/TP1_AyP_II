#include "interacciones.h"
#include <iostream>

using namespace std;

void mostrarOpcionesMenu() {
  cout << "\nSeleccione alguna de las siguientes opcionesSSSSS:" << endl;
  cout << "a) Ejecutar un turno." << endl;
  cout << "b) Reiniciar el Juego" << endl;
  cout << "c) Terminar" << endl;
}

JuegoDeLaVida ejecutarOpcion(JuegoDeLaVida juegoDeLaVida,
                             char opcionSeleccionada) {

  JuegoDeLaVida juegoAux;
  bool opcionIncorrecta = false;

  switch (opcionSeleccionada) {
  case 'a':
    juegoAux = juegoTurno(juegoDeLaVida);
    break;
  case 'b':
    cout << "----El juego se va a reiniciar.----" << endl;
    break;

  case 'c':
    cout << "Juego terminado." << endl;
    break;

  default:
    cout << opcionSeleccionada << " No esta en el menu de opciones" << endl;
    opcionIncorrecta = true;
    break;
  }

  if (opcionIncorrecta) {
    juegoAux = juegoDeLaVida;
  }

  return juegoAux;
}
