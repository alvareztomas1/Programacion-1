#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
    int opcion;

    printf("\n\n---------ABM EMPLEADOS---------\n\n");
    printf("1-Alta Empleado\n");
    printf("2-Baja Empleado\n");
    printf("3-Modificar Empleado\n");
    printf("4-Listar Empleado\n");
    printf("5-Alta Almuerzo\n");
    printf("6-Listar Almuerzo\n");
    printf("7-Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarEmpleados (eEmpleados emp[], int tamEmp)
{
    for (int i=0;i<tamEmp;i++)
    {
        emp[i].itsEmpty=1;
        emp[i].legajo=0;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hardcode (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eMenus men[], int tamMen)
{
    inicializarEmpleados(emp, tamEmp);

    eEmpleados lista[]=
    {
        {1, "Alvarez", "Tomas", 'm', 50000, {10,12,2011}, 1,0},
        {2, "Caballero", "Julian", 'm', 15000, {04,07,2013}, 3, 0},
        {3, "Cortes", "Florencia", 'f', 30000, {21,03,2005}, 5, 0},
        {4, "Abila", "Ramon", 'm', 60000, {17,03,2009}, 3, 0},
        {5, "Cortes", "Julieta", 'f', 35000, {12,10,2010}, 2, 0},
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
    int libre=-1;

    for (int i=0;i<tamEmp;i++)
    {
        if (emp[i].itsEmpty==1)
        {
            libre=i;
            break;
        }
    }

    return libre;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarLegajo (eEmpleados emp[], int tamEmp, int legajo)
{
    int indiceLegajo=-1;

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
void altaEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eAlmuerzo alm[], int contador)
{

    int indiceEspacio;


    indiceEspacio=buscarLibre(emp, tamEmp);

    if (indiceEspacio==-1)
    {
        printf ("\nNo hay espacio en el sistema\n");
    }
    else
    {

        getString(emp[indiceEspacio].apellido, "Ingrese apellido: ", "No entra en el rango. Reingrese: ",0, 51);

        getString(emp[indiceEspacio].nombre, "Ingrese nombre: ", "No entra en el rango. Reingrese: ",0, 51);

        getCharGenero(&emp[indiceEspacio].genero, "Ingrese sexo: ", "Sexo m o f. Reingrese", 'f', 'm');

        getFloat(&emp[indiceEspacio].sueldo, "Ingrese sueldo: ", "No entra en el rango. Reingrese: ", 0, 100000);

        getInt(&emp[indiceEspacio].fechaDeIngreso.dia, "Ingrese dia de ingreso: ", "Superaste el rango. Reingresa: ",1,31);

        getInt(&emp[indiceEspacio].fechaDeIngreso.mes, "Ingrese mes de ingreso: ", "Superaste el rango. Reingresa: ",1,12);

        getInt(&emp[indiceEspacio].fechaDeIngreso.anio, "Ingrese anio de ingreso: ", "Superaste el rango. Reingresa: ",1950,2019);

        for (int i=0;i<tamSec;i++)
        {
            printf ("%d-%s\n", sec[i].id, sec[i].desc);
        }
        getInt(&emp[indiceEspacio].idSector,"Ingrese sector: ", "No entra en el rango. Reingrese: ",1, 5);

        emp[indiceEspacio].legajo=0;
        emp[indiceEspacio].legajo+=contador;
        emp[indiceEspacio].itsEmpty=0;




        printf("\n\nAlta empleado exitosa!!\n\n");


    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEmpleado (eEmpleados emp, eSectores sec[], int tamSec)
{

    char nombreSec[51];

    copiarSector(nombreSec, sec, tamSec, emp.idSector);
    printf ("%02d %15s %15s  %6c        %6.2f      %02d/%02d/%4d %10s\n", emp.legajo, emp.apellido, emp.nombre, emp.genero, emp.sueldo, emp.fechaDeIngreso.dia, emp.fechaDeIngreso.mes, emp.fechaDeIngreso.anio, nombreSec);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEmpleados(eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
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
        printf ("\nNo hay empleado que listar\n\n");

    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void copiarSector (char sector[], eSectores sec[], int tamSec, int id)
{
    for (int i=0; i<tamSec;i++)
    {
        if (sec[i].id==id)
        {

            strcpy(sector, sec[i].desc);
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
            if (stricmp(emp[i].apellido,emp[j].apellido)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
            else if (stricmp(emp[i].apellido,emp[j].apellido)>0 && stricmp(emp[i].nombre,emp[j].nombre)>0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }


        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bajaEmpleado (eEmpleados emp[], int tamEmp)
{
    int legajoBaja;
    int indiceLegajo;
    char salir;

    printf ("Ingrese legajo: ");
    scanf ("%d", &legajoBaja);

    indiceLegajo=buscarLegajo(emp, tamEmp, legajoBaja);

    if (indiceLegajo==-1)
    {
        printf ("Legajo inexistente.\n");
    }
    else
    {
        printf("Legajo numero %d, %s\n", emp[indiceLegajo].legajo, emp[indiceLegajo].apellido);

        printf("Estas seguro que queres continuar? Ingrese s/n: ");
        fflush(stdin);
        salir=getche();
        printf("\n");
        system("pause");

        if (tolower(salir)=='s')
        {
            emp[indiceLegajo].itsEmpty=1;
            printf("Operacion exitosa!!\n");
        }
        else
        {
            printf("Operacion cancelada!!\n");
        }
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modificarEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec)
{
    int legajo;
    int indiceLegajo;
    int opcionM;
    char resp;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indiceLegajo=buscarLegajo(emp, tamEmp, legajo);

    if (indiceLegajo==-1)
    {
        printf("\nLegajo inexistente en el sistema\n\n");
    }
    else
    {
        printf("\nlegajo numero %d, %s\n\n", emp[indiceLegajo].legajo, emp[indiceLegajo].apellido);
        getRespuesta(&resp, "Estas seguro que quiere continuar? Ingrese s/n", "s/n. Reingrese: ");

        if (resp=='s')
        {
            printf("1-Apellido\n");
            printf("2-Nombre\n");
            printf("3-Genero\n");
            printf("4-Sueldo\n");
            printf("5-Fecha de ingreso\n");
            printf("6-Sector\n");
            getInt(&opcionM, "Ingrese campo a modificar: ", "Operacion invalida. Reingrese: ", 1, 6);


            switch(opcionM)
            {
                case 1:

                    getString(emp[indiceLegajo].apellido, "Ingrese nombre: ", "No entra en el rango. Reingrese: ",0, 51);
                    printf ("\nOperacion exitosa!!\n");
                    break;
                case 2:

                    getString(emp[indiceLegajo].nombre, "Ingrese nombre: ", "No entra en el rango. Reingrese: ",0, 51);
                    printf ("\nOperacion exitosa!!\n");
                    break;
                case 3:

                    getCharGenero(&emp[indiceLegajo].genero, "Ingrese sexo: ", "Sexo m o f. Reingrese", 'f', 'm');
                    printf ("\nOperacion exitosa!!\n");
                    break;
                case 4:

                    getFloat(&emp[indiceLegajo].sueldo, "Ingrese sueldo: ", "No entra en el rango. Reingrese: ", 0, 100000);
                    printf ("\nOperacion exitosa!!\n");
                    break;
                case 5:
                    getInt(&emp[indiceLegajo].fechaDeIngreso.dia, "Ingrese dia de ingreso: ", "Superaste el rango. Reingresa: ",1,31);

                    getInt(&emp[indiceLegajo].fechaDeIngreso.mes, "Ingrese mes de ingreso: ", "Superaste el rango. Reingresa: ",1,12);

                    getInt(&emp[indiceLegajo].fechaDeIngreso.anio, "Ingrese anio de ingreso: ", "Superaste el rango. Reingresa: ",1950,2019);

                    printf ("\nOperacion exitosa!!\n");
                    break;
                case 6:

                    for (int i=0;i<tamSec;i++)
                    {
                        printf ("%d-%s\n", sec[i].id, sec[i].desc);
                    }

                    getInt(&emp[indiceLegajo].idSector,"Ingrese sector: ", "No entra en el rango. Reingrese: ",1, 5);
                    printf ("\nOperacion exitosa!!\n");
                    break;
                default:

                printf("Opcion invalida\n");
                break;
            }

        }

        else
        {
            printf("\nOperacion cancelada!!");
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void altaAlmuerzo (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eMenus men[], int tamMen, eAlmuerzo alm[], int contador)
{
    int legajo;
    int busquedaLegajo;
    char salir;

    printf("Ingrese legajo: ");
    scanf ("%d", &legajo);

    busquedaLegajo=buscarLegajo(emp, tamEmp, legajo);

    if (busquedaLegajo==-1)
    {
        printf("\nLegajo inexistente en el sistema\n\n");
    }
    else
    {
        printf("\nLegajo numero: %d-%s, %s\n\n", emp[busquedaLegajo].legajo, emp[busquedaLegajo].apellido, emp[busquedaLegajo].nombre);

        getRespuesta(&salir, "Desea continuar? Ingrese s/n: ", "Error. Reingrese: ");

        if(salir=='n')
        {
            printf("\nOperacion cancelada!!\n\n");
        }
        else
        {
            for (int i=0;i<tamMen;i++)
            {
                printf("%d-%s\n", men[i].idMenu, men[i].desc);
            }

            getInt(&alm[busquedaLegajo].idMenu, "Ingrese opcion: ", "No entra en el rango. Reingrese: ", 1, 5);

            getInt(&alm[busquedaLegajo].fechaDeAlmuerzo.dia, "Ingrese dia de ingreso: ", "Superaste el rango. Reingresa: ",1,31);

            getInt(&alm[busquedaLegajo].fechaDeAlmuerzo.mes, "Ingrese mes de ingreso: ", "Superaste el rango. Reingresa: ",1,12);

            getInt(&alm[busquedaLegajo].fechaDeAlmuerzo.anio, "Ingrese anio de ingreso: ", "Superaste el rango. Reingresa: ",2019,2019);

            alm[busquedaLegajo].legajoEmpleado=emp[busquedaLegajo].legajo;

            alm[busquedaLegajo].idAlmuerzo=0;

            alm[busquedaLegajo].idAlmuerzo+=contador;
            printf("\n\nLegajo vale: %d\n\n",  alm[busquedaLegajo].legajoEmpleado);
            printf("\nOperacion completada!!");

        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarAlmuerzo (eEmpleados emp[], int tamEmp, eMenus men[], int tamMen, eAlmuerzo alm[], int tamAlm)
{
    printf("ALMUERZO   APELLIDO    NOMBRE    MENU    PRECIO\n");
    for (int i=0;i<tamAlm;i++)
    {
        printf("LegajoEmpleado: %d\n", alm[i].legajoEmpleado);
    }
    for (int j=0;j<tamEmp;j++)
    {
        printf("legajoReal: %d\n", emp[j].legajo);
        printf("itsEmpty: %d\n", emp[j].itsEmpty);
    }

    printf("\n//////////////////////\n\n");
    for (int i=0;i<tamMen;i++)
    {
        for (int j=0;j<tamEmp*tamMen;i++)
        {
            if (men[i].idMenu==alm[j].idMenu)
            {
                for (int k=0;k<tamEmp;k++)
                {
                    printf("LegajoEmpleado: %d\n", alm[i].legajoEmpleado);
                    printf("legajoReal: %d\n", emp[j].legajo);
                    printf("itsEmpty: %d\n", emp[j].itsEmpty);
                    if (emp[k].itsEmpty=0 && emp[k].legajo==alm[j].legajoEmpleado)
                    {
                      printf("%d %s %s", emp[k].legajo, emp[k].nombre, men[i].desc);
                    }
                }
            }
        }
    }


}


