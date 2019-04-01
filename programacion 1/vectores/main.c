#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5];
    int suma=0;
    int promedio;

    for (int i=0;i<5;i++)
    {
        printf ("ingrese 5 numeros: ");
        scanf ("\n%d", &vec[i]);

    }
    for (int i=0;i<5;i++)
    {
        printf (" %d ", vec[i]);
        suma=vec[i]+suma;
        promedio=suma/5;
    }


    printf ("\nla suma da %d y el promedio es %d", suma,promedio);
    return 0;
}
