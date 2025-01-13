#ifndef JUEGOYCATEGORIA_H_INCLUDED
#define JUEGOYCATEGORIA_H_INCLUDED

#include "clientes.h"

typedef struct
{

    int codigo;
    char descripcion[20];
    float importe;
    int idCategoria; // cambio en branch1

} eJuego;

typedef struct
{
    int id;
    char descripcion[51];

} eCategoria;


#endif // JUEGOYCATEGORIA_H_INCLUDED
void mostrarCategorias(eCategoria categoria[], int tamCat);
void mostrarCategoria(eCategoria categoria);
void mostrarJuegos(eJuego juegos[],int tamJ);
void mostrarJuego(eJuego juego);
int hardcodearJuegos(eJuego juegos[],int tamJ,int cantidad);
void juegosCategoriaMesa(eCategoria cat[],int tamCa,eJuego juegos[],int tamJ);
