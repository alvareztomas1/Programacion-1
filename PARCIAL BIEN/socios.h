typedef struct
{
    int dia, mes, anio;

}eFecha;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int legajo;
    char apellido[31];
    char nombre [31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha fechaDeIngreso;
    int itsEmpty;

}eSocio;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idAutor;
    char apellido[31];
    char nombre[31];
    int itsEmpty;

}eAutor;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idLibro;
    char titulo[51];
    int idAutor;
    int itsEmpty;

}eLibros;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idPrestamo;
    int idLibro;
    int legajoEmpleado;
    eFecha fechaDePrestamo;
    int itsEmpty;

}ePrestamo;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Menu para ingresar los datos
 *
 * \return opcion ingresada por el usuario
 *
 */

int menu();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre todo el array de estructura eSocio y le da valor 1 al campo itsEmpty
 *
 * \param  soc Array de estructura a recorrer
 * \param  tamSoc El tamaño de la estructura recorrida
 * \return  Void
 *
 */

void inicializarEmpleados (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre todo el array de estructura eLibros y le da valor 1 al campo itsEmpty
 *
 * \param  lib Array de estructura a recorrer
 * \param  tamLib El tamaño de la estructura recorrida
 * \return  Void
 *
 */

void inicializarLibros (eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre todo el array de estructura eAutor y le da valor 1 al campo itsEmpty
 *
 * \param  aut Array de estructuras a recorrer
 * \param  tamAut El tamaño de la estructura recorrida
 * \return  Void
 *
 */

void inicializarAutores (eAutor aut[], int tamAut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Inicializa los valores de los campos de las estructuras
 *
 * \param  soc Array de Estructura socios a la que se le cargan valores
 * \param  tamSoc Tamaño de la estructura soc
 * \param  lib Array de estructuras libros a la que se le cargan valores
 * \param  tamSec Tamaño de la estructura sec
 * \param  pres Array de estructuras prestamos a la que se le cargan valores
 * \param  tamPres Tamaño de la estructura pres
 * \return void
 *
 */

void hardcode (eSocio soc[], int tamSoc, eAutor aut[], int tamAut, eLibros lib[], int tamLib, ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca el campo legajo de un empleado
 *
 * \param soc Array de Estructura a recorrer
 * \param tamSoc Tamaño de la estructura
 * \param legajo Legajo ingresado por el usuario que se compara con los que ya estan dados de alta
 * \return El indice del legajo.
 *
 */

int buscarLegajo (eSocio soc[], int tamSoc, int legajo);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca en el array de estructuras que hay algun campo itsEmpty que valga 1
 *
 * \param soc Array de Estructura a recorrer
 * \param tamSoc Tamaño de la estrucura
 * \return indice donde encontro el itsEmpty = 1 o -2 si no encuentra nada
 *
 */

int buscarLibre (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Pide los datos al usuario, verifica que esten bien, de ser asi da de alta al socio
 *
 * \param soc Array de Estructuras donde se guardan los datos del socio
 * \param tmaSoc Tamaño de la estructura
 * \param contador Me permite volver autoincremental el campo legajo
 * \return Void
 *
 */

void altaSocio (eSocio soc[], int tamSoc, int contador);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Imprime los datos del socio recibido
 *
 * \param soc Estructura de tipo eSocio a imprimir
 * \return Void
 *
 */

void mostrarSocio (eSocio soc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre el array de estructura eSocios e imprime los datos de los socios que tengan itsEmpty valiendo 0
 *
 * \param soc Array de estructuras a recorrer
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */

void mostrarSocios (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Imprime los datos del libro recibido
 *
 * \param soc Estructura de tipo eLibro a imprimir
 * \return Void
 *
 */

void mostrarLibro(eLibros lib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre el array de estructura eLibros e imprime los datos de los libros que tengan itsEmpty valiendo 0
 *
 * \param lib Array de estructuras a recorrer
 * \param tamLib Tamaño de la estructura
 * \return Void
 *
 */

void mostrarLibros (eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Imprime los datos del autor recibido
 *
 * \param aut Estructura de tipo eAutor a imprimir
 * \return Void
 *
 */

void mostrarAutor (eAutor aut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre el array de estructura eAutor e imprime los datos de los autores que tengan itsEmpty valiendo 0
 *
 * \param aut Array de estructuras a recorrer
 * \param tamAut Tamaño de la estructura
 * \return Void
 *
 */

void mostrarAutores (eAutor aut[], int tamAut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Pide el legajo de algun socio y si el usuario acepta da de baja a la persona cambiando el valor de itsEmpty a -1
 *
 * \param soc Array de estructuras donde se cambiara el valor de itsEmpty si el legajo ingresado existe
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */

void bajaSocio (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Ordena los datos de los socios por apellido y nombre
 *
 * \param soc Array de estructuras en la que se ordenaran los datos
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */

void ordenarSocios (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Ordena los datos de los autores por apellido y nombre
 *
 * \param aut Array de estructuras en la que se ordenaran los datos
 * \param tamAut Tamaño de la estructura
 * \return Void
 *
 */

void ordenarAutores (eAutor aut[], int tamAut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Ordena los datos de los libros por titulo
 *
 * \param lib Array de estructuras en la que se ordenaran lols datos
 * \param tamLib Tamaño de la estructura
 * \return Void
 *
 */

void ordenarLibros(eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Permite al usuario cambiar los datos de un socio ya ingresado
 *
 * \param soc Array de estructura donde se modificara los datos del socio en caso de que exista
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */

void modificarSocio (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Inicializa el valor del campo itsEmpty en 1
 *
 * \param pres Array de estructura donde se inicializara el valor del campo
 * \param tamPres Tamaño de la estructura
 * \return Void
 *
 */

void inicializarPrestamo(ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre el array de estructura y busca que en alguno de los indices tengan un campo itsEmpty igual a 1
 *
 * \param  pres Array de estructuras a recorrer
 * \param tamPres tamaño de la estructura
 * \return  Indice donde encontro  el itsEmpty igual a 1. De no ser asi -2
 *
 */

int buscarPrestamoLibre (ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Pide los datos al usuario, verifica que esten bien, de ser asi da de alta el prestamo
 *
 * \param pres Array de Estructuras donde se guardan los datos del prestamo
 * \param tamPres Tamaño del array de estructura pres
 * \param soc Array de estructurtas que permite verificar que el legajo ingresado exista
 * \param tamSoc Tamaño del array de estructuras soc
 * \param lib Array de estructuras que me permite mostrar los libros disponibles
 * \param tamLib Tamaño del array de estructuras lib
 * \param contador Me permite volver autoincremental el campo idPrestamo
 * \return Void
 *
 */

void altaPrestamo (ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc, eLibros lib[], int tamLib, int contador);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recorre  los array de estructuras pres, soc y lib y en caso de que haya encontrado algun prestamo dado de alta lo muestra
 *
 * \param pres Array de estructura a recorrer
 * \param tamPres Tamaño de la estructura pres
 * \param  aut Array de estructura a recorrer
 * \param tamAut Tamaño de la estructura aut
 * \param lib Array de estructura a recorrer
 * \param tamLib Tamaño de la estructura lib
 * \return Void
 *
 */

void mostrarPrestamo (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPrestamosDeLibro (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarAutorConMasLibros (eAutor aut[], int tamAut, eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPrestamosDeUnSocio (eSocio soc[],int tamSoc,eAutor aut[],int tamAut,ePrestamo pres[], int tamPres);

