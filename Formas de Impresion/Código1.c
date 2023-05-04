// Código 01
// Autor: AngelChetosmen
/*Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©*/
#include <stdio.h>
int main()
{
	int i, n, cont = 1; // Declaración de variables
	printf("Ingresa n: ");
	scanf("%d", &n); // Escaneo del valor de la variable n
	for (i = 10; i < n * 5; i *= 2)
	{ // Ciclo para las "n" impresiones de la palabra "Algoritmo"
		printf(" %d -- Algoritmo\n", cont);
		cont++;
	}
	return 0;
}