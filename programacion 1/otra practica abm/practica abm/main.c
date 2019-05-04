#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "input.h"
#include "funciones.h"

#define TAM_EMPLEADOS 5
#define TAM_MENUS 5
#define TAM_SECTOR 5
#define TAM_ALMUERZO 10

int main()
{
    eEmpleados lista[TAM_EMPLEADOS];
    eMenus menus[TAM_MENUS];
    eSectores sectores[TAM_SECTOR];
    eAlmuerzo almuerzos[TAM_ALMUERZO];

    char seguir='s';
    char respuesta;
    int contadorLegajo=0;
    int contadorAlmuerzo=0;

    inicializarEmpleados(lista, TAM_EMPLEADOS);
    hardcode(lista, TAM_EMPLEADOS, sectores, TAM_SECTOR, menus, TAM_MENUS);
    //inicializarAlmuerzos(almuerzos, TAM_ALMUERZO);
    do
    {
        switch (menu())
        {


            case 1:
                system("cls");

                //contadorLegajo++;
                altaEmpleado(lista, TAM_EMPLEADOS, sectores, TAM_SECTOR, contadorLegajo);
                contadorLegajo++;
                break;
            case 2:
                system("cls");
                bajaEmpleado(lista, TAM_EMPLEADOS);
                break;
            case 3:
                system("cls");
                modificarEmpleado(lista, TAM_EMPLEADOS, sectores, TAM_SECTOR);
                break;
            case 4:
                system("cls");
                ordenarEmpleados(lista, TAM_EMPLEADOS);
                mostrarEmpleados(lista, TAM_EMPLEADOS, sectores, TAM_SECTOR);
                break;
            case 5:
                system("cls");
                altaAlmuerzo(almuerzos, TAM_ALMUERZO, lista,TAM_EMPLEADOS, menus,TAM_MENUS, contadorAlmuerzo);
                contadorAlmuerzo++;
                break;
            case 6:
                system("cls");
                mostrarAlmuerzo(lista, TAM_EMPLEADOS, menus, TAM_MENUS, almuerzos, TAM_ALMUERZO);
                break;
            case 7:
                system("cls");
                mostrarEmpleadosPorSector (lista, TAM_EMPLEADOS, sectores, TAM_SECTOR);
                break;
            case 8:

                getCharGenero(&respuesta, "Desea salir? Ingrese s/n: ","Opcion invalida. Reingrese: ", 'n', 's');

                if (respuesta=='s')
                {
                    seguir='n';
                }

                system("cls");
                break;
            default:
                system("cls");
                printf("\nOperacion invalida!!\n\n");
                break;
        }

    }while(seguir=='s');
    return 0;
}
