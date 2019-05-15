#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>



void validarDosChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    printf("%s", message);
    fflush(stdin);
    *input=getche();
    printf("\n");
    system("pause");


    *input = tolower(*input);

    while (*input != lowLimit && *input != hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);

        scanf("%c", input);
        fflush(stdin);
        *input = tolower(*input);
    }
}


