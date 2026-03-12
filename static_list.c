/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera
 * AUTHOR 2: Miguel Magdalena Sánchez LOGIN 2: m.magdalenas
 * GROUP: 4.4
 * DATE: 25 / 02 / 26
 */

#include "static_list.h"
#include "string.h"

void createEmptyList(tList* L) {
 /*
 Objetivo: Inicializar la lista dejándola vacía.
 Entradas: L -> puntero a la lista.
 Salidas: La lista queda inicializada.
 Precondiciones: L debe apuntar a una lista válida.
 Postcondiciones: lastPos toma el valor LNULL.
 */

 L -> lastPos = LNULL;
}

bool isEmptyList(tList L) {
 /*
 Objetivo: Comprobar si la lista está vacía.
 Entradas: L -> lista a comprobar.
 Salidas: true si está vacía, false en caso contrario.
 Precondiciones: La lista debe estar inicializada.
 Postcondiciones: No modifica la lista.
 */

 return L.lastPos == LNULL;
}

tPosL first(tList L) {
 /*
 Objetivo: Obtener la posición del primer elemento.
 Entradas: L -> lista.
 Salidas: Posición del primer elemento o LNULL si está vacía.
 Precondiciones: La lista debe estar inicializada.
 Postcondiciones: No modifica la lista.
 */

 return isEmptyList(L) ? LNULL : 0;
}

tPosL last(tList L) {
 /*
 Objetivo: Obtener la posición del último elemento.
 Entradas: L -> lista.
 Salidas: Posición del último elemento.
 Precondiciones: La lista no debe estar vacía.
 Postcondiciones: No modifica la lista.
 */

 return L.lastPos;
}

tPosL next(tPosL p, tList L) {
 /*
 Objetivo: Obtener la posición del siguiente elemento.
 Entradas: p -> posición actual, L -> lista.
 Salidas: Posición del siguiente elemento o LNULL.
 Precondiciones: p debe ser una posición válida.
 Postcondiciones: No modifica la lista.
 */

 if(p < 0 || p >= L.lastPos) {
  return LNULL;
 }
 return p + 1;
}

tPosL previous(tPosL p, tList L) {
 /*
 Objetivo: Obtener la posición del elemento anterior.
 Entradas: p -> posición actual, L -> lista.
 Salidas: Posición del elemento anterior o LNULL.
 Precondiciones: p debe ser una posición válida.
 Postcondiciones: No modifica la lista.
 */

 if(p < 1 || p > L.lastPos) {
  return LNULL;
 }
 return p - 1;
}

bool insertItem(tItemL d, tPosL p, tList* L) {
 /*
 Objetivo: Insertar un elemento en la lista.
 Entradas: d -> elemento a insertar, p -> posición donde insertar, L -> lista.
 Salidas: true si se inserta correctamente, false si no.
 Precondiciones: p debe ser posición válida o LNULL.
 Postcondiciones: El elemento queda añadido y pueden variar
 las posiciones de los elementos posteriores.
 */

 int i; // variable para desplazar elementos

 if(L->lastPos >= MAX - 1) {
  return false;
 }
 if(p < LNULL || p > (L->lastPos)) {
  return false;
 }
 L->lastPos++;

 if(p == LNULL){
  // Inserción al final
  L->data[L->lastPos] = d;
 }
 else {
  // Desplazar elementos para hacer hueco
  for(i = L->lastPos; i > p; i--) {
   L->data[i] = L->data[i - 1];
  }
  L->data[p] = d;
 }
 return true;
}

void deleteAtPosition(tPosL p, tList* L) {
 /*
 Objetivo: Eliminar el elemento de una posición.
 Entradas: p -> posición a eliminar, L -> lista.
 Salidas: La lista modificada.
 Precondiciones: p debe ser una posición válida.
 Postcondiciones: Los elementos posteriores cambian de posición.
 */

 int i; // variable para desplazar elementos

 if(p >= 0 && p <= L->lastPos) {
  // Desplazar elementos hacia la izquierda
  for(i = p; i < L->lastPos; i++) {
   L->data[i] = L->data[i + 1];
  }
  L->lastPos--;
 }
}

tItemL getItem(tPosL p, tList L) {
 /*
 Objetivo: Obtener el elemento de una posición.
 Entradas: p -> posición del elemento, L -> lista.
 Salidas: Elemento almacenado en esa posición.
 Precondiciones: p debe ser una posición válida.
 Postcondiciones: No modifica la lista.
 */

 return L.data[p];
}

void updateItem(tItemL d , tPosL p, tList* L) {
 /*
 Objetivo: Modificar el elemento de una posición.
 Entradas: d -> nuevo elemento, p -> posición a modificar, L -> lista.
 Salidas: La lista actualizada.
 Precondiciones: p debe ser una posición válida.
 Postcondiciones: El contenido de la posición p cambia.
 */

 L->data[p] = d;
}

tPosL findItem(tProjectName n, tList L) {
 /*
 Objetivo: Buscar un proyecto por su nombre.
 Entradas: n -> nombre del proyecto, L -> lista.
 Salidas: Posición del proyecto o LNULL si no existe.
 Precondiciones: La lista debe estar inicializada.
 Postcondiciones: No modifica la lista.
 */

 int i; // variable para recorrer la lista
 for(i = 0; i <= L.lastPos; i++){
  if(strcmp(L.data[i].projectName, n) == 0) {
   return i;
  }
 }
 return LNULL;
}