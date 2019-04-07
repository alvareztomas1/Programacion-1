#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[64];
    int cantidad;

    printf("Nombre: ");
    //  fgets(cadena, 62, stdin);
    fgets(cadena,sizeof(cadena)-2,stdin);
    /*  con esta funcion hay 1 caracter demas ya que usa 2 \0
        lo que hay que hacer es pasa borrar el primer \0 y pasar el segundo al lugar del primero
        sizeof te dice cuanto ocupa en memoria lo que le ingreses. Gracias a esto si ingresamos mas
    c   aracteres de los que indicamos, los corta hasta los que indicamos.
    */
    cantidad = strlen(cadena);
    //  strlen te devuelve la cantidad de caracteres que tiene la cadena
    cadena[cantidad-1] = '\0';

    printf("%s", cadena);

    return 0;
}
