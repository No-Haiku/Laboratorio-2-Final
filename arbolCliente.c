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
        if(nuevo->dato.nroCliente < arbol->dato.nroCliente){
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
        if(nuevo->dato.nroCliente < arbol->dato.nroCliente){
            arbol->izq = agregarArbolClienteSinRepetidos(arbol->izq, nuevo);
        }else{
            if(nuevo->dato.nroCliente > arbol->dato.nroCliente){
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

nodoArbolCliente* buscaNodoArbolCliente(nodoArbolCliente* arbol, int nroCliente){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(arbol->dato.nroCliente == nroCliente){
            respuesta = arbol;
        }else{
            if(nroCliente < arbol->dato.nroCliente){
                respuesta = buscaNodoArbolCliente(arbol->izq, nroCliente);
            }else{
                respuesta = buscaNodoArbolCliente(arbol->der, nroCliente);
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

nodoArbolCliente* buscaNodoArbolClientePorApellido(nodoArbolCliente* arbol, char apellido[]){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(strcmp(apellido, arbol->dato.apellido)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorApellido(arbol->izq, apellido);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorApellido(arbol->der, apellido);
            }
        }
    }

    return respuesta;
}

nodoArbolCliente* buscaNodoArbolClientePorDni(nodoArbolCliente* arbol, char dni[]){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(strcmp(dni, arbol->dato.dni)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorDni(arbol->izq, dni);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorDni(arbol->der, dni);
            }
        }
    }

    return respuesta;
}

nodoArbolCliente* buscaNodoArbolClientePorDomicilio(nodoArbolCliente* arbol, char domicilio[]){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(strcmp(domicilio, arbol->dato.domicilio)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorDomicilio(arbol->izq, domicilio);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorDomicilio(arbol->der, domicilio);
            }
        }
    }

    return respuesta;
}

nodoArbolCliente* buscaNodoArbolClientePorEmail(nodoArbolCliente* arbol, char email[]){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(strcmp(email, arbol->dato.email)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorEmail(arbol->izq, email);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorEmail(arbol->der, email);
            }
        }
    }

    return respuesta;
}

nodoArbolCliente* buscaNodoArbolClientePorMovil(nodoArbolCliente* arbol, char movil[]){
    nodoArbolCliente* respuesta = NULL;
    if(arbol){
        if(strcmp(movil, arbol->dato.movil)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolClientePorMovil(arbol->izq, movil);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolClientePorMovil(arbol->der, movil);
            }
        }
    }

    return respuesta;
}
