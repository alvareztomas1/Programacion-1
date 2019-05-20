#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pnum;
    int* pauxiliar;

    pnum = (int*) malloc(sizeof(int) * 5);// SI QUISIERA AGRANDAR ESTO SE USA realloc

    if ( pnum==NULL )
    {
        printf("No hay espacio en memoria\n");
        system("pause");
        exit(1);
    }


    for (int i=0; i<5; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", pnum+i);
    }

    printf("\n\n");

    for (int i=0; i<5; i++)
    {

        printf("%d ", *(pnum+i));
    }

    printf("\n\n");

     pauxiliar = (int*)realloc(pnum, sizeof(int) * 10);
     printf("\nSe agrando el array\n");
    /* PUEDE PASAR QUE LOS OTROS ESPACIOS AGREGADOS ESTEN OCUPADOS POR EJEMPLO. DEVUELVE NULL
       SI TENEMOS SUERTE TE DEVUELVE LA MISMA DIRECCION DE MEMORIA
       PUEDE PASAR QUE TRATE DE CONSEGUIRTE ESE ESPACIO EN OTRO LADO
       SI LO ENCUENTRA EN OTRO LADO TE MUDA LAS DIRECCIONES DE MEMORIA
       Y LIBERA LA OTRA PARTE QUE QUEDO LIRE

       SI NO LO PUEDE AGRANDAR PUEDE PASAR QUE TE PIERDA TODOS LOS VALORES ANTERIORES
                    ******POR ESO SE USA UN AUXILIAR******
    */
    if (pauxiliar!=NULL)
    {
        pnum=pauxiliar;

        for (int i=5    ; i<10; i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", pnum+i);
        }

        printf("\n\n");

        for (int i=0; i<10; i++)
        {

            printf("%d ", *(pnum+i));
        }
    }

    pnum = (int*)realloc(pnum, sizeof(int)*5);
    printf("\n\nSe achico el array\n");

    for (int i=0; i<5; i++)
    {
        printf("%d ", *(pnum+i));
    }


    printf("\n\n");

    free(pnum);

    return 0;
}
