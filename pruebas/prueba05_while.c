#include <stdio.h>
int control_variable = 0;

main() {
    puts("Prueba de bucles while");

    printf("", "Valor inicial de la variable de control: ", control_variable); puts("");

    while (control_variable < 10){
        printf("", "Valor de la variable de control: ", control_variable); puts("");
        control_variable = control_variable + 1;
    }
}

//@(main)
