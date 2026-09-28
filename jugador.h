#ifndef JUGADOR_H
#define JUGADOR_H

// Estructura para almacenar los datos de un jugador
typedef struct {
    char iniciales[4]; 
    int puntaje;
} Jugador;

// Prototypes de funciones
void registrarJugador(Jugador *j);
void mostrarJugador(const Jugador *j);

#endif // JUGADOR_H