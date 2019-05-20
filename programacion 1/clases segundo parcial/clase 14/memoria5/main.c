#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;

}eEmpleado;

int main()
{
    eEmpleado emp1;
    eEmpleado* pemp = (eEmpleado*) malloc(sizeof(eEmpleado));

    if (pemp==NULL)
    {
        printf("No hay espacio en memoria\n");
        system("pause");
        exit(1);
    }

    printf("Ingrese legajo: ");
    scanf("%d", &pemp->legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", pemp->nombre);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &pemp->sexo);

    printf("Ingrese sueldo: ");
    scanf("%f", &pemp->sueldo);

    printf("\n\nLeg: %d   Nombre: %s  Sexo: %c   Sueldo: %.2f\n\n", pemp->legajo, pemp->nombre, pemp->sexo, pemp->sueldo);

    return 0;
}

