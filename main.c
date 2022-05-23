#include <stdio.h>
#include <stdlib.h>

#include "color.h"
#include "fecha.h"
#include "mascota.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"

#define TAM_TIPO 5
#define TAM_COLOR 5
#define TAM_SERVICIOS 3
#define TAM_MASCOTA 20
#define TAM_TRABAJO 20


int main()
{
    int idMascota=1;
    int idTrabajo=1;
    int banderaAlta=0;

    char salir= 'n';
    eTipo tipos[TAM_TIPO]= {{1000,"Ave"}, {1001,"Perro"}, {1002,"Roedor"}, {1003,"Gato"}, {1004,"Pez"}};

    eColor colores[TAM_COLOR]= {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Rojo"}, {5003,"Gris"}, {5004, "Azul"}};

    eServicio servicios[TAM_SERVICIOS]= {{20000, "Corte", 450},{20001, "Desparacitado", 800}, {20002, "Castrado", 600}};

    eTrabajo trabajos[TAM_TRABAJO];
    inicializarTrabajo(trabajos, TAM_TRABAJO);
    hardcodearTrabajos(trabajos, TAM_TRABAJO, 10, &idTrabajo);

    eMascota mascotas[TAM_MASCOTA];
    inicializarMascota(mascotas, TAM_MASCOTA);
    hardcodearMascotas(mascotas, TAM_MASCOTA, 10, &idMascota);

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaMascota(mascotas, TAM_MASCOTA, tipos, TAM_TIPO , colores, TAM_COLOR,  &idMascota)){
                printf("Ocurrio un problema\n");
            }
            banderaAlta=1;
            break;
        case 2:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!bajaMascota(mascotas, TAM_MASCOTA, tipos, TAM_TIPO, colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 3:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!modificarMascota(mascotas, TAM_MASCOTA, tipos, TAM_TIPO, colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 4:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!listarMascotas(mascotas, TAM_MASCOTA, tipos, TAM_TIPO, colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 5:
            if(!listarTipos(tipos, TAM_TIPO)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 6:
            if(!listarColores(colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 7:
            if(!listarServicios(servicios, TAM_SERVICIOS)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 8:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!altaTrabajo(trabajos, TAM_TRABAJO, mascotas,TAM_MASCOTA, tipos, TAM_TIPO,servicios, TAM_SERVICIOS, colores, TAM_COLOR, &idTrabajo)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 9:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!listarTrabajos(trabajos, TAM_TRABAJO, servicios, TAM_SERVICIOS)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 10:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!mostrarMascotasColor(mascotas, TAM_MASCOTA, colores, TAM_COLOR, tipos, TAM_TIPO)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 11:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!informarPromedioVacunados(mascotas, TAM_MASCOTA)){
                printf("Ocurrio un problema\n");
            }
            break;
        case 12:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!mostrarMascotasMenorEdad(mascotas, TAM_MASCOTA, colores, TAM_COLOR, tipos, TAM_TIPO)){
                printf("Ocurrio un problema\n");
            }
            break;

         case 13:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!listarMascotasSeparadasPorTipo(mascotas, TAM_MASCOTA, tipos, TAM_TIPO ,colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 14:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!informarColorTipoSeleccionado(mascotas, TAM_MASCOTA, tipos, TAM_TIPO ,colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 15:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!informarColorMasRepetido(mascotas, TAM_MASCOTA, tipos, TAM_TIPO ,colores, TAM_COLOR)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 16:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!listarTrabajosMascotaSeleccionada(trabajos, TAM_TRABAJO, servicios, TAM_SERVICIOS, mascotas, TAM_MASCOTA)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 17:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!informarPrecioMascotaSeleccionada(trabajos, TAM_TRABAJO, mascotas, TAM_MASCOTA, servicios, TAM_SERVICIOS)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 18:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!listarTrabajosPorServicioSeleccionado(trabajos, TAM_TRABAJO, servicios, TAM_SERVICIOS, mascotas, TAM_MASCOTA)){
                printf("Ocurrio un problema\n");
            }
            break;

          case 19:
            if(!banderaAlta){
                printf("Primero debe cargar una mascota\n");
            }
            else if(!mostrarTrabajosPorFechaSeleccionada(trabajos, TAM_TRABAJO, servicios, TAM_SERVICIOS)){
                printf("Ocurrio un problema\n");
            }
            break;

        case 20:
            printf("Confirma salida? s/n \n");
            fflush(stdin);
            scanf("%c", &salir);
        }
        system("pause");
    }
    while(salir!='s');


}
