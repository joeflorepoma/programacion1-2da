#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //tolower toupper

int main()
{
    char nombre[31];
    char apellido[31];
    char apeNom[62];
    int cantidad;

    printf("Nombre: ");
    fflush(stdin);
    fgets(nombre, sizeof(nombre)-2, stdin);
    //scanf("%[^\n]", nombre);
    cantidad = strlen(nombre);

    nombre[cantidad-1] = '\0';

    printf("Apellido: ");
    //fflush(stdin);
    fgets(apellido, sizeof(apellido)-2, stdin);
    //scanf("%[^\n]", nombre);
    cantidad = strlen(apellido);

    apellido[cantidad-1] = '\0';

    printf("%s\n", nombre);
    printf("%s\n", apellido);

    strcpy(apeNom, apellido);
    strcat(apeNom, " ");
    strcat(apeNom, nombre);

    strlwr(apeNom);

    for(int i = 0; i<strlen(apeNom); i++)
    {
        if(apeNom[i] == ' ' && apeNom[i+1] != 'º0')
        {
            apeNom[i+1] = toupper(apeNom[i+1]);
        }
    }

    printf("%s\n", apeNom);

    //printf("%s\n", strlwr(apeNom));

    /*apeNom[0] = '\0';
    strcat(apeNom, apellido);
    strcat(apeNom, " ");
    strcat(apeNom, nombre);

    printf("%s\n", strupr(apeNom));*/

    return 0;
}
