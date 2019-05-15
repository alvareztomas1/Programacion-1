#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"

#define TAM_EMPLEADOS 100

int main()
{
    eEmpleado lista[TAM_EMPLEADOS];
    /*=
    {
        {0, "Tomas", "Alvarez", 50000, 1,0 },
        {1, "Florencia", "Cortes", 30000, 4, 0},
        {2, "Julieta", "Cortes", 35000, 3, 0},
        {3, "Bonavena", "Julio", 60000, 2, 0},
        {4, "Ramon", "Abila", 30000, 1, 0},
    };
*/
    char seguir='s';
    char salir;
    int contadorLegajo=1;
    int estadoAlta;
    int estadoBaja;
    int hayEmpleado=0;
    int estadoMostrar;

    inicializarEmpleados(lista, TAM_EMPLEADOS);

    do
    {

        switch (menu())
        {

            case 1:

                estadoAlta = altaEmpleado(lista, TAM_EMPLEADOS, contadorLegajo);

                if (estadoAlta==-1)
                {
                    printf("\nAlta empleado erronea!!\n\n");
                }
                else
                {
                    printf("\nAlta empleado exitosa!!\n\n");
                    contadorLegajo++;
                    hayEmpleado=1;
                }
                system("pause");
                system("cls");
                break;
            case 2:



                break;
            case 3:
                if (hayEmpleado==0)
                {
                    printf("\nNo hay empleados que dar de baja!!\n\n");
                }
                else
                {
                    estadoBaja=bajaEmpleado(lista, TAM_EMPLEADOS);

                    if (estadoBaja==-1)
                    {
                        printf("\nOperacion erronea!!\n\n");

                    }
                    else
                    {
                        printf("\nOperacion exitosa!!\n\n");
                    }
                }


                system("pause");
                system("cls");
                break;
            case 4:



                switch (subMenu())
                {

                    case 1:

                        if (hayEmpleado==0)
                        {
                            printf("\nNo hay empleados que mostrar!!\n\n");
                        }
                        else
                        {
                            ordenarEmpleados(lista, TAM_EMPLEADOS);
                            estadoMostrar=mostrarEmpleados(lista, TAM_EMPLEADOS);
                            system("pause");
                        }
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    default:
                        printf("\nOpcion invalida!!\n\n");
                        break;
                }

                break;
            case 5:
                system("cls");

                printf("\nDesea salir? Ingrese s/n: ");
                fflush(stdin);
                salir=getche();
                printf("\n");
                system("pause");

                if (tolower(salir)=='s')
                {
                    seguir='n';
                }
                break;

            default:
                system("cls");
                printf("\nOpecion invalida!!\n\n");
                break;
        }
        fflush(stdin);
    }while (seguir=='s');

    return 0;
}
