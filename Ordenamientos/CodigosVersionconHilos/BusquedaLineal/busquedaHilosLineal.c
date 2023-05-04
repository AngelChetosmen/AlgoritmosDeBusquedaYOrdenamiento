/*
Compilación del programa: "gcc busquedaLinealHilos.c tiempo.c -lpthread -o "nombre ejecutable "

Ejecución del programa: "nombre ejecutable " num(numero a buscar) n(tamaño de la muestra donde se buscará)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos"
*/
/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
// Librerias utilizadas
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "tiempo.h"

int n, num, elemento = -1; // Variables globales

/*
Función busquedaLineal
Recibe el arreglo donde se buscará el elemento a encontrar, el numero de elementos y el elemento a buscar
La función va comparando mediante un recorrido con un ciclo for todo el arreglo hasta encontrar el elemento.
*/
void busquedaLineal(int *A, int n, int numeroBuscado)
{
	for (int i = 0; (i < n) && (elemento == -1); i++)
	{
		if (A[i] == numeroBuscado)
		{
			elemento = numeroBuscado;
		}
	}
}

/*
FuncionHiloBusquedaLineal
La función llama a la función de busquedaLineal para que un hilo  lo haga en la primera mitad del arreglo y el segundo lo haga en la segunda mitad en pararelo
*/
void *funcionHiloBusquedaLineal(void *A)
{
	busquedaLineal((int *)A, n, num);
}

int main(int narg, char **varg)
{
	int i, *primerMedio, *segundoMedio, *A, medio, j;	   // Variables auxiliares
	double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medición de tiempos
	pthread_t hilos1, hilos2;							   // Se crean dos hilos

	// Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
	if (narg != 3)
	{
		printf("\nIntroduce una n y tu elemento a buscar");
		exit(1);
	}

	num = atoi(varg[1]); // ELEMENTO A BUSCAR
	n = atoi(varg[2]);	 // TAMAÑO DEL PROBLEMA
	medio = n / 2;		 // Se obtiene la mitad

	// Reservar Memoria
	A = malloc(sizeof(int) * n);
	primerMedio = malloc(sizeof(int) * n);
	segundoMedio = malloc(sizeof(int) * n);

	// Ciclos para leer las entradas
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	for (i = 0; i <= medio; ++i)
	{
		*(primerMedio + i) = *(A + i);
	}
	i = 0;

	for (j = medio + 1; j < n; ++j, i++)
	{
		*(segundoMedio + i) = *(A + j);
	}

	// Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	// Algoritmo de Busqueda Lineal con Hilos
	uswtime(&utime0, &stime0, &wtime0);
	// Errores en caso de que los hilos no se puedan crear
	if (pthread_create(&hilos1, NULL, funcionHiloBusquedaLineal, (void *)primerMedio) != 0)
	{
		perror("El thread 1 no  pudo crearse");
		exit(-1);
	}
	if (pthread_create(&hilos2, NULL, funcionHiloBusquedaLineal, (void *)segundoMedio) != 0)
	{
		perror("El thread 2 no  pudo crearse");
		exit(-1);
	}
	// Algoritmo de Busqueda Lineal en cada mitad
	pthread_join(hilos1, NULL);
	pthread_join(hilos2, NULL);
	uswtime(&utime1, &stime1, &wtime1);
	// Finaliza el conteo de tiempo

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
