#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pruducto.h"
#include "utn.h"

void inicializar(eProducto prod[], int cantidad, int valor)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        prod[i].estado = valor;
    }
}

int buscarPorCodigo(eProducto prod[], int cantidad, int cod)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(prod[i].codigo == cod && prod[i].estado == 1)
        {
            return i;
        }
    }

    return -1;
}

int buscarLibre(eProducto prod[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(prod[i].estado == 0)
        {
            return i;
        }
    }

    return -1;
}
