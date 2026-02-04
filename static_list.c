/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"

#include "string.h"

void createEmptyList(tList* L) {
 L -> lastPos = LNULL;
}

bool isEmptyList(tList L) {
 return L.lastPos == LNULL;
}

tPosL first(tList L) {
 return isEmptyList(L) ? LNULL : 0;
}

tPosL last(tList L) {
 return L.lastPos;
}

tPosL next(tPosL p, tList L) {
 if(p < 0 || p >= L.lastPos) {
  return LNULL;
 }
 return p + 1;
}

tPosL previous(tPosL p, tList L) {
 if(p < 1 || p > L.lastPos) {
  return LNULL;
 }
 return p - 1;
}

bool insertItem(tItemL d, tPosL p, tList* L) {
 int i;

 if(L->lastPos >= MAX - 1) {
  return false;
 }
 if(p < LNULL || p > (L->lastPos)) {
  return false;
 }
 L->lastPos++;

 if(p == LNULL){
  L->data[L->lastPos] = d;
 }
 else {
  for(i = L->lastPos; i > p; i--) {
   L->data[i] = L->data[i - 1];
  }
  L->data[p] = d;
 }
 return true;
}

void deleteAtPosition(tPosL p, tList* L) {
 int i;

 if(p >= 0 && p < L->lastPos) {
  for(i = p; i <= L->lastPos; i++) {
   L->data[i] = L->data[i + 1];
  }
  L->lastPos--;
 }
}

tItemL getItem(tPosL p, tList L) {
 return L.data[p];
}

void updateItem(tItemL d , tPosL p, tList* L) {
 L->data[p] = d;
}

tPosL findItem(tProjectName n, tList L) {
 int i;
 for(i = 0; i <= L.lastPos; i++){
  if(strcmp(L.data[i].projectName, n) == 0) {
   return i;
  }
 }
 return LNULL;
}