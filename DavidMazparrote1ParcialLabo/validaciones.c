#include "clientes.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Valida un nombre o apellido
 *
 * \param Un arreglo de char
 * \return void
 *
*/
void validaNombreApellido(char nombreOApellido[])
{

    while(strlen(nombreOApellido)>51)
    {
        printf("Nombre muy largo ingrese otro por favor: ");
        fflush(stdin);
        gets(nombreOApellido);
    }
}

/** \brief Valida un sexo
 *
 * \param Un char
 * \return void
 *
*/
void validaSexo(char sexo)
{
    while(sexo != 'm' && sexo != 'f')
    {
        printf("Ingrese solo f o m : ");
        fflush(stdin);
        scanf("%c",&sexo);
    }
}

/** \brief Valida un telefono
 *
 * \param Un arreglo de char
 * \return void
 *
*/
void validaTelefono(char telefono[])
{
    while(strlen(telefono)>21)
    {
        printf("Telefono muy largo ingrese otro : ");
        fflush(stdin);
        gets(telefono);

    }
}
