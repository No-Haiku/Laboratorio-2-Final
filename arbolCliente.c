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

nodoArbolCliente* agregarArbolCliente(nodoArbolCliente* arbol, stCliente nuevo){
    if(arbol==NULL){
        arbol = crearNodoArbolCliente(nuevo);
    }else{
        if(nuevo.id < arbol->dato.id){
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

void postOrdenCliente(nodoArbolCliente* arbol){
    if(arbol){
        postOrdenCliente(arbol->izq);
        postOrdenCliente(arbol->der);
        muestraNodoArbolCliente(arbol);
    }
}

void muestraNodoArbolCliente(nodoArbolCliente* nodo){
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
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

nodoArbolCliente* cargarArbolDesdeArchivo(char nombreArchivo[])
{
    FILE* archivo;
    //Creamos una stProducto auxiliar para cargar los datos del archivo
    stCliente aux;
    nodoArbolCliente* arbol;
    arbol = inicArbolCliente(arbol);
    //Primero contamos la cantidad de productos que hay en el archivo para poder distribuir bien los datos en el arbol
    int cantClientes = contarCantidadClientes(nombreArchivo);
    //Dividimos la cantidad de productos por 2 para poner un numero intermedio en la raiz
    cantClientes = cantClientes  / 2;

    archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL)
    {
        //Movemos el cursor hacia la mitad del archivo
        fseek(archivo, (cantClientes  * sizeof(stCliente)), SEEK_SET);
        //Pasamos del archivo al auxiliar
        fread(&aux, sizeof(stCliente), 1, archivo);
        //Ingresamos el producto en el arbol
        arbol = agregarArbolCliente(arbol, aux);
        //Volvemos al principio del archivo
        rewind(archivo);
        //Cargamos los numeros impares
        while(fread(&aux, sizeof(stCliente), 1, archivo) > 0)
        {
            //Verifica si la id del producto es impar y si no es la misma que ya esta cargada en la raiz
            if(aux.id %2 == 1 && aux.id != arbol->dato.id)
            {
                arbol = agregarArbolCliente(arbol, aux);
            }
        }
        //Volvemos otra vez al inicio
        rewind(archivo);
        //Ahora cargamos los numeros pares
        while(fread(&aux, sizeof(stCliente), 1, archivo) > 0)
        {
            //Verifica si la id del producto es par y si no es la misma que ya esta cargada en la raiz
            if(aux.id %2 == 0 && aux.id != arbol->dato.id)
            {
                arbol = agregarArbolCliente(arbol, aux);
            }
        }
    }
    else
        printf("\nError al abrir el archivo %s (cargarArbolDesdeArchivo)", nombreArchivo);
    return arbol;
}
