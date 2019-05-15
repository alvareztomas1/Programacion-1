#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"
#include "sector.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char desc[20];

}eSector;

void obtenerSector (char vec[],eSector sec[], int tamSec, int id)
void mostrarSector (eEmpleado vec[], int tam, eSector sec[], int tamSec);
void mostrarCantidadEmpleadoxSector(eEmpleado vec[], int tam, eSector sec[], int tamSec)


#endif
