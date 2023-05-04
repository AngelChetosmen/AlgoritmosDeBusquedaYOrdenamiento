/*
Compilación del programa: "gcc busquedaArbolBinarioHilos.c tiempo.c -lpthread -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " num(numero a buscar) n(tamaño de la muestra donde se buscará)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos"
*
/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/ /
// Librerias utilizadas

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <pthread.h>
#include "tiempo.h"

	struct arbol
{
	int numero;				// Dato
	struct arbol *nodo_izq; // Hijo izquierdo
	struct arbol *nodo_der; // Hijo Derecho
};

// Prototipos
struct arbol *insertarNumeros(struct arbol *a, int num);
void busquedaArbolBinarioHijos(struct arbol *a, int numeroBuscado);
void busquedaArbolBinarioRaiz(struct arbol *a, int numeroBuscado);
void *funcionHiloArbolRaiz(void *a);
void *funcionHiloArbolHijos(void *a);

int encontrado, num; // Variables Globales

/*Función insertarNumeros
Recibe una estructura arbol y el numero entero a insertar en el arbol ABB
La función como primer camino crea un nodo con el numero a insertar en caso de ser nulo y retorna el nodo creado con el numero con sus respectivos hijos derecho e izquierdo, en caso de que no fuera nulo se compara si se colocará el numero entero a insertar en la izquierda(si fuera menor que el padre) o en la derecha (si fuera mayor que el padre)
*/
struct arbol *insertarNumeros(struct arbol *a, int num)
{
	if (a == NULL)
	{
		struct arbol *aux = NULL;
		aux = (struct arbol *)malloc(sizeof(struct arbol));
		aux->nodo_izq = NULL;
		aux->nodo_der = NULL;
		aux->numero = num;
		return aux;
	}
	if (num < (a->numero))
		a->nodo_izq = insertarNumeros(a->nodo_izq, num);
	else
		a->nodo_der = insertarNumeros(a->nodo_der, num);

	return a;
}

/*Función busquedaArbolBinarioHijos
Recibe una estructura árbol y el elemento a buscar dentro del árbol binario
La función crea una estructura árbol auxiliar que sirve para ir recorriendo el arbol binario que se pasa por parámetro, además se utiliza una variable "encontrado" para saber cuando ya se encontro el valor a buscar preguntando en primer lugar si la raiz es el numero a buscar, sino dependiendo si es mayor o menor el valor comparado con el dato de cada nodo se va a pasar al nodo izquierdo o derecho para repetir el proceso.
*/
void busquedaArbolBinarioHijos(struct arbol *a, int numeroBuscado)
{
	struct arbol *aux = a;
	encontrado = 0;
	while (aux != NULL && encontrado == 0)
	{
		if (numeroBuscado == aux->numero)
		{
			encontrado = 1;
		}
		else if (numeroBuscado < aux->numero)
		{
			aux = aux->nodo_izq;
		}
		else if (numeroBuscado > aux->numero)
		{
			aux = aux->nodo_der;
		}
	}
}

/*
Función busquedaArbolBinarioRaiz
Recibe una estructura árbol y el elemento a buscar dentro del árbol binario
La función se encarga de ir buscando el elemento solamente en la raiz para cambiar la bandera de "encontrado"
*/
void busquedaArbolBinarioRaiz(struct arbol *a, int numeroBuscado)
{
	struct arbol *aux = a;
	encontrado = 0;
	if (aux != NULL)
	{
		if (numeroBuscado == aux->numero)
		{
			encontrado = 1;
		}
	}
}

/*
Función funcionHiloArbolRaiz
La función llama a la función de busquedaArbolBinarioRaiz para que el hilo la haga en pararelo junto con los otros
*/
void *funcionHiloArbolRaiz(void *a)
{
	busquedaArbolBinarioRaiz((struct arbol *)a, num);
}

/*
Función funcionHiloArbolHijos
La función llama a la función de busquedaArbolBinarioHijos para que los dos hilos, uno busque en el hijo izquierdo y otro en el hijo derecho de manera pararelo junto con los otros
*/
void *funcionHiloArbolHijos(void *a)
{
	busquedaArbolBinarioHijos((struct arbol *)a, num);
}

int main(int narg, char **varg)
{
	int n, *numeros, buscar;							   // Variables auxiliares
	double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medir el tiempo
	pthread_t hilos1, hilos2, hilos3;					   // Se crean tres hilos
	struct arbol *a = NULL;								   // Se crea el arbol

	// Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
	if (narg != 3)
	{
		exit(1);
	}
	num = atoi(varg[1]); // Elemento a buscar

	n = atoi(varg[2]); // Tamaño del problema

	numeros = (int *)malloc(sizeof(int) * n);
	// Ciclo para leer las entradas y para insertar los elementos al arbol binario
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numeros[i]);
	}
	for (int i = 0; i < n; i++)
	{
		a = insertarNumeros(a, numeros[i]);
	}

	uswtime(&utime0, &stime0, &wtime0);
	// Algoritmo de Busqueda en Arbol Binario de Busqueda con Hilos
	if (pthread_create(&hilos1, NULL, funcionHiloArbolRaiz, (void *)a) != 0)
	{
		perror("El thread 1 no  pudo crearse");
		exit(-1);
	}

	if (pthread_create(&hilos2, NULL, funcionHiloArbolHijos, (void *)a->nodo_izq) != 0)
	{
		perror("El thread 2 no  pudo crearse");
		exit(-1);
	}

	if (pthread_create(&hilos3, NULL, funcionHiloArbolHijos, (void *)a->nodo_der) != 0)
	{
		perror("El thread 3 no  pudo crearse");
		exit(-1);
	}

	pthread_join(hilos1, NULL);
	pthread_join(hilos2, NULL);
	pthread_join(hilos3, NULL);
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
	//******************************************************************
	// Terminar programa normalmente
	exit(0);
}
