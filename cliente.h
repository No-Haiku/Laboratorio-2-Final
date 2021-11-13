#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int baja; /// 0 si est� activo - 1 si est� eliminado
} stCliente;
void muestraUnCliente(stCliente a);
int contarCantidadClientes(char nombreArchivo[]);

#endif // CLIENTE_H_INCLUDED

