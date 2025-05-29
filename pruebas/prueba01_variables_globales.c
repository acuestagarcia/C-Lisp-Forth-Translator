#include <stdio.h>

// Variables globales
int global_counter;
int global_multiplier = 5;
int a = 10, b = 20, c = 30, d = 40;


main() {
    puts("Test de variables globales");
    // Valores iniciales
    puts("Valores iniciales");
    printf("", global_counter, ", ", global_multiplier, ", ", a, ", ", b, ", ", c, ", ", d);
    
    // Modificación de variables globales
    puts("Sumamos 5 a la primera y multiplicamos por 3 la segunda");
    global_counter = global_counter + 5;
    global_multiplier = global_multiplier * 3;
    
    // Valores modificados
    puts("Valores modificados");
    printf("", global_counter, ", ", global_multiplier);
}

//@(main)
