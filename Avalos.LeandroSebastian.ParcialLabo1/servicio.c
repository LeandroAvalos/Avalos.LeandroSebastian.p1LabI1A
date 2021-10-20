#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionServicio(eServicio servicios[], int tamServ,int idServicio, char descripcion[])
{
    int todoOk = 0;

    if(servicios != NULL && tamServ > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamServ; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(descripcion,servicios[i].descripcion);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarServicios(eServicio servicios[], int tamServ)
{
    int todoOk = 0;

    if(servicios != NULL && tamServ > 0)
    {
        printf("               *** Listado de Servicios ***\n\n");
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("ID         |Colores         |Precio\n");
        printf("-------------------------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < tamServ; i++)
        {
            printf("%d       %-10s       %-2s\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        todoOk = 1;
    }
    return todoOk;
}
