#include <stdio.h>
#include <stdlib.h>

void leerPuntero (int* p);

int main()
{
    int x=10;

    printf("Direccion de memoria de x: %x\n", &x);
   // printf("Antes de llamar a la funcion x vale: %d\n", x);
    leerPuntero(&x);

    return 0;
}

void leerPuntero (int* p)
{
    printf("Direccion guardada en p: %x", p);
    //*p=100;
    //printf("Despues de llamar a la funcion x vale: %d\n", *p);
}
