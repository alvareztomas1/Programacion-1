#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char nombre[20]={"jUAn"};
    char apellido[20]={"pEREz"};

    char nombreCompleto[41];

   strcpy (nombreCompleto, apellido);
   strcat (nombreCompleto, ", ");
   strcat (nombreCompleto, nombre);

   strlwr(nombreCompleto);
   nombreCompleto[0]=toupper(nombreCompleto[0]);

    for (int i=0; i<strlen(nombreCompleto); i++)
   {
       if(nombreCompleto[i]==' ')
       {
           nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
       }
   }

    puts (nombreCompleto);
    return 0;
}
