#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

#define ARCH	".\\bin.dat"



int main()
{
    FILE *bin;
    struct eEmpleado;
    int cant;
    char seguir='s';

    if (bin=fopen(ARCH, "rb+")==NULL)
    {
        if (bin=fopen(ARCH, "wb+")==NULL)
            {
                printf("No se pudo abrir el archivo\n");
                exit(1);
            }
    }

    do
    {
        switch(menu())
        {

        }
    }while (seguir=='s');


    return 0;
}
