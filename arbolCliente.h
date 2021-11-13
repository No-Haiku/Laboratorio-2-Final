#ifndef ARBOLPERSONA_H_INCLUDED
#define ARBOLPERSONA_H_INCLUDED

#include "cliente.h"
#include "listaConsumo.h"

typedef struct _nodoArbolCliente{
    stCliente dato;
    nodoLista* consumos;
    struct _nodoArbolPersona* izq;
    struct _nodoArbolPersona* der;
}nodoArbolCliente;






nodoArbolCliente* inicArbolCliente();
nodoArbolCliente* crearNodoArbolCliente(stCliente dato);
nodoArbolCliente* agregarArbolCliente(nodoArbolCliente* arbol, stCliente nuevo);
nodoArbolCliente* agregarArbolClienteSinRepetidos(nodoArbolCliente* arbol, nodoArbolCliente* nuevo);
void muestraUnCliente(stCliente a);
void preOrdenCliente(nodoArbolCliente* arbol);
void enOrdenCliente(nodoArbolCliente* arbol);
void postOrdenCliente(nodoArbolCliente* arbol);
nodoArbolCliente* buscaNodoArbolClientePorApellido(nodoArbolCliente* arbol, char apellido[]);
nodoArbolCliente* buscaNodoArbolClientePorDni(nodoArbolCliente* arbol, char dni[]);
nodoArbolCliente* buscaNodoArbolClientePorEmail(nodoArbolCliente* arbol, char email[]);
nodoArbolCliente* buscaNodoArbolClientePorDomicilio(nodoArbolCliente* arbol, char domicilio[]);
nodoArbolCliente* buscaNodoArbolClientePorMovil(nodoArbolCliente* arbol, char movil[]);
nodoArbolCliente* cargarArbolDesdeArchivo(char nombreArchivo[]);
#endif // ARBOLPERSONA_H_INCLUDED
