#include "clientes.h"
#include "alquileres.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include <ctype.h>

/** \brief Ingresa una nueva solicitud de cliente
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \param Un entero para el codigo
 * \return Retorna un 1 si dio de alta o 0 si no pudo
 *
 */
int altaCliente(eCliente cliente[], int tamC, int codigo)
{
    int altaCorrecta = 0;
    int indice;
    char nombre[200];
    char apellido[200];
    char sexo;
    char telefono[200];
    char domicilio[200];

    system("cls");

    printf("*****Alta clientes*****\n\n");

    indice = buscarLugarLibre(cliente,tamC);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        validaNombreApellido(nombre);
        nombre[0]=toupper(nombre[0]);

        printf("Ingrese apellido: ");
        gets(apellido);
        validaNombreApellido(apellido);
        apellido[0]=toupper(apellido[0]);

        printf("Ingrese sexo f o m: ");
        fflush(stdin);
        scanf("%c",&sexo);
        validaSexo(sexo);

        printf("Ingrese Telefono: ");
        fflush(stdin);
        gets(telefono);
        validaTelefono(telefono);

        printf("Ingrese domicilio: ");
        fflush(stdin);
        gets(domicilio);

        cliente[indice] = nuevoCliente(codigo,nombre,apellido,sexo,telefono,domicilio);
        altaCorrecta = 1;
        printf("Alta correcta!!\n\n");
    }

    return altaCorrecta;
}

/** \brief Constructor de clientes
 *
 * \param Entero para el codigo
 * \param Arreglo de char para el nombre
 * \param Arreglo de char para el apellido
 * \param Un char para el sexo
 * \param Arreglo de char para el telefono
 * \param Arreglo de char para el domicilio


 * \return Retorna un nuevo cliente
 *
 */
eCliente nuevoCliente( int codigo,char nombre[51],char apellido[51],char sexo,char telefono[],char domiclio[])
{

    eCliente cl;
    cl.codigo= codigo;
    strcpy( cl.nombre, nombre);
    strcpy( cl.apellido,apellido);
    cl.sexo= sexo;
    strcpy(cl.telefono,telefono);
    strcpy( cl.domicilio, domiclio);
    cl.isEmpty=0;
    return cl;
}
/** \brief Da de alta logica a un cliente
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \return void
 *
 */
void inicializarClientes(eCliente vecC[], int tamC)
{
    for(int i = 0; i < tamC; i++)
    {
        vecC[i].isEmpty = 1;
    }
}

/** \brief Busca poscicion para un nuevo cliente
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \return retorna el indice del lugar,puede se 1,0 o -1.
 *
 */
