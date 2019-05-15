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


    eEmpleado* punteroEmpleado;
    punteroEmpleado = &unEmpleado;

    printf("Legajo: %d\n", punteroEmpleado->legajo);
    printf("Legajo: %d\n", *punteroEmpleado);// FUNCIONA PORQUE ESTA MOSTRANDO EL PRIMER ELEMENTO DE LA ESTRUCTURA

    printf("Fecha: %d/%d/%d\n", punteroEmpleado->fecha.dia, punteroEmpleado->fecha.mes, punteroEmpleado->fecha.anio);

     //EL PRINTF DE ABAJO NO TIENE SENTIDO PERO QUISO EXPLICARLO
    //printf("Fecha: %d/%d/%d\n", (*punteroEmpleado).fecha.dia, (*punteroEmpleado).fecha.mes, (*punteroEmpleado).fecha.anio);


    return 0;
}
