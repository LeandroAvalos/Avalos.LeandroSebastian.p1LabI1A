#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


#endif // FECHA_H_INCLUDED

/** \brief Funcion que valida el ingreso de una fecha(tanto si es una fecha valida como si es un año biciesto).
 *
 * \param unaFecha eFecha* Puntero a la estructura fecha donde se guardaran valores en los campos.
 * \return int Retorna -1 si hubo error y 0 si esta todoOK.
 *
 */
int validarFecha(eFecha* unaFecha);
