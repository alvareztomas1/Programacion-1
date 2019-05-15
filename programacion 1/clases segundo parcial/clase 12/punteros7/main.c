#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* cadena);

int main()
{

    char mensaje[]="Hola mundo!";

    mostrarCadena(mensaje);

    return 0;
}

void mostrarCadena(char* cadena)
{
    while (*cadena!='\0')// *cadena ES LA DIRECCION DE MEMORIA DEL PRIMER CARACTER. EN ESTE CASO ES 'H'
    {                   // '\0' esta al final del mensaje. Despues del '!'
        printf("%c ", *cadena);
        cadena++; //cadena++ le suma un sizeof
    }

    for (int i=0; *(cadena+i) != '\0'; i++)
    {
        printf("%c ", *(cadena+i));
    }
}





