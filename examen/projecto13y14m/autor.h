typedef struct
{
    char nombre[51];
    char apellido[51];
    int codAutor;
    int estado;

}eAutor;

void inicializarAutor(eAutor author[], int cantidad);
int buscarEspacioLibreAutor(eAutor author[], int cantidad);
int buscarAutorPorCodigo(eAutor author[], int cantidad, int codAutor);
void mostrarUnAutor(eAutor author);
void mostrarAutores(eAutor author[], int cantidad);

void ingresoDatosAutor(eAutor author[],int espacioLibre, int auxCodAuthor,char auxNombre[], char auxApellido[]);

void ingresoAutor(eAutor author[], int cantidad, int auxCodAutor, char auxNombre[], char auxApellido[]);
void bajaAutor(eAutor author[], int cantidad, int auxCodAutor);
