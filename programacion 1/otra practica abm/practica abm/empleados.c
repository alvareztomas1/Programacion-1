#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "empleados.h"
#include "input.h"
#include "funciones.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu()
{
    int opcion;

    printf("----------ABM----------\n\n");
    printf("1-Alta empleado\n");
    printf("2-Baja empleado\n");
    printf("3-Modificar empleado\n");
    printf("4-Listar empleado\n");
    printf("5-Alta almuerzo\n");
    printf("6-Listar almuerzo\n");
    printf("7-Listar empleados por sector\n");
    printf("8-Listar cantidad de empleados por sector\n");
    printf("9-Listar sector con mas empleados\n");
    printf("10-Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarEmpleados (eEmpleados emp[], int tamEmp)
{
    for (int i=0;i<tamEmp;i++)
    {
        emp[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hardcode (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eMenus men[], int tamMen)
{
    inicializarEmpleados(emp, tamEmp);

    eEmpleados lista[]=
    {
        {0, "Alvarez", "Tomas", 'm', 50000, {10,12,2011}, 1,0},
        {1, "Caballero", "Julian", 'm', 15000, {04,07,2013}, 3, 0},
        {2, "Cortes", "Florencia", 'f', 30000, {21,03,2005}, 5, 0},
        {3, "Abila", "Ramon", 'm', 60000, {17,03,2009}, 3, 0},
        {4, "Cortes", "Julieta", 'f', 35000, {12,10,2010}, 2, 0},
    };

    for (int i=0;i<tamEmp;i++)
    {
        emp[i]=lista[i];
    }

    eSectores sectores[]=
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Ventas"},
        {4, "Legales"},
        {5, "Seguridad"},
    };

    for (int i=0;i<tamSec;i++)
    {
        sec[i]=sectores[i];
    }

    eMenus menus[]=
    {
        {1, "Tarta", 40},
        {2, "Fideos", 70},
        {3, "Tortilla", 65},
        {4, "Sanguche", 50},
        {5, "Sopa", 50},
    };

    for (int i=0;i<tamMen;i++)
    {
        men[i]=menus[i];
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLibre (eEmpleados emp[], int tamEmp)
{
    int indiceLibre=-2;

    for (int i=0;i<tamEmp;i++)
    {
        if (emp[i].itsEmpty==1)
        {
            indiceLibre=i;
            break;
        }
    }

    return indiceLibre;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLegajo (eEmpleados emp[], int tamEmp, int legajo)
{
    int indiceLegajo=-2;

    for (int i=0;i<tamEmp;i++)
    {
        if (emp[i].itsEmpty==0 && emp[i].legajo==legajo)
        {
            indiceLegajo=i;
            break;
        }
    }

    return indiceLegajo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, int contador)
{
    int espacioLibre;
    espacioLibre=buscarLibre(emp, tamEmp);

    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio en el sistema\n\n");
    }
    else
    {
        getString(emp[espacioLibre].apellido, "Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
        getString(emp[espacioLibre].nombre, "Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
        getCharGenero(&emp[espacioLibre].sexo, "Ingrese sexo: ", "Solo m o f. Reingrese: ", 'f', 'm');
        getFloat(&emp[espacioLibre].sueldo, "Ingrese sueldo: ", "No entra en el rango. Reingrese: ", 0, 100000);
        getInt(&emp[espacioLibre].fechaDeIngreso.dia, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 31);
        getInt(&emp[espacioLibre].fechaDeIngreso.mes, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 12);
        getInt(&emp[espacioLibre].fechaDeIngreso.anio, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1900, 2019);

        for (int i=0;i<tamSec;i++)
        {
            printf("%d-%s\n", sec[i].id, sec[i].desc);
        }

        getInt(&emp[espacioLibre].idSector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1, 5);


        emp[espacioLibre].legajo=0;
        emp[espacioLibre].legajo+=contador;
        emp[espacioLibre].itsEmpty=0;

        printf("\nAlta empleado exitosa!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bajaEmpleado (eEmpleados emp[], int tamEmp)
{
    int legajo;
    int busquedaLegajo;
    char respuesta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    busquedaLegajo=buscarLegajo(emp, tamEmp, legajo);

    if (busquedaLegajo==-2)
    {
        printf("\nLegajo inexistente!!\n\n");

    }
    else
    {
        printf("\nLegajo nro %d-%s, %s\n\n", emp[busquedaLegajo].legajo, emp[busquedaLegajo].apellido, emp[busquedaLegajo].nombre);

        getCharGenero(&respuesta, "Desea continuar? Ingrese s/n: ", "Solo 's' o 'n'. Reingrese: ", 'n', 's');

        if (respuesta=='s')
        {
            emp[legajo].itsEmpty=-1;
            printf("\nOperacion exitosa!!\n\n");
        }
        else
        {
            printf("\nOperacion cancelada!!\n\n");
        }
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarEmpleado (eEmpleados emp, eSectores sec[], int tamSec)
{
    char nombreSector[51];

    copiarSector(nombreSector, emp.idSector, sec, tamSec);

    printf("%02d %15s %15s  %6c        %6.2f      %02d/%02d/%4d %10s\n",emp.legajo,  emp.apellido, emp.nombre, emp.sexo, emp.sueldo, emp.fechaDeIngreso.dia ,emp.fechaDeIngreso.mes, emp.fechaDeIngreso.anio, nombreSector);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarEmpleados (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    int contador=0;

    printf ("LEGAJO     APELLIDO         NOMBRE      SEXO       SUELDO    FECHA DEINGRESO   SECTOR\n");

    for (int i=0;i<tamEmp;i++)
    {
        if (emp[i].itsEmpty==0)
        {

            mostrarEmpleado(emp[i], sec, tamSec);
            contador++;
        }
    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void copiarSector (char nombreSector[], int id, eSectores sec[], int tamSec)
{
    for (int i=0;i<tamSec;i++)
    {
        if (sec[i].id==id)
        {
            strcpy(nombreSector, sec[i].desc);
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarEmpleados (eEmpleados emp[], int tamEmp)
{
    eEmpleados aux;

    for (int i=0;i<tamEmp-1;i++)
    {
        for (int j=i+1;j<tamEmp;j++)
        {
            if (strcmp(emp[i].apellido, emp[j].apellido)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
            else if (strcmp(emp[i].apellido, emp[j].apellido)>0 && strcmp(emp[i].nombre, emp[j].nombre)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    int legajo;
    int busquedaLegajo;
    char respuesta;
    int opcionM;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    busquedaLegajo=buscarLegajo(emp, tamEmp, legajo);

    if (busquedaLegajo==-2)
    {
        printf("\nLegajo inexistente en el sistema.\n\n");
    }
    else
    {
        printf("\nLegajo nro %d-%s, %s\n\n", emp[busquedaLegajo].legajo, emp[busquedaLegajo].apellido, emp[busquedaLegajo].nombre);
        getCharGenero(&respuesta, "Desea continuar? Ingrese s/n: ", "Solo 's' o 'n'. Reingrese: ", 'n', 's');

        if  (respuesta=='s')
        {
            printf("1-Apellido\n");
            printf("2-Nombre\n");
            printf("3-Sexo\n");
            printf("4-Sueldo\n");
            printf("5-Fecha de ingreso\n");
            printf("6-Sector\n");
            printf("7-Salir\n\n");

            printf("Ingrese opcion: ");
            scanf("%d", &opcionM);


            switch(opcionM)
            {
                case 1:
                    getString(emp[busquedaLegajo].apellido, "Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 2:
                    getString(emp[busquedaLegajo].nombre, "Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 3:
                    getCharGenero(&emp[busquedaLegajo].sexo, "Ingrese sexo: ", "Solo m o f. Reingrese: ", 'f', 'm');
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 4:
                    getFloat(&emp[busquedaLegajo].sueldo, "Ingrese sueldo: ", "No entra en el rango. Reingrese: ", 0, 100000);
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 5:
                    getInt(&emp[busquedaLegajo].fechaDeIngreso.dia, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 31);
                    getInt(&emp[busquedaLegajo].fechaDeIngreso.mes, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 12);
                    getInt(&emp[busquedaLegajo].fechaDeIngreso.anio, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1900, 2019);
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 6:
                     for (int i=0;i<tamSec;i++)
                    {
                        printf("%d-%s\n", sec[i].id, sec[i].desc);
                    }
                    getInt(&emp[busquedaLegajo].idSector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1, 5);
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 7:
                    break;
                default:
                    system("cls");
                    printf("\nOperacion invalida!!\n\n");
                    break;

            }
        }
        else
        {
            printf("\nOperacion cancelada!!\n\n");
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarAlmuerzos (eAlmuerzo alm[], int tamAlm)
{
    for (int i=0;i<tamAlm;i++)
    {
        alm[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarAlmuerzoLibre (eAlmuerzo alm[], int tamAlm)
{
    int indiceAlmuerzo=-2;

    for (int i=0;i<tamAlm;i++)
    {

        if (alm[i].itsEmpty==1)
        {

            indiceAlmuerzo=i;
            break;
        }

    }

    return indiceAlmuerzo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaAlmuerzo (eAlmuerzo alm[], int tamAlm, eEmpleados emp[], int tamEmp, eMenus men[],int tamMen, int contador)
{
    int busquedaLegajo;
    int espacioLibre;
    int legajo;
    char respuesta;

    espacioLibre=buscarAlmuerzoLibre(alm, tamAlm);


    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio en el sistema!!\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        busquedaLegajo=buscarLegajo(emp, tamEmp, legajo);

        if (busquedaLegajo==-2)
        {
            printf("\nLegajo inexistente en el sistema!!\n\n");
        }
        else
        {
            printf("\nLegajo nro %d-%s, %s\n\n", emp[busquedaLegajo].legajo, emp[busquedaLegajo].apellido, emp[busquedaLegajo].nombre);
            getCharGenero(&respuesta, "Desea continuar? Ingrese s/n: ","Solo 's' o 'n'. Reingrese: ", 's', 'n');

            if (respuesta=='s')
            {
                for (int i=0;i<tamMen;i++)
                {
                    printf("%d-%s\n", men[i].idMenu, men[i].desc);
                }
                printf("\n");

                getInt(&alm[espacioLibre].idMenu, "Ingrese opcion: ", "Opcion invalida. Reingrese: ", 1, 5);
                getInt(&alm[espacioLibre].fechaDeAlmuerzo.dia, "Ingrese dia: ", "Fecha no valida. Reingrese: ", 1, 31);
                getInt(&alm[espacioLibre].fechaDeAlmuerzo.mes, "Ingrese mes: ", "Fecha no valida. Reingrese: ", 1, 12);
                getInt(&alm[espacioLibre].fechaDeAlmuerzo.anio, "Ingrese anio: ", "Fecha no valida. Reingrese: ", 2018, 2019);



                alm[espacioLibre].itsEmpty=0;
                alm[espacioLibre].idAlmuerzo=0;
                alm[espacioLibre].idAlmuerzo+=contador;
                alm[espacioLibre].legajoEmpleado=legajo;

                printf("\nOperacion exitosa!!\n\n");


            }
            else
            {
                printf("\nOperacion cancelada!!\n\n");
            }

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAlmuerzo (eEmpleados emp[], int tamEmp, eMenus men[],int tamMen, eAlmuerzo alm[], int tamAlm)
{
    printf("ALMUERZO    LEGAJO   APELLIDO      NOMBRE       MENU        FECHA\n");

    for (int i=0;i<tamMen;i++)
    {

        for (int j=0;j<tamAlm;j++)
        {

            if (alm[j].idMenu==men[i].idMenu)
            {

                for (int k=0;k<tamEmp;k++)
                {
                    if (emp[k].legajo==alm[j].legajoEmpleado && emp[k].itsEmpty==0)
                    {
                         printf("  %04d       %04d    %8s    %8s     %8s     %02d/%02d/%02d\n", alm[j].idAlmuerzo, emp[k].legajo, emp[k].apellido, emp[k].nombre, men[i].desc, alm[j].fechaDeAlmuerzo.dia, alm[j].fechaDeAlmuerzo.mes, alm[j].fechaDeAlmuerzo.anio);
                    }
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarEmpleadosPorSector (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    for (int i=0;i<tamSec;i++)
    {
        printf("Sector: %s\n", sec[i].desc);
        for (int j=0;j<tamEmp;j++)
        {
            if (sec[i].id==emp[j].idSector)
            {
                mostrarEmpleado(emp[i], sec, tamSec);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarCantidadEmpleadosPorSector (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    int contador;

    for (int i=0;i<tamSec;i++)
    {
        contador=0;

        printf("Sector: %s\n\n", sec[i].desc);

        for (int j=0;j<tamEmp;j++)
        {
            if (emp[j].idSector==sec[i].id && emp[j].itsEmpty==0)
            {
                contador++;

            }
        }

        printf("Cantidad empleados: %d\n\n", contador);
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSectorConMasEmpleados (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
     int contador;
     int max=0;
     char nombreSec[51];

    for (int i=0;i<tamSec;i++)
    {
        contador=0;



        for (int j=0;j<tamEmp;j++)
        {
            if (emp[j].idSector==sec[i].id && emp[j].itsEmpty==0)
            {
                contador++;

                if (contador>max)
                {
                    max=contador;
                    strcpy(nombreSec, sec[i].desc);
                }

            }


        }

    }
     printf("El sector con mas empleados tiene %d. Y es %s\n", max, nombreSec);
}

