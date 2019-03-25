#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo (int x, int y, int z);

int main()
{
    int num1;
    int num2;
    int num3;
    int resultado;

    printf ("ingrese el primer numero:\n ");
    scanf ("%d", &num1);

    printf ("ingrese el segundo numero:\n ");
    scanf ("%d", &num2);

    printf ("ingrese el tercer numero:\n ");
    scanf ("%d", &num3);

    resultado = obtenerMaximo (num1,num2,num3);

    printf ("el numero maximo es %d", resultado);

    return 0;
}
int obtenerMaximo (int x, int y, int z)
{
    int numMax;

    if (x>=y && x>=z)
    {
        numMax=x;
    }
    else
    {
        if (y>=x && y>=z)
        {
            numMax=y;
        }
        else
        {
            numMax=z;
        }
    }

    return numMax;
}
