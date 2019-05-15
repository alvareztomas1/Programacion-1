#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include "input.h"
#include "funciones.h"

#define TAM_SOC 10
#define TAM_LIBROS 20
#define TAM_AUTORES 5
#define TAM_PRSTAMO 50

int main()
{
    eSocio lista[TAM_SOC];
    eLibros libros[TAM_LIBROS];
    eAutor autores[TAM_AUTORES];
    ePrestamo prestamos[TAM_PRSTAMO];

    char seguir='s';
    char respuesta;
    int contadorLegajo=0;
    int contadorLegajoPrestamo=0;

    hardcode(lista, TAM_SOC, autores, TAM_AUTORES, libros, TAM_LIBROS, prestamos, TAM_PRSTAMO);

    do
    {
        switch (menu())
        {
            case 1:
                system("cls");
                altaSocio(lista, TAM_SOC, contadorLegajo);
                contadorLegajo++;
                break;

            case 2:
                system("cls");
                modificarSocio(lista, TAM_SOC);
                break;

            case 3:
                system("cls");
                bajaSocio(lista, TAM_SOC);

                break;

            case 4:
                system("cls");
                ordenarSocios(lista, TAM_SOC);
                mostrarSocios(lista, TAM_SOC);
                system("pause");
                break;

            case 5:
                system("cls");
                ordenarLibros(libros, TAM_LIBROS);
                mostrarLibros(libros, TAM_LIBROS);
                system("pause");


                break;

            case 6:
                system("cls");
                ordenarAutores(autores, TAM_AUTORES);
                mostrarAutores(autores, TAM_AUTORES);
                system("pause");
                break;

                case 7:
                    system("cls");
                    altaPrestamo(prestamos, TAM_PRSTAMO, lista, TAM_SOC, libros, TAM_LIBROS, contadorLegajoPrestamo);
                    contadorLegajoPrestamo++;
                    break;

            case 8:
                system("cls");
                mostrarPrestamo(lista, TAM_SOC, libros, TAM_LIBROS, prestamos, TAM_PRSTAMO);
                system("pause");
                break;

            case 9:
                system("cls");
                informarPrestamosDeLibro(lista, TAM_SOC, libros, TAM_LIBROS, prestamos, TAM_PRSTAMO);
                system("pause");
                break;

            case 10:
                system("cls");
                //informarLibroMasPrestado(lista, TAM_SOC, libros, TAM_LIBROS, prestamos, TAM_PRSTAMO);
                informarAutorConMasLibros(autores, TAM_AUTORES, libros, TAM_LIBROS);
                //informarPrestamosDeUnSocio (lista, TAM_SOC, autores, TAM_AUTORES, prestamos, TAM_PRSTAMO);
                system("pause");
                break;
            case 11:
                system("cls");
                validarDosChar(&respuesta, "Desea salir? Ingrese s/n: ","Opcion invalida. Reingrese: ", 'n', 's');

                break;
                if (respuesta=='s')
                {
                    seguir='n';
                }

                system("cls");
                break;

            default:
                system("cls");
                printf("\nOperacion invalida!!\n\n");
                break;
        }

        fflush(stdin);

    }while(seguir=='s');

    return 0;
}
