
typedef struct
{
    char descripcion[51];
    int codigo;
    float importe;
    int cantidad;
    int estado;

}eProductos;

void menu();

void inicializar(eProductos prod[], int cantidad);
int buscarLibre(eProductos prod[], int cantidad);
int buscarPorCodigo(eProductos prod[], int cantidad, int cod);
