/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera
 * AUTHOR 2: Miguel Magdalena Sánchez LOGIN 2: m.magdalenas
 * GROUP: 4.4
 * DATE: 25 / 02 / 26
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

// Posición nula en la lista
#define LNULL -1
// Tamaño máximo de la lista estática
#define MAX 25

// Representa una posición dentro de la lista
typedef int tPosL;
// Estructura de la lista estática
typedef struct List{
 tItemL data[MAX];    // array que almacena los elementos
 tPosL lastPos;       // posición del último elemento de la lista

}tList;

// Inicializa la lista dejándola vacía
void createEmptyList(tList* L);
// Devuelve true si la lista está vacía
bool isEmptyList(tList L);
// Devuelve la posición del primer elemento
tPosL first(tList L);
// Devuelve la posición del último elemento
tPosL last(tList L);
// Devuelve la posición del siguiente elemento
tPosL next(tPosL p, tList L);
// Devuelve la posición del elemento anterior
tPosL previous(tPosL p, tList L);
// Inserta un elemento en la lista
bool insertItem(tItemL d, tPosL p, tList* L);
// Elimina el elemento en la posición indicada
void deleteAtPosition(tPosL p, tList* L);
// Devuelve el elemento de la posición indicada
tItemL getItem(tPosL p, tList L);
// Modifica el elemento en la posición indicada
void updateItem(tItemL d , tPosL p, tList* L);
// Busca un proyecto por nombre y devuelve su posición
tPosL findItem(tProjectName n, tList L);


#endif