int buscarLugarLibre(eCliente vec[], int tamCliente)
{

    int indice = -1;

    for(int i=0; i < tamCliente; i++)
    {
        if(vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief Muestra a un cliente
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \return void
 *
 */
void mostraCliente(eCliente cli,int tamCli)
{

    printf("%d   %10s      %10s       %c       %10s       %10s        \n",
           cli.codigo,cli.nombre,cli.apellido,cli.sexo,cli.telefono,cli.domicilio);

}

/** \brief Muestra a todos los clientes
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \return void
 *
 */
void mostrarClientes(eCliente cl[], int tamC)
{

    int flag = 0;

    system("cls");

    printf(" Codigo    Nombre     Apellido      sexo      telefono          domicilio   \n\n");

    for(int i=0; i < tamC; i++)
    {
        if(cl[i].isEmpty == 0)
        {

            mostraCliente(cl[i],tamC);

            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay clientes para mostrar\n");
    }

    printf("\n\n");
}
/** \brief Hardcodea un numero de clientes
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \param Un entero para definir cuantos clientes quiere que le pase cuando sea llamado
 * \return Un contador entero auto incremental para poder asignarle un numero de codigo unico
 *
 */
int hardcodearClientes(eCliente vecC[], int tamC, int cantidad)
{
    int contador = 0;

    eCliente clientesAux[]=
    {
        {101, "David","Gutierrez",'m',"1157569945","alberti 4555"},
        {104, "Eugenio","Cruzziti",'m',"1197544445","gonzalez 4555"},
        {103, "Rebeca","Lopez",'f',"1151235945","manberti 445"},
        {102, "Daniel","Delviso",'m',"54969945","republica 102"}
    };

    if( cantidad <= 10 && tamC >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vecC[i] = clientesAux[i];
            contador++;
        }
    }

    return contador;
}

/** \brief Da de baja logica a un cliente
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
  * \return Retorna un 1 si dio de baja o 0 si no pudo
 */

int bajaCliente(eCliente clienteVec[],int tamC)
{
    int bajaOk = 0;
    int codigo;
    int indice;
    char confirmaBaja;
    system("cls");

    printf("***** Baja Cliente*****\n\n");
    mostrarClientes(clienteVec,tamC);
    printf("Ingrese el codigo del cliente: ");
    scanf("%d", &codigo);

    indice = buscarCliente(clienteVec,tamC,codigo);

    if( indice == -1)
    {
        printf("No existe un cliente con ese codigo\n\n");

    }
    else
    {
        mostraCliente(clienteVec[indice],tamC);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirmaBaja);

        if( confirmaBaja == 's')
        {
            clienteVec[indice].isEmpty = 1;
            bajaOk = 1;
            printf("Baja exitosa!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return bajaOk;
}

/** \brief Busca un cliente a traves de su codigo
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \param Un entero para el codigo
  * \return retorna la posicion del cliente
 */

int buscarCliente(eCliente clientes[],int tamC, int codigoCliente)
{

    int indice=-1;

    for(int i=0; i<tamC; i++)
    {
        if(clientes[i].codigo==codigoCliente && clientes[i].isEmpty==0)
        {
            indice=i;
            break;
        }

    }

    return indice;
}

/** \brief Modifica al cliente seleccionado a traves de su codigo
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
 * \return Retorna 1 o 0 dependiendo si pudo modificarlo o no
 */
int modificarCliente(eCliente clientes[],int tamC)
{


    int modificacionOk = 0;
    int codigo;
    int indice;
    system("cls");

    printf("***** Modificar cliente *****\n\n");
    mostrarClientes(clientes,tamC);

    printf("Ingrese codigo del cliente: ");

    scanf("%d", &codigo);
    int opcion;

    indice = buscarCliente(clientes,tamC,codigo);

    if(indice == -1)
    {
        printf("No existe un cliente con ese codigo\n\n");

    }
    else
    {
        system("cls");
        printf("\n");
        mostraCliente(clientes[indice],tamC);

        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar direccion\n");
        printf("4- Modificar telefono\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(clientes[indice].nombre);
            validaNombreApellido(clientes[indice].nombre);
            clientes[indice].nombre[0]=toupper(clientes[indice].nombre[0]);
            printf("\n\nSe modifico el nombre ahora es: %s",clientes[indice].nombre);
            printf("\n\n");
            break;
        case 2:
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            gets(clientes[indice].apellido);
            validaNombreApellido(clientes[indice].apellido);
            clientes[indice].apellido[0]=toupper(clientes[indice].apellido[0]);
            printf("\n\nSe modifico el apellido ahora es: %s",clientes[indice].apellido);
            printf("\n\n");
            break;
        case 3:
            printf("Ingrese nueva direccion: ");
            fflush(stdin);
            gets(clientes[indice].domicilio);
            printf("\n\nSe modifico el domicilio ahora es: %s",clientes[indice].domicilio);
            printf("\n\n");
            break;
        case 4:
            printf("Ingrese nuevo telefono: ");
            fflush(stdin);
            gets(clientes[indice].telefono);
            validaTelefono(clientes[indice].telefono);
            printf("\n\nSe modifico telefono ahora es: %s",clientes[indice].telefono);
            printf("\n\n");
            break;
        case 5:
            printf("Se ha cancelado la modificacion ");
            printf("\n\n");
            break;
        default:
            printf("Opcion invalida");
            break;

        }

    }
    return modificacionOk;
}
/** \brief Ordena a los clientes por su apellido
 *
 * \param Vector de clientes
 * \param Tamaño del vector de clientes
  * \return void
 */
void ordenarClientes(eCliente cl[],int tamC)
{

    eCliente aux;
    for(int i= 0; i < tamC-1 ; i++)
    {
        for(int j= i+1; j <tamC; j++)
        {

            if(cl[i].apellido[0]>cl[j].apellido[0])
            {
                aux= cl[i];
                cl[i]= cl[j];
                cl[j] = aux;
            }
        }
    }
}
/** \brief Muestra el alquiler realizado por un cliente seleccionado
 *
  * \param Vector de clientes
  * \param Tamaño del vector de clientes
  * \param Vector de alquiler
  * \param Tamaño del vector de alquiler
  * \return void
 */
void mostrarAlquilerDeUnClienteSeleccionado(eCliente cliente[],int tamCl,eAlquiler alq[],int tamAl)
{

    int codigoCliente;
    mostrarClientes(cliente,tamCl);
    printf("Ingrese el codigo del cliente:");
    scanf("%d",&codigoCliente);

    for(int i=0; i<tamAl; i++)
    {
        if(alq[i].codigoDecliente==codigoCliente)
        {

            mostrarAlquiler(alq[i],tamAl);
        }

    }
}

/** \brief Muestra el importe total de los alquileres realizados por un cliente seleccionado
 *
  * \param Vector de clientes
  * \param Tamaño del vector de clientes
  * \param Vector de alquiler
  * \param Tamaño del vector de alquiler
  * \param Vector de juegos
  * \param Tamaño del vector de juegos
  * \return void
 */
void mostrarImporteTotalPagadoPorUnCliente(eCliente clientes[],int tamCl,eAlquiler alq[],int tamAl,eJuego juegos[],int tamJ)
{
    int codigoCliente;
    float acumuladorImporte=0;
    mostrarClientes(clientes,tamCl);
    printf("Ingrese codigo de cliente: ");
    scanf("%d",&codigoCliente);

    for(int i=0; i<tamCl; i++)
    {
        for(int j=0; j<tamAl; j++)
        {
            for(int k=0; k<tamJ; k++)
            {

                if(clientes[i].codigo== codigoCliente && codigoCliente== alq[j].codigoDecliente && alq[j].codigoDeJuego==juegos[k].codigo)
                {
                    acumuladorImporte+=juegos[k].importe;
                }

            }

        }
    }
    printf("Deuda todal del cliente: $%.2f",acumuladorImporte);
    printf("\n\n");

}


/** \brief Muestra los clientes que no alquilaron juegos
 *
  * \param Vector de clientes
  * \param Tamaño del vector de clientes
  * \param Vector de alquiler
  * \param Tamaño del vector de alquiler
  * \return void
 */
void mostarClientesSinAlquiler(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq)
{
        int tieneAlquiler;
        for(int i=0; i< tamCli; i++)
        {
            tieneAlquiler = 0;

            for(int j=0; j< tamAlq; j++)
            {
                if(clientes[i].codigo==alquileres[j].codigoDecliente)
                {
                    tieneAlquiler = 1;

                }
            }
            if(tieneAlquiler!=1)
            {
               mostraCliente(clientes[i],tamCli);
            }
        }
}
