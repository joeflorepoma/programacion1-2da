#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "utn.h"
#include "productos.h"

static int esNumerica(char *cadena)
{
    int ret=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}


static int getInt(int *pResultado)
{
    int ret=-1;
    char buffer[8];

    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}

int utn_getNumero(int *pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    int num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(getInt(&num)==1)
        {
            if(num<=maximo && num>=minimo)
                break;
        }
        reintentos--;
        printf(mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }
    return ret;
}

static int esNumeroDecimal(char *cadena)
{
    int ret=-1;
    int i=0;
    int cantidadPuntos=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if (cadena[i] == '.' && cantidadPuntos == 0)
            {
                cantidadPuntos++;
                i++;
                continue;

            }
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}

static int getFloat(float *pResultado)
{
    int ret=-1;
    char buffer[8];

    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esNumeroDecimal(buffer))
    {
        *pResultado = atof(buffer);
        ret=1;
    }
    return ret;
}

int utn_getNumeroConDecimal(float* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int ret;
    float num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(getFloat(&num)==1)
        {
                break;
        }
        reintentos--;
        printf(mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }
    return ret;

}

static int esLetras(char *cadena)
{
    int ret=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
                return 0;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}

static int getString(char* pResultado)
{
    int ret=-1;
    char buffer[51];

    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esLetras(buffer))
    {
        strcpy(pResultado, buffer);
        ret=1;
    }
    return ret;
}

int utn_getTexto(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int ret;
    char aux[256];
    while(reintentos>0)
    {
        printf(mensaje);
        if(getString(aux)==1)
        {
                break;
        }
        reintentos--;
        printf(mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        strcpy(pResultado, aux);
    }
    return ret;

}

