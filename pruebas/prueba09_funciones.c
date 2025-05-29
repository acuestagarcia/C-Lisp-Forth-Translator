#include <stdio.h>

prueba_for_iterativo(int num) {
    int resultado = 1;
    int i;
    for (i = 1; i <= num; i=i+1) {
        resultado = resultado * i;
    }

    return resultado;
}

prueba_for_recursivo(int num) {
    // Caso base
    if (num <= 1) {
        return 1;
    }
    
    // Caso recursivo
    return num * prueba_for_recursivo(num - 1);
}

main() {
    int num = 5;

    // Probamos la llamada a los procedimientos
    puts("----- Llamada a la función de factorial iterativa -----");
    printf("", "Argumento dado: ", num); puts("");
    printf("", "Resultado: ", prueba_for_iterativo(num));

    num = 6;

    puts("----- Llamada a la función de factorial recursiva -----");
    printf("", "Argumento dado: ", num); puts("");
    printf("", "Resultado: ", prueba_for_recursivo(num));
}

//@(main)
