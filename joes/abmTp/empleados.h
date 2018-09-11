typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int estado;

}eEmpleado;

void inicializar(eEmpleado *emple, int cantidad);
int buscarLibre(eEmpleado *emple, int cantidad);
int buscarPorId(eEmpleado *emple, int cantidad, int identi);

