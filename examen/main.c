#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "validaciones.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"

#define CANT 4
#define ESC 27

int main()
{
    eJuegos juegos[CANT];
    inicializarJuego(juegos, CANT);

    eClientes clientes[CANT];
    inicializarClientes(clientes, CANT);

    char opcion;

    do
    {
        printf("\n------------  MENU PRINCIPAL ------------");
        printf("\n1 - ABM JUEGOS \n2 - ABM CLIENTES \n3 - ABM ALQUILERES \nESC - SALIR\n\n\n");
        opcion = getch();

        switch(opcion)
        {
        case '1':
            system("cls");
            adminJuegos(juegos, CANT);
            break;
        case '2':
            system("cls");
            adminClientes(clientes, CANT);
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
