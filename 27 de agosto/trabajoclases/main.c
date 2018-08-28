#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27

int main()
{
    /* int valor = 0;


     while(valor<10)
     {
         printf("%d\n", valor+1);
         valor++;
     }*/

    /*int valor = 0;

    do{

        valor++;
        printf("%d\n", valor);

    }while(valor < 10);*/

    char seguir;
    int numero;
    int max;
    int min;
    int flag = 0;

    do
    {
        system("cls");

        printf("\nIngrese un numero: ");
        scanf("%d", &numero);

        if(flag == 0)
        {
            min = numero;
            max = numero;
            flag = 1;
        }
        if(numero > max)
        {
            max = numero;
        }
        if(numero < min)
        {
            min = numero;
        }

        printf("\nPresione ESC para salir, cualquier otra tecla para continuar...\n");
        seguir = getch();


    }while(seguir != ESC);

    printf("\n%d\n\n", max);
    printf("%d\n", min);

    return 0;
}
