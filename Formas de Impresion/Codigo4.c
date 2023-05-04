// Código 04
// Autor: AngelChetosmen
/*Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©*/
#include <stdio.h>

int main()
{
	int i, n, j, cont = 1; // Declaración de variables

	printf("Ingresa n: ");
	scanf("%d", &n); // Escaneo del valor de
					 // la variable n

	i = n;
	while (i >= 0)
	{
		for (j = n; i < j; i -= 2, j /= 2)
		{
			printf("%d -- Algoritmo\n", cont);
			cont++;
		}
	}
	return 0;
}