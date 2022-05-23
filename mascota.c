#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"
#include "tipo.h"
#include "color.h"


int menu()
{

    int opcionMenu;
    //system("pause");
    system("cls");
    printf("      ** ABM MASCOTAS **\n");
    printf("..........................\n\n");
    printf("  1 - Alta mascota\n");
    printf("  2 - Baja mascota\n");
    printf("  3 - Modificar mascota\n");
    printf("  4 - Listar mascotas\n");
    printf("  5 - Listar tipos\n");
    printf("  6 - Listar colores\n");
    printf("  7 - Listar Servicios\n");
    printf("  8 - Alta trabajo\n");
    printf("  9 - Listar trabajos\n\n");
    printf("--------------------------\n\n");
    printf("  10 - Mostrar mascotas del color seleccionada por el usuario\n");
    printf("  11 - Informar promedio de mascotas vacunadas sobre el total de mascotas\n");
    printf("  12 - Informar la o las mascotas de menor edad\n");
    printf("  13 - Listar las mascotas separadas por tipo\n");
    printf("  14 - Elegir un color y un tipo y contar cuantas mascotas hay de ese color y tipo\n");
    printf("  15 - Mostrar el o los colores con mas cantidad de mascotas\n");
    printf("  16 - Mostrar todos los trabajos que se le hicieron a una mascota seleccionada\n");
    printf("  17 - Informar la suma de los importes de los trabajos que se le hicieron a una mascota seleccionada \n");
    printf("  18 - Mostrar las mascotas a las que se le realizo un servicio seleccionado\n");
    printf("  19 - Mostrar trabajos realizados en fecha ingresada por el usuario\n");
    printf("--------------------------\n\n");
    printf(" 20 - Salir\n\n");

    printf("ingrese opcion: \n");
    scanf("%d", &opcionMenu);

    system("cls");

    return opcionMenu;
}

