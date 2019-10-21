#include "alquileres.h"
#include "juegoYCategoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Muestra un juego
 *
  * \param Vector de juegos
  * \param Tamaño del vector de juegos
  * \return void
 */
void mostrarJuegos(eJuego juegos[],int tamJ)
{
    printf(" Codigo     Descripcion    Importe  idCategoria\n\n");

    for(int i=0; i < tamJ; i++)
    {
        mostrarJuego(juegos[i]);
    }
    printf("\n");
}
/** \brief Muestra todos los juegos
  *
  * \param Vector de juegos
  * \param Tamaño del vector de juegos
  * \return void
 */
void mostrarJuego(eJuego juego)
{

    printf("  %d     %10s      %.2f    %d\n",juego.codigo,juego.descripcion,juego.importe,juego.idCategoria);

}

/** \brief Muestra una categoria de juegos
 *
  * \param Vector de categorias
  * \param Tamaño del vector de categorias
  * \return void
 */
void mostrarCategorias(eCategoria categoria[], int tamCat)
{
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tamCat; i++)
    {
        mostrarCategoria(categoria[i]);
    }
    printf("\n");
}
/** \brief Muestra todas las categorias
 *
  * \param Vector de categorias
  * \return void
 */
void mostrarCategoria(eCategoria categoria)
{

    printf("  %d      %10s\n", categoria.id, categoria.descripcion);

}

/** \brief Hardcodea un numero de juegos
 *
 * \param Vector de juegos
 * \param Tamaño del vector de juegos
 * \param Un entero para definir cuantos juegos quiere que le pase cuando sea llamado
 * \return Un contador entero auto incremental para poder asignarle un numero de codigo unico
 *
*/
int hardcodearJuegos(eJuego juegos[],int tamJ,int cantidad)
{
    int contador = 0;

    eJuego listadoJuegos[]=
    {
        { 700,"Monopoly",300,200},
        { 701,"generala",280,201},
        { 702,"TEG",155,202},
        { 703,"Baile",802,203},
        { 704,"Magia",803,204}

    };

    if( cantidad <= 5 && tamJ >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            juegos[i] = listadoJuegos[i];
            contador++;
        }
    }

    return contador;
}
/** \brief Muestra los juegos que no fueron alquilados
 *
 * \param Vector de juegos
 * \param Tamaño del vector de juegos
  * \return void
 *
*/
void mostarJuegosNoAlquilados(eJuego juegos[], int tamj, eAlquiler alquileres[], int tamAlq)
{
    int fueAlquilado;
    for( int i=0; i< tamj; i++)
    {
        fueAlquilado = 0;

        for(int j=0; j< tamAlq; j++)
        {
            if(juegos[i].codigo == alquileres[j].codigoDeJuego)
            {
                fueAlquilado = 1;

            }
        }

        if(!fueAlquilado)
        {
            mostrarJuego(juegos[i]);

        }
    }
}

/** \brief Muestra los juegos de categoria de mesa
 *
 * \param Vector de categoria
 * \param Tamaño del vector de categoria
 * \param Vector de juegos
 * \param Tamaño del vector de juegos
  * \return void
 *
*/
void juegosCategoriaMesa(eCategoria cat[],int tamCa,eJuego juegos[],int tamJ)
{
    for(int i=0; i<tamCa; i++)
    {
        if(juegos[i].idCategoria==200)
        {
            mostrarJuego(juegos[i]);
        }
    }

}





