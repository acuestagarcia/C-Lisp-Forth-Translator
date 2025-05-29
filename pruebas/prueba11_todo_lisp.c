#include <stdio.h>

// Variables globales
int global_counter = 0;
int global_multiplier = 2;

factorial(int n) {
    int resultado = 1;
    int i;
    // Se incrementa global_counter en cada iteración para contar las multiplicaciones
    // Prueba el bloque "for"
    for (i = 1; i <= n; i=i+1) {
        resultado = resultado * i;
        global_counter = global_counter + 1;
    }
    return resultado;
}

test_if_else(int num) {
    // Prueba de precedencia de operadores
    if (num % 2 == 0) {
        puts("El número escogido es par.");
        return 1;  // Número par
    } else {
        puts("El número escogido es impar.");
        return 0;  // Número impar
    }
}

test_array() {
    puts("Vamos a declarar un vector y darle unos valores.");
    int vec[10];
    int i;
    // Inicialización: el vector toma múltiplos de 3
    // Prueba el bloque "for"
    for (i = 0; i < 10; i=i+1) {
        vec[i] = i * 3;
    }
    // Modificación de un elemento específico
    vec[5] = 42;
    puts("Contenido del vector:");
    for (i = 0; i < 10; i=i+1) {
        puts("");
        printf("vec[%d] = %d\n", i, " ", vec[i]);
    }
}

main() {
    puts("Prueba del traductor de C a Lisp");

    // Muestra el valor inicial de la variable global
    puts("Valor inicial de global_counter:");
    printf("Valor inicial de global_counter: ", global_counter);

    puts("For loop: ");
    int i;
    for (i = 0; i < 5; i=i+1) {
        puts("Iteración: ");
        printf("%d ", i);
    }

    int num = 7;
    puts("Número escogido: ");
    printf("Número: ", num);
    if (num > 0) {
        puts("El número de arriba es positivo.");
    } else {
        puts("El número de arriba es negativo o cero.");
    }
    puts("Global_multiplier = ");
    printf("%d", global_multiplier);
    int valor_local = num * global_multiplier;
    puts("Si multiplicamos el número escogido por el global_multiplier = ");
    printf("Valor local.", valor_local);

    if (test_if_else(num) == 1) {
        puts("Además, el número escogido es par.");
    } else {
        puts("Repito, el número escogido es impar.");
    }

    int n = 5;
    puts("Cambiemos al número: ");
    printf("%d", n);
    int fact = factorial(n);
    puts("Su factorial es: ");
    printf("El factorial de %d es %d", fact);

    test_array();

    // Uso adicional y actualización de la variable global
    global_counter = global_counter + 10;
    puts("Revisemos el valor de global_counter: ");
    printf("Revisemos el valor de global_counter: ", global_counter);

    // Prueba de todo en main
    int vector[5];
    vector[0] = 10;
    vector[1] = 20;
    vector[2] = factorial(3);  // Se espera 6
    vector[3] = num;
    vector[4] = (7 - 4 + 2 * 3);
    puts("Prueba con otro vector:");
    int i;
    for (i = 0; i < 5; i=i+1) {
        puts("");
        printf("vector[%d] = %d\n", "vector[", i, "] = ", vector[i]);
    }

    return 0;
}

//@(main)
