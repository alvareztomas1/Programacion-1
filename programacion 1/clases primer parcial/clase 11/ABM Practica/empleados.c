#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "empleados.h"
#include "input.h"

int menu()
{
    int opcion;

    printf("-----ABM ALMUERZO EMPLEADOS-----\n\n");
    printf ("1-Alta empleado\n");
    printf ("2-Baja empleado\n");
    printf ("3-Modificar empleado\n");
    printf ("4-Listar empleado\n");
    printf ("5-Alta Almuerzo\n");
    printf ("6-Modificar Almuerzo\n");
    printf ("7-Listar Almuerzos\n\n");
    printf ("8-Salir\n\n");
    printf ("Ingrese opcion: ");

    scanf ("%d", &opcion);
    //system("pause");

    return opcion;
}

void inicializarEmpleado (eEmpleados emp[], int tamEmp)
{

    for (int i=0;i<tamEmp;i++)
    {
        emp[i].estado=0;
    }
}

int buscarLibre (eEmpleados emp[], int tamEmp)
{
    int libre=-1;

    for (int i=0;i<tamEmp;i++)
    {
        if (emp[i].estado==0)
        {
            libre=i;
            break;
        }
    }

    return libre;
}

int buscarLegajo (eEmpleados emp[], int tamEmp, int legajo)
{
    int indiceLegajo=-1;


    for (int i=0;i<tamEmp;i++)
    {
        printf ("\n\nANTES DE ENTRAR AL IF%d\n\n", i);
        if ((emp[i].legajo==legajo &&  emp[i].estado==1 ))
        {
            //printf ("\n\nEl estado es %d y El legajo es %d\n\n",emp[i].estado, emp[i].legajo);
            printf ("\n\n%d\n\n", i);
            indiceLegajo=i;
            printf ("\n\n%d\n\n", indiceLegajo);
            break;
        }
    }

    return indiceLegajo;
}

void mostrarEmpleado (eEmpleados emp, eSectores sec[], int tamSec)
{
    char nombreSector[51];

    obtenerSector(nombreSector, tamSec, sec, emp.idSector);

    printf ("%d         %5s         %5s       %c     %.2f     %.02d/%.02d/%d       %s\n", emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSector);
}

void mostrarEmpleados(eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    int contador=0;

    printf ("Legajo     Nombre     Apellido     Sexo     Sueldo    Fecha de ingreso    Sector\n");
    for (int i=0;i<tamEmp;i++)
    {
        if(emp[i].estado==1)
        {

            mostrarEmpleado(emp[i],sec,tamSec);

            contador++;
        }
    }
    if (contador==0)
    {
        printf ("No hay empleado que listar\n");
    }
}

void obtenerSector (char nombreSec[], int tamSec, eSectores sec[], int id)
{
    for (int i=0;i<tamSec;i++)
    {
        if (sec[i].id==id)
        {
            strcpy(nombreSec, sec[i].desc);
        }
    }

}

void altaEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, int contadorLegajo, eAlmuerzos alm[])
{
    int espacioLibre;
    char nombre[51];
    char apellido[51];
    char sexo;
    float sueldo;
    char auxNombre;
    char auxApellido;
    float auxSueldo;
    int auxDia;
    int auxMes;
    int auxAnio;


    espacioLibre=buscarLibre(emp,tamEmp);

    if (espacioLibre==-1)
    {
        printf ("No hay espacio en el sistema");
    }
    else
    {

        int auxLegajo=0;

        auxNombre=getString(emp[espacioLibre].nombre,"Ingrese nombre: ","Reingrese: ",0,51);
        auxApellido=getString(emp[espacioLibre].apellido,"Ingrese apellido (51 caracteres maximo): ", "Superaste los caracteres", 0, 51);


        printf ("Ingrese sexo: ");
        fflush(stdin);
        emp[espacioLibre].sexo=getche();
        printf ("\n");
        system("pause");

        auxSueldo=getFloat(&emp[espacioLibre].sueldo, "Ingrese sueldo: ", "No entro en el rango. Reingresa: ",0,300);

        auxDia=getInt(&emp[espacioLibre].fechaIngreso.dia,"Ingrese dia de ingreso: ", "No entra en el rango.Reingresa: ",0,31);
        auxMes=getInt(&emp[espacioLibre].fechaIngreso.mes, "Ingrese mes de ingreso: ", "No entra en el rango.Reingresa: ",1,12);
        auxAnio=getInt(&emp[espacioLibre].fechaIngreso.anio, "Ingrese año de ingreso: ", "No entra en el rango. REingresa: ", 1950,2019);

        for (int i=0;i<tamSec;i++)
        {
            printf ("%d-%s\n", sec[i].id, sec[i].desc);
        }
        printf ("Ingrese sector: ");
        scanf ("%d", &emp[espacioLibre].idSector);



        emp[espacioLibre].legajo=0;
        emp[espacioLibre].legajo+=contadorLegajo;

        system("cls");
        emp[espacioLibre].estado=1;

        alm[espacioLibre].legajoEmpleado=emp[espacioLibre].legajo;

        printf("\n\n el legajo es %d \n\n", alm[espacioLibre].legajoEmpleado);
        //printf("Se guarda en %d", espacioLibre);

        printf ("\nAlta empleado exitosa!!\n\n");

    }


}

