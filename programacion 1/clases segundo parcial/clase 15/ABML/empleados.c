#include <stdio.h>
#include <stdlib.h>
#include "input.h"

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int itsEmpty;

}eEmpleado;

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
}
