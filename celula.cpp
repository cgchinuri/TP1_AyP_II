#include "celula.h"

Estado inicializarCelula() {
  Estado estado = Muerta;

  return estado;
}

Estado cambiarEstado() {
  Estado estado = Viva;

  return estado;
}

char imprimirEstadoCelula(Estado estado) {
  if (estado == Muerta) {
    return 'M';
  }

  return 'V';
}
