#include "pch.h"
#include <iostream>
#include "node.cpp"
#include "convertToBase.cpp"
using namespace winrt;
using namespace Windows::Foundation;

/*
Realice un algoritmo que reciba como parámetro dos números enteros y retorne la
división de ambos números.(poner en la respuesta link del repositorio (rama o commit)
*/

int divition(int a, int b);
void cases();


/*
* Un árbol es una estructura recursiva compuesta de dos elementos: una raíz y subárboles. 
Una raíz es un árbol, un subárbol es un árbol. Un árbol de peso es el aquel que cada uno de sus elementos tiene un peso, por ejemplo:
*/

int main()
{
	init_apartment();
	cases();
}

//Puede ser Entero pero regularmente se usan flotantes
int divition(int a, int b)
{
	if (a < 0 || b < 0)
	{
		return printf("El Numero debe ser > 0");
	}
	return a / b;
}

void cases() {

	int a;
	printf("Que Ejercicio desea probar: ");	
	printf("1. Divicion de dos numeros\n");
	printf("2. Numero que recibe base y devuelve expresion\n");
	printf("3. Arboles\n");
	scanf_s("%d", &a);

	int num1, num2, res;
	switch (a)
	{
	case 1:
		printf("Ingrese el primer numero: ");
		scanf("%d", &num1);
		printf("Ingrese el segundo numero: ");
		scanf("%d", &num2);
		res = divition(num1, num2);
		printf("El resultado de la divicion es: %d", res);
		break;
	case 2: {
		int num, base;
		printf("Ingrese el numero: ");
		scanf("%d", &num);
		printf("Ingrese la base: ");
		scanf("%d", &base);
		printf("El resultado de la conversion es: %s", convertToBase(num, base));
		break;
	}
	case 3: {
		auto root = create_tree();
		printf("El peso total del arbol es: %d", root->get_weight());
		printf("El numero total de nodos en el arbol es: %d", root->total_nodes());
		printf("El peso promedio de los nodos en el arbol es: %f", root->average_weight());
		break;
	}
	default:
		break;
	}

}
