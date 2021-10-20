#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionColor(eColor colores[], int tamColor,int idColor, char descripcion[])
{
    int todoOk = 0;

    if(colores != NULL && tamColor > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamColor; i++)
        {
            if(colores[i].id == idColor)
            {
                strcpy(descripcion,colores[i].nombreColor);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarColores(eColor colores[], int tamColor)
{
    int todoOk = 0;

    if(colores != NULL && tamColor > 0)
    {
        printf("               *** Listado de Colores ***\n\n");
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("ID         |Colores  \n");
        printf("-------------------------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < tamColor; i++)
        {
            printf("%d       %s\n",colores[i].id, colores[i].nombreColor);
        }
        todoOk = 1;
    }
    return todoOk;
}
