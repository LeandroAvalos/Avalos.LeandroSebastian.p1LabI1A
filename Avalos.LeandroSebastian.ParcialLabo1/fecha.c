#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "trabajo.h"

int validarFecha(eFecha* unaFecha)
{
    int error = -1;

    printf("Ingrese una fecha (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);

    while(error == -1)
    {
        if(unaFecha->anio >= 1950 && unaFecha->anio <= 2021)
        {
            if(unaFecha->mes >= 1 && unaFecha->mes <= 12)
            {
                switch(unaFecha->mes)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(unaFecha->dia < 1 || unaFecha->dia > 31)
                        {
                            printf("Error. Día invalido para el mes %0d. Ingrese una fecha nuevamente (DD/MM/AAAA): ", unaFecha->mes);
                            scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
                        }
                        else
                        {
                            error=0;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(unaFecha->dia < 1 || unaFecha->dia > 30)
                        {
                            printf("Error. Día invalido para el mes %0d. Ingrese una fecha nuevamente (DD/MM/AAAA): ", unaFecha->mes);
                            scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
                        }
                        else
                        {
                            error=0;
                        }
                        break;
                    case 2:
                        if(unaFecha->anio %4 == 0 || (unaFecha->anio %100 != 0 && unaFecha->anio %400 == 0))
                        {
                            if(unaFecha->dia < 1 || unaFecha->dia > 29)
                            {
                                printf("Error.Día invalido para el mes %0d. Ingrese una fecha nuevamente (DD/MM/AAAA): ", unaFecha->mes);
                                scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
                            }
                            else
                            {
                                error=0;
                            }
                        }
                        else
                        {
                            if(unaFecha->dia < 1 || unaFecha->dia > 28)
                            {
                                printf("Error. Día invalido para el mes %0d. Ingrese una fecha nuevamente (DD/MM/AAAA): ", unaFecha->mes);
                                scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
                            }
                            else
                            {
                                error=0;
                            }
                        }
                        break;
                }
            }
            else
            {
                printf("Error. Mes invalido. Ingrese una fecha nuevamente (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
            }
        }
        else
        {
            printf("Error. Anio invalido. Ingrese una fecha nuevamente (DD/MM/AAAA): ");
            scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
        }
    }
    return error;
}
