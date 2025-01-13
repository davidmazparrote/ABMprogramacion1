
#include "alquileres.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Ingresa una nueva solicitud de alquiler
 *
 * \param Iector de clientes
 * \param Tamaño del vector de clientes
 * \param Vector de alquiler
 * \param Tamaño del vector de alquiler
 * \param Vector de juegos
 * \param Tamaño del vector de juegos

 * \return Retorna un 1 si dio de alta o 0 si no pudo
 *
 */

int altaAlquileres(eCliente clientes[],int tamC,int codigoDeAlquiler,eAlquiler alquilerVec[],int tamA,eJuego juegos[],int tamJ)
{
    int altaOk=0;
    int indice=-1;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha; //modifico una clase

    system("cls");

    printf("*****Alta de alquileres*****\n\n");

    indice = buscarLugarLibreAlquiler(alquilerVec,tamA);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarJuegos(juegos,tamJ);

        printf("Ingrese el codigo del juego que desea alquilar: ");
        scanf("%d", &codigoJuego);

        mostrarClientes(clientes,tamC);
        printf("Ingrese el codigo de cliente: ");
        scanf("%d", &codigoCliente);

        printf("Ingrese fecha de alquiler: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        alquilerVec[indice]= nuevoAlquiler(codigoDeAlquiler,codigoJuego,codigoCliente,fecha);
        altaOk = 1;
        printf("Alta alquiler exitosa!!\n\n");
    }


    return altaOk;
}

/** \brief Constructor de Alquileres
 *
 * \param Entero para el codigo de alquiler
 * \param Entero para el codigo de juego
 * \param Entero para el codigo de cliente
 * \param Estructura de fecha

 * \return Retorna un nuevo alquiler
 *
 */
eAlquiler nuevoAlquiler(int codigoAlquiler,int codigoJuego,int codigoCliente, eFecha fecha)
{
    eAlquiler nuevoA;
    nuevoA.codigoAlquiler=codigoAlquiler;
    nuevoA.codigoDeJuego=codigoJuego;
    nuevoA.codigoDecliente=codigoCliente;
    nuevoA.fecha=fecha;
    nuevoA.isEmpty = 0;

    return nuevoA;
}
/** \brief Da de alta logica a un alquiler
 *
 * \param Vector de alquiler
 * \param Tamaño del vector de alquiler
 * \return void
 *
 */
void inicializarAlquiler(eAlquiler vecAl[], int tamAl)
{
    for(int i = 0; i < tamAl; i++)
    {
        vecAl[i].isEmpty = 1;
    }
}
/** \brief Busca poscicion para un nuevo alquiler
 *
 * \param Vector de alquilers
 * \param Tamaño del vector de alquileres
 * \return retorna el indice del lugar,puede se 1,0 o -1.
 *
 */
int buscarLugarLibreAlquiler(eAlquiler vec[],int tamAlq)
{
    int indice=-1;
    for(int i=0; i<tamAlq; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }

    }
    return indice;

}
/** \brief Muestra a un alquiler
 *
 * \param Vector de alquiler
 * \param Tamaño del vector de alquileres
 * \return void
 *
 */
void mostrarAlquiler(eAlquiler vecA,int tamAl)
{

    printf("  %d               %d               %d                %d/%d/%d\n", vecA.codigoAlquiler,vecA.codigoDeJuego,vecA.codigoDecliente,vecA.fecha.dia,vecA.fecha.mes,vecA.fecha.anio);
}

/** \brief Muestra todos los alquileres
 *
 * \param Vector de alquiler
 * \param Tamaño del vector de alquileres
 * \return void
 *
 */
void mostrarAlquileres(eAlquiler vecA[], int tamA)
{

    int flag = 0;
    system("cls");

    printf(" Codigo alquiler     codigo del juego    Codigo cliente     Fecha \n\n");

    for(int i=0; i < tamA; i++)
    {
        if( vecA[i].isEmpty == 0)
        {
            mostrarAlquiler(vecA[i],tamA);

            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alquiler que mostrar\n");
    }

    printf("\n\n");

}
/** \brief Hardcodea un numero de alquileres
 *
 * \param Vector de alquiler
 * \param Tamaño del vector de alquiler
 * \param Un entero para definir cuantos clientes quiere que le pase cuando sea llamado
 * \return Un contador entero auto incremental para poder asignarle un numero de codigo unico
 *
*/
int hardcodearAlquileres( eAlquiler alquileres[], int tamAl, int cantidad)
{
    int contador = 0;
    eAlquiler listado[]=
    {
        {300, 701, 102, {10, 1, 2019}, 0},
        {301, 702, 102, {4, 12, 2018}, 0},
        {301, 701, 102, {4, 12, 2099}, 0},
        {302, 701, 103, {14, 5, 2019}, 0}

   };

    if( cantidad <= 5 && tamAl >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            alquileres[i] = listado[i];
            contador++;
        }
    }

    return contador;
}
