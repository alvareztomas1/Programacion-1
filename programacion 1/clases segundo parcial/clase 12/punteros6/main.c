#include <stdio.h>
#include <stdlib.h>

void getChar(char* message, char* caracter);

int main()
{
    char sexo;
    char mensaje[]="Ingrese sexo: ";

    getChar(mensaje, &sexo);/*LOS PARAMETROS FORMALES SON IGUALES PERO PORQUE LOS DOS GUARDAN LA DIRECCION DE MEMORIA
                              DEL PRIMER ELEMENTO DEL VECTOR, PERO DESPUES DECLARAMOS CHAR SEXO. OSEA QUE ES UN CARAC
                              TER SOLO*/

    printf("El sexo es: %c", sexo);

    return 0;
}

void getChar(char* message, char* caracter)
{
    printf("%s ", message);
    fflush(stdin);
    scanf("%c", caracter); //VA SOLO CARACTER PORQUE YA LE LLEGO UNA DIRECCION DE MEMORIA




}
