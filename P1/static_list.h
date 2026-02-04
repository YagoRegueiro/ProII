/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera@udc.es
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: 4.4
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define LNULL -1
#define MAX 25

typedef int tPosL;
typedef struct List{
    tItemL data[MAX];
    tPosL lastPos;
}tList;

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
