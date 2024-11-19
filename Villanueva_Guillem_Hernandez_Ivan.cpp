#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void juego();

int main() {
    char map[10][10];
    int move;
    int x = 0, y = 0;
    

    while(!(x == 4 && y == 4)){
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = '-';
            }
        }

        map[4][4] = 'R';  // Esta posición representa el punto en el mapa donde el jugador encuentra el reto
        map[x][y] = 'X';  // Posición del jugador

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        printf("Que accion quieres realizar? \n");
        printf("1. Mover hacia arriba\n");
        printf("2. Mover hacia abajo\n");
        printf("3. Mover hacia la derecha\n");
        printf("4. Mover hacia la izquierda\n");
        scanf_s("%d", &move);

        switch (move) {
        case 1:
            if (x > 0) x--; // Mover hacia arriba
            break;
        case 2:
            if (x < 9) x++; // Mover hacia abajo
            break;
        case 3:
            if (y < 9) y++; // Mover hacia la derecha
            break;
        case 4:
            if (y > 0) y--; // Mover hacia la izquierda
            break;
        default:
            printf("Opción inválida\n");
            break;
        }

      

    }printf("Has llegado al reto\n");
        juego(); 
    return 0;
}

void juego() {
    int vidas = 10;
    char palabra[] = "thegrefg";
    int longitud = strlen(palabra);
    char palabra2[8];
    char letra;

    printf("Has accedido al colgado\n");

   
    for (int i = 0; i < longitud; i++) {
        palabra2[i] = '_';
        printf("%c ", palabra2[i]);
    }
    printf("\n\n");

    
    do {
        printf("Introduce una letra: ");
        scanf_s(" %c", &letra);

        bool letra_encontrada = false;

        
        for (int i = 0; i < longitud; i++) {
            if (letra == palabra[i]) {
                palabra2[i] = palabra[i];
                letra_encontrada = true;
            }
            printf("%c ", palabra2[i]);
        }
        printf("\n");

       
        if (!letra_encontrada) {
            vidas--;
            printf("Has perdido una vida, te quedan %d vidas\n", vidas);
        }

    } while (vidas > 0 && strncmp(palabra, palabra2, longitud) != 0);

    if (vidas > 0) {
        printf("Has ganado\n");
    }
    else {
        printf("Has perdido\n");
    }
}
