#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 5


int main()
{
    // hay una funcion en string.h que te deja comparar cadenas
    strcmp(cad1,cad2)
    /*  devuelve un valor entero: 0 si cad1==cad2. >0 si cad1>cad2. <0 si cad1<cad2
        cuando encuentra la primer diferencia determina cual es mas grande segun el acsii.
        No importa que alguna tenga muchos mas caracteres
    */


    stricmp
    //  funciona igual pero da lo mismo que sea mayuscula o minuscula (por  lo del acsii. Vamos a usar la de arriba)



    strcpy (cad1,cad2)
    //  cad1 siempre tiene que ser una variable. Le das el valor de cad2 a cad1


    return 0;
}




/*
-----------------------cadena con scanf-----------------------------------------//
char cadena[50];// siempre tenemos un caractermenos de los que ponemos porque se usa el ultimo para cortar la cadena con '\0'

    printf ("ingrese un nombre: ");
    fflush (stdin);
    scanf("%s", cadena);//sin & porque el nombre del vector es la direccion de memoria del comienzo del vector. Se podria poner &cadena[0]
    printf ("\nEl nombre ingresado es %s", cadena);
----------------------ORDENAR DE FORMA ASCENDENTE--------------------------------------------------------
 int vec[5];
    int aux;// necesito para ordenar, asi guardo el dato que se movera. (tiene quye ser del mismo tipo que el vector)

    for (int i=0;i<CANT;i++)
    {
        printf ("Ingrese 5 vectores: ");
        scanf ("%d", &vec[i]);
    }
    for (int i=0;i<CANT-1;i++)
    {
        for(int j=i+1;j<CANT;j++)
        {
            if (vec[i]>vec[j])//si usas mayor se ordena ascendente
            {
                aux=vec[i];//guardar el valoir en auxiliar y luego truncas los valores
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
    for (int i=0;i<CANT;i++)// ES NECESARIO OTRO FOR PARA MOSTRAR, ASI TOMA LOS DIFERENTES INDICES EN LA VARIABLE I
    {
      printf ("%d ", vec[i]);
    }

---------------------DECLARAR VECTOR, SUMARLOS Y SACAR PROMEDIO--------------------------------
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
        suma+=vec[i];
        promedio=suma/5;
    }


    printf ("\nla suma da %d y el promedio es %d", suma,promedio);
    return 0;
    */
