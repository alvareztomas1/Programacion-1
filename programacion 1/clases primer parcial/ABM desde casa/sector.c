#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "sector.h"
#include "empleado.h"

void obtenerSector (char vec[],eSector sec[], int tamSec, int id)
{
    for (int i=0;i<tamSec;i++)
    {
        if (id==sec[i].id)
        {
            strcpy(vec,sec[i].desc);
            break;
        }
    }
}
//---------------------------------------------------------------------------------
void mostrarSector (eEmpleado vec[], int tam, eSector sec[], int tamSec)
{
    system("cls");

    for (int i=0;i<tamSec;i++)
    {
        printf ("Sector: %s\n\n", sec[i].desc);
        for (int j=0;j<tam;j++)
        {
            if((vec[j].idSector==sec[i].id) && vec[j].estado==1)
            {
                mostrarEmpleado(vec[j],sec,tamSec);
            }

        }
    }

    printf ("\n\n");
}
//---------------------------------------------------------------------------------
void mostrarCantidadEmpleadoxSector(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{
    int contador;
    system("cls");

    for (int i=0;i<tamSec;i++)
    {
        contador=0;
        printf ("Sector: %s\n", sec[i].desc);

        for (int j=0;j<tam;j++)
        {

            if((vec[j].idSector==sec[i].id) && vec[j].estado==1)
            {
                contador++;
            }

        }

        printf ("Cantidad: %d\n\n", contador);
    }
}

