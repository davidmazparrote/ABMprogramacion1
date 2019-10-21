#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "clientes.h"
#include "juegoYCategoria.h"
typedef struct
{
    int dia;
    int mes;
    int anio;


} eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoDeJuego;
    int codigoDecliente;
    eFecha fecha;
    int isEmpty;

} eAlquiler;


#endif // ALQUILERES_H_INCLUDED
void mostrarAlquiler(eAlquiler vecA,int tamAl);
void mostrarAlquileres(eAlquiler vecA[], int tamA);
int altaAlquileres(eCliente clientes[],int tamC,int codigoDeAlquiler, eAlquiler alquilerVec[],int tamA,eJuego juegos[],int tamJ);
eAlquiler nuevoAlquiler(int codigoAlquiler,int codigoJuego,int codigoCliente, eFecha fecha);
int buscarLugarLibreAlquiler(eAlquiler vec[],int tamAlq);
void inicializarAlquiler(eAlquiler vecAl[], int tamAl);
int hardcodearAlquileres( eAlquiler alquileres[], int tamAl, int cantidad);
void mostarClientesSinAlquiler(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq);
void mostarJuegosNoAlquilados(eJuego juegos[], int tamj, eAlquiler alquileres[], int tamAlq);
void mostrarAlquilerDeUnClienteSeleccionado(eCliente cliente[],int tamCl,eAlquiler alq[],int tamAl);
void mostrarImporteTotalPagadoPorUnCliente(eCliente clientes[],int tamCl,eAlquiler alq[],int tamAl,eJuego juegos[],int tamJ);
