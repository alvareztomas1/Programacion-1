#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"
#include "input.h"

#define CANT_EMPLEADOS 10
#define CANT_SECTORES 5
#define CANT_MENUS 5
#define CANT_ALMUERZOS 2000


int main()
{

    char seguir='n';
    char salir;
    int contadorLegajo=0;
    eEmpleados lista[CANT_EMPLEADOS];/*=
    {
        {1, "Tomas", "Alvarez", 'm', 50000, {03,12,2018}, 2, 1},
        {2, "Julian", "Perez", 'm', 20000, {07,9,2017}, 5, 1},
        {3, "Florencia", "Cortes", 'f', 30000, {03,12,2010}, 1, 1},
        {4, "Julieta", "Cortes", 'f', 35000, {22,06,2011}, 2, 1},
        {5, "Ramon", "Abila", 'm', 55000, {17,12,2009}, 3, 1},

    };
*/
    eSectores sectores[CANT_SECTORES]=
    {
        {1, "RRHH"},
        {2, "Sistemas"},
        {3, "Seguridad"},
        {4, "Ventas"},
        {5, "Legales"},
    };
    eMenus menus[CANT_MENUS]=
    {
        {1, "Ensalada", 70},
        {2, "Hamburguesa de Garbanzo", 120},
        {3, "Tacos veganos", 95},
        {4, "Tarta de acelga", 90},
        {5, "Tortilla de espinaca", 100},
    };
    eAlmuerzos almuerzo[CANT_ALMUERZOS];

    inicializarEmpleado(lista,CANT_EMPLEADOS);

   do
   {
       switch(menu())
        {
            case 1:
                //printf ("1-Alta empleado\n");
                contadorLegajo++;
                altaEmpleado(lista,CANT_EMPLEADOS,sectores,CANT_SECTORES, contadorLegajo, almuerzo);
                break;
            case 2:
                bajaEmpleado(lista,CANT_EMPLEADOS);
                //printf ("2-Baja empleado\n");
                break;
            case 3:
                //printf ("3-Modificar empleado\n");
                modificarEmpleado(lista,CANT_EMPLEADOS,sectores,CANT_SECTORES);
                break;
            case 4:
                // printf ("4-Listar empleado\n");
                ordenarEmpleados(lista, CANT_EMPLEADOS);
                mostrarEmpleados(lista,CANT_EMPLEADOS,sectores,CANT_SECTORES);

                break;
            case 5:
                //printf ("5-Alta almuerzo\n");
                altaAlmuerzo(lista, CANT_EMPLEADOS, menus, CANT_MENUS, almuerzo);
                break;
            case 6:
                //printf ("6-Baja almuerzo\n");
                break;
            case 7:
                mostrarAlmuerzos(lista, CANT_EMPLEADOS, menus, CANT_MENUS, almuerzo, CANT_ALMUERZOS);
                break;
            case 8:
                //printf ("9-Salir\n\n");
                printf ("Desea salir? Ingrese s/n: ");
                fflush(stdin);

                salir=getche();

                printf ("\n");
                system("pause");

                if(tolower(salir)=='s')
                {
                    seguir='s';
                }
                system("cls");

                break;
            default:
                system("cls");
                printf ("No es una opcion valida\n\n");

                break;
        }
   }while (seguir=='n');

    return 0;
}



