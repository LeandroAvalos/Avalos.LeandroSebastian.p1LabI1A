#include "bicicleta.h"

#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED

/** \brief Imprime un menu de opciones para el usuario.
 *
 * \return int Retorna la opcion elegida por el usuario
 *
 */
int menu();

/** \brief Imprime un sub menu de modificaciones para el usuario.
 *
 * \return int Retorna la opcion elegida por el usuario.
 *
 */
int menuDeModificaciones();

/** \brief Pide una cadena de caracteres al usuario, valida su rango y su maximo de caracteres
 *
 * \param cadena char* Array de caracteres que guarda lo ingresado por el usuario para lugego validarlo.
 * \param mensaje char* Mensaje a transmitir al usuario.
 * \param mensajeError char* Mensaje de error a transmitir al usuario.
 * \param max int maximo de caracteres permitidos al usuario.
 * \return int Retorna -1 si fallo y 0 si esta todoOK.
 *
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);

/** \brief Pide un numero flotante al usuario, se valida su rango mediante un minimo y un maximo y se devuelve su valor por puntero.
 *
 * \param flotante float* Valor flotante ingresado por el usuario.
 * \param mensaje char* Mensaje a transmitir al usuario.
 * \param mensajeError char* Mensaje de error a transmitir al usuario.
 * \param min float Valor minimo a validar.
 * \param max float Valor maximo a validar.
 * \return int Retorna -1 si fallo y 0 si esta todoOK.
 *
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/** \brief Pide un numero entero al usuario, se valida su rango mediante un minimo y un maximo y se devuelve su valor por puntero.
 *
 * \param entero int* Valor entero ingresado por el usuario.
 * \param mensaje char* Mensaje a transmitir al usuario.
 * \param mensajeError char* Mensaje de error a transmitir al usuario.
 * \param min int Valor minimo a validar.
 * \param max int Valor maximo a validar.
 * \return int Retorna -1 si fallo y 0 si esta todoOK.
 *
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/** \brief Funcion para convertir las primeras letras en un array de caracteres a mayuscula.
 *
 * \param name[] char array de caracteres.
 * \return int Retorna 0 si fallo y 1 si esta todoOK.
 *
 */
int ordenarCaracteresMayuscula(char name[]);

/** \brief Funcion que valida que valida que no se puedan ingresar numeros o simbolos en un array de caracteres.
 *
 * \param name[] char Array de caracteres.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int soloLetras(char name[]);

/** \brief Funcion que sirve para pisar el valor de una flag en el switch main para corroborar que se haya ingresado algo antes de entrar a la opcion.
 *
 * \param bicicletas[] eBicicleta
 * \param tamBic int
 * \param flag int* Valor de la flag pasada por puntero.
 * \return int Devuelve 1 si esta todoOK y 0 si fallo.
 *
 */
int cambiarValorDeFlag(eBicicleta bicicletas[], int tamBic, int* flag);

/** \brief Funcion que pide un caracter y valida que sea la opcion que se pide.
 *
 * \param caracter char* Caracter ingresado por el usuario.
 * \param mensaje char* Mensaje que se le da al usuario.
 * \param mensajeError char* Mensaje de error que se le da al usuario.
 * \param caracterVal1 char Primer caracter a validar.
 * \param caracterVal2 char Segundo caracter a validar.
 * \return int Retorna -1 si fallo y 0 si esta todoOK.
 *
 */
int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);
