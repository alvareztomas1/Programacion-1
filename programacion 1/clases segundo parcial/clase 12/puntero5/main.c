#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVector1 (int vec[], int tam);// Utiliza nomenclatura vectorial
void mostrarVector2 (int vec[], int tam);// Utiliza nomenclatura puntero
void mostrarVector3 (int* vec, int tam);// Puntero-->vector
void mostrarVector4 (int* vec, int tam);// Puntero-->puntero

int main()
{
    int numeros[]={3, 5, 2, 4, 3};
    int *puntero=&numeros;

    mostrarVector1(numeros, TAM);// FORMA CORRECTA QUE NO VAMOS A USAR. SI LO RECIBIS COMO CORCHETE LO TRABAJAS COMO CORCHETE
    printf("\n");
    mostrarVector2(numeros, TAM);// VERSIONN QUE NO SE VE
    printf("\n");
    mostrarVector3(puntero, TAM);// VERSION NO BIEN VISTA
    printf("\n");
    mostrarVector4(puntero, TAM);/* FORMA CORRECTA. SI LO RECIBIS COMO PUNTERO LO TRABAJAS COMO PUNTERO.*DE ESTA FORMA LO VAMOS A HACER* */



    return 0;
}

void mostrarVector1 (int vec[], int tam)
{
    for (int i=0;i<tam;i++)
    {
        printf("%d ", vec[i]);
    }
}

void mostrarVector2(int vec[], int tam)
{
    for (int i=0;i<tam;i++)
    {
        printf("%d ", *(vec+i));
    }
}

void mostrarVector3 (int* vec, int tam)
{
    for (int i=0;i<tam;i++)
    {
        printf("%d ", vec[i]);
    }
}

void mostrarVector4 (int* vec, int tam)
{
    for (int i=0;i<tam;i++)
    {
        printf("%d ", *(vec+i));
    }
}
