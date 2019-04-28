#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


typedef struct{

    int dia,mes,anio;
}eFechas;
typedef struct{

    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo;
    float sueldo;
    eFechas fechaIngreso;
    int idSector;
    int estado;
}eEmpleados;
typedef struct{

    int id;
    char desc[51];
}eSectores;
typedef struct{

    int idMenu;
    char desc[51];
    int precio;
}eMenus;

typedef struct{

    int idAlmuerzo;
    int idMenu;
    int legajoEmpleado;
    eFechas fechaAlmuerzo;
}eAlmuerzos;

//________________________________________________________________________________

int menu();
void inicializarEmpleado (eEmpleados emp[], int tamEmp);
int buscarLibre (eEmpleados emp[], int tamEmp);
void mostrarEmpleado (eEmpleados emp, eSectores sec[], int tamSec);
void mostrarEmpleados(eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);
void obtenerSector (char nombreSec[], int tamSec, eSectores sec[], int id);
void altaEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec, int contadorLegajo, eAlmuerzos alm[]);
void bajaEmpleado (eEmpleados emp[], int tamEmp);
void modificarEmpleado (eEmpleados emp[], int tamEmp, eSectores sec[], int tamSec);
void altaAlmuerzo (eEmpleados emp[], int tamEmp, eMenus men[], int tamMenu, eAlmuerzos alm[]);
void mostrarAlmuerzo (eMenus men[], int tamMen);
void mostrarAlmuerzos (eEmpleados emp[], int tamEmp, eMenus men[], int tamMen, eAlmuerzos alm[], int tamAlm);
//________________________________________________________________________________

#endif
