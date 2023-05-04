// Código 02
// Autor: AngelChetosmen
/*Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©*/
#include <stdio.h>

int main()
{
	int i, n, j, cont = 1; // Declaración de variables
	printf("Ingresa n: "); // Escaneo del valor de la variable n
	scanf("%d", &n);

	// Ciclos y condición para las "n"
	// impresiones de la palabra "Algoritmo"
	for (j = n; j > 1; j /= 2)
	{
		if (j < (n / 2))
		{
			for (i = 0; i < n; i += 2)
			{
				printf(" %d -- Algoritmo\n", cont);
				cont++;
			}
		}
	}
	return 0;
}