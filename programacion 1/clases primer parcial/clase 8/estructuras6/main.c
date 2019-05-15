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
    struct datosPersonales agenda[3], contactos[3], amigos[3];

for (int i=0;i<3;i++)
{//recorre el vector y pide los datos

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
{// asigno los valores del vector agenda al vector contactos. *DE ESTA FORMA ES DE CAMPO A CAMPO*
    strcpy (contactos[i].nombre,agenda[i].nombre);
    strcpy (contactos[i].apellido,agenda[i].apellido);
    strcpy (contactos[i].calle,agenda[i].calle);
    contactos[i].numero=agenda[i].numero;
    contactos[i].codigoPostal=agenda[i].codigoPostal;
    printf ("%s\n", contactos[i].nombre);
    printf ("%s\n", contactos[i].apellido);
    printf ("%s\n", contactos[i].calle);
    printf ("%d\n", contactos[i].numero);
    printf ("%d\n", contactos[i].codigoPostal);
    printf ("\n\n");


}

for (int i=0;i<3;i++)
{// forma mas corta de hacerlo. *DE ESTA FORMA PASA TODO DE UNA*
    amigos[i]=contactos[i];
    printf ("%s\n", amigos[i].nombre);
    printf ("%s\n", amigos[i].apellido);
    printf ("%s\n", amigos[i].calle);
    printf ("%d\n", amigos[i].numero);
    printf ("%d\n", amigos[i].codigoPostal);
    printf ("\n\n");
}
    return 0;
}


