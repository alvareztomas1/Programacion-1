#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vec;

    vec = (int*)calloc(10, sizeof(int)*10);
    //calloc TE SIRVE PARA INICIALIZAR UN NUMERO DE VALORES A 0

    /* NO SE USA MUCHO*/
    for (int i=0; i< 10;i++)
    {
        printf("%d ", *(vec+i));
    }
    return 0;
}
