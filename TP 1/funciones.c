float sumar (float x,float y)
{
    int suma;

    suma=x+y;

    return suma;
}
float restar (float x, float y)
{
    int resta;

    resta=x-y;

    return resta;
}
 float dividir (float x, float y)
{
    int division;

    division=x/y;

    return division;
}
float multiplicar (float x, float y)
{
    int multiplicacion;

    multiplicacion=x*y;

    return multiplicacion;
}
int factorear (float x)
{
    int factoreo;
    factoreo=1;

    for ((int)x;x!=0;x--)
    {

        if (factoreo==1)
        {
            factoreo=x;
        }
        else
        {
            factoreo=factoreo*x;
        }
    }

    return factoreo;
}
