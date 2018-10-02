#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "funciones.h"
#include "utn.h"

/** \brief Inicializa el estado en un array de products
 * \param product el array donde hay que buscar
 * \param cantidad la longitud del array
 * \return devuelve void
 */

void inicializar(eProducto product[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        product[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param product el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibre(eProducto product[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(product[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param book Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param codigo Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */


int buscarProductoPorCodigo(eProducto product[], int cantidad, int code)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(product[i].estado == 1 && product[i].codigo == code)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnProducto(eProducto product)
{
    printf("\n | %6d  | %13s | %6.2f | %6d |\n", product.codigo, product.descripcion, product.importe, product.cantidad );
}

void mostrarProductos(eProducto product[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Productos---\n\n");

    printf("\n | %6s  | %13s | %6s | %6s |\n", "Cod.", "Descripcion", "Importe", "Cantidad" );

    for(i=0; i < cantidad; i++)
    {
        if(product[i].estado != 0)
        {
            mostrarUnProducto(product[i]);
        }
    }

    system("pause");
}

void ingresoDatos(eProducto product[],int espacioLibre, int auxCod,char auxDescrip[], float auxImporte,int auxCantidadProd)
{
    product[espacioLibre].codigo = auxCod;
    strcpy(product[espacioLibre].descripcion,auxDescrip);
    product[espacioLibre].importe = auxImporte;
    product[espacioLibre].cantidad = auxCantidadProd;
    product[espacioLibre].estado = 1;
}

void ingresoProducto(eProducto product[], int cantidad, int code, char description[], float impor, int cantidadProd)
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Productos-----\t\n\n");


    espacioLibre = buscarEspacioLibre(product, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        code = getValidInt("\nIngrese el codigo: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = buscarProductoPorCodigo(product,cantidad, code);

        if(busqueda != -1)
        {
            printf("\nEl codigo del producto ya existe.\n");
            printf("\n | %6s  | %13s | %6s | %6s |\n", "Cod.", "Descripcion", "Importe", "Cantidad" );
            mostrarUnProducto(product[busqueda]);

        }
        else
        {
            getValidString("Ingrese la descripcion: \n", "\nIngrese solo caracteres.\n\n", description);
            impor = getValidFloat("Ingrese importe: \n", "\nIngrese numeros reales.\n\n");
            cantidadProd = getValidInt("Ingrese la cantidad: \n", "\nIngrese solo numeros\n\n", 1, 10000);

            ingresoDatos(product, espacioLibre, code, description, impor, cantidadProd);

        }
    }

    system("pause");
}

void modificarProducto(eProducto product[], int cantidad, int code, char description[], float impor, int cantidadProd)
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Productos-----\t\n\n");


    code = getValidInt("\nIngrese el codigo a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 1000);

    busqueda = buscarProductoPorCodigo(product, cantidad, code);

    if(busqueda == -1)
    {
        printf("\nEl codigo del producto no se encuentra en la base de datos.\n");
    }
    else
    {
        getValidString("Re-ingrese la descripcion: \n", "\nIngrese solo caracteres.\n\n", description);
        impor = getValidFloat("Re-ingrese el importe: \n", "\nIngrese numeros reales.\n\n");
        cantidadProd = getValidInt("Re-ingrese la cantidad: \n", "\nIngrese solo numeros\n\n", 1, 10000);

        ingresoDatos(product, busqueda, code, description, impor, cantidadProd);
    }

    system("pause");
}

void bajaProducto(eProducto product[], int cantidad, int code)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Producto-----\t\n\n");

    code = getValidInt("\nIngrese el codigo dar de baja: \n", "Ingrese solo numeros.\n", 1, 1000);

    busqueda = buscarProductoPorCodigo(product, cantidad, code);

    if(busqueda == -1)
    {
        printf("\n El el codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {

        printf("\n | %6s  | %13s | %6s | %6s |\n", "Cod.", "Descripcion", "Importe", "Cantidad" );
        mostrarUnProducto(product[busqueda]);

        do
        {
            printf("\n\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            product[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void ordenarPorDescripcion(eProducto product[], int cantidad)
{
    int i, j;
    eProducto auxProd;

    for(i=0; i<cantidad-1; i++)
    {
        if(product[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(product[i].estado == 0)
            {
                continue;
            }

            if(strcmp(product[i].descripcion,product[j].descripcion)==0 && product[i].cantidad>product[j].cantidad)

            {
                auxProd = product[i];
                product[i] = product[j];
                product[j] = auxProd;
            }
            else if(strcmp(product[i].descripcion,product[j].descripcion)>0)
            {

                    auxProd = product[i];
                    product[i] = product[j];
                    product[j] = auxProd;

            }

        }
    }
}
