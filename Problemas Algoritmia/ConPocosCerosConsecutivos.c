/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
int CalCadBin(int N);
int main()
{
	int N, P;
	scanf("%d", &N);
	P = CalCadBin(N);
	printf("%d\n", P);
	return 0;
}
int CalCadBin(int N)
{
	if (N == 1)
	{
		return 2;
	}
	else if (N == 2)
	{
		return 4;
	}
	else if (N == 3)
	{
		return 7;
	}
	else
	{
		return CalCadBin(N - 1) + CalCadBin(N - 2) + CalCadBin(N - 3);
	}
}