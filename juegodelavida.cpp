#include "juegodelavida.h"
#include <iostream>

using namespace std;

JuegoDeLaVida inicializarJuegoDeLaVida() {

  JuegoDeLaVida juegoDeLaVida;

  juegoDeLaVida.tablero = inicializarTablero();
  juegoDeLaVida.porNacer = inicializarTablero();
  juegoDeLaVida.celulasMuertasTurno = 0;
  juegoDeLaVida.celulasNacidasTurno = 0;
  juegoDeLaVida.celulasVivasActuales = 0;
  juegoDeLaVida.turnoActual = 0;
  juegoDeLaVida.turnoLimite = 0;
  juegoDeLaVida.turnosSinCambios = 0;
  juegoDeLaVida.nacimientosTotales = 0;
  juegoDeLaVida.muertesTotales = 0;

  return juegoDeLaVida;
}

void mostrarJuegoDeLaVida(JuegoDeLaVida juegoDeLaVida) {

  float promedioNacimientos =
      (float)juegoDeLaVida.nacimientosTotales / juegoDeLaVida.turnoActual;
  float promedioMuertes =
      (float)juegoDeLaVida.muertesTotales / juegoDeLaVida.turnoActual;

  if (juegoDeLaVida.turnosSinCambios == CONGELADO) {
    cout << "\n----> Juego congelado <----" << endl;
  } else {
    cout << "\n- Cantidad de celulas vivas: "
         << juegoDeLaVida.celulasVivasActuales << endl;
    cout << "- Cantidad de celulas que nacieron en el ultimo turno: "
         << juegoDeLaVida.celulasNacidasTurno << endl;
    cout << "- Cantidad de celulas que murieron en el ultimo turno: "
         << juegoDeLaVida.celulasMuertasTurno << endl;
    cout << "- Promedio nacimientos a lo largo del juego: "
         << promedioNacimientos << endl;
    cout << "- Promedio muertes a lo largo del juego: " << promedioMuertes
         << endl;
  }
}

JuegoDeLaVida inicioDelJuego() {
  JuegoDeLaVida juegoDeLaVida;
  juegoDeLaVida = inicializarJuegoDeLaVida();

  cout << "\n:::::: Juego de la Vida ::::::" << endl;
  cout << "Ingrese la cantidad de turnos a jugar" << endl;
  cin >> juegoDeLaVida.turnoLimite;

  juegoDeLaVida.tablero = ingresarCelulas();

  mostrarTableroInicial(juegoDeLaVida.tablero);

  return juegoDeLaVida;
}

JuegoDeLaVida juegoTurno(JuegoDeLaVida juegoDeLaVida) {
  JuegoDeLaVida juegoTurnoEjecutado;

  juegoTurnoEjecutado = juegoTransicion(juegoDeLaVida);

  return juegoTurnoEjecutado;
}

JuegoDeLaVida juegoTransicion(JuegoDeLaVida juegoDeLaVida) {

  JuegoDeLaVida juegoTemp;
  Estado estado;
  int vecinasVivas;
  juegoDeLaVida.celulasMuertasTurno = 0;
  juegoDeLaVida.celulasNacidasTurno = 0;
  bool cambios = false;

  for (int i = 0; i < FILAS_MAXIMAS; i++) {
    for (int j = 0; j < COLUMNAS_MAXIMAS; j++) {

      estado = juegoDeLaVida.tablero.celulas[i][j].estadoCelula;
      vecinasVivas = cantidadCelulasVecinasVivas(juegoDeLaVida.tablero, i, j);

      if ((estado == Muerta) && (vecinasVivas == NACE)) {

        juegoDeLaVida.porNacer.celulas[i][j].estadoCelula = Naciendo;
        cambios = true;

      }

      else if ((estado == Viva) && (vecinasVivas == 1 || vecinasVivas == 0)) {
        juegoDeLaVida.tablero.celulas[i][j].estadoCelula = Muerta;
        juegoDeLaVida.celulasMuertasTurno++;
        juegoDeLaVida.muertesTotales++;
        cambios = true;
      }

      if (juegoDeLaVida.porNacer.celulas[i][j].estadoCelula == Naciendo) {
        juegoDeLaVida.tablero.celulas[i][j].estadoCelula = Viva;
        juegoDeLaVida.celulasNacidasTurno++;
        juegoDeLaVida.nacimientosTotales++;
        juegoDeLaVida.porNacer.celulas[i][j].estadoCelula = Muerta;
        cambios = true;
      }
    }
  }

  if (!cambios) {
    juegoDeLaVida.turnosSinCambios++;
  }

  juegoTemp = juegoDeLaVida;

  return juegoTemp;
}

int cantidadCelulasVecinasVivas(Tablero tablero, int fila, int columna) {

  int vecinasVivas = 0;

  if (fila == 0 && columna == 0) {
    if (tablero.celulas[1][0].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[1][1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[0][1].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (fila == 0 && columna == 79) {
    if (tablero.celulas[0][78].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[1][78].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[1][79].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (fila == 19 && columna == 0) {
    if (tablero.celulas[18][0].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[18][1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[19][1].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (fila == 19 && columna == 79) {
    if (tablero.celulas[19][78].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[18][78].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[18][79].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (fila == 0 && columna != 0 && columna < 79) {
    if (tablero.celulas[fila][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (fila == 19 && columna != 0 && columna < 79) {
    if (tablero.celulas[fila][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (columna == 0 && fila != 0 && fila < 19) {
    if (tablero.celulas[fila - 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (columna == 79 && fila != 0 && fila < 19) {
    if (tablero.celulas[fila - 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  if (fila > 0 && fila < 19 && columna > 0 && columna < 79) {
    if (tablero.celulas[fila - 1][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna - 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila + 1][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna + 1].estadoCelula == Viva) {
      vecinasVivas++;
    }
    if (tablero.celulas[fila - 1][columna].estadoCelula == Viva) {
      vecinasVivas++;
    }
  }

  return vecinasVivas;
}
