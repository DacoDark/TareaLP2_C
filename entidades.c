#include "main.h"
#include "entidades.h"
#include <stddef.h>

void mover_jugador(struct Juego *juego, int direccion_x){
    Tablero *tablero = juego->t;
    int y = tablero->H - 1; //El jugador siempre estará en la última fila
    int nueva_direccion_x = juego->jugador_x + direccion_x;

    // verificación de límite
    if(nueva_direccion_x < 0 || nueva_direccion_x >= tablero->W) {
        printf("Movimiento inválido: fuera de los límites del tablero.\n"); //Agregar validación en el main
        return; 
    }

    tablero->celdas[y][nueva_direccion_x] = tablero->celdas[y][juego->jugador_x]; //Movemos al jugador a la nueva posición
    tablero->celdas[y][juego->jugador_x] = NULL;                                  //Dejamos la posición anterior vacía
    juego->jugador_x = nueva_direccion_x;                                         //Actualizamos
}

void mover_aliens(struct Juego *juego){
    Tablero *tablero = juego->t;
    for (int altura = tablero->H-2; altura>=0; altura--){
        for (int ancho = 0; ancho < tablero->W; ancho++){
            Celda *celda = (Celda*)tablero->celdas[altura][ancho];
            if (celda && celda->alien){
                if (tablero->celdas[altura+1][ancho]==NULL){
                    tablero->celdas[altura+1][ancho] = tablero->celdas[altura][ancho];
                    tablero->celdas[altura][ancho] = NULL;
                    celda->alien->y = altura+1;
                }
            }
        }
    }
}
