typedef struct
{
    int codigo;
    char descripcion[51];
    int cantidad;
    float importe;
    int estado;

}eProducto;


void inicializar(eProducto product[], int cantidad);
int buscarEspacioLibre(eProducto product[], int cantidad);
int buscarProductoPorCodigo(eProducto product[], int cantidad, int code);
void mostrarUnProducto(eProducto product);
void ingresoDatos(eProducto product[],int espacioLibre, int auxCod,char auxDescrip[], float auxImporte,int auxCantidadProd);
void mostrarProductos(eProducto product[], int cantidad);

void ordenarPorDescripcion(eProducto product[], int cantidad);

void ingresoProducto(eProducto product[], int cantidad, int code, char description[], float impor, int cantidadProd);
void modificarProducto(eProducto product[], int cantidad, int code, char description[], float impor, int cantidadProd);
void bajaProducto(eProducto product[], int cantidad, int code);

