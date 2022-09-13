#include "pch.h"
#include <conio.h>
#include "Lista.h"
using namespace System;
#define ASCENDENTE 1
#define DESCENDENTE 0
int main()
{
	srand(time(NULL)); 
    CLista *lista = new CLista(); 
	for (int i = 0; i < 5; i++)
	{
		lista->Agregar(rand() % 12); 
	}
	lista->Mostrar(ASCENDENTE);
	lista->Mostrar(DESCENDENTE);

	lista->Primero(); 
	cout << "El primer elemento: " << lista->ValorActual() << endl;

	lista->Ultimo();
	cout << "El ultimo elemento: " << lista->ValorActual() << endl;

	lista->Borrar(4);
	lista->Borrar(3);
	lista->Borrar(1);
	lista->Borrar(2);

	lista->Mostrar(ASCENDENTE);
	lista->Mostrar(DESCENDENTE);

	_getch(); 
	return 0;
}
