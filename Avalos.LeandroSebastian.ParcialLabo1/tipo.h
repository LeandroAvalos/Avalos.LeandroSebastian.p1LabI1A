#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Funcion que verifica si el id ingresado por el usuario es igual al id existente de algun tipo si es asi devuelve el nombre del tipo deseado.
 *
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos
 * \param idTipo int ID ingresado por el usuario.
 * \param descripcion[] char Array donde se guarda la descripcion del tipo una vez verificada y copiada
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int idTipo, char descripcion[]);

/** \brief Muestra los tipos existentes con sus respectivos IDs.
 *
 * \param tipos[] eTipo Array de tipos.
 * \param tamTipo int Tamaño del array de tipos
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int mostrarTipos(eTipo tipos[], int tamTipo);
