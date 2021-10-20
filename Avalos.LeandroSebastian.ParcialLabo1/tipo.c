#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>

int cargarDescripcionTipo(eTipo tipos[], int tamTipo,int idTipo, char descripcion[])
{
    int todoOk = 0;

    if(tipos != NULL && tamTipo > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamTipo; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcion,tipos[i].descripcion);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarTipos(eTipo tipos[], int tamTipo)
{
    int todoOk = 0;

    if(tipos != NULL && tamTipo > 0)
    {
        printf("               *** Listado de Tipos ***\n\n");
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("ID         |Tipos  \n");
        printf("-------------------------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < tamTipo; i++)
        {
            printf("%d       %s\n",tipos[i].id, tipos[i].descripcion);
        }
        todoOk = 1;
    }
    return todoOk;
}
