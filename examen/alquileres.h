typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int CodigoAlquiler;
    int CodigoJuego;
    int CodigoCliente;
    eFecha date;
    int estado;
}eAlquileres;

void inicializarAlquiler(eAlquileres rent[], int cantidad);
int buscarEspacioLibreAlquiler(eAlquileres rent[], int cantidad);
int buscarAlquilerPorCodigo(eAlquileres rent[], int cantidad, int auxCodAlquiler);

void mostrarUnAlquiler(eAlquileres rent, eJuegos games, eClientes client);
