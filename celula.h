#ifndef CELULA_H
#define CELULA_H

typedef enum { Viva, Muerta, Naciendo, Muriendo } Estado;

typedef struct {
  Estado estadoCelula;
} Celula;

Estado inicializarCelula();
Estado cambiarEstado();
char imprimirEstadoCelula(Estado estado);

#endif
