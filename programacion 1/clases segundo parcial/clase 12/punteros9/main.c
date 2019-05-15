#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fecha;

}eEmpleado;


int main()
{
    eEmpleado unEmpleado={1234, "Juan", 'm', 30000, {13,5,2019}};
    eEmpleado otroEmpleado={2222, "Ana", 'f', 32000, {20,8,2019}};
    eEmpleado lista[]= {unEmpleado, otroEmpleado};

    for (int i=0;i<2;i++)//MUESTRO JUAN Y ANA
    {
         printf("%s\n", (lista+i)->nombre);
    }


    printf("%s\n", (lista+1)->nombre); //LISTA+1 ES LA DIRECCION DE MEMORIA DE ANA

    return 0;
}
