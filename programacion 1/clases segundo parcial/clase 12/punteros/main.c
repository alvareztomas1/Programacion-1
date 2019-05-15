#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=10;
    int* p;// no es un entero. ES UNA DIRECCION DE VARIABLE ENTERA
    char* j;// no es un caracter. ES UNA DIRECCION DE VARIABLE CHAR

    p=&num; // guardo la direccion de memoria en el puntero p

    printf("%d\n", num); // Formas de mostrar el valor
    printf("%d\n", *p);


    printf("%x\n", p); // ASI MUESTRO LA DIRECCION DE MEMORIA


    return 0;
}














