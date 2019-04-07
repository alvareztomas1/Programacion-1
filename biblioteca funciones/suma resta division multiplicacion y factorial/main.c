#include <stdio.h>
#include <stdlib.h>

float sumar (float x,float y)
{
    float suma;

    suma=x+y;

    return suma;
}
float restar (float x, float y)
{
    float resta;

    resta=x-y;

    return resta;
}
 float dividir (float x, float y)
{
    float division;

    if (y=0)
    {
        printf ("no se puede dividir por 0. Reingrese");
    }

    division=x/y;

    return division;
}
int multiplicar (float x, float y)
{
    float multiplicacion;

    multiplicacion=x*y;

    return multiplicacion;
}

int factoreo (float x)
{
    int resp;
    resp=1;

    for (x;x!=0;(int)x;x--)
    {

        if (resp==1)
        {
            resp=x;
        }
        else
        {
            resp=resp*x;
        }
    }

    return resp;
}


/*
int sumar (int num1,int num2);
int restar (int num1, int num2);
float dividir (int num1, int num2);
int multiplicar (int num1, int num2);
int factoreo (int num1, int num2);
*/




