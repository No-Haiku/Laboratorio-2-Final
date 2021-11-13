#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED
#include "consumo.h"

typedef struct _nodoLista{
	stConsumos dato;
	struct _nodoLista* sig;
}nodoLista;

nodo* inicLista();
nodo* crearNodo(stConsumos dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraNodo(nodo *nodo);
void muestraLista(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
stConsumos verPrimero(nodo* lista);
int cuentaLista(nodo* lista);
int sumaConsumos(nodo* lista);



#endif // LISTACONSUMO_H_INCLUDED
