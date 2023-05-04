/*
Compilación del programa: "gcc busquedaExponencialHilos.c tiempo.c -lpthread -o "nombre ejecutable"

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
#define MIN(n, m) ((n) < (m)) ? (n) : (m) // Macro para el minimo de 2 números
void busquedaBinaria(int *A, int inicio, int final, int numeroBuscado);
void *funcionHiloBusquedaBinaria(void *A);
int num, n, aux, mitadExponencial, inicio, encontrado = 0;
; // Variables globales

/*
FuncionHiloBusquedaBinaria
La función llama a la función de busquedaBinaria para que un hilo  lo haga en la primera mitad del  nuevo arreglo reducido y el segundo lo haga en la segunda mitad del nuevo arreglo reducido en pararelo
*/
void *funcionHiloBusquedaBinaria(void *A)
{
	busquedaBinaria((int *)A, inicio, aux, num);
}

/*
Función busquedaExponencial
Recibe el arreglo donde se buscará el elemento a encontrar, el numero de elementos y el elemento a buscar
Se compara la primera posición del arreglo con el elemento a buscar, en caso de que sean iguales se retorna y termina
la función. En caso de que sean diferentes se inicia por buscar el rango en potencias de 2 hasta encontrarlo, y se pasa el rango para realizar una busqueda binaria y continuar con el proceso de busqueda.*/
void busquedaExponencial(int *A, int n, int x)
{
	// Verificar el primer lugar del arreglo
	int *primeraMitad, *segundaMitad, j, k; // Variables auxiliares
	pthread_t hilos3, hilos4;				// Hilos para la busqueda binaria
	if (A[0] == x)
		encontrado == 1;
	int i = 1;
	// Encontrar el rango donde deberia de estar el numero
	while ((i < n) && (A[i] <= x) && encontrado == 0)
	{
		i *= 2;
	}
	if (encontrado == 0)
	{
		aux = MIN(i, (n - 1));					// Final
		mitadExponencial = ((i / 2) + aux) / 2; // Mitad
		inicio = i / 2;							// Inicio

		// Reservar memoria
		primeraMitad = malloc(sizeof(int) * n);
		segundaMitad = malloc(sizeof(int) * n);

		// Se llenan los dos nuevos arreglos para la busqueda binaria
		for (j = inicio; j <= mitadExponencial; ++j)
		{
			*(primeraMitad + j) = *(A + j);
		}
		j = 0;

		for (k = mitadExponencial + 1; k < n; ++k, j++)
		{
			*(segundaMitad + j) = *(A + k);
		}

		// Errores en caso de que no se puedan crear los hilos
		if (pthread_create(&hilos3, NULL, funcionHiloBusquedaBinaria, (void *)primeraMitad) != 0)
		{
			perror("El thread 3 no  pudo crearse");
			exit(-1);
		}
		if (pthread_create(&hilos4, NULL, funcionHiloBusquedaBinaria, (void *)segundaMitad) != 0)
		{
			perror("El thread 4 no  pudo crearse");
			exit(-1);
		}
		// Algoritmo de Busqueda Binaria en cada mitad
		pthread_join(hilos3, NULL);
		pthread_join(hilos4, NULL);
	}
}

/*
Función funcionHiloBusquedaExponencial
La función llama a la función de busquedaExponencial para que los dos hilos, uno busque en la primera mitad del arreglo original y el segundo busque en la segunda mitad del arreglo original en pararelo
*/
void *funcionHiloBusquedaExponencial(void *A)
{
	busquedaExponencial((int *)A, n, num);
}

/*
Función busquedaBinaria
Recibe el arreglo donde se buscará el elemento a buscar, el indice del inicio y fin del arreglo y el elemento a buscar
Se maneja una bandera que indica si ya se encontró el elemento buscado, entonces se inicia por marcar el medio del arreglo, como primera comparacion se tiene que es el medio con el valor a buscar, sino se pregunta si es mayor o menor el valor a buscar con respecto al medio, dependiendo de eso se va a actualizar el inicio o el final hasta que solo quede un elemento que puede ser o no nuestro elemento a buscar.
*/
void busquedaBinaria(int *A, int inicio, int final, int numeroBuscado)
{
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

	// Se llenan los dos nuevos arreglos
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
	// Algoritmo de Busqueda Exponencial con Hilos
	uswtime(&utime0, &stime0, &wtime0);
	// Errores en caso de que los hilos no se puedan crear
	if (pthread_create(&hilos1, NULL, funcionHiloBusquedaExponencial, (void *)primerMedio) != 0)
	{
		perror("El thread 1 no  pudo crearse");
		exit(-1);
	}
	if (pthread_create(&hilos2, NULL, funcionHiloBusquedaExponencial, (void *)segundoMedio) != 0)
	{
		perror("El thread 2 no  pudo crearse");
		exit(-1);
	}
	// Algoritmo de Busqueda Binaria en cada mitad
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
