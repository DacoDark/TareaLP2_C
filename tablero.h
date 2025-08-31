typedef struct {
int W, H;
void ***celdas; /* celdas[y][x] -> (void*) que apunta a Celda* */
} Tablero;

Tablero* tablero_crear(int ancho, int alto);

void tablero_imprimir(struct Juego *juego);
void tablero_cerrar(Tablero *tablero);
