#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "mascota.h"
#include "servicio.h"

typedef struct{

    int idTrabajo;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int estaVacio;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

//Funciones ABM trabajo

/** \brief busca en el array de trabajos si hay lugar libre para dar de alta uno nuevo
 * \param  trabajos[], tam_ trabajo
 * \return 1 sin error || 0 si hubo error
 */
int buscarTrabajoLibre(eTrabajo trabajos[], int tam, int* pIndex);



/** \brief Se da alta a un trabajo pidiendo id mascota y servicio
 * \param trabajos[], tam_trabajos, mascotas[], tam_mascota, tipos[], tam_tipos, servicios[], tam_servicio, *pIdTrabajo
 * \return 1 sin error || 0 si hubo error
 */
int altaTrabajo(eTrabajo trabajos[], int tam_trabajos, eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipos, eServicio servicios[], int tam_servicio, eColor colores[], int tam_color, int* pIdTrabajo);

//Funcion complementaria
/** \brief inicializa el vector de trabajos en el campo estaVacio en cero para limpiar basura
 * \param trabajos[], tam_trabajos
 * \return  1 sin error || 0 si hubo error
 */
int inicializarTrabajo(eTrabajo trabajos[], int tam);


//Funciones para mostrar trabajo/s


/** \brief muestra en pantalla la lista de trabajos dados de alta
 * \param  trabajos[], tam_trabajo,  servicios[],  tam_servicio
 * \return 1 sin error || 0 si hubo error
 */
int listarTrabajos(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio);

/** \brief muestra un solo trabajo
 * \param  un trabajo, tam_trabajo,  servicios[],  tam_servicio
 * \return 1 sin error || 0 si hubo error
 *
 */

int mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tam_servicio);

//Funcion para el hardcodeo de maximo 10 trabajos

/** \brief harcodea como maximo10 trabajos
 * \param  trabajos[], tam_trabajo,  cantidad a hardodear, *idTrabajo);
 * \return 1 sin error || 0 si hubo error
 */

int hardcodearTrabajos(eTrabajo trabajos[], int tam_trabajo, int cantidad,int* idTrabajo);


/** \brief muestra los trabajos que se le realizaron a una mascota seleccionada mediante id por el usuario
 * \param trabajos[] y su tamaño, servicios[] y su tamaño, mascotas[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int listarTrabajosMascotaSeleccionada(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio, eMascota mascotas[], int tam_mascota);



/** \brief informa la suma total de precios de los trabajos que se le realizaron a una mascota seleccionada mediante su id por el usuario
 * \param trabajos[] y su tamaño, servicios[] y su tamaño, mascotas[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int informarPrecioMascotaSeleccionada(eTrabajo trabajos[], int tam_trabajo, eMascota mascotas[], int tam_mascota, eServicio servicios[], int tam_servicio);


/** \brief lista todos los trabajos en los que se realizo el servicio seleccionado por el usuario mediante su id
 * \param trabajos[] y su tamaño, servicios[] y su tamaño, mascotas[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int listarTrabajosPorServicioSeleccionado(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio, eMascota mascotas[], int tam_mascota);




/** \brief muestra los trabajos que se realizaron en la fecha ingresada por el usuario
 * \param trabajos[] y su tamaño, servicios[] y su tamaño, mascotas[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int mostrarTrabajosPorFechaSeleccionada(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio);
