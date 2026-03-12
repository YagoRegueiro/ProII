#ifndef PRO2_2026_P1_TYPES_H
#define PRO2_2026_P1_TYPES_H

// Longitud máxima del nombre de un proyecto
#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

// Nombre de un proyecto
typedef char tProjectName[NAME_LENGTH_LIMIT];
// Número de votos de un proyecto
typedef int tNumVotes;
// Indica si el proyecto es ecológico
typedef bool tProjectEco;

// Información de un proyecto almacenado en la lista
typedef struct tItemL {
    tProjectName projectName;
    tNumVotes numVotes;
    tProjectEco projectEco;
} tItemL;

#endif //PRO2_2026_P1_TYPES_H
