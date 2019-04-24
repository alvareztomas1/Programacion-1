#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validarChar (char* caracter,char* mensaje,char* msjError, char min, char max);

int main()
{
    char x[1];
    int ok;

    ok=validarChar(x,"Ingrese sexo: ","Error\n",'m', 'f');

    if (ok)
    {
        printf ("Su sexo es: %c", x);
    }
    else
    {
        printf ("No entro");
    }

    return 0;
}
int validarChar (char* caracter,char* mensaje,char* msjError, char min, char max)
{
    int todoOk=0;
    char caracterBien;

    printf (mensaje);
    caracterBien=getche();
    printf("\n");
    system("pause");

    if (caracterBien==min || caracterBien==max)
    {
        strcpy(caracter,caracterBien);
        todoOk=1;
    }
    else
    {
      printf(msjError);
    }
    return todoOk;
}