int inicializarMascota(eMascota mascotas[], int tam)
{
    int todoOk = 0;
    if(mascotas != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            mascotas[i].estaVacio = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarMascotaLibre(eMascota mascotas[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(mascotas != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( mascotas[i].estaVacio )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaMascota(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipos, eColor colores[], int tam_colores, int* pIdMascota)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eMascota nuevaMascota;


    if(mascotas && tam_mascota && pIdMascota && tipos && colores && tam_colores && tam_tipos)
    {
        printf("           *** ALTA MASCOTA ***        \n");
        printf("-----------------------------------------\n");
        if( buscarMascotaLibre(mascotas, tam_mascota, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema para cargar una nueva mascota\n");
            }
            else
            {
                printf("Ingrese el nombre de la mascota: ");
                fflush(stdin);
                gets(auxCad);
                while(!validarStr(auxCad))
                {
                    printf("Error. Reingrese el nombre de la mascota: ");
                    fflush(stdin);
                    gets(auxCad);
                }

                while(strlen(auxCad) >= 19)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaMascota.nombre, auxCad);

                printf("Esta vacunado/a? ('s' o 'n'): ");
                fflush(stdin);
                scanf("%c", &nuevaMascota.vacunado);
                while(nuevaMascota.vacunado != 's' && nuevaMascota.vacunado!= 'n' )
                {
                    printf("Error. Esta vacunado/a? ('s' o 'n'): ");
                    fflush(stdin);
                    scanf("%c", &nuevaMascota.vacunado);
                }

                printf("Ingrese edad: ");
                scanf("%s", auxCad);
                while(!validarEntero(auxCad))
                {
                    printf("Error. Reingrese edad: ");
                    scanf("%s", auxCad);
                }
                nuevaMascota.edad= atoi(auxCad);

                printf("\n\n");

                listarTipos(tipos, tam_tipos);
                printf("Ingrese tipo de animal: ");
                scanf("%d", &nuevaMascota.idTipo);
                while(!validarTipo(tipos, tam_tipos, nuevaMascota.idTipo))
                {
                    printf("Error. Reingrese tipo de animal: ");
                    scanf("%d", &nuevaMascota.idTipo);
                }

                printf("\n\n");

                listarColores(colores, tam_colores);
                printf("Ingrese el id del color del animal: ");
                scanf("%d", &nuevaMascota.idColor);
                while(!validarColores(colores, tam_colores, nuevaMascota.idColor))
                {
                    printf("Error. Reingrese el id del color del animal: ");
                    scanf("%d", &nuevaMascota.idColor);
                }


                nuevaMascota.estaVacio = 0;
                nuevaMascota.idMascota = *pIdMascota;
                *pIdMascota = *pIdMascota + 1;
                mascotas[indice] = nuevaMascota;
                todoOk = 1;
            }
        }
    }
    else
    {
        printf("Ocurrio un problema con los parametros\n");
    }

    return todoOk;
}




int mostrarMascota(eMascota unaMascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color)
{
    int todoOk = 0;
    char descTipo[20];
    char descColor[20];

    if(tipos && tam_tipo && colores && tam_color )
    {
        cargarDescripcionColor( colores, tam_color, unaMascota.idColor, descColor);
        cargarDescripcionTipo( tipos, tam_tipo, unaMascota.idTipo, descTipo);

        printf("   %2d     %10s    %10s    %8s      %2d        %c\n", unaMascota.idMascota, unaMascota.nombre, descTipo,descColor, unaMascota.edad, unaMascota.vacunado);


        todoOk = 1;
    }
    return todoOk;
}


int listarMascotas(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color)
{
    int todoOk = 0;
    int flag = 0;
    if(mascotas && tam_mascota  &&tipos && tam_tipo && colores && tam_color)
    {
        ordenarMascotasTipoNombre(mascotas, tam_mascota);
        system("cls");
        printf("                   *** Listado de Mascotas ***\n\n");
        printf(" idMasc        Nombre         Tipo       Color     Edad    Vacunas\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0; i < tam_mascota; i++)
        {
            if( !mascotas[i].estaVacio )
            {
                mostrarMascota(mascotas[i], tipos, tam_tipo, colores, tam_color);
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

int bajaMascota(eMascota mascotas[], int tam,eTipo tipos[], int tam_tipo,  eColor colores[], int tam_color)
{
    int todoOk = 0;
    int indice;
    int idMascota;
    char confirma;
    if(mascotas && tam && tipos && tam_tipo && colores && tam_color)
    {
        listarMascotas(mascotas, tam, tipos, tam_tipo,colores, tam_color);
        printf("\n           *** BAJA MASCOTA ***        \n");
        printf("-----------------------------------------\n");
        printf("Ingrese id de la mascota: ");
        scanf("%d", &idMascota);
        if( buscarMascota(mascotas, tam, idMascota, &indice))
        {
            while(indice == -1)
            {
                printf("No hay una mascota con legajo %d . Reingrese id: \n", idMascota);
                scanf("%d", &idMascota);
                buscarMascota(mascotas, tam, idMascota, &indice);
            }

            mostrarMascota(mascotas[indice], tipos, tam_tipo, colores, tam_color);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma != 'S' && confirma != 's')
            {
                printf("Baja cancelada por el usuario\n");
            }
            else
            {
                mascotas[indice].estaVacio = 1;
                printf("Baja realizada con el exito.\n");
                todoOk = 1;
            }


        }
        else
        {
            printf("Ocurrio un problema al buscar mascota\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int buscarMascota(eMascota mascotas[], int tam,int id, int* pIndex)
{
    int todoOk = 0;


    if(mascotas && tam  && pIndex  && id )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !mascotas[i].estaVacio  &&  mascotas[i].idMascota == id )
            {
                *pIndex = i;
                break;

            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tam_tipo,  eColor colores[], int tam_color)
{
    int todoOk = 0;
    int indice;
    int idMascota;
    int opcion;
    int nuevoTipo;
    char nuevaVacunacion;

    if(mascotas  && tam&& tipos && tam_tipo && colores && tam_color)
    {
        listarMascotas(mascotas, tam, tipos, tam_tipo, colores, tam_color);
        printf("\n           *** MODIFICACION MASCOTA ***        \n");
        printf("-----------------------------------------------------\n");
        printf("Ingrese id de la mascota: ");
        scanf("%d", &idMascota);

        if( buscarMascota(mascotas, tam, idMascota, &indice)!= -1)
        {
            while(indice == -1)
            {
                printf("No hay una mascota con id %d. Reingrese id: \n", idMascota);
                scanf("%d", &idMascota);
                buscarMascota(mascotas, tam, idMascota, &indice);
            }
            printf("\n");
            mostrarMascota(mascotas[indice], tipos, tam_tipo, colores, tam_color);
            printf("\n\nIngrese el campo que desea modificar: 0 - Tipo || 1 - Vacunacion \n");
            scanf("%d", &opcion);
            while(opcion!= 1 && opcion!=0)
            {
                printf("Error. Reingrese el campo que desea modificar: 0 - Tipo || 1 - Vacunacion \n");
                scanf("%d", &opcion);
            }
            if(!opcion)
            {
                printf("\n");
                listarTipos(tipos, tam_tipo);
                printf("Ingrese el nuevo tipo: \n");
                scanf("%d", &nuevoTipo);
                while(!validarTipo(tipos, tam_tipo, nuevoTipo ))
                {
                    printf("Error. Reingrese el nuevo tipo: \n");
                    scanf("%d", &nuevoTipo);

                }
                mascotas[indice].idTipo=nuevoTipo;
            }
            else
            {
                printf("Ingrese nueva vacunacion: \n");
                fflush(stdin);
                scanf("%c", &nuevaVacunacion);
                while(nuevaVacunacion!='s' && nuevaVacunacion!='n')
                {
                    printf("Error. Reingrese el nueva vacunacion. \n");
                    fflush(stdin);
                    scanf("%c", &nuevaVacunacion);

                }
                mascotas[indice].vacunado=nuevaVacunacion;
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar mascota\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int hardcodearMascotas(eMascota mascotas[], int tam, int cant, int* pLegajo)
{

    int todoOk = 0;
    if(mascotas && tam && cant && pLegajo)
    {
        eMascota hardcodeo[] =
        {
            {0, "Pepita",   1000, 5000, 3, 's'},
            {0, "Juanita",  1002, 5002, 1, 's'},
            {0, "Roco",     1003, 5001, 14, 's'},
            {0, "Pedro",    1004, 5000, 16, 'n'},
            {0, "Gaspar",   1001, 5003,  7, 's'},
            {0, "Tomi",     1000, 5004,  2, 'n'},
            {0, "Tobi",     1000, 5000,  1, 'n'},
            {0, "Bobi",     1002, 5004, 18, 's'},
            {0, "Loki",     1003, 5004, 20, 'n'},
            {0, "Luli",     1004, 5003,  5, 's'},
        };

        if(mascotas != NULL && tam > 0 && pLegajo != NULL && cant > 0 && cant <= tam)
        {

            for(int i=0; i < cant; i++)
            {
                mascotas[i] = hardcodeo[i];
                mascotas[i].idMascota = *pLegajo;
                *pLegajo = *pLegajo +1;
                mascotas[i].estaVacio=0;

            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int ordenarMascotasTipoNombre(eMascota mascotas[], int tam_mascotas)
{
    int todoOk = 0;
    eMascota auxMascota;

    if(mascotas && tam_mascotas)
    {
        for(int i=0; i<tam_mascotas; i++)
        {
            for(int j=0; j<tam_mascotas; j++)
            {
                if((mascotas[i].idTipo<mascotas[j].idTipo) || (mascotas[i].idTipo == mascotas[j].idTipo && stricmp(mascotas[i].nombre,mascotas[j].nombre )<0))
                {
                    auxMascota= mascotas[i];
                    mascotas[i]=mascotas[j];
                    mascotas[j]= auxMascota;
                }
            }
        }

        todoOk = 1;
    }

    return todoOk;
}

int validarStr(char str[])
{
    int todoOk=1;
    for(int i=0; i<strlen(str); i++)
    {
        if(!(str[i]>=65 && str[i]<=90) && !(str[i]>=97 && str[i]<=122) )
        {
            todoOk=0;
        }
    }
    return todoOk;
}

int validarEntero(char precio[])
{
    int todoOk=1;
    for(int i=0; i<strlen(precio); i++)
    {
        if(!(precio[i]>=48 && precio[i]<=57))
        {
            todoOk=0;
        }
    }
    return todoOk;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
// I N F O R M E S

int mostrarMascotasColor(eMascota mascotas[], int tam_mascota, eColor colores[], int tam_color, eTipo tipos[], int tam_tipo)
{
    int todoOk=0;
    int idColor;
    int flag=0;

    if(mascotas && tam_mascota && colores && tam_color && tipos && tam_tipo)
    {
        listarColores(colores, tam_color);
        printf("Ingrese el id del color: ");
        scanf("%d", &idColor);
        while(!validarColores(colores, tam_color, idColor))
        {
            printf("Error. Ingrese el id del color: ");
            scanf("%d", &idColor);
        }

        system("cls");
        printf("             *** Listado de Mascotas por color  ***\n\n");
        printf(" idMasc        Nombre         Tipo       Color     Edad    Vacunas\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0; i < tam_mascota; i++)
        {
            if( !mascotas[i].estaVacio && mascotas[i].idColor == idColor )
            {
                mostrarMascota(mascotas[i], tipos, tam_tipo, colores, tam_color);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}

int listarMascotasSeparadasPorTipo(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color)
{
    int todoOk = 0;
    int flag = 0;
    if(mascotas && tam_mascota  &&tipos && tam_tipo && colores && tam_color)
    {

        system("cls");
        printf("                   *** Listado de Mascotas ***\n\n");
        printf(" idMasc        Nombre         Tipo       Color     Edad    Vacunas\n");
        for(int t=0; t<tam_tipo ; t++)
        {
            printf("\nTipo de mascota: %s\n", tipos[t].descripcionTipo);
            printf("---------------------------------------------------------------------\n");
            for(int i=0; i < tam_mascota; i++)
            {

                if( !mascotas[i].estaVacio && mascotas[i].idTipo == tipos[t].idTipo )
                {
                    mostrarMascota(mascotas[i], tipos, tam_tipo, colores, tam_color);
                    flag++;
                }
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

int informarColorTipoSeleccionado(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color)
{
    int todoOk=0;
    int idTipo;

    int idColor;
    int contador=0;

    if(mascotas && tam_mascota && colores && tam_color && tipos && tam_tipo)
    {
        listarTipos(tipos, tam_tipo);
        printf("Ingrese el id del tipo: ");
        scanf("%d", &idTipo);
        while(!validarTipo(tipos, tam_tipo, idTipo))
        {
            printf("Error. Ingrese el id del tipo: ");
            scanf("%d", &idTipo);
        }

        listarColores(colores, tam_color);
        printf("Ingrese el id del color: ");
        scanf("%d", &idColor);
        while(!validarColores(colores, tam_color, idColor))
        {
            printf("Error. Ingrese el id del color: ");
            scanf("%d", &idColor);
        }


        system("cls");
        printf("       *** Mostrar mascotas por color y tipo seleccionado ***\n\n");
        printf(" idMasc        Nombre         Tipo       Color     Edad    Vacunas\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0; i < tam_mascota; i++)
        {
            if( !mascotas[i].estaVacio && mascotas[i].idTipo == idTipo &&  mascotas[i].idColor == idColor)
            {
                mostrarMascota(mascotas[i], tipos, tam_tipo, colores, tam_color);
                contador++;
            }
        }
        if(contador == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        else
        {
            printf("\n\n Del color %d y tipo %d hay %d mascotas \n", idColor, idTipo, contador);
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}

int informarColorMasRepetido(eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipo, eColor colores[], int tam_color)
{
    int todoOk=0;
    int mayorCantidad;
    int auxColores[tam_color];
    int flag=0;

    if(mascotas && tam_mascota && tipos && tam_tipo && colores && tam_color)
    {
        for(int i=0; i<tam_color; i++)
        {
            auxColores[i]=0;
        }

        for( int c=0 ; c<tam_color ; c++)
        {
            for(int i=0; i<tam_mascota  ; i++)
            {
                if(!mascotas[i].estaVacio && mascotas[i].idColor == colores[c].idColor)
                {
                    auxColores[c]= auxColores[c]+1;
                }
            }
        }

        for(int i =0; i<tam_color; i++)
        {
            if(!flag || auxColores[i] > mayorCantidad)
            {
                flag=1;
                mayorCantidad= auxColores[i];
            }
        }

        printf("     *** Informe de color/es mas repetido/s en mascotas ***    \n");
        printf(" --------------------------------------------------------------\n\n");
        printf("El color mas repetido se repitio %d veces  \n", mayorCantidad);
        for(int i=0; i< tam_color; i++)
        {
            if(auxColores[i] == mayorCantidad)
            {
                printf("Color: %s \n", colores[i].nombreColor);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarMascotasMenorEdad(eMascota mascotas[], int tam_mascota, eColor colores[], int tam_color, eTipo tipos[], int tam_tipo)
{
    int todoOk=0;
    int flag=0;
    int menorEdad;

    if(mascotas && tam_mascota && colores && tam_color && tipos && tam_tipo)
    {

        for(int i=0; i<tam_mascota; i++)
        {
            if((!mascotas[i].estaVacio) && (!flag || mascotas[i].edad < menorEdad))
            {
                flag=1;
                menorEdad= mascotas[i].edad;
            }
        }
        printf("            *** Mostrar menor/es mascota/s *** \n\n");
        printf(" idMasc        Nombre         Tipo       Color     Edad    Vacunas\n");
        printf("---------------------------------------------------------------------\n\n");
        for(int i =0; i<tam_mascota; i++)
        {
            if((!mascotas[i].estaVacio) && (mascotas[i].edad == menorEdad))
            {
                mostrarMascota(mascotas[i], tipos, tam_tipo, colores, tam_color);
            }
        }

        todoOk=1;
    }
    return todoOk;
}

int informarPromedioVacunados(eMascota mascotas[], int tam_mascota)
{
    int todoOk=0;
    int totalMascotas=0;
    int contadorVacunados=0;
    float promedio;

    if(mascotas && tam_mascota)
    {
        for( int i=0; i<tam_mascota ; i++)
        {
            if(!mascotas[i].estaVacio)
            {
                totalMascotas++;
            }
            if(mascotas[i].vacunado == 's')
            {
                contadorVacunados++;
            }
        }

        if(!contadorVacunados)
        {
            printf("No hay mascotas vacunadas en el sistema. \n");
        }
        else
        {
            printf("        *** Informe promedio de mascotas vacunadas ***\n");
            printf(" --------------------------------------------------------\n\n");
            promedio= (float) contadorVacunados/totalMascotas;
            printf("El total de mascotas cargadas en sistema es: %d\n", totalMascotas);
            printf("El total de mascotas vacunadas es: %d\n", contadorVacunados);
            printf("El promedio de mascotas vacunadas es: %.2f\n", promedio);
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarIdMascota(eMascota mascotas[], int tam, int id){
    int esValido = 0;
    int indice;

    for(int i=0; i<tam ; i++){
        if(!mascotas[i].estaVacio && mascotas[i].idMascota == id){
            indice= i;
            break;
        }
    }
    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}
