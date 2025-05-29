#include <stdio.h>

int resultado = 1;
int num = 5;
int i;

main() {
    puts("Prueba de bucles for con un factorial");

    printf("", "Número escogido: ", num); puts("");

    for (i = 1; i <= num; i=i+1) {
        resultado = resultado * i;
        printf("", "Iteración", i, ": ", resultado); puts("");
    }

    printf("", "Resultado: ", resultado);
}

//@(main)
