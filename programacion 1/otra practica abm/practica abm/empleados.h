typedef struct
{
    int dia, mes, anio;

}eFecha;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int legajo;
    char apellido[51];
    char nombre [51];
    char sexo;
    float sueldo;
    eFecha fechaDeIngreso;
    int idSector;
    int itsEmpty;

}eEmpleados;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int id;
    char desc[51];
}eSectores;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idMenu;
    char desc[51];
    int precio;

}eMenus;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idAlmuerzo;
    int idMenu;
    int legajoEmpleado;
    eFecha fechaDeAlmuerzo;
    int itsEmpty;

}eAlmuerzo;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarEmpleados (eEmpleados emp[], int tamEmp);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hardcode (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, eMenus men[], int tamMen);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLegajo (eEmpleados emp[], int tamEmp, int legajo);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLibre (eEmpleados emp[], int tamEmp);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bajaEmpleado (eEmpleados emp[], int tamEmp);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarEmpleado (eEmpleados emp, eSectores sec[], int tamSec);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void copiarSector (char nombreSector[], int id, eSectores sec[], int tamSec);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarEmpleados (eEmpleados emp[], int tamEmp);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarAlmuerzos(eAlmuerzo alm[], int tamAlm);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarAlmuerzoLibre (eAlmuerzo alm[], int tamAlm);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaAlmuerzo (eAlmuerzo alm[], int tamAlm, eEmpleados emp[], int tamEmp, eMenus men[],int tamMen, int contador);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAlmuerzo (eEmpleados emp[], int tamEmp, eMenus men[],int tamMen, eAlmuerzo alm[], int tamAlm);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarEmpleadosPorSector (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarCantidadEmpleadosPorSector (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarCantidadEmpleadosPorSector (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSectorConMasEmpleados (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);
