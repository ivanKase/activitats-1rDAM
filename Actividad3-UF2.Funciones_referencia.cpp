#include <stdio.h>
#include <math.h> 

void num(int* n1, int* n2);
void menu(char* opcion);
void operacion(int n1, int n2, char oper, float* resul, int* error);

int factorial(int num);

int main() {
    int n1 = 0, n2 = 0;
    char opcion;
    float resultado;
    int error;

    menu(&opcion);

    while (opcion != 's') {
        if (opcion == '!') {
            printf("Introduce un número para calcular su factorial: ");
            scanf_s("%d", &n1);
            n2 = 0; 
        }
        else {
            num(&n1, &n2);
        }

        operacion(n1, n2, opcion, &resultado, &error);

        if (error == 1) {
            if (opcion == '!') {
                printf("El factorial de %d es %.0f\n", n1, resultado);
            }
            else {
                printf("El resultado es: %.2f\n", resultado);
            }
        }
        else if (error == 2) {
            printf("Error: entrada inválida para el factorial.\n");
        }
        else {
            printf("Error: no se pudo realizar la operacion.\n");
        }
        menu(&opcion);
    }

    printf("Hasta luego!\n");
    return 0;
}

void num(int* n1, int* n2) {
    printf("Introduce 2 valores tipo enteros:\n");
    scanf_s("%d", n1);
    scanf_s("%d", n2);
}

void menu(char* opcion) {
    printf("Selecciona la operacion que quieres realizar:\n\n");
    printf("(+) --> Sumar\n(-) --> Restar\n(*) --> Multiplicar\n(/) --> Dividir\n(^) --> Potencia\n(!) --> Factorial\n(s) --> Salir\nElija opcion: ");
    scanf_s(" %c", opcion);
}

void operacion(int n1, int n2, char opcion, float* resul, int* error) {
    switch (opcion) {
    case '+':
        *resul = n1 + n2;
        *error = 1;
        break;
    case '-':
        *resul = n1 - n2;
        *error = 1;
        break;
    case '*':
        *resul = n1 * n2;
        *error = 1;
        break;
    case '/':
        if (n2 != 0) {
            *resul = (float)n1 / n2;
            *error = 1;
        }
        else {
            *error = -1;
        }
        break;
    case '^':
        *resul = pow(n1, n2);
        *error = 1;
        break;
    case '!':
        if (n1 >= 0) {
            *resul = (float)factorial(n1);
            *error = 1;
        }
        else {
            *error = 2; // Factorial no definido para números negativos
        }
        break;
    default:
        *error = -1;
        break;
    }
}

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}
