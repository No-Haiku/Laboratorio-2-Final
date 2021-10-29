#include <stdio.h>
#include <stdlib.h>
#include "arbolCliente.h"


nodoArbolCliente* inicArbolCliente(){
    return NULL;
}

nodoArbolCliente* crearNodoArbolCliente(stCliente dato){
    nodoArbolCliente* nuevo = (nodoArbolCliente*)malloc(sizeof(nodoArbolCliente));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbolCliente* agregarArbolCliente(nodoArbolCliente* arbol, nodoArbolCliente* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.legajo < arbol->dato.legajo){
            arbol->izq = agregarArbolCliente(arbol->izq, nuevo);
        }else{
            arbol->der = agregarArbolCliente(arbol->der, nuevo);
        }
    }

    return arbol;
}

nodoArbolCliente* agregarArbolClienteSinRepetidos(nodoArbolCliente* arbol, nodoArbolCliente* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.legajo < arbol->dato.legajo){
            arbol->izq = agregarArbolClienteSinRepetidos(arbol->izq, nuevo);
        }else{
            if(nuevo->dato.legajo > arbol->dato.legajo){
                arbol->der = agregarArbolClienteSinRepetidos(arbol->der, nuevo);
            }
        }
    }

    return arbol;
}

void preOrdenCliente(nodoArbolCliente* arbol){
    if(arbol){
        muestraNodoArbolCliente(arbol);
        preOrdenCliente(arbol->izq);
        preOrdenCliente(arbol->der);
    }
}

void enOrdenCliente(nodoArbolCliente* arbol){
    if(arbol){
        enOrdenCliente(arbol->izq);
        muestraNodoArbolCliente(arbol);
        enOrdenCliente(arbol->der);
    }
}

void postOrdenPersona(nodoArbolPersona* arbol){
    if(arbol){
        postOrdenPersona(arbol->izq);
        postOrdenPersona(arbol->der);
        muestraNodoArbolPersona(arbol);
    }
}

void muestraNodoArbolCliente(nodoArbolPersona* nodo){
    muestraUnCliente(nodo->dato);///CREAR ESTA FUNCION<<<<<<<<<<<<<-----------
}

nodoArbolCliente* buscaNodoArbolCliente(nodoArbolCliente* arbol, int legajo){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(arbol->dato.legajo == legajo){
            respuesta = arbol;
        }else{
            if(legajo < arbol->dato.legajo){
                respuesta = buscaNodoArbolCliente(arbol->izq, legajo);
            }else{
                respuesta = buscaNodoArbolCliente(arbol->der, legajo);
            }
        }
    }

    return respuesta;
}

nodoArbolCliente* buscaNodoArbolClientePorNombre(nodoArbolCliente* arbol, char nombre[]){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(strcmp(nombre, arbol->dato.nombre)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorNombre(arbol->izq, nombre);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorNombre(arbol->der, nombre);
            }
        }
    }

    return respuesta;
}
