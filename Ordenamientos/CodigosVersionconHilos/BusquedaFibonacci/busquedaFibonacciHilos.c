/*
Compilación del programa: "gcc busquedaFibonacci.c tiempo.c -lpthread -o "nombre ejecutable -lpthread"

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

int *B, *A, z, N; // Variables Globales

// Prototipos
void *fibo(void *id);
int fibsearch(int *a, int x, int n);

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
		pos = inf + fib[--k]; // Checamos si la seccion del arreglo es una locacion valida
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

void *fibo(void *id)
{
	int *a, i, pos;
	a = malloc(sizeof(int) * (N));
	if ((long)id == 0)
	{
		for (i = 0; i < N; i++)
		{ // Lo dividimos en dos arreglos
			a[i] = A[i];
		}
	}
	else
	{
		for (i = 0; i < N; i++)
		{ // Segundo arreglo
			a[i] = B[i];
		}
	}
	pos = busquedaFibonacci(a, N, z); // Hagamos de nuevo la busqueda
}

int main(int argc, char *argv[])
{
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	pthread_t *hilos; // Variable para los hilos
	int x, n, num, k; // variables que ocupara nuestro algoritmo
	int long i;
	// Lectura del argumento de entrada para n
	if (argc != 3)
		exit(1);

	num = atoi(argv[1]);
	n = atoi(argv[2]);

	A = malloc(sizeof(int) * (n / 2));
	B = malloc(sizeof(int) * (n / 2));
	hilos = malloc(sizeof(pthread_t) * 2);
	N = n / 2;
	// Si no hay espacio salimos del programa
	if (A == NULL)
		exit(1);

	// Leer Numeros
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
	}
	// Inicio de conteo
	// Algoritmo de Busqueda Fibonacci con Hilos
	uswtime(&utime0, &stime0, &wtime0);
	for (i = 0; i < 2; i++)
	{
		pthread_create(&hilos[i], NULL, fibo, (void *)i);
	}

	for (i = 0; i < 2; i++)
	{
		pthread_join(hilos[i], NULL);
	}
	uswtime(&utime1, &stime1, &wtime1);

	// Finaliza el conteo de tiempo
	printf("%d---------------------------------------------------------------------------------\n", n);
	printf("%d---------------------------------------------------------------------------------", num);

	// Calculo del tiempo de ejecucion del programa
	printf("\n");
	printf("%.10f\n", wtime1 - wtime0);
	printf("\n");

	// Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("\n\n");
	// //******************************************************************

	// Terminar programa normalmente
	exit(0);
}
