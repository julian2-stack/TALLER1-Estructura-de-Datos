#include <stdio.h>
#include <string.h>
#include "jugador.h"

void registrarJugador(Jugador *j) {
    printf("\n=== REGISTRO DE JUGADOR ===\n");
    
    // Captura de 3 iniciales
    printf("Ingrese sus 3 iniciales (ej. GTA): ");
    scanf("%3s", j->iniciales);

    // Limpieza de buffer
    while (getchar() != '\n');

    // Captura del puntaje
    printf("Ingrese su puntaje: ");
    while (scanf("%d", &j->puntaje) != 1 || j->puntaje < 0) {
        printf("Puntaje invalido. Ingrese un numero entero positivo: ");
        while (getchar() != '\n');
    }
}

void mostrarJugador(const Jugador *j) {
    printf("Jugador: %s | Puntaje: %d\n", j->iniciales, j->puntaje);
}