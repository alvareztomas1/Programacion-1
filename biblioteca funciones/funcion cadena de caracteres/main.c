#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadena (char cadena[64], char* mensaje);

int main()
{
    char vec[64];
    int result;

    result = cadena(vec[64], "ingrese nombre: ");

    printf ("\n\n el nombre ingresado fue: %s", result);

    return 0;
}
int cadena (char cadena[64], char* mensaje)
{
    int cantidad;

    printf("%s ", mensaje);

    fgets(cadena,sizeof(cadena)-2,stdin);

    cantidad = strlen(cadena);

    cadena[cantidad-1] = '\0';


    return cadena;
}
