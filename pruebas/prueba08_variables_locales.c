#include <stdio.h>

int variable_global;

main() {
    puts("Test de variables locales");

    int a;
    int b = 1;
    int c = 10, d = 20, e = 30, f = 40;
    
    puts("Valores iniciales");
    printf("", "Variable global: ", variable_global, ". ", "Variables locales: ", a, ", ", b, ", ", c, ", ", d, ", ", e, ", ", f);
    
    // Probamos la asignación de valores a variables
    puts("Sumamos 5 a la variable global y a la primera variable local");
    variable_global = variable_global + 5;
    a = a + 5;
    
    puts("Valores modificados");
    printf("", "Variable global: ", variable_global, ". ", "Variables locales: ", a, ", ", b, ", ", c, ", ", d, ", ", e, ", ", f);
}

//@(main)
