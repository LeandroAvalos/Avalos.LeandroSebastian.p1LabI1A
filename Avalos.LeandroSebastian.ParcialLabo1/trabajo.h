#include "fecha.h"
#include "servicio.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    int isEmpty;
    eFecha fecha;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Funcion que inicializa todos los indices del array trabajos en 1.
 *
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTrab int Tamaño del array de trabajos.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int inicializarTrabajo(eTrabajo trabajos[], int tamTrab);

/** \brief Funcion que busca un indice libre en el array de trabajos.
 *
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTrab int Tamaño del array de trabajos.
 * \return int Retorna -1 si fallo y el indice si esta todoOK.
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrab);

/** \brief Funcion para dar de alta un trabajo.
 *
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTrab int Tamaño del array de trabajos.
 * \param servicios[] eServicio Array de servicios.
 * \param tamServ int Tamaño del array de servicios.
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos.
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \param pIdTrabajo int* Puntero al ID de trabajos el cual recibe un valor y lo devuelve modificado si se pudo dar de alta correctamente el trabajo.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamTrab , eServicio servicios[], int tamServ ,eBicicleta bicicletas[], int tamBic, eTipo tipos[],int tamTipo, eColor colores[], int tamColor, int* pIdTrabajo);

/** \brief Funcion que sirve para mostrar un trabajo.
 *
 * \param unTrabajo eTrabajo Un valor del array de trabajos.
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param servicios[] eServicio Array de servicios.
 * \param tamServ int Tamaño del array de servicios.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos.
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \return void No retorna nada
 *
 */
void mostrarUnTrabajo(eTrabajo unTrabajo, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);

/** \brief Funcion que sirve para mostrar todos los trabajos dados de alta.
 *
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTrab int Tamaño del array de trabajos.
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param servicios[] eServicio Array de servicios.
 * \param tamServ int Tamaño del array de servicios.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos.
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
