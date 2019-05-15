#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x=10;
    int* p=&x;
   // int* q=p;
    int** r=&p;// Puntero a puntero

    printf("%d\n", **r);

    //printf("%d\n", *q);
    return 0;
}


