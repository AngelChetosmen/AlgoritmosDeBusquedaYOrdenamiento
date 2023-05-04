/*
Compilación del programa: "gcc busquedaBinaria.c tiempo.c -o "nombre ejecutable"

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
Función busquedaBinaria
Recibe el arreglo donde se buscará el elemento a buscar, el indice del inicio y fin del arreglo y el elemento a buscar
Se maneja una bandera que indica si ya se encontró el elemento buscado, entonces se inicia por marcar el medio del arreglo, como primera comparacion se tiene que es el medio con el valor a buscar, sino se pregunta si es mayor o menor el valor a buscar con respecto al medio, dependiendo de eso se va a actualizar el inicio o el final hasta que solo quede un elemento que puede ser o no nuestro elemento a buscar. Retorna -1 si no se encontró el elemento y en caso de que se haya encontrado retorna el valor del elemento
*/
void busquedaBinaria(int *A, int inicio, int final, int numeroBuscado)
{
    int encontrado = 0;
    while (encontrado == 0 && inicio <= final)
    {
        int medio = (inicio + final) / 2;
        if (A[medio] == numeroBuscado)
        {
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
}

//*****************************************************************
// PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)
{
    int n, num, buscar, *A;                                // Variables auxiliares
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medir el tiempo

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
    // Algoritmo de Busqueda Binaria
    busquedaBinaria(A, 0, n - 1, num);
    uswtime(&utime1, &stime1, &wtime1);
    // Finaliza el conteo de tiempo

    //(buscar == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", buscar);
    printf("%d---------------------------------------------------------------------------------\n", n);
    printf("%d---------------------------------------------------------------------------------", num);

    // Calculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("\n");
    printf("%.10f\n", wtime1 - wtime0);
    // Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("\n\n");
    // //******************************************************************
    // Terminar programa normalmente
    exit(0);
}
