// Burbuja Simple
/*
Compilación del programa: "gcc BurbujaSimple.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable "n (numeros a ordenar) >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos a ordenar"
*/
/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
// Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//*****************************************************************
// PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	// Reservar Memoria.
	int n, i, j, aux = 0;
	double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medicion de tiempos.

	n = atoi(argv[1]); // Se convierte en int el argumento y se asigna a n.

	int *A = (int *)malloc(sizeof(int) * n);

	// Ciclo para leer las entradas
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	//******************************************************************
	// Recepcion y decodificacion de argumentos
	//******************************************************************

	// Si no se introducen exactamente 2 argumentos (Cadena de ejecucion y cadena=n)
	if (argc != 2)
	{
		exit(1);
	}
	// Tomar el segundo argumento como tamanio del algoritmo
	else
	{
		n = atoi(argv[1]);
	}

	//******************************************************************
	// Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************

	//******************************************************************
	// Algoritmo ordenamiento burbuja simple
	//******************************************************************
	for (i = 0; i <= n - 2; i++)
	{
		for (j = 0; j <= n - 2; j++)
		{
			if (A[j] > A[j + 1])
			{
				aux = A[j];
				A[j] = A[j + 1];
				A[j + 1] = aux;
			}
		}
	}
	//******************************************************************

	//******************************************************************
	// Evaluar los tiempos de ejecucion
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	/*for(i = 0; i < n; i++)
	{
		printf("%d\n",A[i]);
	}*/
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

	// Terminar programa normalmente
	exit(0);
}
