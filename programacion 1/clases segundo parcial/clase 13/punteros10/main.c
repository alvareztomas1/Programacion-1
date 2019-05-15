#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* punteroCadena);
void mostrarCadena2(char* punteroCadena);

int main()
{
    char letra='a';
    char palabra[]="Hola";
    char* p;
    char* q;

    p=&letra;
    q=palabra;

    mostrarCadena(q);
    printf("\n");
    mostrarCadena2(q);
    printf("\n\n");

    return 0;
}

void mostrarCadena(char* punteroCadena)
{
    while(*punteroCadena != '\0')
    {
        printf("%p ", punteroCadena);
        punteroCadena++;
    }
}

void mostrarCadena2(char* punteroCadena)
{
    int i=0;

    while (*(punteroCadena+i) != '\0')
    {
         printf("%p ", punteroCadena);
         *(punteroCadena+i);
         i++;
    }
}
