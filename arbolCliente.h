#ifndef ARBOLPERSONA_H_INCLUDED
#define ARBOLPERSONA_H_INCLUDED

#include "cliente.h"

typedef struct _nodoArbolCliente{
    stCliente dato;
    struct _nodoArbolPersona* izq;
    struct _nodoArbolPersona* der;
}nodoArbolCliente;



nodoArbolCliente* inicArbolCliente();
nodoArbolCliente* crearNodoArbolCliente(stPersona dato);
nodoArbolCliente* agregarArbolCliente(nodoArbolPersona* arbol, nodoArbolCliente* nuevo);
nodoArbolCliente* agregarArbolClienteSinRepetidos(nodoArbolCliente* arbol, nodoArbolCliente* nuevo);
void preOrdenCliente(nodoArbolCliente* arbol);
void enOrdenCliente(nodoArbolCliente* arbol);
void postOrdenCliente(nodoArbolCliente* arbol);
nodoArbolCliente* buscaNodoArbolClientePorApellido(nodoArbolCliente* arbol, char apellido[]);
nodoArbolCliente* buscaNodoArbolClientePorDni(nodoArbolCliente* arbol, char dni[]);
nodoArbolCliente* buscaNodoArbolClientePorEmail(nodoArbolCliente* arbol, char email[]);
nodoArbolCliente* buscaNodoArbolClientePorDomicilio(nodoArbolCliente* arbol, char domicilio[]);
nodoArbolCliente* buscaNodoArbolClientePorMovil(nodoArbolCliente* arbol, char movil[]);

#endif // ARBOLPERSONA_H_INCLUDED
