#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief Funcion que inicializa todos los indices del array bicicleta en 1.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int inicializarBiciletas(eBicicleta bicicletas[], int tamBic);

/** \brief Funcion que busca un indice libre en el array de bicicletas.
 *
 * \param biciletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \return int Retorna - 1 si fallo y retorna el indice si esta todoOK.
 *
 */
int buscarLibreBicicleta(eBicicleta biciletas[], int tamBic);

/** \brief Funcion para dar de alta una bicicleta.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos.
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \param pIdBicicleta int* Puntero al ID de bicicletas el cual recibe un valor y lo devuelve modificado si se pudo dar de alta correctamente la bicicleta.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int altaBicicleta(eBicicleta bicicletas[], int tamBic, eTipo tipos[],int tamTipo, eColor colores[], int tamColor, int* pIdBicicleta);

/** \brief Funcion que sirve para mostrar los datos de una bicicleta.
 *
 * \param unaBicicleta eBicicleta Un valor del array de bicicletas.
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos.
 * \return void No retorna nada.
 *
 */
void mostrarBicicleta(eBicicleta unaBicicleta, eColor colores[], int tamColor, eTipo tipos[], int tamTipo);

/** \brief Funcion que sirve para mostrar los datos de todas las bicicletas.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \param tipos[] eTipo Array de tipos
 * \param tamTipo int Tamaño del array de tipos.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int mostrarBicicletas(eBicicleta bicicletas[], int tamBic, eColor colores[], int tamColor, eTipo tipos[], int tamTipo);

/** \brief Funcion que sirve para ordenar las bicicletas por Tipo y Material. Si los tipos son diferente los ordena por tipo y si son iguales los ordena por Material. luego de ordenarlo reemplaza los ID por los nombres correspondientes y los ordena alfabeticamente.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param tipos[] eTipo Array de tipos
 * \param tamTipo int Tamaño del array de tipos.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int ordenarBicicletasTipoYMaterial(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTipo);

/** \brief Funcion para dar de baja una bicicleta.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int  Tamaño del array de bicicletas.
 * \param tipos[] eTipo Array de tipos
 * \param tamTipo int Tamaño del array de tipos.
 * \param colores[] eColor Array de colores
 * \param tamColor int Tamaño del array de colores
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int bajaBicicleta(eBicicleta bicicletas[], int tamBic , eTipo tipos[],int tamTipo, eColor colores[], int tamColor);

/** \brief Funcion para modificar una bicicleta.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param tipos[] eTipo Array de tipos
 * \param tamTipo int Tamaño del array de tipos.
 * \param colores[] eColor  Array de colores
 * \param tamColor int Tamaño del array de colores
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int modificarBicleta(eBicicleta bicicletas[], int tamBic , eTipo tipos[],int tamTipo, eColor colores[], int tamColor);

/** \brief Funcion que valida si el ID ingresado por el usuario corresponde a un ID existente de alguna bicicleta.
 *
 * \param bicicletas[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param idBicicleta int ID ingresado por el usuario.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int validarIdBicicleta(eBicicleta bicicletas[], int tamBic, int idBicicleta);

/** \brief Funcion que verifica si el ID Ingresado por el usuario corresponde a un ID existente.
 *
 * \param bicicleta[] eBicicleta Array de bicicletas.
 * \param tamBic int Tamaño del array de bicicletas.
 * \param idBici int ID ingresado por el usuario.
 * \return int Retorna -1 si no se encontro el ID y retorna el indice del ID si se encontro.
 *
 */
int buscarBicicletaId(eBicicleta bicicleta[], int tamBic , int idBici);
