#include <stdio.h>
#include <stdlib.h>
#include "consumo.h"

void muestraUnConsumo(stConsumos a)
{
    printf("ID -%d-\n",a.id);
    printf("Numero de cliente: %d\n",a.idCliente);
    printf("Anio: %d\n",a.anio);
    printf("Mes: %d\n",a.mes);
    printf("Dia: %d\n",a.dia);
    printf("Datos consumidos %d mb\n",a.datosConsumidos);
    printf("Estado %d\n",a.baja);
}

///CARGA CONSUMOS
void cargaDatosConsumo(char archivoConsumo[],stCliente b)
{
    char opcion=0;
    stConsumos a;
    int dato=0;
    int validos=cuentaRegistros(archivoConsumo, sizeof(stConsumos));

    FILE *archi=fopen(archivoConsumo,"a+b");
    int flag=0;
    int mesesDiasCuenta;
    if(archi)
    {
        while(opcion!=27)
        {   system("cls");
            a.idCliente=b.nroCliente;
            printf("Ingrese anio de consumo \n");
            scanf("%d",&a.anio);
            if(a.anio>ANIO_ACTUAL)
            {
                while(a.anio>ANIO_ACTUAL)
                {
                    printf("Ingrese anio de consumo \n");
                    scanf("%d",&a.anio);
                }
            }
            flag=anioBisiesto(a);
            printf("Ingrese mes\n");
            scanf("%d",&a.mes);
            if(a.mes<1||a.mes>12)
            {
                while(a.mes<1||a.mes>12)
                {
                    printf("Ingrese mes\n");
                    scanf("%d",&a.mes);
                }
            }

            printf("Ingrese dia\n");
            scanf("%d",&a.dia);
            /// calcula el mes y los dias
            mesesDiasCuenta=mesesYdias(a,flag);
            if(flag==1&&a.mes==2&&a.dia<1||a.dia>29)
            {
                while(a.dia<1||a.dia>29)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            if(mesesDiasCuenta==2&&a.dia<1||a.dia>28)
            {
                while(a.dia<1||a.dia>28)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            if(mesesDiasCuenta==3&&a.dia<1||a.dia>30)
            {
                while(a.dia<1||a.dia>30)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            if(mesesDiasCuenta==4&&a.dia<1||a.dia>31)
            {
                while(a.dia<1||a.dia>31)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            printf("Ingrese datos consumidos\n");
            scanf("%d",&a.datosConsumidos);
            dato=a.datosConsumidos;
            a.baja=0;
            a.id=validos;
            validos++;

            a=agregaConsumosDias(archivoConsumo,a,dato);
            fwrite(&a,sizeof(stConsumos),1,archi);

            printf("Precione ESC para salir ,Cualquier tecla para continuar cargando consumos\n");
            opcion=getch();

        }
        fclose(archi);
        filtraClientes("clientes.bin",archivoConsumo);
    }
}
