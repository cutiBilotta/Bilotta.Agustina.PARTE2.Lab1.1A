#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"

int inicializarTrabajo(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            trabajos[i].estaVacio = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( trabajos[i].estaVacio )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], int tam_trabajos, eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipos, eServicio servicios[], int tam_servicio, eColor colores[], int tam_color, int* pIdTrabajo)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;


    if(trabajos && tam_trabajos && mascotas && tam_mascota && pIdTrabajo && tipos && servicios && tam_servicio && tam_tipos && colores && tam_color)
    {
        buscarTrabajoLibre(trabajos, tam_trabajos, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema para cargar un nuevo trabajo\n");
        }
        else
        {
            listarMascotas(mascotas, tam_mascota, tipos, tam_tipos, colores, tam_color);
            printf("Ingrese el id de la mascota: \n");
            scanf("%d", &nuevoTrabajo.idMascota);
            buscarMascota(mascotas, tam_mascota, nuevoTrabajo.idMascota, &indice);
            while(indice == -1)
            {
                printf("Error. Reingrese el id de la mascota: \n");
                scanf("%d", &nuevoTrabajo.idMascota);
                buscarMascota(mascotas, tam_mascota, nuevoTrabajo.idMascota, &indice);
            }

            listarServicios(servicios, tam_servicio);
            printf("Ingrese el id del servicio: ");
            scanf("%d", &nuevoTrabajo.idServicio);
            while(nuevoTrabajo.idServicio <20000 || nuevoTrabajo.idServicio>20002)
            {
                printf("Error. Reingrese el id del servicio: \n");
                scanf("%d", &nuevoTrabajo.idServicio);

            }


            trabajos[indice].idTrabajo= *pIdTrabajo;
            trabajos[indice].idMascota= nuevoTrabajo.idMascota;
            trabajos[indice].idServicio= nuevoTrabajo.idServicio;
            trabajos[indice].estaVacio=0;

            (*pIdTrabajo)++;

            todoOk=1;
        }
    }
    else
    {
        printf("Ocurrio un problema con los parametros\n");
    }
    return todoOk;
}

int mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tam_servicio)
{
    int todoOk = 0;
    char descServicio[20];

    if(servicios && tam_servicio )
    {
        cargarDescripcionServicio( servicios, tam_servicio, unTrabajo.idServicio, descServicio);

        printf("  %4d            %4d         %15s     %02d/%02d/%d \n", unTrabajo.idTrabajo, unTrabajo.idMascota, descServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);


        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio)
{
    int todoOk = 0;
    int flag = 0;
    if(trabajos != NULL && tam_trabajo > 0 && servicios && tam_servicio )
    {


        system("cls");
        printf("                *** Listado de Trabajos ***\n\n");
        printf(" idTrabajo      idMascota            Servicio         Fecha \n");
        printf("-----------------------------------------------------------------\n");
        for(int i=0; i < tam_trabajo; i++)
        {
            if( !trabajos[i].estaVacio )
            {
                mostrarTrabajo(trabajos[i], servicios, tam_servicio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tam_trabajo, int cantidad,int* idTrabajo)
{
    int todoOk=0;

    if(trabajos && tam_trabajo && cantidad && idTrabajo)
    {
        eTrabajo auxTrabajos[10]= {{0,3,20002,{10,10,2016},0},  {0,1,20001,{22,11,2022},0},
            {0,9,20001,{14,10,2020},0},  {0,7,20000,{1,2,2020},0},
            {0,3,20002,{17,2,2019},0},   {0,2,20001,{22,11,2022},0},
            {0,6,20000,{17,2,2019},0},    {0,6,20001,{4,6,2018},0},
            {0,8,20002,{22,11,2022},0},    {0,1,20002,{28,6,2022},0}
        };


        for(int i=0; i<cantidad ; i++)
        {

            trabajos[i]= auxTrabajos[i];
            trabajos[i].idTrabajo= *idTrabajo;
            (*idTrabajo)++;
        }

        todoOk=1;
    }
    return todoOk;
}

//////////////////////////////////////////////////////////////////////////////
// I N F O R M E S

int listarTrabajosMascotaSeleccionada(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio, eMascota mascotas[], int tam_mascota)
{

    int todoOk=0;
    int idMascota;

    if( trabajos && tam_trabajo && servicios && tam_servicio )
    {
        printf("Ingrese el id de la mascota: \n");
        scanf("%d", &idMascota);
        while(!buscarIdMascota(mascotas, tam_mascota, idMascota))
        {
            printf("Error. Ingrese el id de la mascota: \n");
            scanf("%d", &idMascota);
        }

        system ("cls");
        printf("      *** Listado de trabajos a una mascota *** \n\n");
        printf(" idTrabajo      idMascota            Servicio         Fecha \n");
        printf("-----------------------------------------------------------------\n");

        for( int i=0; i<tam_trabajo ; i++)
        {
            if(!trabajos[i].estaVacio && trabajos[i].idMascota == idMascota)
            {
                mostrarTrabajo(trabajos[i], servicios, tam_servicio );

            }
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}

int informarPrecioMascotaSeleccionada(eTrabajo trabajos[], int tam_trabajo, eMascota mascotas[], int tam_mascota, eServicio servicios[], int tam_servicio)
{

    int todoOk=0;
    int idMascota;
    float acumPrecio=0;
    int flag=0;

    if(mascotas && tam_mascota && trabajos && tam_trabajo && servicios && tam_servicio )
    {
        printf("Ingrese el id de la mascota: \n");
        scanf("%d", &idMascota);
        while(!buscarIdMascota(mascotas, tam_mascota, idMascota))
        {
            printf("Error. Ingrese el id de la mascota: \n");
            scanf("%d", &idMascota);
        }

        printf("   *** Informe total precio de trabajos a una mascota *** \n\n");
        printf(" idTrabajo      idMascota            Servicio         Fecha \n");
        printf("-----------------------------------------------------------------\n");

        for( int i=0; i<tam_trabajo ; i++)
        {
            if(!trabajos[i].estaVacio && trabajos[i].idMascota == idMascota)
            {
                flag=1;
                mostrarTrabajo(trabajos[i], servicios, tam_servicio);
                for(int s=0 ; s<tam_servicio ; s++)
                {
                    if(trabajos[i].idServicio == servicios[s].idServicio)
                    {
                        acumPrecio= servicios[s].precio + acumPrecio;
                    }
                }
            }
        }
        printf(" \n\n");
        if(!flag)
        {
            printf("No se le realizaron trabajos a la mascota seleccionada\n\n");

        }
        else
        {
            printf("El precio total de los trabajos que se le realizaron a la mascota seleccionada es: %.2f \n\n", acumPrecio);
        }
        todoOk=1;
    }
    return todoOk;
}

int listarTrabajosPorServicioSeleccionado(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio, eMascota mascotas[], int tam_mascota)
{
    int todoOk = 0;
    int flag = 0;
    int idServicio;
    if(trabajos  && tam_trabajo > 0 && servicios && tam_servicio && mascotas && tam_mascota )
    {
        listarServicios(servicios, tam_servicio);
        printf("Ingrese el id del servicio: \n");
        scanf("%d", &idServicio);
        while(!validarServicio(servicios, tam_servicio, idServicio))
        {
            printf("Error. Ingrese el id del servicio: \n");
            scanf("%d", &idServicio);
        }


        system("cls");
        printf("      *** Listado de Trabajos por servicio seleccionado ***\n\n");
        printf(" idTrabajo      idMascota            Servicio         Fecha \n");
        printf("-----------------------------------------------------------------\n");
        for(int i=0; i < tam_trabajo; i++)
        {
            if( !trabajos[i].estaVacio && trabajos[i].idServicio == idServicio)

            {
                mostrarTrabajo(trabajos[i], servicios, tam_servicio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


int mostrarTrabajosPorFechaSeleccionada(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio){
    int todoOk=0;
    eFecha fecha;
    int flag=0;

    if(trabajos && tam_trabajo && servicios && tam_servicio){

        printf("Ingrese fecha: dd/mm/aaaa \n");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        system("cls");
        printf("      *** Listado de Trabajos por fecha seleccionada ***\n\n");
        printf(" idTrabajo      idMascota            Servicio         Fecha \n");
        printf("-----------------------------------------------------------------\n");
        for(int i=0; i<tam_trabajo;i++){
            if(!trabajos[i].estaVacio && trabajos[i].fecha.dia == fecha.dia && trabajos[i].fecha.mes == fecha.mes && trabajos[i].fecha.anio == fecha.anio){
                mostrarTrabajo(trabajos[i], servicios, tam_servicio);
                flag=1;
            }
        }
        if(!flag){
            printf("No hay trabajos con la fecha ingresada\n\n");
        }

        todoOk=1;
    }
    return todoOk;
}
