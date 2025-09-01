#include <stdlib.h>
#include <stdio.h>
#include "tablero.h"
#include "main.h"

#define FilasFacil 5
#define ColumnasFacil 15

int main(){
    struct Juego juego;
    juego.t = tablero_crear(FilasFacil, ColumnasFacil);
    if (!juego.t) {
        printf("Error al crear el tablero.\n");
        return 1;
    }

    tablero_imprimir(&juego);
    tablero_cerrar(juego.t);
    return 0;
}