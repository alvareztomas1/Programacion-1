#include <stdio.h>
#include <stdlib.h>

int getChar (char min, char max, char* valor, char* mensaje, int intentos, char* msjError);


main()
{
    char x;
    int ok;

    ok=getChar('a','c',&x,"Ingrese opcion",3,"Error. solo");

    if(ok)
    {
       printf ("Continuo con la opcion '%c'", x);
    }
    else
    {
        printf ("no se encontro el dato");
    }
}
int getChar (char min, char max, char* valor, char* mensaje, int intentos, char* msjError)
{
    int caracter;
    int todoOk=0;
    int contador=0;

    printf ("%s entre %c y %c: ",mensaje, min, max);
    fflush (stdin);
    scanf ("%c", &caracter);

    while ((caracter!=min && caracter!=max) && contador<intentos)
    {
        contador++;
        if (contador==intentos)
        {
            break;
        }
        printf ("%s entre %c y %c: ",msjError, min, max);
        fflush (stdin);
        scanf ("%c", &caracter);
    }
    if (contador<intentos)
    {
        *valor=caracter;
        todoOk=1;
    }

    return todoOk;
}






/*
----------------------------------------------------------------------------------------
int getFloat (float min, float max, float* valor, char* mensaje, int intentos, char* msjError);

main()
{
    float x;
    int ok;

    ok=getFloat(0,10,&x,"Ingrese un precio",3,"El rango es ");

    if (ok)
    {
        printf ("usted ingreso el numero %.2f", x);
    }
    else
    {
        printf ("no se encontro el dato\n\n\n");
    }
    return 0;
}
int getFloat (float min, float max, float* valor, char* mensaje, int intentos, char* msjError)
{
    float numero;
    int contador=0;
    int todoOk=0;

    printf ("%s entre %.2f y %.2f: ", mensaje, min, max);
    scanf ("%f", &numero);

    while ((numero<min || numero>max) && contador<intentos)
    {
        contador++;
        if (contador==intentos)
        {
            break;
        }
        printf ("%s entre %.2f y %.2f: ", msjError, min, max);
        scanf ("%f", &numero);
    }


    if (contador<intentos)
    {
        *valor=numero;
        todoOk=1;
    }

    return todoOk;
}

-----------------------------------------------------------------------------------------------

int getInt (int min,int max, int* valor, char* mensaje, int intentos, char* msjError);

int main()
 {
    int x;
    int ok;

    ok = getInt(0,10,&x,"ingrese una nota",3,"Reingrese. El numero tiene que estar");

    if (ok)
    {
        printf ("usted ingreso el numero %d\n\n", x);
    }
    else
    {
        printf ("No se pudo obtener el dato\n\n");
    }
    return 0;
 }

int getInt (int min,int max, int* valor, char* mensaje, int intentos, char* msjError)
{
    int numero;
    int todoOk = 0;
    int contador = 0;


    printf ("%s entre %d y %d: ", mensaje,min,max);
    scanf ("%d", &numero);

    while ((numero<min || numero>max) && contador<intentos)
    {
        contador++;

        if (contador==intentos)
        {
            break;
        }

        printf ("%s entre %d y %d: ", msjError,min,max);
        scanf ("%d", &numero);


    }
    if (contador<intentos)
        {
            *valor=numero;
            todoOk=1;
        }

        return todoOk;


}
*/


