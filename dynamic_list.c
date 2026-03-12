/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera
 * AUTHOR 2: Miguel Magdalena Sánchez LOGIN 2: m.magdalenas
 * GROUP: 4.4
 * DATE: 25 / 02 / 26
 */

#include "dynamic_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyList(tList* L){
  /*
  Objetivo: Inicializar la lista vacía.
  Entradas: L -> puntero a la lista.
  Salidas: La lista inicializada.
  Precondiciones: L debe ser válido.
  Postcondiciones: La lista queda vacía (LNULL).
  */

  *L = LNULL;
}

bool isEmptyList(tList L){
  /*
  Objetivo: Comprobar si la lista está vacía.
  Entradas: L -> lista.
  Salidas: true si está vacía, false si no.
  Precondiciones: La lista debe estar inicializada.
  Postcondiciones: No modifica la lista.
  */

  return L == LNULL;
}

tPosL first(tList L){
  /*
  Objetivo: Obtener la posición del primer elemento.
  Entradas: L -> lista.
  Salidas: Posición del primer nodo.
  Precondiciones: La lista debe estar inicializada.
  Postcondiciones: No modifica la lista.
  */

  return L;
}

tPosL last(tList L){
  /*
  Objetivo: Obtener la posición del último elemento.
  Entradas: L -> lista.
  Salidas: Posición del último nodo.
  Precondiciones: La lista no debe estar vacía.
  Postcondiciones: No modifica la lista.
  */

  tPosL p = L; // puntero usado para recorrer la lista

  while(p->next != LNULL)
    p = p->next;
  return p;
}

tPosL next(tPosL p, tList L){
  /*
  Objetivo: Obtener la posición del siguiente elemento.
  Entradas: p -> posición actual, L -> lista.
  Salidas: Posición del siguiente nodo o LNULL.
  Precondiciones: p debe ser una posición válida.
  Postcondiciones: No modifica la lista.
  */

  return p->next;
}

tPosL previous(tPosL p, tList L){
  /*
  Objetivo: Obtener la posición del nodo anterior.
  Entradas: p -> posición actual, L -> lista.
  Salidas: Posición del nodo anterior o LNULL.
  Precondiciones: p debe ser una posición válida.
  Postcondiciones: No modifica la lista.
  */

  if(p == L)
    return LNULL;

  tPosL prev = L;

  while(prev->next != p)
    prev = prev->next;
  return prev;
}

bool insertItem(tItemL d, tPosL p, tList* L){
  /*
  Objetivo: Insertar un elemento en la lista.
  Entradas: d -> elemento a insertar, p -> posición donde insertar, L -> lista.
  Salidas: true si la inserción se realiza correctamente.
  Precondiciones: p debe ser posición válida o LNULL.
  Postcondiciones: El elemento queda añadido en la lista.
  */

  tPosL newNode, auxNode;

  newNode = malloc(sizeof(*newNode));
  if(newNode == LNULL)
    return false;

  newNode->data = d;
  newNode->next = LNULL;

  if(*L == LNULL)
    *L = newNode;
  else if(p == LNULL){
    // inserción al final
    auxNode = last(*L);
    auxNode->next = newNode;
  }
  else if(p == *L){
    // inserción al principio
    newNode->next = *L;
    *L = newNode;
  }
  else{
    // inserción en posición intermedia
    auxNode = previous(p, *L);
    newNode->next = p;
    auxNode->next = newNode;
  }

  return true;
}

void deleteAtPosition(tPosL p, tList* L){
  /*
  Objetivo: Eliminar el elemento de la posición indicada.
  Entradas: p -> posición a eliminar, L -> lista.
  Salidas: La lista modificada.
  Precondiciones: p debe ser una posición válida.
  Postcondiciones: El nodo se elimina de la lista.
  */

  tPosL node;

  if(p == *L)
    *L = p->next;
  else{
    node = previous(p, *L);
    node->next = p->next;
  }
  free(p);
}

tItemL getItem(tPosL p, tList L){
  /*
  Objetivo: Obtener el elemento almacenado en una posición.
  Entradas: p -> posición del nodo, L -> lista.
  Salidas: Elemento almacenado en esa posición.
  Precondiciones: p debe ser una posición válida.
  Postcondiciones: No modifica la lista.
  */

  return p->data;
}

void updateItem(tItemL d , tPosL p, tList* L){
  /*
  Objetivo: Modificar el elemento de una posición.
  Entradas: d -> nuevo elemento, p -> posición a modificar, L -> lista.
  Salidas: La lista actualizada.
  Precondiciones: p debe ser una posición válida.
  Postcondiciones: El contenido del nodo cambia.
  */

  p->data = d;
}

tPosL findItem(tProjectName n, tList L){
  /*
  Objetivo: Buscar un proyecto por su nombre.
  Entradas: n -> nombre del proyecto, L -> lista.
  Salidas: Posición del proyecto o LNULL si no existe.
  Precondiciones: La lista debe estar inicializada.
  Postcondiciones: No modifica la lista.
  */

  tPosL p = L; // puntero para recorrer la lista

  while(p != LNULL){
    if(strcmp(p->data.projectName, n) == 0)
      return p;
    p = p->next;
  }

  return NULL;
}