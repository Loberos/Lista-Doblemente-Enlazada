#pragma once
#include "Nodo.h"
class CLista
{
public:
    CLista() : plista(NULL) {}
    ~CLista() {
        Nodo aux;
        Primero();
        while (plista) {
            aux = plista;
            plista = plista->siguiente;
            delete aux;
        }
    }
    void Agregar(int num);
    void Borrar(int num);
    bool ListaVacia(); 
    void Mostrar(int orden);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual(); 
    int ValorActual() { return plista->valor;}
private:
    Nodo plista;
};

void CLista::Agregar(int v){
    Nodo nuevo;
    Primero();
    if (ListaVacia() || plista->valor > v) {
        nuevo = new CNodo(v, plista);
        if (!plista) plista = nuevo;
        else plista->anterior = nuevo;
    }
    else {
        while (plista->siguiente && plista->siguiente->valor <= v) Siguiente();
        nuevo = new CNodo(v, plista->siguiente, plista);
        plista->siguiente = nuevo;
        if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
    }
}
void CLista::Borrar(int v){
    Nodo nodo;
    nodo = plista;
    while (nodo && nodo->valor < v) nodo = nodo->siguiente;
    while (nodo && nodo->valor > v) nodo = nodo->anterior;
    if (!nodo || nodo->valor != v) return;
    if (nodo->anterior) 
        nodo->anterior->siguiente = nodo->siguiente;
    if (nodo->siguiente)
        nodo->siguiente->anterior = nodo->anterior;
    delete nodo;
}
bool CLista::ListaVacia() { return plista == NULL; }
void CLista::Mostrar(int orden){
    Nodo nodo;
    if (orden == 1) {
        Primero();
        nodo = plista;
        while (nodo) {
            cout << nodo->valor << "-> ";
            nodo = nodo->siguiente;
        }
    }
    else {
        Ultimo();
        nodo = plista;
        while (nodo) {
            cout << nodo->valor << "-> ";
            nodo = nodo->anterior;
        }
    }
    cout << endl;
}
void CLista::Siguiente(){ if (plista) plista = plista->siguiente; }
void CLista::Anterior(){ if (plista) plista = plista->anterior; }
void CLista::Primero(){ while (plista && plista->anterior) plista = plista->anterior; }
void CLista::Ultimo(){ while (plista && plista->siguiente) plista = plista->siguiente; }
bool CLista::Actual() { return plista != NULL; }
