#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

#define ARCH	".\\bin.dat"
#define TAM_EMP 2

int main()
{
    FILE* bin;
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));
    char seguir = 's';
    char salir;
    int contadorLegajo = 0;
    int estadoIni;

    estadoIni = inicializarEmpleados(lista, TAM_EMP);

    if (estadoIni == 1)
    {
        printf("\nNo se pudo inicializar empleados\n\n");
        system("pause");
        exit(1);
    }

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");


                altaEmpleado (bin, lista, TAM_EMP, contadorLegajo);


                contadorLegajo++;


                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                system("cls");
                validarDosChar(&salir, "Desea salir? Ingrese s/n: ", "Solo s/n. Reingrese: ",  's', 'n');

                if (salir == 's')
                {
                    seguir = 'n';
                }

                break;

            default:
                system("cls");
                printf("\nOperacion invalida!!\n\n");

                break;


        }

    }while (seguir == 's');


    return 0;
}
