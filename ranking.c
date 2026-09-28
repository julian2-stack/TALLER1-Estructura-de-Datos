#include <stdio.h>
#include <string.h>
#include "ranking.h"

void inicializarRanking(Ranking *r) {
    r->cantidadActual = 0;
    for (int i = 0; i < CAPACIDAD_RANKING; i++) {
        strcpy(r->top[i].iniciales, "---");
        r->top[i].puntaje = 0;
    }
}

void mostrarRanking(const Ranking *r) {
    printf("\n===================================\n");
    printf("     GTA VI - TOP 3 ARCADE RANKING  \n");
    printf("===================================\n");
    printf("POS\tINICIALES\tPUNTAJE\n");
    printf("-----------------------------------\n");
    
    for (int i = 0; i < CAPACIDAD_RANKING; i++) {
        printf(" #%d\t  %s\t\t%d\n", i + 1, r->top[i].iniciales, r->top[i].puntaje);
    }
    printf("===================================\n\n");
}

int actualizarRanking(Ranking *r, const Jugador *nuevoJugador) {
    // Verificar si el puntaje califica para entrar al Top 3
    int posicionInsercion = -1;

    for (int i = 0; i < CAPACIDAD_RANKING; i++) {
        if (nuevoJugador->puntaje > r->top[i].puntaje) {
            posicionInsercion = i;
            break;
        }
    }

    // Si el puntaje no supera a ninguno de la tabla, se ignora
    if (posicionInsercion == -1) {
        return 0; // No ingreso al ranking
    }

    // Desplazar los elementos hacia abajo para hacer espacio
    for (int i = CAPACIDAD_RANKING - 1; i > posicionInsercion; i--) {
        r->top[i] = r->top[i - 1];
    }

    // Insertar el nuevo jugador en la posicion correspondiente
    r->top[posicionInsercion] = *nuevoJugador;
    
    if (r->cantidadActual < CAPACIDAD_RANKING) {
        r->cantidadActual++;
    }

    return 1; // Actualizado con exito
}