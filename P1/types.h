/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera@udc.es
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: 4.4
 * DATE: ** / ** / **
 */
#ifndef PRO2_2024_P1_TYPES_H
#define PRO2_2024_P1_TYPES_H

#include <stdbool.h>

#define NAME_LENGTH_LIMIT 10

typedef char tProjectName[NAME_LENGTH_LIMIT];
typedef int tNumVotes;
typedef bool tProjectEco;

typedef struct tItemL {
    tProjectName projectName;
    tNumVotes numVotes;
    tProjectEco projectEco;
} tItemL;


#endif

