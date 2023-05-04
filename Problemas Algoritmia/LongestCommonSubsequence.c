/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Declaracion de macrodefiniciones,typedef y/o variables globales;
typedef int d;
// Definición de peququeñas funciones y procesos del código y algoritmo;
d MAX(d A, d B);
d SCL(char *X, char *Y, d n, d m);
// Declaración y desarrollo de la funcion principal del algoritmo;
d main()
{
	char *X, *Y;
	X = malloc(1000 * sizeof(char));
	Y = malloc(1000 * sizeof(char));
	// Declaración de los punteros;
	scanf("%s"
		  "%s",
		  X, Y);
	d m = strlen(X), n = strlen(Y), Z;
	Z = SCL(X, Y, m, n);
	printf("%d", Z);
	return 0;
}
// Desarrollo de las pequeñas funciones o procesos del algoritmo;
// implementacion de la función recursiva que hará la DP;
d MAX(d A, d B)
{
	return (A > B) ? A : B;
}
d SCL(char *X, char *Y, int m, int n)
{
	d i, j, S[m + 1][n + 1];
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				S[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				S[i][j] = S[i - 1][j - 1] + 1;
			}
			else
			{
				S[i][j] = MAX(S[i - 1][j], S[i][j - 1]);
			}
		}
	}
	return S[m][n];
}