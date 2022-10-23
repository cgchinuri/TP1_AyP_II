#include "interacciones.h"
#include <iostream>

using namespace std;

int main() {

  JuegoDeLaVida juegoDeLaVida;

  char opcionSeleccionada;

  juegoDeLaVida = inicioDelJuego();

  while (juegoDeLaVida.turnoActual < juegoDeLaVida.turnoLimite) {

    mostrarOpcionesMenu();
    cin >> opcionSeleccionada;

    juegoDeLaVida = ejecutarOpcion(juegoDeLaVida, opcionSeleccionada);

    if (opcionSeleccionada == EJECUTAR_TURNO) {
      (juegoDeLaVida.turnoActual)++;
      juegoDeLaVida.celulasVivasActuales =
          mostrarTablero(juegoDeLaVida.tablero);
      mostrarJuegoDeLaVida(juegoDeLaVida);

      if (juegoDeLaVida.turnosSinCambios == CONGELADO) {
        juegoDeLaVida.turnosSinCambios = 0;
      }
    }
    if (opcionSeleccionada == REINICIO) {
      juegoDeLaVida = inicioDelJuego();
    }
    if (opcionSeleccionada == TERMINAR) {
      juegoDeLaVida.turnoActual = juegoDeLaVida.turnoLimite;
    }
  }

  return 0;
}
