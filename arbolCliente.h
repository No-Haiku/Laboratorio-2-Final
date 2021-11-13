#ifndef ARBOLPERSONA_H_INCLUDED
#define ARBOLPERSONA_H_INCLUDED

#include "cliente.h"

typedef struct _nodoArbolCliente{
    stCliente dato;
    struct _nodoArbolPersona* izq;
    struct _nodoArbolPersona* der;
}nodoArbolCliente;



typedef struct
{
    int id; /// campo único y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumos;



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
