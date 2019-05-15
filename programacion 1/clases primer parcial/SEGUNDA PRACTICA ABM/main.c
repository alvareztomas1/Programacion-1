#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"

#define TAM_EMPLEADOS 5
#define TAM_MENUS 5
#define TAM_SECTORES 5
#define TAM_ALMUERZOS 5

int main()
{
    eEmpleados lista[TAM_EMPLEADOS]
    =
    {
        {1, "Alvarez", "Tomas", 'm', 50000, {10,12,2011}, 1, 0},
        {2, "Caballero", "Julian", 'm', 15000, {04,07,2013}, 2, 0},
        {3, "Cortes", "Florencia", 'f', 30000, {21,03,2005}, 1, 0},
        {4, "Abila", "Ramon", 'm', 60000, {17,03,2009}, 4, 0},
        {5, "Cortes", "Julieta", 'f', 35000, {12,10,2010}, 3, 0},
    };

    eMenus menus[TAM_MENUS]
    =
    {
        {1, "Tarta", 40},
        {2, "Fideos", 70},
        {3, "Tortilla", 65},
        {4, "Sanguche", 50},
        {5, "Sopa", 50},
    };

    eSectores sectores[TAM_SECTORES]
    =
    {

        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Ventas"},
        {4, "Legales"},
        {5, "Seguridad"},
    };

    eAlmuerzo almuerzo[TAM_ALMUERZOS];
    int seguir='s';
    int salir;
    int contadorLegajo=0;
    int contadorAlmuerzo=0;

  // inicializarEmpleados(lista, TAM_EMPLEADOS);

    do
    {
       // hardcode(lista, TAM_EMPLEADOS, sectores, TAM_SECTORES, menus, TAM_MENUS);
        switch(menu())
        {
            case 1:
                system("cls");
                contadorLegajo++;
                altaEmpleado(lista, TAM_EMPLEADOS, sectores, TAM_SECTORES, almuerzo, contadorLegajo);

                break;
            case 2:
                bajaEmpleado(lista, TAM_EMPLEADOS);
                system("cls");
                break;
            case 3:
                system("cls");
                modificarEmpleado(lista, TAM_EMPLEADOS, sectores, TAM_SECTORES);
                break;
            case 4:
                system("cls");
                ordenarEmpleados(lista, TAM_EMPLEADOS);
                mostrarEmpleados(lista, TAM_EMPLEADOS, sectores, TAM_SECTORES);
                break;
            case 5:
                system("cls");
                contadorAlmuerzo++;
                altaAlmuerzo(lista, TAM_EMPLEADOS, sectores, TAM_SECTORES, menus, TAM_MENUS, almuerzo, contadorAlmuerzo);
                break;
            case 6:
                mostrarAlmuerzo(lista, TAM_EMPLEADOS, menus, TAM_MENUS, almuerzo, TAM_ALMUERZOS);
                break;
            case 7:
                printf ("\nDesea salir? Ingrese s/n: ");
                salir=getche();
                printf("\n");
                system("pause");

                if (tolower(salir)=='s')
                {
                    seguir='n';
                }

                system("cls");
                break;
            default:
                printf ("\nOperacion inexistente\n\n");
                break;


        }

    }while (seguir=='s');



    return 0;
}
