/*
Compilación del programa: "gcc busquedaExponencial.c tiempo.c -o "nombre ejecutable"

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
#define MIN(n, m) ((n) < (m)) ? (n) : (m) // Macro para el minimo de 2 números
void busquedaBinaria(int *A, int inicio, int final, int numeroBuscado);

/*
Función busquedaExponencial
Recibe el arreglo donde se buscará el elemento a encontrar, el numero de elementos y el elemento a buscar
Se compara la primera posición del arreglo con el elemento a buscar, en caso de que sean iguales se retorna y termina la función. En caso de que sean diferentes se inicia por buscar el rango en potencias de 2 hasta encontrarlo, y se pasa el rango para realizar una busqueda binaria y continuar con el proceso de busqueda.*/
void busquedaExponencial(int *A, int n, int x)
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
    busquedaBinaria(A, i / 2, MIN(i, (n - 1)), x);
}

/*
Función busquedaBinaria
Recibe el arreglo donde se buscará el elemento a encontrar, el indice del inicio y fin del arreglo y el elemento a buscar
Se maneja una bandera que indica si ya se encontró el elemento buscado, entonces se inicia por marcar el medio del arreglo, como primera comparacion se tiene que es el medio con el valor a buscar, sino se pregunta si es mayor o menor el valor a buscar con respecto al medio, dependiendo de eso se va a actualizar el inicio o el final hasta que solo quede un elemento que puede ser o no nuestro elemento a buscar.
*/
void busquedaBinaria(int *A, int inicio, int final, int numeroBuscado)
{
    int encontrado = 0;
    while (encontrado == 0 && inicio < final)
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
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medicion de tiempos.

    // Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
    if (narg != 3)
    {
        printf("\nIntroduce una n y tu elemento a buscar");
        exit(1);
    }

    num = atoi(varg[1]); // ELEMENTO A BUSCAR
    n = atoi(varg[2]);   // TAMAÑO DEL PROBLEMA

    // Reservar memoria
    A = malloc(sizeof(int) * n);

    // Ciclo para leer las entradas
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Algoritmo de Busqueda Exponencial
    busquedaExponencial(A, n, num);

    //******************************************************************
    // Evaluar los tiempos de ejecucion
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    //(buscar == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", buscar);

    printf("%d---------------------------------------------------------------------------------\n", n);
    printf("%d---------------------------------------------------------------------------------", num);

    // Cálculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("\n");

    // Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("\n");
    //******************************************************************
    // Terminar programa normalmente
    exit(0);
}
