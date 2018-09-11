#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include <string.h>

void inicializar(eEmpleado *emple, int cantidad)
{
    int i=0;

    for(i=0; i<cantidad; i++)
    {
        emple->estado = 0;
    }
}

int buscarLibre(eEmpleado *emple, int cantidad)
{
    int i=0;

    for(i=0; i<cantidad; i++)
    {
        if(emple->estado == 0)
            return i;
    }

    return -1;
}

int buscarPorId(eEmpleado *emple, int cantidad, int identi)
{
    int i=0;

    for(i=0; i<cantidad; i++)
    {
        if(emple[i].estado == 1 && emple[i].id == identi)
            return i;
    }

    return -1;
}
