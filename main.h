#ifndef MAIN_H
#define MAIN_H

#include "tablero.h" 
#include "armas.h"
#include "entidades.h"
#include "spawn.h"

typedef struct Juego {
    struct Tablero *t; /* encapsula W/H y la politica de memoria/render */
    Armas armas;
    PoolAliens pool;

    int dificultad;
    int turno, vivos, jugador_x;
} Juego;

#endif // MAIN_H