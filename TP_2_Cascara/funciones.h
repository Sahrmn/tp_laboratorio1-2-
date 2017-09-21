#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);


/** \brief Carga datos de una persona
 * \param Lista el array se pasa como parametro
 * \param Numero de indice del elemento a cargar
 */
void agregarPersona(EPersona lista[],int);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);


/**
 *  Borra una persona del array
 * \param Lista el array se pasa como parametro
 */
void borrarPersona(EPersona lista[]);


/** \brief Imprime en pantalla el contenido de un elemento persona
 * \param Lista el array se pasa como parametro
 */
void imprimirUnaPersona(EPersona);


/** \brief Imprime en pantalla el contenido de los elementos del vector estructura ordenados alfabeticamente
 * \param Lista el array se pasa como parametro
 */
void imprimirPersonas(EPersona[]);


/** \brief Ordena alfabeticamente por el nombre los elementos del vector estructura
 * \param Lista el array se pasa como parametro
 */
void ordenarPersonas(EPersona[]);


/** \brief Imprime en pantalla un grafico de edades
 * \param Lista el array se pasa como parametro
 */
void imprimirGrafico(EPersona[]);

#endif // FUNCIONES_H_INCLUDED
