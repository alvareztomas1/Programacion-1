#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int *punteroInt;
    int **punteroPuntero;
    punteroInt = &a; // Obtenemos la posición de memoria
    punteroPuntero = &punteroInt; // Obtenemos la posición de memoria

    printf("\n%p\n", &a);
    printf("%p\n", punteroInt);
    printf("%p\n", *punteroPuntero);

    printf("\n");

    printf("%d\n", a);
    printf("%d\n", *punteroInt);
    printf("%d\n\n", **punteroPuntero);

    return 0;
}
