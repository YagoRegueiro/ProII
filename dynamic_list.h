/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera
 * AUTHOR 2: Miguel Magdalena Sánchez LOGIN 2: m.magdalenas
 * GROUP: 4.4
 * DATE: 25 / 02 / 26
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdbool.h>

// Valor que representa una posición nula
#define LNULL NULL

// Posición de un elemento de la lista (puntero a nodo)
typedef struct tNode *tPosL;
// La lista se representa como un puntero al primer nodo
typedef tPosL tList;

// Nodo de la lista dinámica
struct tNode{
  tItemL data;    // información del proyecto
  tPosL next;     // puntero al siguiente nodo
};

// Inicializa la lista vacía
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
// Devuelve el elemento de una posición
tItemL getItem(tPosL p, tList L);
// Modifica el elemento en una posición
void updateItem(tItemL d , tPosL p, tList* L);
// Busca un proyecto por nombre
tPosL findItem(tProjectName n, tList L);

#endif

