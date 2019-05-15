#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "empleado.h"

#define TAM 5
#define TAM_SECTOR 5

//---------------------------------------------------------------------------------
int main()
{
    char seguir='s';
    char salir;
    char confirmaOrdenar;
    int mostroSector;
    eEmpleado lista[TAM]={
        {111,"Juan",'m',30000,{01,02,1999},1,1},
        {222,"Ana",'f',20000,{10,6,1980},3,1},
        {33,"Tom",'m',15000,{10,12,1999},4,1},
        {66,"Julio",'m',10000,{20,04,1972},3,1},
        {55,"Paula",'m',15000,{8,03,1990},5,1},

        };

    eSector sector[TAM_SECTOR]=
    {
        {1,"Sistemas"},
        {2,"RRHH"},
        {3,"Compras"},
        {4,"Ventas"},
        {5,"Legales"},
    };
//---------------------------------------------------------------------------------
   //inicializarEstado(lista,TAM);
//---------------------------------------------------------------------------------
    do
    {
        switch (menu())
        {
            case 1:
                //printf ("Alta empleado\n");
                altaEmpleado(lista,TAM,sector,TAM_SECTOR);
                system("pause");
                break;
            case 2:
                //printf ("Baja empleado\n");
                bajaEmpleado(lista,TAM);
                system("pause");
                break;
            case 3:
                //printf ("Modificar empleado\n");
                modificarEmpleado(lista,TAM);
                system("pause");
                break;
            case 4:
                //printf ("Ordenar empleados\n");
                printf ("Estas seguro que quiere ordenar? ingrese s/n:");
                fflush(stdin);
                confirmaOrdenar = getche();
                printf ("\n");
                if (tolower(confirmaOrdenar)=='s')
                {
                    confirmaOrdenar='n';
                    ordenarEmpleado(lista,TAM);
                    printf ("Operacion exitosa!\n");
                }
                else
                {
                    printf ("Operacion cancelada!\n");

                }

                system("pause");
                break;
            case 5:
                //printf ("Listar empleados\n");
                mostrarEmpleados(lista,TAM, sector,TAM_SECTOR);
                system("pause");
                break;
            case 6:
                //printf ("Listar sector con sector\n");
                mostrarSector(lista,TAM,sector,TAM_SECTOR);
                system("pause");
                break;

            case 7:

                mostrarCantidadEmpleadoxSector(lista,TAM,sector,TAM_SECTOR);
                system("pause");
                break;
            case 8:
                printf ("Desea salir? Ingrese s/n: ");
                fflush(stdin);
                salir = getche();
                printf ("\n");
                system("pause");

                if (tolower(salir)=='s')
                {
                    seguir='n';
                }

                system("cls");
                break;
            default:
                printf ("\nNo es una opcion valida\n\n");
                system("break");
            }
    }while(seguir=='s');

    return 0;
}
