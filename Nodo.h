#pragma once
#include<stdlib.h>
#include<time.h>
#include "Lista.h"
#include <iostream>
using namespace std;

class CNodo
{
public:
	CNodo(int v, CNodo* sig = NULL, CNodo* ant = NULL) :
		valor(v), siguiente(sig), anterior(ant) {}
private:
	int valor;
	CNodo* siguiente;
	CNodo* anterior;
	friend class CLista; 
};
typedef CNodo* Nodo;