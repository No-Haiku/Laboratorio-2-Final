#include "cliente.h"
void muestraUnCliente(stCliente a)
{

    printf("ID -%d-\n",a.id);
    printf("Numero de cliente: %d\n",a.nroCliente);
    printf("Nombre: %s\n",a.nombre);
    printf("Apellido: %s\n",a.apellido);
    printf("D.N.I: %s\n",a.dni);
    printf("Email: %s\n",a.email);
    printf("Domicilio: %s\n",a.domicilio);
    printf("Movil: %s\n",a.movil);
    printf("Estado %d\n",a.baja);
}


///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int contarCantidadClientes(char nombreArchivo[])
{
    FILE* archivo;
    int contador = 0;
    stCliente cliente;

    archivo = fopen(nombreArchivo, "rb");
    //Si el archivo no es nulo
    if(archivo)
    {
        while(fread(&cliente, sizeof(stCliente), 1, archivo) > 0)
        {
            //Contamos cada producto que haya en el archivo
            contador++;
        }
        fclose(archivo);
    }
    else
        printf("\nError al abrir el archivo %s (contarCantidadProductos)", nombreArchivo);

    return contador;
}
