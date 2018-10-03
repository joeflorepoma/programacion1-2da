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

/** \brief Inicializa el estado en un array de gamess
 * \param games el array donde hay que buscar
 * \param cantidad la longitud del array
 * \return devuelve void
 */

void inicializarAlquiler(eAlquileres rent[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        rent[i].estado = 0;
    }
}

/** \brief busca el primer lugar libre en el array
 * \param games el array donde se va a buscar
 * \param cantidad indica la longitud del array
 * \return  -1 si no hay espacio libre y (i) si hay la posicion del mismo
 */

int buscarEspacioLibreAlquiler(eAlquileres rent[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(rent[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param games Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param codigo Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */


int buscarAlquilerPorCodigo(eAlquileres rent[], int cantidad, int auxCodAlquiler)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(rent[i].estado == 1 && rent[i].CodigoAlquiler == auxCodAlquiler)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnAlquiler(eAlquileres rent, eJuegos games, eClientes client)
{
    printf("\n | %6d  | %10d | %10d | %10d | %10d | %10d |\n", rent.CodigoAlquiler, rent.date.dia, rent.date.mes, rent.date.anio, games.CodigoJuego, client.CodigoCliente);
}

/** \brief imprime los datos ingresados
 * \param games el array donde se buscara los datos
 * \param cantidad el numero de datos ingresados
 * \return no devuelve nada
 */


