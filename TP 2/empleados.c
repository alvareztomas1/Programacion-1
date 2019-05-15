#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"
#include "input.h"

int menu()
{
    int opcion;

    printf("---------ABM EMPLEADOS----------\n\n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Informes\n");
    printf("5-Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int subMenu()
{
    int respuesta;

    printf("----------INFORMES----------\n\n");
    printf("1-Listado empleados\n");
    printf("2-Total y promedio salarios\n");
    printf("3-Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &respuesta);

    return respuesta;
}

int inicializarEmpleados (eEmpleado emp[], int tam)
{
    int todoOk=-1;

    if (tam !=0)
    {
        for (int i=0;i<tam;i++)
        {
            emp[i].itsEmpty=1;
            todoOk=0;
        }
    }

    return todoOk;
}

int buscarLibre (eEmpleado emp[], int tam)
{
    int espacioLibre=-2;

    if (tam !=0)
    {
         for (int i=0;i<tam;i++)
        {
            if (emp[i].itsEmpty==1)
            {
                espacioLibre=i;
                break;
            }
        }
    }

    return espacioLibre;
}

int buscarEmpleado (eEmpleado emp[], int tam, int id)
{
    int indice=-1;

    if (tam!=0)
    {
        for (int i=0;i<tam;i++)
        {
            if (emp[i].id==id && emp[i].itsEmpty==0)
            {
                indice=i;
                break;
            }
        }
    }


    return indice;
}

int altaEmpleado (eEmpleado emp[], int tam, int contador)
{
    int todoOk=-1;
    int espacioLibre=-2;

    if (tam !=0)
    {
         for (int i=0;i<tam;i++)
        {
            if (emp[i].itsEmpty==1)
            {
                espacioLibre=i;
                break;
            }
        }
    }

    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio libre en el sistema!!\n\n");
    }
    else
    {
        getString(emp[espacioLibre].lastName, "Ingrese apellido: ","No entra en el rango. Reingrese: ", 0, 51);
        getString(emp[espacioLibre].name, "Ingrese nombre: ", "No entra en el rango. Reingrese: ", 0, 51);
        getFloat(&emp[espacioLibre].salary, "Ingrese sueldo: ", "No entar en el rango. Reingrese: ", 0, 1000000);
        getInt(&emp[espacioLibre].sector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1,5);

        emp[espacioLibre].id=0;
        emp[espacioLibre].id+=contador;
        emp[espacioLibre].itsEmpty=0;

        todoOk=0;

    }



    return todoOk;
}

int bajaEmpleado (eEmpleado emp[], int tam)
{
    int id;
    int busquedaId;
    char salida;
    int todoOk=-1;

    printf("Ingrese id: ");
    scanf("%d", &id);

    busquedaId=buscarEmpleado(emp, tam, id);

    if (busquedaId!=-1)
    {
        printf("Legajo %d-%s, %s\n\n", emp[busquedaId].id, emp[busquedaId].lastName, emp[busquedaId].lastName);
        printf("Desea continuar? Ingrese s/n: ");
        salida=getche();
        printf("\n");
        system("pause");

        if (tolower(salida)=='s')
        {
            emp[busquedaId].itsEmpty=1;
            todoOk=0;
        }
        else
        {
            printf("\nOperacion cancelada!!\n\n");
        }

    }
    else
    {

        printf("Legajo inexistente en el sistema!!\n");
    }

    return todoOk;
}

int mostrarEmpleados (eEmpleado emp[], int tam)
{
    int todoOk=-1;

    for (int i=0;i<5;i++)
    {
        if (emp[i].itsEmpty==0)
        {
            printf("ID   APELLIDO   NOMBRE  SUELDO   SECTOR\n");
            printf("%d   %-s    %-s   %.2f    %3d\n\n", emp[i].id, emp[i].lastName, emp[i].name, emp[i].salary, emp[i].sector);
            todoOk=0;
        }
    }

    return todoOk;
}


/*
int ordenarEmpleados (eEmpleado emp[], int tam)
{
    int todoOk=-1;
    eEmpleado aux;

    for (int i=0;i<tam-1;i++)
    {
        for (int j=i+1;j<tam;j++)
        {
            if(stricmp(emp[i].name, emp[j].name)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
            else if ((stricmp(emp[i].name, emp[j].name)>0) && emp[i].id>emp[j].id)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }

        }
    }


    return todoOk;
}
*/
