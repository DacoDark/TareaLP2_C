#ifndef TABLERO_H
#define TABLERO_H

#include "main.h"

typedef struct Tablero {
int W, H;
void ***celdas; /* celdas[y][x] -> (void*) que apunta a Celda* */
} Tablero;

Tablero* tablero_crear(int ancho, int alto);
void tablero_imprimir(Juego *juego);
void tablero_cerrar(Tablero *tablero);

#endif // TABLERO_H