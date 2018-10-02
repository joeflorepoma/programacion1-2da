#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "productos.h"
#include "utn.h"

#define CANT 2
#define ESC 27

void inicializar(eProductos prod[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        prod[i].estado = 0;
    }
}

int buscarLibre(eProductos prod[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(prod[i].estado == 0)
        {
            return i;
            break;
        }
    }

    return -1;
}

int buscarPorCodigo(eProductos prod[], int cantidad, int cod)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(prod[i].estado == 1 && prod[i].codigo == cod)
        {
            return i;
            break;
        }
    }
    return -1;
}


void menu()
{
    eProductos product[CANT];

    int auxCodigo;
    char auxDescripcion[51];
    float auxImporte;
    int auxCantidad;

    int r;
    int l;
    int m;
    int n;

    char opcion;
    int libre;
    int busqueda;

    inicializar(product, CANT);

    do
    {
        system("cls");
        printf("\n\t-----ABM PRODUCTOS-----");
        printf("\n\n1.-Alta: \n2.-Modificar: \n3.-Baja: \n4.-Listar: \nESC para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            system("cls");

            printf("\n\t-----ALTA-----\n");

            libre = buscarLibre(product, CANT);

            if(libre == -1)
            {
                printf("\nno hay espacios libres.\n");

            }
            else
            {
                r = utn_getNumero(&auxCodigo, "Ingrese un codigo: ", "Ingrese solo numeros.\n", 1, 10000, 3);


                if(r == -1)
                {
                    printf("\nFin de los reintentos.\n");
                    system("pause");
                }
                else
                {
                    busqueda = buscarPorCodigo(product, CANT, auxCodigo);

                    if(busqueda != -1)
                    {
                        printf("\nEse codigo ya existe.\n");

                    }
                    else
                    {
                        product[libre].codigo = auxCodigo;

                        l = utn_getTexto(auxDescripcion, "Ingrese la descripcion: \n", "\nIngrese solo letras.\n", 3);

                        if(l == -1)
                        {
                            printf("\nFin de los reintentos.\n");
                            system("pause");
                        }
                        else
                        {
                            strcpy(product[libre].descripcion, auxDescripcion);

                            m = utn_getNumeroConDecimal(&auxImporte, "Ingrese el importe: ", "Ingrese solo numeros: \n", 3);

                            if(m == -1)
                            {
                                printf("\nFin de los reintentos.\n");
                                system("pause");
                            }
                            else
                            {
                                product[libre].importe = auxImporte;

                                n = utn_getNumero(&auxCantidad, "Ingrese la cantidad: \n", "\nIngrese solo numeros.\n", 1, 1000, 3);

                                if(n == -1)
                                {
                                    printf("\nFin de los reintentos.\n");
                                    system("pause");
                                }else
                                {
                                    product[libre].cantidad = auxCantidad;
                                    product[libre].estado = 1;
                                }
                            }
                        }
                    }
                }

            }

            break;

        case '2':
            break;

        case '3':
            break;

        case '4':
            system("cls");

            for(int i=0; i<CANT; i++)
            {
                printf("%d\n", product[i].codigo);
            }
            system("pause");
            break;

        case ESC:
            break;
        }


    }
    while(opcion != ESC);
}

