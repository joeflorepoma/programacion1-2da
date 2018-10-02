#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "libros.h"
#include "validaciones.h"
#include "autor.h"

#define ESC 27

void inicializar(eLibro book[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        book[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param book el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibre(eLibro book[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(book[i].estado == 0)
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


int buscarLibroPorCodigo(eLibro book[], int cantidad, int code)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(book[i].estado == 1 && book[i].codLibro == code)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnLibro(eLibro book)
{
    printf("\n | %6d  | %13s | %6.d | %6d |\n", book.codLibro, book.titulo, book.codAutor, book.stock );
}

void mostrarLibros(eLibro book[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Libros---\n\n");

    printf("\n | %6s  | %13s | %6.d | %6s |\n", "Cod.Lib", "titulo", "cod.Autor", "Stock" );

    for(i=0; i < cantidad; i++)
    {
        if(book[i].estado != 0)
        {
            mostrarUnLibro(book[i]);
        }
    }

    system("pause");
}

void ingresoDatos(eLibro book[],int espacioLibre, int auxCodLib,char auxTitulo[], int auxCodAutor,int auxStock)
{
    book[espacioLibre].codLibro = auxCodLib;
    strcpy(book[espacioLibre].titulo,auxTitulo);
    book[espacioLibre].codAutor = auxCodAutor;
    book[espacioLibre].stock = auxStock;
    book[espacioLibre].estado = 1;
}

void ingresoLibro(eLibro book[], int cantidad, int auxCodLibro, char auxTitulo[], int auxCodAutor, int auxStock)
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Libro-----\t\n\n");


    espacioLibre = buscarEspacioLibre(book, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodLibro = getValidInt("\nIngrese el codigo de libro: \n", "\nIngrese solo numeros\n\n", 1, 5000);

        busqueda = buscarLibroPorCodigo(book,cantidad, auxCodLibro);

        if(busqueda != -1)
        {
            printf("\nEl codigo del libro ya existe.\n");
            printf("\n | %6d  | %13s | %6.d | %6d |\n", "Cod.Lib", "titulo", "cod.Autor", "Stock" );
            mostrarUnLibro(book[busqueda]);

        }
        else
        {
            getValidString("Ingrese el titulo: \n", "\nIngrese solo caracteres.\n\n", auxTitulo);
            auxCodAutor = getValidInt("Ingrese el codigo del autor: \n", "\nIngrese numeros.\n\n",1, 500);
            auxStock = getValidInt("Ingrese stock: \n", "\nIngrese solo numeros\n\n", 1, 10000);

            ingresoDatos(book, espacioLibre, auxCodLibro, auxTitulo, auxCodAutor, auxStock);

        }
    }

    system("pause");
}

void modificarLibro(eLibro book[], int cantidad, int auxCodLibro, char auxTitulo[], int auxCodAutor, int auxStock)
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Libro-----\t\n\n");


    auxCodLibro = getValidInt("\nIngrese el codigo a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 5000);

    busqueda = buscarLibroPorCodigo(book, cantidad, auxCodLibro);

    if(busqueda == -1)
    {
        printf("\nEl codigo del libro no se encuentra en la base de datos.\n");
    }
    else
    {
        getValidString("Re-ingrese El titulo: \n", "\nIngrese solo caracteres.\n\n", auxTitulo);
        auxCodLibro = getValidInt("Re-ingrese el codigo autor: \n", "\nIngrese numeros.\n\n",1, 500);
        auxStock = getValidInt("Re-ingrese el stock: \n", "\nIngrese solo numeros\n\n", 1, 10000);

        ingresoDatos(book, busqueda, auxCodLibro, auxTitulo, auxCodAutor, auxStock);
    }

    system("pause");
}

void bajaLibro(eLibro book[], int cantidad, int auxCodLibro)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Libro-----\t\n\n");

    auxCodLibro = getValidInt("\nIngrese el codigo dar de baja: \n", "Ingrese solo numeros.\n", 1, 5000);

    busqueda = buscarLibroPorCodigo(book, cantidad, auxCodLibro);

    if(busqueda == -1)
    {
        printf("\n El el codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {

        printf("\n | %6d  | %13s | %6.d | %6d |\n", "Cod.Lib", "titulo", "cod.Autor", "Stock" );
        mostrarUnLibro(book[busqueda]);

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
            book[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void ordenarPorTitulo(eLibro book[], int cantidad)
{
    int i, j;
    eLibro auxLib;

    for(i=0; i<cantidad-1; i++)
    {
        if(book[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(book[i].estado == 0)
            {
                continue;
            }

            if(strcmp(book[i].titulo,book[j].titulo)>0 )
            {
                auxLib = book[i];
                book[i] = book[j];
                book[j] = auxLib;
            }
            else if(strcmp(book[i].titulo,book[j].titulo)==0 && book[i].codLibro>book[j].codLibro)
            {
                    auxLib = book[i];
                    book[i] = book[j];
                    book[j] = auxLib;

            }

        }
    }
}

void adminLibros(eLibro book[], int cantidad)
{

    int auxCodigoLibro=0;
    char auxTitulo[51];
    int auxCodigoAutor=0;
    int auxStock=0;

    char opcion;

    //inicializar(libros, CANT);

    do
    {
        system("cls");
        printf("\n-------\tABM LIBROS\t-------\n");
        printf("\n1.- Alta: \n2.- Modificacion : \n3.- Baja : \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            ingresoLibro(book, cantidad, auxCodigoLibro, auxTitulo, auxCodigoAutor, auxStock);

            break;
        case '2':

            modificarLibro(book, cantidad, auxCodigoLibro, auxTitulo, auxCodigoAutor, auxStock);
            break;
        case '3':

            bajaLibro(book, cantidad, auxCodigoLibro);
            break;
        case '4':
            ordenarPorTitulo(book, cantidad);
            mostrarLibros(book, cantidad);
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

    }while(opcion != ESC);
}

