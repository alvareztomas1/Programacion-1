#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 3
//---------------------------------------------------------------------------------
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;

}eEmpleado;
//---------------------------------------------------------------------------------
int menu(void);
int inicializarEstado (eEmpleado vec[], int tam);
void mostrarEmpleado (eEmpleado emp);
void mostrarEmpleados (eEmpleado vec[], int tam);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (eEmpleado vec[], int tam, int legajo);
void altaEmpleado (eEmpleado vec[], int tam);
void bajaEmpleado (eEmpleado vec[], int tam);
void modificarEmpleado (eEmpleado vec[], int tam);
//---------------------------------------------------------------------------------
int main()
{
    char seguir='s';
    char salir;
    eEmpleado lista[TAM]={{111,"Juan",'m',30000,1},{222,"Ana",'f',20000,1},{33,"Tom",'f',15000,0}, };
//---------------------------------------------------------------------------------
    //inicializarEstado(lista,TAM);
//---------------------------------------------------------------------------------
    printf ("*******ABM EMPLEADOS*******");

    do
    {
        switch (menu())
        {
            case 1:
                //printf ("Alta empleado\n");
                altaEmpleado(lista,TAM);
                system("pause");
                break;
            case 2:
                //printf ("Baja empleado\n");
                bajaEmpleado(lista,TAM);
                system("pause");
                break;
            case 3:
                //printf ("Modificar empleado\n");
                modificarEmpleado(lista,TAM);
                system("pause");
                break;
            case 4:
                //printf ("Ordenar empleados\n");

                system("pause");
                break;
            case 5:
                //printf ("Listar empleados\n");
                mostrarEmpleados(lista,TAM);
                system("pause");
                break;
            case 6:
                printf ("Ingrese s/n para salir: ");
                fflush(stdin);
                scanf ("%c", &salir);


                if (tolower(salir)=='s')
                {
                    seguir='n';
                }

                system("cls");
                break;
            default:
                printf ("no es una opcion valida\n\n");
                system("break");
                break;

            }
    }while(seguir=='s');

    return 0;
}
//---------------------------------------------------------------------------------

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
    printf (" %d  %s  %c  %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);
}
//---------------------------------------------------------------------------------

void mostrarEmpleados (eEmpleado vec[], int tam)
{
    int contador=0;
    printf ("\n Legajo   Nombre    Sexo   Sueldo\n");

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
        printf ("No se encuentra el legajo en el sistema\n");
    }
    else
    {
        printf ("Legajo numero %d\n", vec[indiceLeg]);
        printf ("Esta seguro que quiere continuar? s/n: ");
        fflush(stdin);
        scanf ("%c", &confirma);
        if(tolower(confirma)=='n')
        {
            printf ("Baja cancelada!\n");
        }
        else
        {
            vec[indiceLeg].estado=0;
            printf ("\nBaja empleado exitosa!!\n");

        }
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
        printf ("Legajo numero %d\n", legajo);
        printf ("Esta seguro que quiere modificar? Ingrese s/n: ");
        fflush(stdin);
        scanf ("%c", &continuar);

        if (tolower(continuar)=='n')
        {
            printf ("Modificacion cancelada!\n");
        }
        else
        {
            printf ("Ingrese sueldo: ");
            scanf ("%d", &sueldo);

            vec[indiceLeg].sueldo=sueldo;
            printf ("Modificacion exitosa!!\n");
        }
    }
}
//---------------------------------------------------------------------------------

