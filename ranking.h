#ifndef RANKING_H
#define RANKING_H

#include "jugador.h"

#define CAPACIDAD_RANKING 3

typedef struct {
    Jugador top[CAPACIDAD_RANKING];
    int cantidadActual;
} Ranking;

// Prototypes de funciones
void inicializarRanking(Ranking *r);
void mostrarRanking(const Ranking *r);
int actualizarRanking(Ranking *r, const Jugador *nuevoJugador);

#endif // RANKING_H