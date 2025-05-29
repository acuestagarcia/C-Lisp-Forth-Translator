#include <stdio.h>

main() {
    puts("Prueba de operaciones aritméticas");                                                 puts("");
    printf("", "5 + 3                                     = ", 5 + 3);                         puts("");
    printf("", "10 - 4                                    = ", 10 - 4);                        puts("");
    printf("", "6 * 7                                     = ", 6 * 7);                         puts("");
    printf("", "20 / 4                                    = ", 20 / 4);                        puts("");

    puts("Prueba de operaciones booleanas");                                                   puts("");
    printf("", "5 < 3                                     = ", 5 < 3);                         puts("");
    printf("", "10 <= 4                                   = ", 10 <= 4);                       puts("");
    printf("", "7 != 7                                    = ", 7 != 7);                        puts("");
    printf("", "!(1 == 0)                                 = ", !(1 == 0));                     puts("");
    printf("", "(1 == 1) && (1 == 1)                      = ", (1 == 1) && (1 == 1));          puts("");
    printf("", "(1 != 1) || (1 != 1)                      = ", (1 != 1) || (1 != 1));          puts("");

    puts("Prueba de asociatividad de operadores");                                             puts("");
    printf("", "Izquierda: 5 - 3 - 2 = (5-3)-2            = ", 5 - 3 - 2);                     puts("");
    printf("", "Derecha: !!!(1 == 1) = !(!(!(1 == 1)))    = ", !!!(1 == 1));                   puts("");

    puts("Prueba de precedencia de operadores");                                                                       puts("");
    printf("", "-5 - +2                                   = ((-5) - (+2)                     = ", -5 - +2);            puts("");
    printf("", "7 + 2 / 2 * 3                             = 7 + ((2 / 2) * 3)                = ", 7 + 2 / 2 * 3);      puts("");
    printf("", "25 == 4 * 5 + 5                           = 25 == ((4 * 5) + 5)              = ", 25 == 4 * 5 + 5);    puts("");
    printf("", "!0 && 0                                   = (!0) && 0                        = ", !0 && 0);            puts("");
    printf("", "4 < 5 && 5 > 4 || 5 != 5                  = ((4 < 5) && (5 > 4)) || (5 != 5) = ", 4 < 5 && 5 > 4 || 5 != 5);
}

//@(main)
