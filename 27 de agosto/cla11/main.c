#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pruducto.h"
#include "utn.h"
#define CANT 20
#define ESC 27

int main()
{
    eProducto productos[CANT];

    char auxDescripcion[51];
    int auxCodigo;
    int auxCantidad;
    float auxImporte;

    char auxCantidadStr[50];
    char auxCodigoStr[50];
    char auxImporteStr[50];

    int libre;
    int buscar;
    char opcion;

    inicializar(productos, CANT, 0);
    do
    {
        system("cls");
        printf("1- Agregar empleado\n");
        printf("2- Borrar empleado\n");
        printf("3- Modificar empleado\n");
        printf("4- Imprimir lista\n");
        printf("ESC- Salir\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':

            libre = buscarLibre(productos, CANT);

            if(libre == -1)
            {
                printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                break;
            }

            printf("\nALTA\n");

            if(!getStringNumeros("Ingrese codigo: ", auxCodigoStr))
            {
                printf("El codigo debe ser numerico.\n");
                system("pause");
                break;
            }

            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            system("pause");
            break;

        }

    }
    while(opcion != ESC);

    return 0;
}
