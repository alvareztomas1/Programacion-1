#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"

int menu(void)
{
    int rta;
    printf ("-----------ABM empleados-----------\n\n");
    printf("\n1-Alta empleado\n2-Baja empleado\n3-Modificacion Empleado\n4-Ordenar\n5-Listar\n6-Salir");
    fflush (stdin);
    printf ("\n\n");
    printf ("Ingrese opcion: ");
    scanf("%d", &rta);

        return rta;
}
//---------------------------------------------------------------------------------

int inicializarEstado (eEmpleado vec[], int tam)
{
    for (int i=0;i<tam;i++)
    {
        vec[i].estado=0;
    }
}
//---------------------------------------------------------------------------------

void mostrarEmpleado (eEmpleado emp)
{
    printf ("   %d       %s       %c       %.2f   %0d/%d/%d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaNac.dia, emp.fechaNac.mes, emp.fechaNac.anio);
}
//---------------------------------------------------------------------------------

void mostrarEmpleados (eEmpleado vec[], int tam)
{
    int contador=0;
    printf ("\n Legajo     Nombre      Sexo     Sueldo     Nacimiento\n");

    for (int i=0;i<tam;i++)
    {
        if (vec[i].estado==1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }
    if (contador==0)
    {
        printf ("No hay empleados que listar\n\n");
    }
}
//---------------------------------------------------------------------------------

int buscarLibre (eEmpleado vec[], int tam)
{
    int espacio=-1;
    for (int i=0;i<tam;i++)
    {
        if (vec[i].estado==0)
        {
            espacio=i;
        }
    }

    return espacio;
}
//---------------------------------------------------------------------------------

int buscarEmpleado (eEmpleado vec[], int tam, int legajo)
{
    int indiceLeg=-1;

    for (int i=0;i<tam;i++)
    {
        if (vec[i].estado==1 && vec[i].legajo==legajo)
        {
            indiceLeg=i;
        }
    }

    return indiceLeg;
}
//---------------------------------------------------------------------------------

void altaEmpleado (eEmpleado vec[], int tam)
{
    int esta;
    int indice;
    int legajo;

    indice=buscarLibre(vec, tam);

    if (indice==-1)
    {
        printf ("\nNo hay lugar en el sistema\n\n");
    }
    else
    {
        printf ("Ingrese legajo: ");
        scanf ("%d", &legajo);

        esta=buscarEmpleado(vec,tam,legajo);

        if (esta!=-1)
        {
            printf ("Ya esta ocupado ese nro de legajo");
            mostrarEmpleado(vec[esta]);
        }
        else
        {
            vec[indice].legajo=legajo;

            printf ("Ingrese nombre: ");
            fflush (stdin);
            gets(vec[indice].nombre);

            printf ("Ingrese sexo: ");
            fflush (stdin);
            scanf ("%c", &vec[indice].sexo);

            printf ("Ingrese sueldo: ");
            scanf ("%f", &vec[indice].sueldo);

            printf ("Ingrese dia de nacimiento: ");
            scanf ("%d", &vec[indice].fechaNac.dia);

            printf ("Ingrese mes de nacimiento: ");
            scanf ("%d", &vec[indice].fechaNac.mes);

            printf ("Ingrese anio de nacimiento: ");
            scanf ("%d", &vec[indice].fechaNac.anio);

            vec[indice].estado = 1;

            printf ("Alta empleado exitosa!\n");
        }

    }


}
//---------------------------------------------------------------------------------

void bajaEmpleado (eEmpleado vec[], int tam)
{
    int legajo;
    int indiceLeg;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indiceLeg=buscarEmpleado(vec, tam, legajo);

    if (indiceLeg==-1)
    {
        printf ("\nNo se encuentra el legajo en el sistema\n");
    }
    else
    {
        do
        {
            printf ("\nLegajo numero %d\n", vec[indiceLeg]);
            printf ("Esta seguro que quiere continuar? s/n: ");
            fflush(stdin);
            confirma=getche();
            printf ("\n");
            system("pause");


            if(tolower(confirma)=='n')
            {
                printf ("Baja cancelada!\n");
                break;
            }
            else
            {
                vec[indiceLeg].estado=0;
                printf ("\nBaja empleado exitosa!!\n");
            }

        }while (confirma!='s');

    }


}
//---------------------------------------------------------------------------------
void modificarEmpleado (eEmpleado vec[], int tam)
{
    int indiceLeg;
    int legajo;
    char continuar;
    int sueldo;

    printf ("Ingrese legajo: ");
    scanf ("%d", &legajo);

    indiceLeg=buscarEmpleado(vec, tam, legajo);

    if (indiceLeg==-1)
    {
        printf ("Legajo inexistente en el sistema\n");
    }
    else
    {
        do
        {
            printf ("Legajo numero %d\n", legajo);
            printf ("Esta seguro que quiere modificar? Ingrese s/n: ");
            fflush(stdin);
            continuar=getche();
            printf ("\n");
            system("pause");

            if (tolower(continuar)=='n')
            {
                printf ("Modificacion cancelada!\n");
                break;
            }
            else
            {
                printf ("Ingrese sueldo: ");
                scanf ("%d", &sueldo);

                vec[indiceLeg].sueldo=sueldo;
                printf ("Modificacion exitosa!!\n");
            }

        }while (continuar!='s');
    }
}
//---------------------------------------------------------------------------------

