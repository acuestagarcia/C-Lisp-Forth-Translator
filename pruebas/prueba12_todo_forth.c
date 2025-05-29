#include <stdio.h>

// variables globales para la prueba de factorial
int resultado ;
int n_fact ; 

// variable globales para la prueba de números pares e impares
int a ;
int b ;

//variable globales para la prueba de números primos
int primo ;
int n_primo ; 
int m ;
int d ;
int i ;
int p ;

// Variables para pruebas if/else
int x;
int y;

// Variables para pruebas de precedencia
int prec1, prec2, prec3, prec4;

main ()
{

    // --- PRUEBAS PRINT ---
    puts ("--- Pruebas Print --- ");

    // imprimir una expresión de número entero, un string y una variable
    resultado = 10; // Inicializar resultado para el print
    printf ("El texto no se imprime %d %s %d", 123+1, " el texto se imprime ", resultado) ;

    puts("");
    // --- PRUEBA WHILE (Factorial) ---
    puts ("--- Prueba Factorial de 5 (While) --- ");

    // imprime el factorial de 5 => 120
    n_fact = 5 ;
    resultado = 1 ;

    while (n_fact > 1) {
        resultado = resultado * n_fact ;
        n_fact = n_fact - 1 ;
    }
    printf("Factorial de 5: %d", resultado) ;

    puts("");
    // --- PRUEBAS WHILE + IF ELSE (Pares/Impares) ---
    puts ("--- Prueba Pares/Impares desde el número 5 decreciendo (While + If/Else) --- ");

    // imprime si los números del 5 al 1 son pares o impares
    a = 5 ;

    while (a > 0) {
        printf ("%d", a) ;
        if (a % 2 == 0) {
            puts (" es par ") ;
        } else {
            puts (" es impar ") ;
        }
        a = a - 1 ;
    }

    // --- PRUEBAS WHILE ANIDADO + IF (Números Primos) ---
    puts ("--- Prueba Números Primos del 1 al 30 (While anidado + If) --- ");

    // imprime todos los números primos del 1 al 30
    n_primo = 1 ; // n_primo no se usa realmente aquí, se podría quitar
    m = 30 ;

    i = 2 ;
    while (i < m) {
        primo = 1 ;
        d = 2 ;
        while (d < i) {
            if (i % d == 0) {   // check for right precedence
                primo = 0 ;
                // break; // Opcional: optimización para salir antes
            }
            d = d + 1 ;
        }

        if (primo != 0) {
            printf ("%d ", i) ;
        }
        i = i + 1 ;
    }

    puts("");
    // --- PRUEBAS IF / ELSE IF / ELSE ---
    puts ("--- Pruebas If / Else If / Else --- ");

    x = 10;
    y = 5;

    printf("", "(x es ", x, ") ");
    printf("", "(y es ", y, ") ");


    if (x > y * 2) {  
        puts("(x es mayor que el doble de y)");
    } else {
        if (x == y * 2) {
            puts("(x es igual al doble de y)");
        } else {
            puts("(x es menor que el doble de y)");
        }
    }

    x = 5;
    if (x < 0) {
        puts("(x es negativo)");
    } else {
        if (x == 0) {
         puts("(x es cero)");
        } else {
            puts("(x es positivo)");
        }
    }

    // --- PRUEBAS DE PRECEDENCIA DE OPERADORES ---
    puts ("--- Pruebas Precedencia Operadores. Debería ser True, True, 28 y True --- ");
    
    a = 5;
    b = 10;
    x = 2;
    y = 3;

    // Precedencia: *, +, ==
    prec1 = a + b * x == 25; // 5 + (10 * 2) == 25 -> 5 + 20 == 25 -> 25 == 25 -> -1 (true)
    printf("a + b * x == 25 : %d (Esperado en gforth: -1)", prec1);

    // Precedencia: %, +, <
    prec2 = b % y + a < 10; // (10 % 3) + 5 < 10 -> 1 + 5 < 10 -> 6 < 10 -> -1 (true)
    printf("b %% y + a < 10 : %d (Esperado en gforth: -1)", prec2);

    // Precedencia: *, /, + (* y / tienen la misma precedencia y son asociativos de izquierda a derecha)
    prec3 = a * b / x + y; // (5 * 10) / 2 + 3 -> 50 / 2 + 3 -> 25 + 3 -> 28
    printf("a * b / x + y : %d (Esperado en gforth: 28)", prec3);

    // Precedencia: operadores relacionales (misma precedencia: <, >, ==) y operadores booleanos (&& tiene más precedencia que ||) 
    prec4 = a < b && x > y || a == 5; // (5 < 10) && (2 > 3) || (5 == 5) -> true && false || true -> false || true -> -1 (true)
    printf("a < b && x > y || a == 5 : %d (Esperado en gforth: -1)", prec4);

}

//@(main)
