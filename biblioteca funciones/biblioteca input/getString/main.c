#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getString (int min, int max,char dato[], char* mensaje,int intentos, char* msjError);
int main()
{
    char x[64];
    char mensaje;
    int ok;

    ok=getString(0, 1, x,"Ingrese nombre ", 3, "Superaste los caracteres. Reingresa");

    if (ok)
    {
        printf ("\n%s\n\n", x);
    }
    else
    {
        printf ("\nSe supero la cantidad de intentos\n\n");
    }


    return 0;
}
int getString (int min, int max,char dato[], char* mensaje,int intentos, char* msjError)
{
    int todoOk=0;
    int cantidad;
    int cont=0;

    printf ("%s entre %d y %d caracteres: ",mensaje, min, max);
    gets(dato);

    while ((strlen(dato)<min || strlen(dato)>max) && cont<intentos)
    {
        cont++;
        if (cont==intentos)
        {
            break;
        }
        printf ("%s entre %d y %d: ", msjError, min, max);
        fflush (stdin);
        gets(dato);
    }

    if (cont<intentos)
    {
        todoOk=1;
    }

    return todoOk;
}
