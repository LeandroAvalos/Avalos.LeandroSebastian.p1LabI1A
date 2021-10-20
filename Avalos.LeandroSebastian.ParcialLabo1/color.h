#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief Funcion que verifica si el id ingresado por el usuario es igual al id existente de algun color si es asi devuelve el nombre del tipo deseado.
 *
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \param idColor int ID ingresado por el usuario.
 * \param descripcion[] char Array donde se guarda la descripcion del tipo una vez verificada y copiada.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int cargarDescripcionColor(eColor colores[], int tamColor,int idColor, char descripcion[]);

/** \brief Muestra los colores existentes con sus respectivos IDs.
 *
 * \param colores[] eColor Array de colores.
 * \param tamColor int Tamaño del array de colores.
 * \return int Retorna 1 si esta todoOK y 0 si fallo.
 *
 */
int mostrarColores(eColor colores[], int tamColor);
