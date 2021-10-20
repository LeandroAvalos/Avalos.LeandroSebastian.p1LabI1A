#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "trabajo.h"
#include "servicio.h"
#include "color.h"
#include "bicicleta.h"
#include "tipo.h"
#include "inputs.h"

int inicializarTrabajo(eTrabajo trabajos[], int tamTrab)
{
    int todoOk = 0;

    if(trabajos != NULL && tamTrab > 0)
    {
        for(int i = 0; i < tamTrab; i++)
        {
             trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrab)
{
    int indice = -1;

    if(trabajos != NULL && tamTrab > 0)
    {
        for(int i = 0; i < tamTrab; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajos[], int tamTrab , eServicio servicios[], int tamServ ,eBicicleta bicicletas[], int tamBic, eTipo tipos[],int tamTipo, eColor colores[], int tamColor, int* pIdTrabajo)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(trabajos != NULL && tamTrab > 0 && servicios != NULL && tamServ > 0 && bicicletas != NULL && tamBic > 0 && tipos != NULL && tamTipo > 0 && colores != NULL && tamColor > 0 && pIdTrabajo != NULL)
    {
        system("cls");
        printf("    *** Alta Trabajo ***\n");
        indice = buscarLibreTrabajo(trabajos, tamTrab);
        if(indice == - 1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;

            mostrarBicicletas(bicicletas, tamBic, colores, tamColor, tipos, tamTipo);
            printf("\nIngrese el Id de la bicicleta: \n");
            scanf("%d", &auxTrabajo.idBicicleta);
            while(!validarIdBicicleta(bicicletas, tamBic, auxTrabajo.idBicicleta))
            {
                printf("Error. Ingrese el Id de la bicicleta nuevamente: \n");
                scanf("%d", &auxTrabajo.idBicicleta);
            }
            trabajos[indice].idBicicleta = auxTrabajo.idBicicleta;

            mostrarServicios(servicios, tamServ);
            pedirEntero(&auxTrabajo.idServicio, "Ingrese el ID del servicio deseado.\n", "Error. Ingrese nuevamente el ID del servicio deseado\n", 20000, 20003);
            trabajos[indice].idServicio = auxTrabajo.idServicio;


            validarFecha(&auxTrabajo.fecha);

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;
            todoOk = 1;
            printf("Alta de trabajo Exitosa!!!\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarUnTrabajo(eTrabajo unTrabajo, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    char descripcionServicio[20];
    char descripcionTipo[20];
    char descripcionColor[20];
    int indiceBiciAMostrar;


    if(bicicletas != NULL && tamBic > 0 && servicios != NULL && tamServ > 0 && tipos != NULL && tamTipo > 0 && colores != NULL && tamColor > 0)
    {
        indiceBiciAMostrar=buscarBicicletaId(bicicletas, tamBic, unTrabajo.idBicicleta);
        cargarDescripcionServicio(servicios, tamServ, unTrabajo.idServicio, descripcionServicio);
        cargarDescripcionColor(colores, tamColor, bicicletas[indiceBiciAMostrar].idColor, descripcionColor);
        cargarDescripcionTipo(tipos, tamTipo, bicicletas[indiceBiciAMostrar].idTipo, descripcionTipo);


        printf("%d\t       %d\t       %-10s     %-10s        %-10s %c          \t   %-10s     %02d/%02d/%2d\n",
        unTrabajo.id,
        bicicletas[indiceBiciAMostrar].id,
        bicicletas[indiceBiciAMostrar].marca,
        descripcionTipo,
        descripcionColor,
        bicicletas[indiceBiciAMostrar].material,
        descripcionServicio,
        unTrabajo.fecha.dia,
        unTrabajo.fecha.mes,
        unTrabajo.fecha.anio);

    }
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int todoOk = 0;
    int flag = 1;

    if(trabajos != NULL && tamTrab > 0 && bicicletas != NULL && tamBic > 0 && servicios != NULL && tamServ > 0 && colores != NULL && tamColor > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        printf("     *** Listado de Trabajos ***\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("IdTrabajo     |IdBici         |Marca         |Tipo             |Color     |Material       |Servicio      |DD/MM/AAAA\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");

        ordenarBicicletasTipoYMaterial(bicicletas, tamBic, tipos, tamTipo);
        for(int i = 0; i < tamTrab; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarUnTrabajo(trabajos[i], bicicletas, tamBic, servicios, tamServ, tipos, tamTipo, colores, tamColor);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay trabajos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

