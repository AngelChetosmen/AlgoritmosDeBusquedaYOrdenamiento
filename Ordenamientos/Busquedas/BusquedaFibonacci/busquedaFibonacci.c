/*
Compilación del programa: "gcc busquedaFibonacci.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " num(numero a buscar) n(tamaño de la muestra donde se buscará)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos"
*/
/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
// Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*
Funcion busquedaFibonacci
La busqueda por Fibonacci consiste en encontrar el rango donde se encuentra el numero a buscar por medio de dos numeros de Fibonacci, esta busqueda que la hace diferente es que solo se hacen sumas o restas para encontrar el rango, despues se va aumentando o disminuyendo para ir encontrando el numero a buscar. Retorna la posicion del elemento en caso de encontrarse, y -1 en caso de no encontrarse dentro del arreglo
*/
int busquedaFibonacci(int *a, int x, int n)
{
    int inf = 0, pos, k;
    static int kk = -1, nn = -1;

    // Fibonacci Numeros
    static int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 98,
                        1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
                        514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817,
                        39088169, 63245986, 102334155, 165580141};

    if (nn != n)
    {
        k = 0;
        while (fib[k] < n) // Checamos numeros de la serie que se aproximen a nuestro numero buscado
            k++;
        kk = k;
        nn = n;
    }
    else
        k = kk;
    while (k > 0) // si k es mas grande que el valor en nuestra serie
    {
        pos = inf + fib[--k]; // checamos si la seccion del arreglo es una locacion valida
        if ((pos >= n) || (x < a[pos]))
            ;
        else if (x > a[pos]) // Si es major a nuestra posicion no nos sirve
        {
            inf = pos + 1;
            k--; // Reducimos k para acercar la busqueda
        }
        else
        {
            return pos; // Lo encontramos
        }
    }
    return -1; // Elemento no encontrado
}

//*****************************************************************
// PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)
{
    int n, num, buscar, *A;                                // Varibles auxiliares
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para la medición del tiempo

    // Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
    if (narg != 3)
    {
        printf("\nIntroduce una n y tu elemento a buscar");
        exit(1);
    }
    num = atoi(varg[1]); // ELEMENTO A BUSCAR
    n = atoi(varg[2]);   // TAMAÑO DEL PROBLEMA

    // Reservar Memoria
    A = malloc(sizeof(int) * n);

    // Ciclo para leer las entradas
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);
    // Algoritmo de Busqueda Fibonacci
    buscar = busquedaFibonacci(A, num, n);
    uswtime(&utime1, &stime1, &wtime1);
    // Finaliza el conteo de tiempo

    //(buscar == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", buscar);
    printf("%d---------------------------------------------------------------------------------\n", n);
    printf("%d---------------------------------------------------------------------------------", num);

    // Calculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("\n");

    // Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("\n\n");
    // //******************************************************************

    // Terminar programa normalmente
    exit(0);
}
