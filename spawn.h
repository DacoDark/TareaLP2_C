#ifndef SPAWN_H
#define SPAWN_H

typedef struct {
int especial; int skater; int drone;
int vivos_tope; /* tope de aliens simultaneos en pantalla */
} PoolAliens;

void spawn_inicio(struct Juego *juego);

#endif // SPAWN_H