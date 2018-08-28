
typedef struct
{
    char descripcion[51];
    int codigo;
    int cantidad;
    float importe;
    int estado;
}eProducto;

void inicializar(eProducto prod[], int cantidad, int valor);
int buscarPorCodigo(eProducto prod[], int cantidad, int cod);
int buscarLibre(eProducto prod[], int cantidad);
