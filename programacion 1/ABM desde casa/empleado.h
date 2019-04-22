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
    eFecha fechaNac;
    int idSector;
    int estado;


}eEmpleado;

typedef struct
{
    int id;
    char desc[20];

}eSector;

int menu(void);
void inicializarEstado (eEmpleado vec[], int tam);
void mostrarEmpleado (eEmpleado emp, eSector sec[], int tamSector);
void mostrarEmpleados (eEmpleado vec[], int tam, eSector sec[], int tamSector);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (eEmpleado vec[], int tam, int legajo);
void altaEmpleado (eEmpleado vec[], int tam, eSector sec[], int tamSector);
void bajaEmpleado (eEmpleado vec[], int tam);
void modificarEmpleado (eEmpleado vec[], int tam);
void ordenarEmpleado (eEmpleado vec[], int tam);
void obtenerSector (char vec[],eSector sec[], int tamSec, int id);
