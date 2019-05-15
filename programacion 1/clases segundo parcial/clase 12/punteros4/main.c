#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[]={3, 5, 2, 4, 3};

    //int* p;
    for (int i=0;i<5;i++)
    {
         printf("%d ", *(vec+i));
    }
    //printf("%d\n", *(vec+3));// decirle +1 es decirle + UN SIZEOF DE ENTERO

    return 0;
}

