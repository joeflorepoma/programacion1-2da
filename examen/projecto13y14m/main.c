#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "libros.h"
#include "validaciones.h"
#include "autor.h"

#define CANT 4
#define ESC 27

int main()
{
    eLibro libros[CANT];
    inicializar(libros, CANT);

    char opcion;

    do
    {
        printf("\n------------  MENU PRINCIPAL ------------");
        printf("\n1 - ABM LIBROS \n2 - ABM AUTORES \n3 - LISTAR LIBROS\n4 - SALIR\n\n\n");
        opcion = getch();

        switch(opcion)
        {
        case '1':
            system("cls");
            adminLibros(libros, CANT);

            break;
        case '2':
            break;
        case '3':
            break;
        case ESC:
            system("cls");
            printf("\n\nPrograma finalizado.\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }
    while(opcion != ESC);

    return 0;
}
