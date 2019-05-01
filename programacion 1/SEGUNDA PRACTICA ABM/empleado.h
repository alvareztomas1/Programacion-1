typedef struct
{
    int dia,mes,anio;

}eFecha;

typedef struct
{
    int legajo;
    char apellido[20];
    char nombre[20];
    char genero;
    float sueldo;
    eFecha fechaDeIngreso;
    int idSector;
    int itsEmpty;

}eEmpleados;

typedef struct
{
    int id;
    char desc[51];
}eSectores;

typedef struct
{
    int idMenu;
    char desc[51];
    int precio;

}eMenus;

typedef struct
{
    int idAlmuerzo;
    int idMenu;
    int legajoEmpleado;
    eFecha fechaDeAlmuerzo;

}eAlmuerzo;

int menu();
void inicializarEmpleados (eEmpleados emp[], int tamEmp);
void hardcode (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eMenus men[], int tamMen);
int buscarLibre (eEmpleados emp[], int tamEmp);
void altaEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eAlmuerzo alm[], int contador);
void mostrarEmpleado (eEmpleados emp, eSectores sec[], int tamSec);
void mostrarEmpleados(eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);
void copiarSector (char sector[], eSectores sec[], int tamSec, int id);
void ordenarEmpleados (eEmpleados emp[], int tamEmp);
void bajaEmpleado (eEmpleados emp[], int tamEmp);
void modificarEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);
void altaAlmuerzo (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eMenus men[], int tamMen, eAlmuerzo alm[], int contador);
void mostrarAlmuerzo (eEmpleados emp[], int tamEmp, eMenus men[], int tamMen, eAlmuerzo alm[], int tamAlm);
