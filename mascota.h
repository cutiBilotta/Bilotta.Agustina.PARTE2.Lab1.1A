#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include "tipo.h"
#include "color.h"

typedef struct{

    int idMascota;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int estaVacio;

}eMascota;

#endif // MASCOTA_H_INCLUDED


//Funciones ABM y Menu

/** \brief Muenstra menu ABM con 10 opciones
 * \return opcion del munu seleccionada por el usuario
 */
int menu();


/** \brief Se da alta a una mascota pidiendo todos sus campos
 * \param mascotas[], tam_mascota, tipos[], tam_tipos, colores[], tam_color, *pIdMascota
 * \return 1 sin error || 0 si hubo error
 */
int altaMascota(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipos, eColor colores[], int tam_color, int* pIdMascota);


/** \brief realiza baja logica a la mascota seleccionada por el usuario por id
 * \param mascotas[], tam_mascota, tipos[], tam_tipos, colores[], tam_color
 * \return 1 sin error || 0 si hubo error
 */
int bajaMascota(eMascota mascotas[], int tam,eTipo tipos[], int tam_tipo,  eColor colores[], int tam_color);



/** \brief modifica Tipo o Vacunas de la mascota seleccionada por id
 * \param mascotas[],tam tipos[],tam_tipo,colores[], tam_color
 * \return 1 sin error || 0 si hubo error
 */
int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tam_tipo,  eColor colores[], int tam_color);


//Funciones complementarias


/** \brief inicializa el array de mascotas en el campo estaVaio en CERO para limpiar basura
 * \param mascotas, tam_mascotas
 * \return 1 sin error || 0 si hubo error
 */
int inicializarMascota(eMascota mascotas[], int tam);

/** \brief recibe un id y verifica que se encuentre dada de alta una mascota con ese id
 * \param  mascotas, tam, id, *pIndex
 * \return en caso de existir devuelve el indice || si es inexsistente -1
 */
int buscarMascota(eMascota mascotas[], int tam,int id, int* pIndex);


/** \brief verifica que en el array de mascotas haya lugares libres para dar de alta una nueva
 * \param mascotas[], tam, *pIdex
 * \return si hay lugar devuelve en pIndex libre || si no hay lugares pIndex es -1
 */
int buscarMascotaLibre(eMascota mascotas[], int tam, int* pIndex);


//Funciones para mostrar mascota/s


/** \brief muestra todas las mascotas dadas de alta ordenadas por tipo, y en caso de igualdad por campo nombre
 * \param mascotas[], tam_mascota, tipos,  tam_tipo,  colores,  tam_color
 * \return   1 sin error || 0 si hubo error
 */
int listarMascotas(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color);


/** \brief muestra una mascota con sus campos
 * \param mascotas[], tipos,  tam_tipo,  colores,  tam_color
 * \return 1 sin error || 0 si hubo error
 */
int mostrarMascota(eMascota unaMascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color);


//Funcion que permite ordenamiento del array mascotas


/** \brief ordena el array de mascotas y compara el campo tipo, en caso de igualdad compara el campo nombre
 * \param mascota,  tam_mascotas
 * \return 1 sin error || 0 si hubo error
 */
int ordenarMascotasTipoNombre(eMascota mascotas[], int tam_mascotas);

//Funcion que hardcodea como maximo 10 mascotas
/** \brief harcodea como maximo diez mascotas con todos sus campos
 * \param mascotas[], int tam, cantidad a hardcodear,  *pLegajo para autoincrementar;
 * \return 1 sin error || 0 si hubo error
 *
 */
int hardcodearMascotas(eMascota mascotas[], int tam, int cant, int* pLegajo);

//Funciones para validar string y entero
int validarStr(char str[]);
int validarEntero(char precio[]);


/** \brief muestra todas las mascotas que tienen el color seleccionado por el usuario mediante su id
 * \param mascotas[] y tu manaño, colores[] y su tamaño, tipos[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int mostrarMascotasColor(eMascota mascotas[], int tam_mascota, eColor colores[], int tam_color, eTipo tipos[], int tam_tipo);


/** \brief muestra el promedio de mascotas vacunadas sobre el total de mascotas siendo el resultado 1 que todos los animales esten vacunados
 * \param mascotas[] y tu manaño
 * \return 1 sin error || 0 si hubo error
 */
int informarPromedioVacunados(eMascota mascotas[], int tam_mascota);



/** \brief muestra todas las mascotas separadas por tipo
 * \param mascotas[] y tu manaño, colores[] y su tamaño, tipos[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int listarMascotasSeparadasPorTipo(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color);


/** \brief muestra todas las mascotas que tienen el color y tipo seleccionado por el usuario mediante sus id
 * \param mascotas[] y tu manaño, colores[] y su tamaño, tipos[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int informarColorTipoSeleccionado(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color);



/** \brief informa el color mas repetido
 * \param mascotas[] y tu manaño, colores[] y su tamaño, tipos[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int informarColorMasRepetido(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color);



/** \brief muestra todas las mascotas que tienen la edad menor
 * \param mascotas[] y tu manaño, colores[] y su tamaño, tipos[] y su tamaño
 * \return 1 sin error || 0 si hubo error
 */
int mostrarMascotasMenorEdad(eMascota mascotas[], int tam_mascota, eColor colores[], int tam_color, eTipo tipos[], int tam_tipo);



/** \brief busca el id de la mascota para verificar que haya una mascota con el id que recibe la funcion
 * \param mascotas[] y tu manaño, colores[] y su tamaño, tipos[] y su tamaño
 * \return 1 si se encontro || 0 si no se encontro
 */
int buscarIdMascota(eMascota mascotas[], int tam, int id);
