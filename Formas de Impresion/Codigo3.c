// Código 03
// Autor: AngelChetosmen
/*Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©*/
#include <stdio.h>
int main()
{
	int i, n, j, k, cont = 1; // Declaración de variables
	printf("Ingresa n: ");
	scanf("%d", &n); // Escaneo del valor de
					 // la variable n
	for (i = 0; i < n * 5; i += 2)
	{
		for (j = 0; j < 2 * n; j++)
		{
			for (k = j; k < n; k++)
			{

				cont++;
			}
		}
	}
	printf("%d -- Algoritmo\n", cont);
	return 0;
}