#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "utn.h"

#define ESC 27
#define CANT 4

int main()
{
    eProducto productos[CANT]={{5, "panadero", 2, 12.32,1},
                               {1, "casa", 3, 11.33,1},
                               {2, "casa", 4, 123.32,1},
                               {4, "abel", 43, 11.44,1}};

    int auxCodigo=0;
    char auxDescripcion[51];
    float auxImporte=0;
    int auxCantidadProd=0;

    char opcion;

    //inicializar(productos, CANT);


    do
    {
        system("cls");
        printf("\n\tEmpleados");
        printf("\n\n1.-Alta: \n2.-Modificar: \n3.-Baja: \n4.-Listar: \nESC para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            ingresoProducto(productos, CANT,auxCodigo, auxDescripcion, auxImporte, auxCantidadProd);
            break;
        case '2':
            modificarProducto(productos, CANT, auxCodigo, auxDescripcion, auxImporte, auxCantidadProd);
            break;
        case '3':
            bajaProducto(productos, CANT, auxCodigo);
            break;
        case '4':
            ordenarPorDescripcion(productos, CANT);
            mostrarProductos(productos, CANT);
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
