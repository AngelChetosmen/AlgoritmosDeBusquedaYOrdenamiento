/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

int busquedaBinaria(int *A, int inicio, int final, int numeroBuscado);
int busquedaExponencial(int *A, int n, int x)
{
    // Verificar el primer lugar del arreglo
    if (A[0] == x)
        return A[0];
    int i = 1;
    // Encontrar el rango donde deberia de estar el numero
    while ((i < n) && (A[i] <= x))
    {
        i *= 2;
    }
    return busquedaBinaria(A, i / 2, min(i, (n - 1)), x);
}

int busquedaBinaria(int *A, int inicio, int final, int numeroBuscado)
{
    int elemento = -1;
    int encontrado = 0;
    while (encontrado == 0 && inicio < final)
    {
        int medio = (inicio + final) / 2;
        if (A[medio] == numeroBuscado)
        {
            elemento = numeroBuscado;
            encontrado = 1;
        }

        else if (A[medio] < numeroBuscado)
        {
            inicio = medio + 1;
        }

        else if (A[medio] > numeroBuscado)
        {
            final = medio - 1;
        }
    }
    return elemento;
}

int main(int narg, char **varg)
{
    int n, num, x;
    int *A;
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medicion de tiempos.

    if (narg != 3)
    {
        printf("\nIntroduce una n y tu elemento a buscar");
        exit(1);
    }
    num = atoi(varg[1]); // ELEMENTO A BUSCAR

    n = atoi(varg[2]); // TAMAÑO DEL PROBLEMA

    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************

    A = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int buscar;

    buscar = busquedaExponencial(A, n, x);
    (buscar == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", buscar);

    //******************************************************************
    // Evaluar los tiempos de ejecucion
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);

    printf("%d---------------------------------------------------------------------------------", n);
    // Cálculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciones de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    // Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    printf("sys (Tiempo en acciones de E/S)  %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
    //******************************************************************

    return 0;
}
