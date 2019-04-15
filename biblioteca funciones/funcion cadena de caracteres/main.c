#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadena (char vec[],int tam, char* mensaje);

int main()
{
    char vec[64];
    int result;

    cadena(vec,64, "ingrese nombre: ");



    return 0;
}
void cadena (char vec[],int tam, char* mensaje)
{
    char cad[tam];
    int cantidad;

    printf("%s", mensaje);

    fgets(cad,sizeof(cad)-2,stdin);
    cantidad = strlen(cad);
    cad[cantidad-1] = '\0';

    printf ("%s", cad);
}
