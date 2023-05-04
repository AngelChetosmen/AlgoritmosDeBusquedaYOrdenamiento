/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Declaracion de un typedef para evitar la repeticion;
typedef long long int ld;
// Declaracion de las pequeñas funciones usadas para el D Y V.

long int MaxiDos(ld a1, ld b1);
long int MaximaSumaCross(ld *A1, ld L, ld M, ld R);
long int MaxiTres(ld a1, ld b1, ld c1);
long int MaximaSum(ld *A1, ld L, ld R);

// Implementacion del D y V;
int main()
{
	// Declaracion de variables "locales";
	ld N, j, y;
	scanf("%lld", &N);
	ld *A1 = (ld *)malloc(N * sizeof(ld));
	// Aplicacion;
	for (j = 0; j < N; j++)
	{
		scanf("%lld", &A1[j]);
	}
	y = MaximaSum(A1, 0, N - 1);
	printf("%ld\n", y);
	return 0;
}

// Desarrollo de las pequeñas D Y V declaradas;
long int MaxiDos(ld a1, ld b1)
{
	return (a1 > b1) ? a1 : b1;
}

long int MaximaSumaCross(ld *A1, ld L, ld M, ld R)
{

	ld Sum = 0, j;
	ld SumIzq = INT_MIN;
	for (j = M; j >= L; j--)
	{
		Sum = Sum + A1[j];
		if (Sum > SumIzq)
		{
			SumIzq = Sum;
		}
	}
	Sum = 0;
	// Ahora para la parte derecha;
	ld SumDer = INT_MIN;
	for (j = M + 1; j <= R; j++)
	{
		Sum = Sum + A1[j];
		if (Sum > SumDer)
		{
			SumDer = Sum;
		}
	}
	return MaxiTres(SumIzq + SumDer, SumIzq, SumDer);
}

long int MaxiTres(ld a1, ld b1, ld c1)
{
	return MaxiDos(MaxiDos(a1, b1), c1);
}

long int MaximaSum(ld *A1, ld L, ld R)
{
	if (L == R)
	{
		return A1[L];
	}
	ld M = (L + R) / 2;
	return MaxiTres(MaximaSum(A1, L, M), MaximaSum(A1, M + 1, R),
					MaximaSumaCross(A1, L, M, R));
}