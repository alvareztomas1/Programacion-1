#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadena (char dato[], int tam,char* mensaje, char* msjFinal);

int main()
{
    char result;
    char dato[64];

    cadena(dato,64, "ingrese nombre: ", "el nombre es");


    return 0;
}
void cadena (char dato[] ,int tam, char* mensaje, char* msjFinal)
{
    int cantidad;


    printf("%s", mensaje);

    fgets(dato,sizeof(dato)-2,stdin);
    cantidad = strlen(dato);
    dato[cantidad-1] = '\0';

    printf ("%s %s", msjFinal, dato);
}










/*void cadena (int tam,char* mensaje, char* msjFinal);

int main()
{
    char result;

    cadena(64, "ingrese nombre: ", "el nombre es");


    return 0;
}
void cadena (int tam, char* mensaje, char* msjFinal)
{
    int cantidad;
    char cadena[tam];

    printf("%s", mensaje);

    fgets(cadena,sizeof(cadena)-2,stdin);
    cantidad = strlen(cadena);
    cadena[cantidad-1] = '\0';

    printf ("%s %s", msjFinal, cadena);
}
*/
