#include <stdio.h>
#include <stdlib.h>
int factorial (int);

int main()
{
    int num;
    int result;

    do
    {
    printf ("ingrese un numero positivo: ");
    scanf ("\n%d", &num);
    }
    while (num<-1);

    result = factorial(num);
    printf ("el factorial da %d", result);

    return 0;
}
int factorial(int num)
{
    int contador;

    contador=1;

    for (num;num!=0;num--)
    {
        if (contador==1)
        {
            contador=num;
        }
        else
        {
            contador=contador*num;
        }
    }


    return contador;
}

