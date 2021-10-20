#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"

int menu()
{
    char opcion;

    system("cls");
    printf("        *** Menu de la Bicicleteria ***          \n");
    printf("-------------------------------------------------\n");
    printf("   A- Alta bicicleta\n");
    printf("   B- Modificar bicicleta\n");
    printf("   C- Baja bicicleta\n");
    printf("   D- Listar bicletas\n");
    printf("   E- Listar tipos\n");
    printf("   F- Listar colores\n");
    printf("   G- Listar servicios\n");
    printf("   H- Alta trabajo\n");
    printf("   I- Listar trabajos\n");
    printf("   J- Salir\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}

int menuDeModificaciones()
{
    int opcion;

    system("cls");
    printf("        *** Menu de Modificaciones ***          \n");
    printf("------------------------------------------------\n");
    printf("   1- Tipo\n");
    printf("   2- Material\n");
    printf("   3- Salir\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int ordenarCaracteresMayuscula(char name[])
{
    int todoOk = 0;
    int i = 0;

    if(name != NULL)
    {
        strlwr(name);
        name[0] = toupper(name[0]);

        while(name[i] != '\0')
        {
            if(name[i] == ' ')
            {
                name[i + 1] = toupper(name [i + 1]);
            }
            i++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int soloLetras(char name[])
{
    int i = 0;
    int todoOk = 1;

    if(name != NULL)
    {
        while(name[i] != '\0')
        {
            if(name[i] != ' ')
            {
                if((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z'))
                {
                    todoOk = 0;

                    while(todoOk == 0)
                    {
                        printf("Error. Ingreselo nuevamente solo con letras(hasta 30 caracteres)\n");
                        fflush(stdin);
                        gets(name);
                        i = 0;
                        todoOk = 1;
                    }
                }
            }
            i++;
        }
    }
    return todoOk;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int todoOk = -1;
	char buffer[256];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(buffer);

		soloLetras(buffer);

		while(strlen(buffer)>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(buffer);
			soloLetras(buffer);
		}

		ordenarCaracteresMayuscula(buffer);

		strcpy(cadena, buffer);
		todoOk = 0;
	}
	return todoOk;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int todoOk = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		todoOk = 0;
	}

	return todoOk;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int todoOk = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		todoOk = 0;
	}

	return todoOk;
}

int cambiarValorDeFlag(eBicicleta bicicletas[], int tamBic, int* flag)
{
    int todoOk = 0;

    if(bicicletas != NULL && tamBic > 0)
    {
        for(int i = 0; i < tamBic ; i++)
        {
            if(bicicletas[i].isEmpty == 1)
            {
                *flag = 0;
            }
            else
            {
                *flag = 1;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracterVal1 && caracterIngresado != caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}
