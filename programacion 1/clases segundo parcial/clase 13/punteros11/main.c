#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int *punteroInt;
    int **punteroPuntero;
    punteroInt = &a; // Obtenemos la posici�n de memoria
    punteroPuntero = &punteroInt; // Obtenemos la posici�n de memoria

    printf("\n%p\n", &a);
    printf("%p\n", punteroInt);
    printf("%p\n", *punteroPuntero);

    printf("\n");

    printf("%d\n", a);
    printf("%d\n", *punteroInt);
    printf("%d\n\n", **punteroPuntero);

    return 0;
}
