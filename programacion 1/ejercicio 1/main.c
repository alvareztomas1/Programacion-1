#include <stdio.h>
#include <stdlib.h>
int factorial (int);

 main()
{   //FACTORIAL

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

/*

-----PASAJE POR REFERENCIA-----
int main()
{
    int x,y;

    printf ("ingrese: ");
    scanf ("%d", &x);
    printf ("ingrese: ");
    scanf ("%d", &y);

    muestra (&x,y);

    printf ("x: &d  y:%d", x,y);

    return 0;
}
void muestra (int *x, int y)
{
    *x=y;
    printf ("x: %d  y: &d",*x,y);
}
*/
/*

-----VALOR MAXIMO Y MINIMO-----

int valor;
    int min;
    int max;
    int flag;
    char rta;

    flag=0;

    do
    {
        printf ("ingrese un valor: ");
        scanf ("%d", &valor);

        if (flag==0 || valor>max)
        {
            max=valor;
        }
        if (flag==0 || valor<min)
        {
            min=valor;

        }

        flag++;
    }while (flag<5);

    printf ("el valor maximo es %d\n", max);
    printf ("el valor minimo es %d", min);
    */
//------------------------REPASO--------------------------------

/*
    int contador;
    int nota;
    int acumulador;
    float promedio;

    contador=0;
    acumulador=0;

    do
    {
        printf ("Ingrese su nota: ");
        scanf ("%d", &nota);

        acumulador=nota+acumulador;


        contador++;
    }
    while (contador<5);
    promedio=(float)acumulador/contador;
    printf ("la suma de notas es %d\n", acumulador);
    printf ("el promedio de notas da %1.f ", promedio);

*/
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/*
char hora;

    printf ("ingrese la hora: ");
    fflush (stdin);
    scanf ("%c", &hora);

    switch (hora)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            printf ("a dormir");
            break;
        case '7':
        case '8':
            printf ("buenos dias");
            break;

        default:
            printf ("no es una hora valida");
            break;
    }
*/
//-------------------------------------------------------------------------------
/*int hora;

    printf ("ingrese la hora: ");
    scanf ("%d", &hora);

    switch (hora)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf ("a dormir");
            break;
        case 7:
        case 8:
        case 9:
            printf ("buenos dias");
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
            printf ("es de noche");
            break;
        default:
            printf ("no es una hora valida"
            break;
    }
//------------------------------------------------------------------------------

    int numero2 = 34;
    float altura = 23.5;
    char letra = 'a';

    numero2 = altura;


    printf ("la variable altura vale %.2f y la letra vale %c", altura , letra);
    printf ("la variable numero vale %d y la variable numero2 vale %d\n", numero , numero2);
    printf ("la letra vale %c\n", letra);

    */
//------------------------------------------------------------------------------
    /*
    int numero;
    int numero1;
    float resultado;

    printf ("ingrese un numero: ");
    scanf ("%d", &numero);

    printf ("ingrese el segundo numero: ");
    scanf ("%d", &numero1);



    resultado=(float)numero/numero1;

    printf ("el resultado da %.1f", resultado);
    */
//------------------------------------------------------------------------------0
