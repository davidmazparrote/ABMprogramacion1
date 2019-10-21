#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int codigo;
    char nombre[200];
    char apellido[200];
    char sexo;
    char telefono[200];
    char domicilio[200];
    int isEmpty;
} eCliente;




#endif // CLIENTES_H_INCLUDED
void mostrarClientes(eCliente cl[], int tamC);
eCliente nuevoCliente( int codigo,char nombre[51],char apellido[51],char sexo,char telefono[],char domicilio[]);
void mostraCliente(eCliente cl,int tamCli);
int altaCliente(eCliente cliente[], int tamC, int codigo);
void inicializarClientes(eCliente vecC[], int tamC);
int hardcodearClientes( eCliente vecC[], int tamC, int cantidad);
int buscarCliente(eCliente clientes[],int tamC, int codigoCliente);
int bajaCliente(eCliente clienteVec[],int tamC);
int modificarCliente(eCliente clientes[],int tamC);
void ordenarClientes(eCliente cl[],int tamC);
int buscarLugarLibre(eCliente vec[], int tamCliente);
