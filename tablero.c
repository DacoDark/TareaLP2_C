#include <stdlib.h>
#include <stdio.h>
#include "tablero.h"
#include "main.h"

#define facil_ancho 5
#define facil_alto 15

struct Tablero* tablero_crear(int ancho, int alto){
    struct Tablero *tablero = (struct Tablero*)malloc(sizeof(Tablero));
    if (!tablero) return NULL;
    
    tablero->W = ancho;
    tablero->H = alto;

    //Reservamos memoria para filas
    tablero->celdas = (void ***)malloc(alto * sizeof(void**));
    if (!tablero->celdas) {
        free(tablero);
        return NULL;
    }

    //Reservamos memoria para columnas en cada fila
    for (int i = 0; i < alto; i++) {
        tablero->celdas[i] = (void **)malloc(ancho * sizeof(void*));
        if (!tablero->celdas[i]) {
            // Liberar memoria previamente asignada en caso de error
            for (int j = 0; j < i; j++) {
                free(tablero->celdas[j]);
            }
            free(tablero->celdas);
            free(tablero);
            return NULL;
        }
        for (int x = 0; x<ancho ;x++){
        tablero->celdas[i][x] = NULL;
        }
    }
    return tablero;
}

void tablero_imprimir(struct Juego *juego){
    struct Tablero *tablero = juego->t;

    printf("Tablero (%dx%d):\n", tablero->W, tablero->H);
    for (int y = 0; y < tablero->H; y++) {
        for (int x = 0; x < tablero->W; x++) {
            //Aqui se puede escribir la lógica para imprimir a los personajes del juego, de momento solo imprime si la celda está vacía o no
            if (tablero->celdas[y][x] == NULL) {
                printf("[ ]"); // Celda vacía
            } else {
                printf("[X]");
            }
        }
        printf("\n");
    }
}

void tablero_cerrar(Tablero *tablero){
    if (!tablero) return;
    for (int indice = 0; indice < tablero->H; indice++){
        free(tablero->celdas[indice]);
    }
    free(tablero->celdas);
    free(tablero);
}