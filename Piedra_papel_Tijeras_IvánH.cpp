#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de funciones
int ElecPC();
int accion();
void juego();
void determinarGanador(int pj1, int PC2);

int accion() { // Función para la elección del jugador
    int e, confirmacion;
    do {
        printf("Selecciona que quieres utilizar: 1 (piedra), 2 (tijeras), 3 (papel):\n");
        scanf_s("%d", &e);

        switch (e) {
        case 1:
            printf("Has seleccionado piedra.\n");
            break;
        case 2:
            printf("Has seleccionado tijeras.\n");
            break;
        case 3:
            printf("Has seleccionado papel.\n");
            break;
        default:
            printf("Opcion invalida, por favor intenta de nuevo.\n");
            continue;
        }

        printf("sEstas seguro de tu eleccion? 1 (si), 2 (no):\n");
        scanf_s("%d", &confirmacion);

    } while (confirmacion != 1 || (e < 1 || e > 3)); // Validar elección entre 1 y 3

    return e;
}

int ElecPC() { // Función para la elección del PC
    int e = (rand() % 3) + 1; // Generar aleatorio entre 1 y 3

    switch (e) {
    case 1:
        printf("El PC ha elegido piedra.\n");
        break;
    case 2:
        printf("El PC ha elegido tijeras.\n");
        break;
    case 3:
        printf("El PC ha elegido papel.\n");
        break;
    }

    return e;
}

void determinarGanador(int pj1, int PC2) { // Función para determinar el ganador
    if (pj1 == PC2) {
        printf("Es un empate.\n");
    }
    else if ((pj1 == 1 && PC2 == 2) || (pj1 == 2 && PC2 == 3) || (pj1 == 3 && PC2 == 1)) {
        printf("¡Has ganado esta ronda!\n");
    }
    else {
        printf("El PC ha ganado esta ronda.\n");
    }
}

void juego() {
    int oportunidades = 3; // Tres oportunidades para jugar
    srand((unsigned int)time(NULL)); // Inicializar generador aleatorio

    for (int i = 0; i < oportunidades; i++) {
        printf("\n----- Ronda %d -----\n", i + 1);
        int jugador = accion();   // Elección del jugador
        int pc = ElecPC(); // Elección del PC

        determinarGanador(jugador, pc);
    }

    printf("\nFin del juego. ¡Gracias por jugar!\n");
}

int main() {
    printf("Bienvenido al Piedra, Papel o Tijeras de Ivan Hernandez\n");
    juego();
    return 0;
}
