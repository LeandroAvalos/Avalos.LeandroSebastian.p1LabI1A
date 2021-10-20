#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    char precio[10];
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief Muestra los servicios existentes con sus respectivos IDs.
 *
 * \param servicios[] eServicio Array de servicios.
 * \param tamServ int Tamaño del array de servicios.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int mostrarServicios(eServicio servicios[], int tamServ);

/** \brief Funcion que verifica si el id ingresado por el usuario es igual al id existente de algun servicio si es asi devuelve el nombre del tipo deseado.
 *
 * \param servicios[] eServicio Array de servicios.
 * \param tamServ int Tamaño del array de servicios.
 * \param idServicio int ID ingresado por el usuario.
 * \param descripcion[] char Array donde se guarda la descripcion del tipo una vez verificada y copiada.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tamServ,int idServicio, char descripcion[]);
