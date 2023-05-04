/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
// Declaraciones de typedef;
typedef long int ld;
// Declraciones de pequeños procesos y funciones para el D Y V;
ld CP(ld N);
ld B(ld inicio, ld final);
// Declaracion de variables globales;
ld num1, num2, A, B1;
ld R1, R2, R3, Ax, mitad;
// Declración y desarrollo de la función principal;
int main()
{
	// Declaracion de variables locales;
	// Inicio del algoritmo;
	// printf("\nIngrese en una linea los 4 numeros enteros positivos:\n");
	// printf("\n->:");
	scanf("%ld"
		  "%ld"
		  "%ld"
		  "%ld",
		  &num1, &num2, &A, &B1);
	// Impresion del proceso:
	printf("\n%ld", B(num1 + num2, 6LL * (num1 + num2)));
	return 0;
}
// Desarrollo de las funciones antes ya declaradas;
ld CP(ld N)
{
	// Implementacion de variables;
	R1 = N - (N / A);
	R2 = N - (N / A) - (N / B1) + (N / (A * B1));
	R3 = N - (N / B1);
	R3 -= R2;
	R1 -= R2;
	// Desarrollo de la funcion o proceso;
	// Primera fase de condiciones;
	if (R3 < num2)
	{
		R2 -= num2 - R3;
	}
	if (R2 < 0)
	{
		return 0;
	}
	// Segunda fse de condiciones;
	if (R1 < num1)
	{
		R2 -= num1 - R1;
	}
	if (R2 < 0)
	{
		return 0;
	}
	return 1;
}
ld B(ld inicio, ld final)
{
	// Implementacion de variables;
	mitad = (inicio + final) / 2;
	// Condicionales para la propuesta de recursion;
	if (inicio == final)
	{
		return inicio;
	}
	if (CP(mitad))
	{
		return B(inicio, mitad);
	}
	else
	{
		return B(mitad + 1, final);
	}
}