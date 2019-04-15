#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
    int codigoPostal;
};

int main()
{
    struct datosPersonales agenda;

    printf ("Ingrese el nombre: ");
    gets (agenda.nombre);
    fflush(stdin);

    printf ("Ingrese el apellido: ");
    gets (agenda.apellido);
    fflush(stdin);

    printf ("Ingrese la calle: ");
    gets (agenda.calle);
    fflush(stdin);

    printf ("Ingrese el numero de calle: ");
    scanf ("%d", &agenda.numero);

    printf ("Ingrese el numero postal: ");
    scanf ("%d", &agenda.codigoPostal);

    printf ("%s\n", agenda.nombre);
    printf ("%s\n", agenda.apellido);
    printf ("%s\n", agenda.calle);
    printf ("%d\n", agenda.numero);
    printf ("%d\n", agenda.codigoPostal);

    return 0;
}
