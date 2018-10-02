typedef struct
{
    int codLibro;
    char titulo[51];
    int codAutor;
    int stock;
    int estado;
}eLibro;



void mostrarUnLibro(eLibro book);
void mostrarLibros(eLibro book[], int cantidad);
void ingresoDatos(eLibro book[],int espacioLibre, int auxCodLib,char auxTitulo[], int auxCodAutor,int auxStock);

void inicializar(eLibro book[], int cantidad);
int buscarEspacioLibre(eLibro book[], int cantidad);
int buscarLibroPorCodigo(eLibro book[], int cantidad, int code);
void ordenarPorTitulo(eLibro book[], int cantidad);

void ingresoLibro(eLibro book[], int cantidad, int auxCodLibro, char auxTitulo[], int auxCodAutor, int auxStock);
void modificarLibro(eLibro book[], int cantidad, int auxCodLibro, char auxTitulo[], int auxCodAutor, int auxStock);
void bajaLibro(eLibro book[], int cantidad, int auxCodLibro);

void adminLibros(eLibro book[], int cantidad);
