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
    struct datosPersonales agenda[3];

for (int i=0;i<3;i++)
{
    fflush(stdin);

    printf ("Ingrese el nombre: ");
    gets (agenda[i].nombre);

    printf ("Ingrese el apellido: ");
    gets (agenda[i].apellido);

    printf ("Ingrese la calle: ");
    gets (agenda[i].calle);

    fflush(stdin);


    printf ("Ingrese el numero de calle: ");
    scanf ("%d", &agenda[i].numero);
    fflush(stdin);
    printf ("Ingrese el numero postal: ");
    scanf ("%d", &agenda[i].codigoPostal);
    fflush(stdin);
}

for (int i=0;i<3;i++)
{

    printf ("%s\n", agenda[i].nombre);
    printf ("%s\n", agenda[i].apellido);
    printf ("%s\n", agenda[i].calle);
    printf ("%d\n", agenda[i].numero);
    printf ("%d\n", agenda[i].codigoPostal);
    printf ("\n\n");
}





    return 0;
}
