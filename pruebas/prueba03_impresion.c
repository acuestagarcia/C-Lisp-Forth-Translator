#include <stdio.h>

int tres = 3;

main() {
    puts("Test de puts");

    // No debería imprimir el primer string, pero sí todos los otros argumentos
    printf("Test de printf", "Test de printf: ", 1, ", ", 1+1, ", ", tres);
}

//@(main)
