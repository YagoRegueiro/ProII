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

#define LNULL NULL

typedef struct tNode *tPosL;
typedef tPosL tList;

struct tNode{
  tItemL data;
  tPosL next;
};

void createEmptyList(tList* L);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL next(tPosL p, tList L);
tPosL previous(tPosL p, tList L);
bool insertItem(tItemL d, tPosL p, tList* L);
void deleteAtPosition(tPosL p, tList* L);
tItemL getItem(tPosL p, tList L);
void updateItem(tItemL d , tPosL p, tList* L);
tPosL findItem(tProjectName n, tList L);

#endif
