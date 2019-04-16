#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 3
//------------------------------------------------------------------------------------------
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;

}eEmpleado;
//------------------------------------------------------------------------------------------
void inicializarEmpleados (eEmpleado vec[], int tam);
void mostrarEmpleado (eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
int buscarLibre (eEmpleado vec[], int tam);
//------------------------------------------------------------------------------------------
int main()
{
    int flag=0;
    int rta;
    char salir;
    eEmpleado lista[TAM]={{111,"Juan",'m',30000,1}, {222,"Ana",'f',32000,1}, {333,"Franco",'m',15000,0}};

    inicializarEmpleados(lista, TAM);

    do
    {
        printf ("-----------ABM empleados-----------\n\n");
        printf("\n1-Alta empleado\n2-Baja empleado\n3-Modificacion Empleado\n4-Listar\n5-Ordenar\n6-Salir");
        fflush (stdin);
        printf ("\n\n");
        printf ("Ingrese opcion: ");
        scanf("%d", &rta);

        switch (rta)
        {
            case 1:
                printf ("\nAlta empleado\n\n");
                system("pause");
                break;
            case 2:
                printf ("\nBaja empleado\n\n");
                system("pause");
                break;
            case 3:
                printf ("\nModificacion empleado\n\n");
                system("pause");
                break;
            case 4:
                //printf ("\nListar\n\n");

                mostrarEmpleados(lista, TAM);
                system("pause");

                break;
            case 5:
                printf ("\nOrdenar\n\n");
                system("pause");
                break;
            case 6:
                printf ("Desea continuar? Ingrese s/n: ");
                fflush(stdin);
                scanf ("%c", &salir);

                tolower(salir);

                if (salir=='n')
                {
                    salir=='n';
                }
                system("cls");
                break;
        }

    printf ("\n\n");
    }while (salir=='s');


        return 0;
}
//------------------------------------------------------------------------------------------
void inicializarEmpleados (eEmpleado vec[], int tam)
{
    for (int i=0;i<tam;i++)
    {
        vec[i].estado=0;
    }
}
//------------------------------------------------------------------------------------------
void mostrarEmpleado (eEmpleado emp)
{
    printf (" %d   %10s   %c   %.2f\n", emp.estado, emp.nombre, emp.sexo, emp.sueldo);
}
//------------------------------------------------------------------------------------------
void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador=0;
    printf ("\nLegajo    Nombre  Sexo  Sueldo\n");
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
        printf ("No hay empleado que listar\n\n");
    }
}
//------------------------------------------------------------------------------------------
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
