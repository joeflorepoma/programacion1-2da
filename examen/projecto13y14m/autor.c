#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "validaciones.h"
#include "autor.h"

void inicializarAutor(eAutor author[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        author[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param book el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibreAutor(eAutor author[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(author[i].estado == 0)
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


int buscarAutorPorCodigo(eAutor author[], int cantidad, int codAutor)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(author[i].estado == 1 && author[i].codAutor == codAutor)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void ingresoDatosAutor(eAutor author[],int espacioLibre, int auxCodAuthor,char auxNombre[], char auxApellido[])
{
    author[espacioLibre].codAutor = auxCodAuthor;
    strcpy(author[espacioLibre].nombre,auxNombre);
    strcpy(author[espacioLibre].apellido, auxApellido);
    author[espacioLibre].estado = 1;
}

void mostrarUnAutor(eAutor author)
{
    printf("\n | %6d  | %13s | %6s |\n", author.codAutor, author.nombre, author.apellido);
}

void mostrarAutores(eAutor author[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de autores---\n\n");

    printf("\n | %6s  | %13s | %6s |\n", "Cod.Autor", "nombre", "apellido");

    for(i=0; i < cantidad; i++)
    {
        if(author[i].estado != 0)
        {
            mostrarUnAutor(author[i]);
        }
    }

    system("pause");
}

void ingresoAutor(eAutor author[], int cantidad, int auxCodAutor, char auxNombre[], char auxApellido[])
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Autor-----\t\n\n");


    espacioLibre = buscarEspacioLibreAutor(author, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodAutor = getValidInt("\nIngrese el codigo de autor: \n", "\nIngrese solo numeros\n\n", 1, 500);

        busqueda = buscarAutorPorCodigo(author,cantidad, auxCodAutor);

        if(busqueda != -1)
        {
            printf("\nEl codigo del autor ya existe.\n");
            printf("\n | %6s  | %13s | %6s |\n", "Cod.Autor", "nombre", "apellido");
            mostrarUnAutor(author[busqueda]);

        }
        else
        {
            getValidString("Ingrese el nombre: \n", "\nIngrese solo caracteres.\n\n", auxNombre);
            getValidString("Ingrese el apellido: \n", "\nIngrese solo caracteres.\n\n", auxApellido);

            ingresoDatosAutor(author, espacioLibre, auxCodAutor, auxNombre, auxApellido);

        }
    }

    system("pause");
}

void bajaAutor(eAutor author[], int cantidad, int auxCodAutor)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Autor-----\t\n\n");

    auxCodAutor = getValidInt("\nIngrese el codigo dar de baja: \n", "Ingrese solo numeros.\n", 1, 500);

    busqueda = buscarAutorPorCodigo(author, cantidad, auxCodAutor);

    if(busqueda == -1)
    {
        printf("\n El el codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {

        printf("\n | %6s  | %13s | %6s |\n", "Cod.Autor", "nombre", "apellido");
        mostrarUnAutor(author[busqueda]);

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
            author[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}
