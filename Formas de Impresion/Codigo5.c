// Código 05
//  Autor: AngelChetosmen
/*Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©*/
#include <stdio.h>
int main()
{
	int i, n, j, cont = 1; // Declaración de variables
	printf("Ingresa n: ");
	scanf("%d", &n); // Escaneo del valor de
					 // la variable n
	for (i = 1; i < 4 * n; i *= 2)
		for (j = i; j < 5 * n; j += 3)
		{
			cont++;
		}
	printf("%d -- Algoritmo\n", cont);
	return 0;
}