#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "socios.h"
#include "input.h"
#include "funciones.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu()
{
    int opcion;

    printf("----------ABM----------\n\n");
    printf("1-Alta socio\n");
    printf("2-Modificar socio\n");
    printf("3-Baja socio\n");
    printf("4-Listar socio\n");
    printf("5-Listar libros \n");
    printf("6-Listar autores\n");
    printf("7-Alta prestamo\n");
    printf("8-Listar prestamos\n");
    printf("9-Informar prestamos del libro\n");
    printf("10-Informar libro mas prestado\n");
    printf("11-Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarSocios (eSocio soc[], int tamSoc)
{
    for (int i=0;i<tamSoc;i++)
    {
        soc[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarLibros (eLibros lib[], int tamLib)
{
    for (int i=0;i<tamLib;i++)
    {
        lib[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarAutores (eAutor aut[], int tamAut)
{
    for (int i=0;i<tamAut;i++)
    {
        aut[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hardcode (eSocio soc[], int tamSoc, eAutor aut[], int tamAut, eLibros lib[], int tamLib, ePrestamo pres[], int tamPres)
{
    inicializarSocios(soc, tamSoc);
    inicializarAutores(aut, tamAut);
    inicializarLibros(lib, tamLib);
    inicializarPrestamo(pres, tamPres);

    eSocio lista[]=
    {
        {0, "Alvarez", "Tomas", 'm', "1140515642","tomasalvarez1@hotmail.com", {10,12,2011},0},
        {1, "Caballero", "Julian", 'm', "1198724643","juliancaballero2@hotmail.com", {04,07,2013}, 0},
        {2, "Cortes", "Florencia", 'f', "1103965201","cortesflorencia@hotmail.com", {21,03,2005}, 0},
        {3, "Abila", "Ramon", 'm', "1133906453","abilaramon@hotmail.com", {17,03,2009}, 0},
        {4, "Cortes", "Julieta", 'f', "1155402310", "julietacortes@hotmail.com", {12,10,2010}, 0},
    };

    for (int i=0;i<5;i++)
    {
        soc[i]=lista[i];
    }

    eAutor autores[]=
    {
        {100, "Cortazar", "Julio", 0},
        {101, "Orwell", "George", 0},
        {102, "Saint-Exupery", "Antoine", 0},
        {103, "Garcia Marquez", "Gabriel", 0},
        {104, "Shelley", "Mary", 0},
    };

    for (int i=0;i<5;i++)
    {
        aut[i]=autores[i];
    }

    eLibros libros[]=
    {
        {1000, "Rayuela", 100, 0},
        {1001, "Casa tomada", 100, 0},
        {1002, "Bestiario", 100, 0},
        {1003, "Revelion en la granja", 101, 0},
        {1004, "1984", 101, 0},
        {1005, "El principito", 102, 0},
        {1006, "El naufrago", 103, 0},
        {1007, "Frankenstein", 104, 0},
    };

    for (int i=0;i<8;i++)
    {
        lib[i]=libros[i];
    }

   ePrestamo prestamos[]=
    {
        {0, 1001, 2, {10,07,2018}, 0},
        {1, 1001, 2, {22,04,2019}, 0},
        {2, 1001, 3, {06,01,2019}, 0},
        {3, 1001, 2, {13,10,2018}, 0},
        {4, 1001, 2, {07,9,2018}, 0},

    };

    for (int i=0;i<5;i++)
    {
        pres[i]=prestamos[i];
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLibre (eSocio soc[], int tamSoc)
{
    int indiceLibre=-2;

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==1)
        {
            indiceLibre=i;
            break;
        }
    }

    return indiceLibre;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLegajo (eSocio soc[], int tamSoc, int legajo)
{
    int indiceLegajo=-2;

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==0 && soc[i].legajo==legajo)
        {
            indiceLegajo=i;
            break;
        }
    }

    return indiceLegajo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaSocio (eSocio soc[], int tamSoc, int contador)
{
    int espacioLibre;
    espacioLibre=buscarLibre(soc, tamSoc);

    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio en el sistema\n\n");
    }
    else
    {
        getString(soc[espacioLibre].apellido, "Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
        getString(soc[espacioLibre].nombre, "Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
        validarDosChar(&soc[espacioLibre].sexo, "Ingrese sexo: ", "Solo m o f. Reingrese: ", 'f', 'm');
        getString(soc[espacioLibre].telefono, "Ingrese telefono: ", "No entra en el rango. Reingrese: ", 0, 16);
        getInt(&soc[espacioLibre].fechaDeIngreso.dia, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 0, 16);
        getInt(&soc[espacioLibre].fechaDeIngreso.mes, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 12);
        getInt(&soc[espacioLibre].fechaDeIngreso.anio, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1900, 2019);
        getString(soc[espacioLibre].eMail, "Ingrese email: ", "No entra en el rango. Reingrese: ", 0, 31);


        soc[espacioLibre].legajo=0;
        soc[espacioLibre].legajo+=contador;
        soc[espacioLibre].itsEmpty=0;

        printf("\nAlta empleado exitosa!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bajaSocio (eSocio soc[], int tamSoc)
{
    int legajo;
    int busquedaLegajo;
    char respuesta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    busquedaLegajo=buscarLegajo(soc, tamSoc, legajo);

    if (busquedaLegajo==-2)
    {
        printf("\nLegajo inexistente!!\n\n");
    }
    else
    {
        printf("\nLegajo nro %d-%s, %s\n\n", soc[busquedaLegajo].legajo, soc[busquedaLegajo].apellido, soc[busquedaLegajo].nombre);

        validarDosChar(&respuesta, "Desea continuar? Ingrese s/n: ", "Solo 's' o 'n'. Reingrese: ", 'n', 's');

        if (respuesta=='s')
        {
            soc[legajo].itsEmpty=-1;
            printf("\nOperacion exitosa!!\n\n");
        }
        else
        {
            printf("\nOperacion cancelada!!\n\n");
        }
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSocio (eSocio soc)
{
    printf("%d  %s  %s  %c   %s   %s  %02d/%02d/%4d\n",soc.legajo,  soc.apellido, soc.nombre, soc.sexo, soc.telefono, soc.eMail, soc.fechaDeIngreso.dia ,soc.fechaDeIngreso.mes, soc.fechaDeIngreso.anio);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSocios (eSocio soc[], int tamSoc)
{
    int contador=0;

    printf ("LEGAJO    APELLIDO     NOMBRE      SEXO      TELEFONO      EMAIL      FECHA\n");

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==0)
        {
            mostrarSocio(soc[i]);
            contador++;
        }
    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarSocios (eSocio soc[], int tamSoc)
{
    eSocio aux;

    for (int i=0;i<tamSoc-1;i++)
    {
        for (int j=i+1;j<tamSoc;j++)
        {
            if (strcmp(soc[i].apellido, soc[j].apellido)>0)
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }
            else if (strcmp(soc[i].apellido, soc[j].apellido)>0 && strcmp(soc[i].nombre, soc[j].nombre)>0)
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarLibros (eLibros lib[], int tamLib)
{
    eLibros aux;

    for (int i=0;i<tamLib-1;i++)
    {
        for (int j=i+1;j<tamLib;j++)
        {
            if (strcmp(lib[i].titulo, lib[j].titulo)>0)
            {
                aux=lib[i];
                lib[i]=lib[j];
                lib[j]=aux;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarAutores (eAutor aut[], int tamAut)
{
    eAutor aux;

    for (int i=0;i<tamAut-1;i++)
    {
        for (int j=i+1;j<tamAut;j++)
        {
            if (strcmp(aut[i].apellido, aut[j].apellido)>0)
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
            else if (strcmp(aut[i].apellido, aut[j].apellido)>0 && strcmp(aut[i].nombre, aut[j].nombre)>0)
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarSocio (eSocio soc[], int tamSoc)
{
    int legajo;
    int busquedaLegajo;
    char respuesta;
    int opcionM;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    busquedaLegajo=buscarLegajo(soc, tamSoc, legajo);

    if (busquedaLegajo==-2)
    {
        printf("\nLegajo inexistente en el sistema.\n\n");
    }
    else
    {
        printf("\nLegajo nro %d-%s, %s\n\n", soc[busquedaLegajo].legajo, soc[busquedaLegajo].apellido, soc[busquedaLegajo].nombre);
        validarDosChar(&respuesta, "Desea continuar? Ingrese s/n: ", "Solo 's' o 'n'. Reingrese: ", 'n', 's');

        if  (respuesta=='s')
        {
            printf("1-Apellido\n");
            printf("2-Nombre\n");
            printf("3-Sexo\n");
            printf("4-Telefono\n");
            printf("5-eMail\n");
            printf("6-Salir\n\n");

            printf("Ingrese opcion: ");
            scanf("%d", &opcionM);


            switch(opcionM)
            {
                case 1:
                    getString(soc[busquedaLegajo].apellido, "Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
                    printf("\nOperacion exitosa!!\n\n");
                    break;

                case 2:
                    getString(soc[busquedaLegajo].nombre, "Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
                    printf("\nOperacion exitosa!!\n\n");
                    break;

                case 3:
                    validarDosChar(&soc[busquedaLegajo].sexo, "Ingrese sexo: ", "Solo m o f. Reingrese: ", 'f', 'm');
                    printf("\nOperacion exitosa!!\n\n");
                    break;

                case 4:
                    getString(soc[busquedaLegajo].telefono, "Ingrese telefono: ", "No entra en el rango. Reingrese: ", 0, 16);
                    printf("\nOperacion exitosa!!\n\n");
                    break;

                case 5:
                    getString(soc[busquedaLegajo].eMail, "Ingrese email: ", "No entra en el rango. Reingrese: ", 1, 31);
                    printf("\nOperacion exitosa!!\n\n");
                    break;
                case 6:
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

void mostrarLibro (eLibros lib)
{
    printf("%4d  %15s  %3d\n", lib.idLibro, lib.titulo, lib.idAutor);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarLibros (eLibros lib[], int tamLib)
{
    int contador=0;

    printf ("ID LIBRO       TITULO  ID AUTOR\n");

    for (int i=0;i<tamLib;i++)
    {
        if (lib[i].itsEmpty==0)
        {
            mostrarLibro(lib[i]);
            contador++;
        }

    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAutor (eAutor aut)
{
    printf("%4d  %15s  %15s\n", aut.idAutor, aut.apellido, aut.nombre);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAutores (eAutor aut[], int tamAut)
{
    int contador=0;

    printf ("ID AUTOR       APELLIDO         NOMBRE\n");

    for (int i=0;i<tamAut;i++)
    {
        if (aut[i].itsEmpty==0)
        {
            mostrarAutor(aut[i]);
            contador++;
        }
    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarPrestamo (ePrestamo pres[], int tamPres)
{
    for (int i=0;i<tamPres;i++)
    {
        pres[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarPrestamoLibre (ePrestamo pres[], int tamPres)
{
    int indicePrestamo=-2;

    for (int i=0;i<tamPres;i++)
    {
        if (pres[i].itsEmpty==1)
        {
            indicePrestamo=i;
            break;
        }

    }

    return indicePrestamo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaPrestamo (ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc, eLibros lib[], int tamLib, int contador)
{
    int busquedaLegajo;
    int espacioLibre;
    int legajo;
    char respuesta;

    espacioLibre=buscarPrestamoLibre(pres, tamPres);


    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio en el sistema!!\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        busquedaLegajo=buscarLegajo(soc, tamSoc, legajo);

        if (busquedaLegajo==-2)
        {
            printf("\nLegajo inexistente en el sistema!!\n\n");
        }
        else
        {
            printf("\nLegajo nro %d-%s, %s\n\n", soc[busquedaLegajo].legajo, soc[busquedaLegajo].apellido, soc[busquedaLegajo].nombre);
            validarDosChar(&respuesta, "Desea continuar? Ingrese s/n: ","Solo 's' o 'n'. Reingrese: ", 's', 'n');

            if (respuesta=='s')
            {
                for (int i=0;i<tamLib;i++)
                {
                    if (lib[i].itsEmpty==0)
                    {
                         printf("%d-%s\n", lib[i].idLibro, lib[i].titulo);
                    }

                }
                getInt(&pres[espacioLibre].idLibro, "Ingrese libro: ", "No entra en el rango. Reingrese: ", 1000, 1004);
                getInt(&pres[espacioLibre].fechaDePrestamo.dia, "Ingrese dia: ", "Fecha no valida. Reingrese: ", 1, 31);
                getInt(&pres[espacioLibre].fechaDePrestamo.mes, "Ingrese mes: ", "Fecha no valida. Reingrese: ", 1, 12);
                getInt(&pres[espacioLibre].fechaDePrestamo.anio, "Ingrese anio: ", "Fecha no valida. Reingrese: ", 2018, 2019);


                pres[espacioLibre].itsEmpty=0;
                pres[espacioLibre].idPrestamo=0;
                pres[espacioLibre].idPrestamo+=contador;
                pres[espacioLibre].legajoEmpleado=legajo;


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

void mostrarPrestamo (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
    int contador=0;

    printf("PRESTAMO     SOCIO   LIBRO    FECHA\n");

    for (int i=0;i<tamLib;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (pres[j].idLibro==lib[i].idLibro)
            {
                for (int k=0;k<tamSoc;k++)
                {
                    if (soc[k].legajo==pres[j].legajoEmpleado  && soc[k].itsEmpty==0  && pres[j].itsEmpty==0  && lib[i].itsEmpty==0)
                    {
                         printf("  %04d       %04d   %04d   %02d/%02d/%02d\n", pres[j].idPrestamo, soc[k].legajo, lib[i].idLibro, pres[j].fechaDePrestamo.dia, pres[j].fechaDePrestamo.mes, pres[j].fechaDePrestamo.anio);
                         contador++;
                    }
                }
            }
        }
    }
    if (contador==0)
    {
        printf("\nNo hay libros prestados!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPrestamosDeLibro (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
     int contador=0;

     for (int i=0;i<tamLib;i++)
     {
         for (int j=0;j<tamLib*tamSoc;j++)
         {
             if (pres[j].idLibro==lib[i].idLibro)
             {
                 for (int k=0;k<tamSoc;k++)
                 {
                     if (soc[k].legajo==pres[j].legajoEmpleado && soc[k].itsEmpty==0 && pres[j].itsEmpty==0)
                     {
                         if (pres[j].idLibro==1001)
                         {
                             contador++;

                         }
                     }
                }
            }
        }
    }

    if(contador==0)
    {
        printf("\nEL libro nunca fue prestado!!\n\n");
    }
    else
    {
        printf("El libro fue listado %d veces\n", contador);
    }

 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarLibroMasPrestado (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
    int contador;
    int max=0;
    int idMax=0;
    int flag=0;

     for (int i=0;i<tamLib;i++)
     {
         contador=0;

         for (int j=0;j<tamPres;j++)
         {
             if (pres[j].idLibro==lib[i].idLibro && pres[j].itsEmpty==0 && lib[i].itsEmpty==0)
             {
                 contador++;
                 if (contador>max || flag==0)
                 {
                     max=contador;
                     idMax=pres[j].idLibro;
                     flag++;

                 }
            }
        }

    }

    if(idMax>0)
    {
        printf("\nEl libro mas prestado es el %d con %d veces\n\n", idMax, max);
    }
    else
    {
        printf("\nNo hay nada que mostrar!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarAutorConMasLibros (eAutor aut[], int tamAut, eLibros lib[], int tamLib)
{
    int contador;
    int max;
    int flag=0;
    int idMax;
    char nombreAutor[31];

    for (int i=0;i<tamLib;i++)
    {
        contador=0;
        for (int j=0;j<tamAut;j++)
        {

            if (aut[j].idAutor==lib[i].idAutor)
            {
                contador++;
                if (contador>max || flag==0)
                {
                    max=contador;
                    idMax=aut[j].idAutor;
                    strcpy(nombreAutor, aut[j].apellido);
                    flag++;
                }
            }
        }
    }
    if (idMax>0)
    {
        printf("\nEl autor con mas libros es %d y tiene %d libros. Se llama %s\n", idMax, max, nombreAutor);
    }
    else
    {
        printf("\nNo hay nada que listar!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPrestamosDeUnSocio (eSocio soc[],int tamSoc,eAutor aut[],int tamAut,ePrestamo pres[], int tamPres)
{
    int contador = 0;
    int legajo;
    int indice;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice=buscarLegajo(soc, tamSoc, legajo);

    if(indice==-2)
    {
        printf("\nError,No se encuentra su legajo\n\n");
    }
    else
    {
        printf("\n PRESTAMO  LEGAJO  ID LIBRO  FECHA \n");

        for(int i=0;i<tamPres;i++)
        {
            if(pres[i].itsEmpty==0 && pres[i].legajoEmpleado==legajo)
            {
                printf("%d   %d   %d   %02d/%02d/%4d\n\n", pres[i].idPrestamo, pres[i].legajoEmpleado, pres[i].idLibro, pres[i].fechaDePrestamo.dia, pres[i].fechaDePrestamo.mes, pres[i].fechaDePrestamo.anio);
                contador++;
            }

        }

        printf("Este SOCIO tiene %d prestamo/s\n",contador);
    }

    if(contador==0)
    {
        printf("\nEste empleado no tiene prestamos");
    }

}
