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

void createEmptyList(tList* L){ *L = LNULL; }

bool isEmptyList(tList L){ return L == LNULL; }

tPosL first(tList L){ return L; }

tPosL last(tList L){
  tPosL p = L;

  while(p->next != LNULL)
    p = p->next;
  return p;
}

tPosL next(tPosL p, tList L){ return p->next; }

tPosL previous(tPosL p, tList L){
  if(p == L)
    return LNULL;

  tPosL prev = L;

  while(prev->next != p)
    prev = prev->next;
  return prev;
}

bool insertItem(tItemL d, tPosL p, tList* L){
  tPosL newNode, auxNode;

  newNode = malloc(sizeof(*newNode));
  if(newNode == LNULL)
    return false;

  newNode->data = d;
  newNode->next = LNULL;

  if(*L == LNULL)
    *L = newNode;
  else if(p == LNULL){
    auxNode = last(*L);
    auxNode->next = newNode;
  }
  else if(p == *L){
    newNode->next = *L;
    *L = newNode;
  }
  else{
    auxNode = previous(p, *L);
    newNode->next = p;
    auxNode->next = newNode;
  }
  return true;
}

void deleteAtPosition(tPosL p, tList* L){
  tPosL node;

  if(p == *L)
    *L = p->next;
  else{
    node = previous(p, *L);
    node->next = p->next;
  }
  free(p);
}

tItemL getItem(tPosL p, tList L){ return p->data; }

void updateItem(tItemL d , tPosL p, tList* L){ p->data = d; }

tPosL findItem(tProjectName n, tList L){
  tPosL p = L;

  while(p != LNULL){
    if(strcmp(p->data.projectName, n) == 0)
      return p;
    p = p->next;
  }

  return NULL;
}