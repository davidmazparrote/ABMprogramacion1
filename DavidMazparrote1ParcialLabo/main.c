#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "clientes.h"
#include "alquileres.h"
#define TAMCLIENTE 6
#define TAMF 20
#define TAMALQ 5
#define TAMJ 5
#define TAMCAT 5

int menuPrincipal();
void mostrarInformes(eCategoria cate[],int tamC,eAlquiler alq[],int tamAl,eJuego jue[],int tamJ,eCliente clientes[],int tamCli);
int main()
{
    int codigoCliente = 101;
    eCliente listaDeClientes[TAMCLIENTE];
    char salir = 'n';
    int codigoAlquiler=300;

    eCategoria listaCatecoria[]= {{200,"mesa"},
        {201,"azar"},
        {202,"estrategia"},
        {203,"salon"},
        {204,"magia"}
    };
    eAlquiler listaAlquileres[TAMALQ];
    inicializarClientes(listaDeClientes,TAMCLIENTE);
    inicializarAlquiler(listaAlquileres,TAMALQ);
    eJuego juegos[TAMJ];
    hardcodearJuegos(juegos,TAMJ,5);
    codigoCliente = codigoCliente + hardcodearClientes(listaDeClientes,TAMCLIENTE,4);
    codigoAlquiler= codigoAlquiler+ hardcodearAlquileres(listaAlquileres,TAMALQ,4);


    do
    {
        switch(menuPrincipal())
        {
        case 1:

            if(altaCliente(listaDeClientes,TAMCLIENTE,codigoCliente))
            {
                codigoCliente++;
            }
            break;
        case 2:
            bajaCliente(listaDeClientes,TAMCLIENTE);
            break;
        case 3:
            modificarCliente(listaDeClientes,TAMCLIENTE);
            break;
        case 4:
            ordenarClientes(listaDeClientes,TAMCLIENTE);
            mostrarClientes(listaDeClientes,TAMCLIENTE);

            break;
        case 5:
            mostrarAlquileres(listaAlquileres,TAMALQ);
            break;
        case 6:

            altaAlquileres(listaDeClientes,TAMCLIENTE,codigoAlquiler,listaAlquileres,TAMALQ,juegos,TAMJ);
            codigoAlquiler++;
            break;
        case 7:
            mostrarInformes(listaCatecoria,TAMCAT,listaAlquileres,TAMALQ,juegos,TAMJ,listaDeClientes,TAMCLIENTE);
            break;
        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            scanf("%c",&salir);
            break;
        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}
/** \brief Imprime el menu pricipal
  * \return Un entero con la opcion seleccionada
  *
  */
int menuPrincipal()
{
    int opcion;

    system("cls");
    printf("****** ABM Alquiler de Juegos *******\n\n");
    printf("1-Alta clientes\n");
    printf("2-Baja clientes\n");
    printf("3-Modificar clientes\n");
    printf("4-Listar clientes\n");
    printf("5-Listar alquileres\n");
    printf("6-Alta de alquileres\n");
    printf("7-Mostrar informes\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief Imprime el menu de informes
  * \return Un entero con la opcion seleccionada
 *
*/
int menuInformes()
{

    int opcion;

    system("cls");
    printf("****** Informes de alquiler de Juegos *******\n\n");
    printf("1-Mostrar juegos de categoria de mesa\n");
    printf("2-Mostrar los alquileres efectuados por algun cliente seleccionado\n");
    printf("3-Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("4-Listar los clientes que no alquilaron juegos\n");
    printf("5-Listar los juegos que no han sido alquilados\n");
    printf("6-salir\n");
    scanf("%d",&opcion);


    return opcion;
}

void mostrarInformes(eCategoria cate[],int tamC,eAlquiler alq[],int tamAl,eJuego jue[],int tamJ,eCliente clientes[],int tamCli)
{
    char salir='n';
    do
    {
        switch(menuInformes())
        {

        case 1:
            juegosCategoriaMesa(cate,tamC,jue,tamJ);
            break;
        case 2:
            mostrarAlquilerDeUnClienteSeleccionado(clientes,tamCli,alq,tamAl);
            break;
        case 3:
            mostrarImporteTotalPagadoPorUnCliente(clientes,tamCli,alq,tamAl,jue,tamJ);
            break;
        case 4:
            mostarClientesSinAlquiler(clientes,tamCli,alq,tamAl);

            break;
        case 5:
            mostarJuegosNoAlquilados(jue,tamJ,alq,tamAl);
            break;

        case 6:
            printf("Confirma salir");
            fflush(stdin);
            scanf("%c",&salir);
            break;

        default:
            printf("Opcion invalida");
        }

        system("pause");

    }
    while(salir=='n');

}

