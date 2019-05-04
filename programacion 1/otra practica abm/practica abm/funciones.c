#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>


void getRespuesta (char* resp, char* message, char* eMessage)
{
    printf("%s", message);
    *resp=getche();
    printf("\n");
    system("pause");


    while (tolower(*resp)!='s' && tolower(*resp)!='n')
    {
        printf("%s", eMessage);
        *resp=getche();
        printf("\n");
        system("pause");
        printf("\n");
    }
}

void getCharGenero(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
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


