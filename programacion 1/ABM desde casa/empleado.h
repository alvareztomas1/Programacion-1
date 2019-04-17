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
    int estado;
    eFecha fechaNac;
    int idSector;

}eEmpleado;

typedef struct
{
    int id;
    char desc[31];
}
int menu(void);
void inicializarEstado (eEmpleado vec[], int tam);
void mostrarEmpleado (eEmpleado emp);
void mostrarEmpleados (eEmpleado vec[], int tam);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (eEmpleado vec[], int tam, int legajo);
void altaEmpleado (eEmpleado vec[], int tam);
void bajaEmpleado (eEmpleado vec[], int tam);
void modificarEmpleado (eEmpleado vec[], int tam);
