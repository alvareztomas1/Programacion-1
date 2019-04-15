#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
};

int main()
{
    struct datosPersonales agenda,contactos;

    strcpy (agenda.nombre, "Yanina");
    strcpy (agenda.apellido, "Scudero");
    strcpy (agenda.calle, "Avenida Mitre");
    agenda.numero= 750;

    contactos=agenda;

    printf ("%s\n", contactos.nombre);
    printf ("%s\n", contactos.apellido);
    printf ("%s %d\n", contactos.calle, agenda.numero);

    return 0;
}
