#include <stdio.h>

main() {
    puts("Prueba de vectores");
    int vec[10];

    printf("", "Vector inicial: ", vec);


    puts("Lo inicialiciamos con múltiplos de 3");
    int i;
    // Inicialización: el vector toma múltiplos de 3
    for (i = 0; i < 10; i=i+1) {
        vec[i] = i * 3;
    }

    puts("Contenido del vector:");
    for (i = 0; i < 10; i=i+1) {
        puts("");
        printf("", "Índice ", i, ": ", vec[i]);
    }

    return 0;
}

//@(main)
