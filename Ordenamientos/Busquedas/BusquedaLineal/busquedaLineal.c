/*
Compilación del programa: "gcc busquedaLineal.c tiempo.c -o "nombre ejecutable"

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
Función busquedaLineal
Recibe el arreglo donde se buscará el elemento a encontrar, el numero de elementos y el elemento a buscar
La función va comparando mediante un recorrido con un ciclo for todo el arreglo hasta encontrar el elemento, en caso de que se encuentre se retorna el valor del elemento, en caso de que no retorna -1
*/
void busquedaLineal(int *A, int n, int numeroBuscado)
{
    int elemento = -1;
    for (int i = 0; i < n && elemento == -1; i++)
    {
        if (A[i] == numeroBuscado)
        {
            elemento = numeroBuscado;
        }
    }
}

//*****************************************************************
// PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)
{
    int n, num, buscar, *A;                                // Variables auxiliares
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medición del tiempo

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
    // Algoritmo de Busqueda Lineal
    busquedaLineal(A, n, num);
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
