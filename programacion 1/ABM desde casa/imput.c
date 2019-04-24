
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

int getChar (char min, char max, char* valor, char* mensaje, int intentos, char* msjError)
{
    char caracter;
    int todoOk=0;
    int contador=0;

    printf ("%s entre %c y %c: ",mensaje, min, max);
    fflush (stdin);
    caracter=getche();
    printf ("\n");
    system("pause");

    while ((caracter<min || caracter>max) && contador<intentos)
    {
        contador++;
        if (contador==intentos)
        {
            break;
        }

        printf ("%s entre %c y %c: ",msjError, min, max);
        fflush (stdin);
        caracter=getche();

        printf ("\n");
        system("pause");
    }
    if (contador<intentos)
    {
        *valor=caracter;
        todoOk=1;
    }

    return todoOk;
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
