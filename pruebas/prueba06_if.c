#include <stdio.h>
int cero = 0;
int uno = 1;

main() {
    puts("Prueba de sentencias if e if else");

    puts("Prueba de if");
    printf("", "Valor: ", cero);

    if (cero == 0) {
        puts("El número es 0");
    }

    puts("Prueba de if else");
    printf("", "Valor: ", uno);
    
    if (uno == 0) {
        puts("El número es 0");
    } else {
        puts("El número no es 0");
    }
}

//@(main)
