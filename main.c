/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Yago Regueiro Piera LOGIN 1: y.regueiro.piera
 * AUTHOR 2: Miguel Magdalena Sánchez LOGIN 2: m.magdalenas
 * GROUP: 4.4
 * DATE: 13 / 03 / 26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void new(tList *list, char *projectName, char *projectEco){
    /*
    Objetivo: Da alta a un proyecto con un número de votos inicial a 0. Se registra su valor eco o non-eco.
    Entradas: list -> puntero a la lista, projectName -> nombre del proyecto, projectEco -> tipo de proyecto.
    Salidas: La lista con el elemento añadido y mensajes de control.
    Precondiciones: list debe ser válido.
    Postcondiciones: La lista tiene un nuevo elemento.
    */
    tItemL item;
    strcpy(item.projectName, projectName);
    item.numVotes = 0;
    if(strcmp(projectEco, "eco")==0){
        item.projectEco = true;
    } else if(strcmp(projectEco, "non-eco")==0){
        item.projectEco = false;
    }
    if(findItem(projectName, *list) != LNULL || insertItem(item, LNULL, list) == false) {
        printf("+ Error: New not possible\n");
    } else{
        printf("* New: project %s category %s\n", projectName, projectEco);
    }
}

void vote(tList *list, char *projectName, int *nullVoteCounter, int *validVoteCounter){
    /*
    Objetivo: Suma un voto al proyecto indicado.
    Entradas: list -> puntero a la lista, projectName -> nombre del proyecto, nullVoteCounter -> puntero a contador de votos nulos, validVoteCounter -> puntero a contador de votos válidos.
    Salidas: La lista con el voto añadido al proyecto indicado, los contadores actualizados y mensajes de control.
    Precondiciones: list debe ser válido.
    Postcondiciones: El voto se añade al proyecto.
    */
    tItemL item;
    tPosL pos;
    char* projectEco;
    pos = findItem(projectName, *list);
    if (pos==LNULL){
        printf("+ Error: Vote not possible. Project %s not found. NULLVOTE\n", projectName);
        (*nullVoteCounter)++;
        return;
    }
    item = getItem(pos, *list);
    if(item.projectEco) projectEco = "eco";
    else projectEco = "non-eco";
    item.numVotes++;
    updateItem(item, pos, list);
    (*validVoteCounter)++;
    printf("* Vote: project %s category %s numvotes %d\n", projectName, projectEco, item.numVotes);
}

void disqualify(tList *list, char *projectName, int *nullVoteCounter, int *validVoteCounter){
    /*
    Objetivo: Descalifica un proyecto eliminándolo de la lista y pasando a ser nulos todos sus votos.
    Entradas: list -> puntero a la lista, projectName -> nombre del proyecto, nullVoteCounter -> puntero a contador de votos nulos, validVoteCounter -> puntero a contador de votos válidos.
    Salidas: La lista sin el proyecto indicado, los contadores actualizados y mensajes de control
    Precondiciones: list debe ser válido.
    Postcondiciones: El proyecto está eliminado de la lista.
    */
    tItemL item;
    tPosL pos;
    char* projectEco;
    pos = findItem(projectName, *list);
    if(pos==LNULL){
        printf("+ Error: Disqualify not possible\n");
        return;
    }
    item = getItem(pos, *list);
    if(item.projectEco) projectEco = "eco";
    else projectEco = "non-eco";
    *nullVoteCounter += item.numVotes;
    *validVoteCounter -= item.numVotes;
    deleteAtPosition(pos, list);
    printf("* Disqualify: project %s category %s\n", projectName, projectEco);
}

void stats(tList list, char *totalEvaluators, int nullVoteCounter, int validVoteCounter){
    /*
    Objetivo: Presenta al usuario estadísticas sobre la lista de proyectos, los votos y los miembros del comité de evaluación.
    Entradas: list -> contenidos de la lista, totalEvaluators -> número de evaluadores, nullVoteCounter -> número de votos nulos, validVoteCounter -> número de votos válidos.
    Salidas: Resumen estadístico de los proyectos, votos y miembros evaluadores
    Precondiciones: n/a.
    Postcondiciones: n/a.
    */
    if(isEmptyList(list)){
        printf("+ Error: Stats not possible\n");
    }

    tPosL pos = first(list);
    tItemL item;
    char* eco;
    float perc;
    float participation;
    int numEvaluators = atoi(totalEvaluators);
    while(pos != LNULL){
        item = getItem(pos, list);
        item.projectEco ? (eco = "eco") : (eco = "non-eco");
        if(validVoteCounter > 0) perc = ((float)item.numVotes / validVoteCounter) * 100;
        else perc = 0.00f;
        printf("Project %s category %s numvotes %d (%.2f%%)\n", item.projectName, eco, item.numVotes, perc);
        pos = next(pos, list);
    }
    participation = ((float)(nullVoteCounter + validVoteCounter)/numEvaluators)*100;
    printf("Null votes %d\n", nullVoteCounter);
    printf("Participation: %d votes from %s evaluators (%.2f%%)\n", nullVoteCounter + validVoteCounter, totalEvaluators, participation);
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *list, int *nullVoteCounter, int *validVoteCounter) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: project %s category %s\n", commandNumber, command, param1, param2);
            new(list, param1, param2);
            break;
        case 'V':
            printf("********************\n");
            printf("%s %c: project %s\n", commandNumber, command, param1);
            vote(list, param1, nullVoteCounter, validVoteCounter);
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: project %s\n", commandNumber, command, param1);
            disqualify(list, param1, nullVoteCounter, validVoteCounter);
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c: totalevaluators %s\n", commandNumber, command, param1);
            stats(*list, param1, *nullVoteCounter, *validVoteCounter);
            break;
        default:
            break;
    }
}

void readTasks(char *filename, tList *list, int *nullVoteCounter, int *validVoteCounter) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, list, nullVoteCounter, validVoteCounter);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    //Se declara e inicializa la lista
    tList list;
    createEmptyList(&list);
    int nullVoteCounter = 0;
    int validVoteCounter = 0;

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, &list, &nullVoteCounter, &validVoteCounter);

    return 0;
}
