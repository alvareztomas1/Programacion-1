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
    struct datosPersonales agenda;

    strcpy (agenda.nombre, "Yanina");
    strcpy (agenda.apellido, "Scudero");
    strcpy (agenda.calle, "Avenida Mitre");
    agenda.numero= 750;

    printf ("%s\n", agenda.nombre);
    printf ("%s\n", agenda.apellido);
    printf ("%s %d\n", agenda.calle, agenda.numero);

    return 0;
}
