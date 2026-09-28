#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "ranking.h"

void mostrarMenu() {
    printf("\n--- MENU GTA VI ARCADE ---\n");
    printf("1. Jugar / Registrar nuevo puntaje\n");
    printf("2. Ver Top 3 Ranking\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Ranking miRanking;
    inicializarRanking(&miRanking);

    int opcion = 0;
    Jugador jugadorActual;

    do {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1) {
            printf("Opcin invalida. Intente de nuevo.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                registrarJugador(&jugadorActual);
                if (actualizarRanking(&miRanking, &jugadorActual)) {
                    printf("\n FELICIDADES! Has entrado al TOP 3 del Ranking!\n");
                } else {
                    printf("\n Tu puntaje no supero los mejores registros del Ranking.\n");
                }
                mostrarRanking(&miRanking);
                break;

            case 2:
                mostrarRanking(&miRanking);
                break;

            case 3:
                printf("\nSaliendo del modulo GTA VI Arcade...\n");
                break;

            default:
                printf("\nOpción no valida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    return 0;
}