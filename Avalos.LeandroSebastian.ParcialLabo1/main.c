#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"

#define TAM_TIPOS 4
#define TAM_COLOR 5
#define TAM_SERVICIOS 4
#define TAM_BIC 50
#define TAM_TRAB 50

int main()
{
    char seguir = 's';
    int nextIdBicicleta = 1;
    int nextIdTrabajo = 1;
    int flagPrimerIngreso = 0;
    int flagSegundoIngreso = 0;

     eTipo tipos[TAM_TIPOS] = {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };

    eColor colores[TAM_COLOR] = {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };

    eServicio servicios[] = {
        {20000, "Limpieza", "$30"},
        {20001, "Parche", "$400"},
        {20002, "Centrado", "$500"},
        {20003, "Cadena", "$450"}
    };

    eBicicleta bicicletas[TAM_BIC];
    eTrabajo trabajos[TAM_TRAB];

    if(!inicializarBiciletas(bicicletas, TAM_BIC))
    {
        printf("Hubo un problema al inicializar las bicicletas.\n");
    }
    if(!inicializarTrabajo(trabajos, TAM_TRAB))
    {
        printf("Hubo un problema al inicializar los trabajos.\n");
    }


    do
    {
        switch(menu())
        {
            case 'A':
                if(!altaBicicleta(bicicletas, TAM_BIC, tipos, TAM_TIPOS,colores, TAM_COLOR, &nextIdBicicleta))
                {
                    printf("Hubo un problema al hacer el alta.\n");
                }
                flagPrimerIngreso = 1;
                break;
            case 'B':
                if(flagPrimerIngreso)
                {
                    if(!modificarBicleta(bicicletas, TAM_BIC, tipos, TAM_TIPOS, colores, TAM_COLOR))
                    {
                        printf("Hubo un problema al hacer la modificacion.\n");
                    }
                }
                else
                {
                    printf("Al menos debe dar de alta una bicicleta para poder modificarla\n");
                }
                break;
            case 'C':
                if(flagPrimerIngreso)
                {
                    if(!bajaBicicleta(bicicletas, TAM_BIC, tipos, TAM_TIPOS, colores, TAM_COLOR))
                    {
                        printf("Hubo un problema al hacer la baja.\n");
                    }
                    cambiarValorDeFlag(bicicletas, TAM_BIC, &flagPrimerIngreso);
                }
                else
                {
                    printf("Al menos debe dar de alta una bicicleta para poder darla de baja\n");
                }
                break;
            case 'D':
                if(flagPrimerIngreso)
                {
                    if(!mostrarBicicletas(bicicletas, TAM_BIC, colores, TAM_COLOR, tipos, TAM_TIPOS))
                    {
                        printf("Hubo un problema al listar las bicicletas.\n");
                    }
                }
                else
                {
                    printf("Al menos debe dar de alta una bicicleta para poder mostrar las bicicletas\n");
                }
                break;
            case 'E':
                if(!mostrarTipos(tipos, TAM_TIPOS))
                {
                    printf("Hubo un problema al listar los tipos.\n");
                }
                break;
            case 'F':
                if(!mostrarColores(colores, TAM_COLOR))
                {
                    printf("Hubo un problema al listar los colores.\n");
                }
                break;
            case 'G':
                if(!mostrarServicios(servicios, TAM_SERVICIOS))
                {
                    printf("Hubo un problema al listar los servicios.\n");
                }
                break;
            case 'H':
                if(flagPrimerIngreso)
                {
                    if(!altaTrabajo(trabajos, TAM_TRAB, servicios, TAM_SERVICIOS, bicicletas, TAM_BIC, tipos, TAM_TIPOS, colores, TAM_COLOR, &nextIdTrabajo))
                    {
                        printf("Hubo un problema al dar de alta un trabajo.\n");
                    }
                    flagSegundoIngreso = 1;
                }
                else
                {
                    printf("Al menos debe dar de alta una bicicleta para poder dar de alta un trabajo\n");
                }
                break;
            case 'I':
                if(flagPrimerIngreso && flagSegundoIngreso)
                {
                   if(!mostrarTrabajos(trabajos, TAM_TRAB, bicicletas, TAM_BIC, servicios, TAM_SERVICIOS, tipos, TAM_TIPOS, colores, TAM_COLOR))
                   {
                        printf("Hubo un problema al listar los trabajos.\n");
                   }
                }
                else
                {
                    printf("Al menos debe dar de alta una bicicleta y dar de alta un trabajo para poder mostrar los trabajos\n");
                }
                break;
            case 'J':
                seguir = 'n';
                printf("Salida exitosa!!! Mucha suerte!!!\n");
                break;
            default:
                printf("Ingrese una opcion valida!!\n");
                break;
        }
        system("pause");
    }while(seguir == 's');

    return 0;
}