void bajaEmpleado (eEmpleados emp[], int tamEmp)
{
    int buscaLegajo;
    int salir;

    printf ("Ingrese legajo: ");
    scanf ("%d", &buscaLegajo);

    for (int i=0;i<tamEmp;i++)
    {
        if (buscaLegajo==emp[i].legajo)
        {
            printf ("\nLegajo %d\n", emp[i].legajo);
            printf ("Esta seguro que quiere continuar? Ingrese s/n: ");
            salir=getche();
            printf ("\n");
            if (tolower(salir)=='s')
            {
                printf ("Operacion exitosa!!\n\n");
                emp[i].estado=0;
                break;
            }
            else
            {
                printf ("Operacion cancelada!!\n\n");
                break;
            }
        }
    }

}

void ordenarEmpleados (eEmpleados emp[], int tamEmp)
{
    eEmpleados aux;
    int auxSueldo;

    for (int i=0;i<tamEmp-1;i++)
    {
        for (int j=i+1;j<tamEmp;j++)
        {
            if (strcmp(emp[i].apellido,emp[j].apellido)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
        }
    }
}

void modificarEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    int opcionM;
    int busqueda;
    system("cls");

    printf ("1-Apellido\n");
    printf ("2-Nombre\n");
    printf ("3-Sexo\n");
    printf ("4-Salario\n");
    printf ("5-Fecha de ingreso\n");
    printf ("6-Sector\n");
    printf ("7-Salir\n\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcionM);

    switch(opcionM)
    {
        case 1:
            printf ("Ingrese legajo: ");
            scanf ("%d", &busqueda);
            for (int i=0;i<tamEmp;i++)
            {
                if (busqueda==emp[i].legajo)
                {
                    getString(emp[i].apellido,"Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
                    printf ("Operacion exitosa!!\n");
                    break;
                }
                else
                {
                    printf ("Legajo inexistente\n");
                    break;

                }
            }
            break;
        case 2:
            printf ("Ingrese legajo: ");
            scanf ("%d", &busqueda);
            for (int i=0;i<tamEmp;i++)
            {
                if (busqueda==emp[i].legajo)
                {
                    getString(emp[i].nombre,"Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
                    printf ("Operacion exitosa!!\n");
                    break;
                }
                else
                {
                    printf ("Legajo inexistente\n");
                    break;
                }
            }
            break;
        case 3:
            printf ("Ingrese legajo: ");
            scanf ("%d", &busqueda);
            for (int i=0;i<tamEmp;i++)
            {
                if (busqueda==emp[i].legajo)
                {
                    printf ("Ingrese sexo: ");
                    fflush(stdin);
                    emp[i].sexo=getche();
                    printf ("\n");
                    system("pause");

                    break;
                }
                else
                {
                    printf ("Legajo inexistente\n");
                    break;
                }
            }
            break;
        case 4:
            printf ("Ingrese legajo: ");
            scanf ("%d", &busqueda);
            for (int i=0;i<tamEmp;i++)
            {
                if (busqueda==emp[i].legajo)
                {
                    getFloat(&emp[i].sueldo,"Ingrese sueldo: ", "Supero los caracteres. Reingrese: ", 0, 100000);
                    printf ("Operacion exitosa!!\n");
                    break;
                }
                else
                {
                    printf ("Legajo inexistente\n");
                    break;
                }
            }
            break;
        case 5:
            printf ("Ingrese legajo: ");
            scanf ("%d", &busqueda);

            for (int i=0;i<tamEmp;i++)
            {
                if (busqueda!=emp[i].legajo)
                {
                    getInt(&emp[i].fechaIngreso.dia,"Ingrese dia de ingreso: ", "Supero los caracteres. Reingrese: ", 1, 31);
                    getInt(&emp[i].fechaIngreso.mes,"Ingrese mes de ingreso: ", "Supero los caracteres. Reingrese: ", 1, 12);
                    getInt(&emp[i].fechaIngreso.anio,"Ingrese anio de ingreso: ", "Supero los caracteres. Reingrese: ", 1950, 2019);

                    printf ("Operacion exitosa!!\n");
                    break;
                }
                else
                {
                    printf ("Legajo inexistente\n");
                    break;
                }
            }
            break;
        case 6:
            printf ("Ingrese legajo: ");
            scanf ("%d", &busqueda);
            for (int i=0;i<tamEmp;i++)
            {
                if (busqueda==emp[i].legajo)
                {
                    printf ("1-RRHH\n");
                    printf ("2-Sistemas\n");
                    printf ("3-Seguridad\n");
                    printf ("4-Ventas\n");
                    printf ("5-Legales\n");
                    getInt(&emp[i].idSector,"Ingrese sector: ","No entro en el rango", 1,5);

                    printf ("Operacion exitosa!!\n");
                    break;
                }
                else
                {
                    printf ("Legajo inexistente\n");
                    break;
                }
            }
            break;
        case 7:
            break;
        default:
            printf ("No es una opcion valida");
            break;
    }
}

void altaAlmuerzo (eEmpleados emp[], int tamEmp, eMenus men[], int tamMenu, eAlmuerzos alm[])
{
    int legajo;
    char salir;
    int indiceLegajo;

    printf ("Ingrese legajo: ");
    scanf ("%d", &legajo);

    indiceLegajo=buscarLegajo(emp, tamEmp, legajo);



    if (indiceLegajo==-1)
    {
        printf ("Legajo inexistente.");
    }
    else
    {
        printf ("Legajo nro %d,  ", emp[indiceLegajo].legajo, emp[indiceLegajo].apellido, emp[indiceLegajo].nombre);

        printf ("Estas seguro que quiere continuar? Ingrese s/n: ");
        fflush(stdin);
        salir=getche();
        printf ("\n");
        system("pause");

        if(tolower(salir)=='s')
        {
            getInt(&alm[indiceLegajo].fechaAlmuerzo.dia, "Ingrese dia: ","No entra en el rango: ", 1, 31);
            getInt(&alm[indiceLegajo].fechaAlmuerzo.mes,"Ingrese mes: ","No entra en el rango: ", 1, 12);


            printf ("1-Ensalada\n");
            printf ("2-Hamburguesa de garbanzo\n");
            printf ("3-Tacos veganos\n");
            printf ("4-Tarta de acelga\n");
            printf ("5-Tortilla de espinaca\n");

            getInt(&alm[indiceLegajo].idMenu,"Ingrese menu: ", "Opcion invalida", 1,5);

            printf ("Operacion exitosa!!\n");
        }

    }

}


void mostrarAlmuerzos (eEmpleados emp[], int tamEmp, eMenus men[], int tamMen, eAlmuerzos alm[], int tamAlm)
{
    printf ("\n ID   LEGAJO    APELLIDO    NOMBRE     MENU     PRECIO\n");

    for (int i=0;i<tamMen;i++)
    {
        for (int j=0;j<tamAlm;j++)
        {

            if (men[i].idMenu==alm[j].idAlmuerzo)
            {

                for (int k=0;k<tamEmp;k++)
                {

                    if (emp[k].estado==1 && alm[j].legajoEmpleado==emp[k].legajo)
                    {
                        printf ("\n\n el estado es %d EL LEGAJO ES %d \n\n", emp[k].estado, alm[j].legajoEmpleado);
                        printf ("FUNCA\n");
                        printf ("%04d   %04d    %s    %s    %s    %04d", alm[j].idAlmuerzo, emp[k].legajo, emp[k].nombre, men[i].desc,   men[i].precio);

                    }
                }
            }
        }
    }
}








