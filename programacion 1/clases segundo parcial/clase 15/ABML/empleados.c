//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "empleados.h"
#include "funciones.h"

#define ARCH	"./bin.dat"
#define ESC 27
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int menu()
{
    int opcion;

    printf("-------ABML-------\n");
    printf("1-Alta empleado\n");
    printf("2-Baja empleado\n");
    printf("3-Modificar empleado\n");
    printf("4-Listar empleados\n");
    printf("5-Salir\n");

    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. Reingrese: ", 1, 5);

    return opcion;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int inicializarEmpleados (eEmpleado* emp, int tamEmp)
{
    int error=1;

    if (emp!=NULL && tamEmp>0)
    {
        for (int i=0; i<tamEmp; i++)
        {
            (emp+i)->itsEmpty = 1;
        }
        error = 0;
    }

    return error;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int buscarEspacio (eEmpleado* emp, int tamEmp)
{
    int* indice = (int*) malloc(sizeof(int));
    *indice=-1;

    for (int i=0; i<tamEmp; i++)
    {
         if ((emp+i)->itsEmpty == 1)
         {
             *indice = i;
             break;
         }

    }

    return *indice;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int buscarLegajo (eEmpleado* emp, int tamEmp, int* legajo)
{
    int* indice = (int*) malloc(sizeof(int));
    *indice=0;

    for (int i=0; i<tamEmp; i++)
    {
        if ((emp+i)->itsEmpty == 0 && (emp+i)->legajo == *legajo)
        {
            *indice = i;
            break;
        }
    }

    return *indice;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int altaEmpleado (FILE* bin, eEmpleado* emp, int tamEmp, int contador)
{
    int* indiceLibre = (int*) malloc(sizeof(int));
    int error = 1;

    if ((bin=fopen(ARCH,"rb+"))==NULL)
    {
        if ((bin=fopen(ARCH,"wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            return 0;
        }
   }

    *indiceLibre=buscarEspacio(emp, tamEmp);

    if (*indiceLibre == -1)
    {
        printf("\nNo hay espacio en el sistema\n\n");
    }
    else
    {
        do
        {
            getString((emp+*indiceLibre)->nombre, "Ingrese nombre: ", "No entra en el rango. Reingrese: ", 0, 20);

            validarDosChar(&(emp+*indiceLibre)->sexo, "Ingrese sexo: ", "Solo m/f. Reingrese: ", 'f', 'm');

            getFloat(&(emp+*indiceLibre)->sueldo, "Ingrese sueldo: ", "No entra en el rango. Reingrse: ", 0, 100000);

            (emp+*indiceLibre)->legajo = 1;
            (emp+*indiceLibre)->legajo = (emp+*indiceLibre)->legajo + contador;
            (emp+*indiceLibre)->itsEmpty = 0;

            /*fprintf(bin, "%s", (emp+*indiceLibre)->nombre);
            fprintf(bin, "%c", &(emp+*indiceLibre)->sexo);
            fprintf(bin, "%f", &(emp+*indiceLibre)->sueldo);
            fprintf(bin, "%d", &(emp+*indiceLibre)->legajo);
            */

            fwrite(&emp, sizeof(emp), 1, bin);

            printf("\nPresione ESC para terminar");
        }while ((getche())!=ESC);

        rewind (bin);

        printf("\nAlta empleado exitosa!!\n\n");

        error = 0;
    }

    return error;
}
