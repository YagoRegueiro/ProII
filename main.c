/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
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


tList projectList;
int nullVotes = 0;


void processCommand(char *commandNumber, char command, char *param1, char *param2) {
    /*
    Objetivo: Procesar una operación del fichero de entrada.
    Entradas: commandNumber -> número de comando, command -> tipo de operación (N, V, D, S)
                    ,param1 -> primer parámetro, param2 -> segundo parámetro
    Salidas: ninguna
    Precondiciones: la lista debe estar inicializada
    Postcondiciones: la lista puede modificarse según la operación
    */
    tPosL p;
    tItemL item;

    printf("********************\n");

    switch (command) {

        case 'N':

            printf("%s N: project %s category %s\n", commandNumber, param1, param2);

            if (findItem(param1, projectList) != LNULL) {
                printf("+ Error: New not possible\n");
                break;
            }

            strcpy(item.projectName, param1);
            item.numVotes = 0;
            item.projectEco = (strcmp(param2, "eco") == 0);

            if (!insertItem(item, LNULL, &projectList)) {
                printf("+ Error: New not possible\n");
                break;
            }

            printf("* New: project %s category %s\n", param1, param2);

            break;


        case 'V':

            printf("%s V: project %s\n", commandNumber, param1);

            if (isEmptyList(projectList)) {
                printf("+ Error: Vote not possible. Project %s not found. NULLVOTE\n", param1);
                nullVotes++;
                break;
            }

            p = findItem(param1, projectList);

            if (p == LNULL) {
                printf("+ Error: Vote not possible. Project %s not found. NULLVOTE\n", param1);
                nullVotes++;
                break;
            }

            item = getItem(p, projectList);
            item.numVotes++;

            updateItem(item, p, &projectList);

            printf("* Vote: project %s category %s numvotes %d\n",
                   item.projectName,
                   item.projectEco ? "eco" : "non-eco",
                   item.numVotes);

            break;


        case 'D':

            printf("%s D: project %s\n", commandNumber, param1);

            if (isEmptyList(projectList)) {
                printf("+ Error: Disqualify not possible\n");
                break;
            }

            p = findItem(param1, projectList);

            if (p == LNULL) {
                printf("+ Error: Disqualify not possible\n");
                break;
            }

            item = getItem(p, projectList);

            nullVotes += item.numVotes;

            deleteAtPosition(p, &projectList);

            printf("* Disqualify: project %s category %s\n",
                   item.projectName,
                   item.projectEco ? "eco" : "non-eco");

            break;


        case 'S': {

            int totalEvaluators = atoi(param1);
            int validVotes = 0;
            int totalVotes;
            float percentage;
            float participation;
            tPosL pos;

            printf("%s S: totalevaluators %d\n", commandNumber, totalEvaluators);

            if (isEmptyList(projectList)) {
                printf("+ Error: Stats not possible\n");
                break;
            }

            for (pos = first(projectList); pos != LNULL; pos = next(pos, projectList)) {
                item = getItem(pos, projectList);
                validVotes += item.numVotes;
            }

            for (pos = first(projectList); pos != LNULL; pos = next(pos, projectList)) {

                item = getItem(pos, projectList);

                percentage = 0.0;

                if (validVotes > 0)
                    percentage = (item.numVotes * 100.0) / validVotes;

                printf("Project %s category %s numvotes %d (%.2f%%)\n",
                       item.projectName,
                       item.projectEco ? "eco" : "non-eco",
                       item.numVotes,
                       percentage);
            }

            printf("Null votes %d\n", nullVotes);

            totalVotes = validVotes + nullVotes;

            participation = 0.0;

            if (totalEvaluators > 0)
                participation = (totalVotes * 100.0) / totalEvaluators;

            printf("Participation: %d votes from %d evaluators (%.2f%%)\n",
                   totalVotes,
                   totalEvaluators,
                   participation);

            break;
        }

        default:
            break;
    }
}


void readTasks(char *filename) {
    /*
    Objetivo: Leer el fichero de tareas y procesarlas
    Entradas: filename -> nombre del fichero
    Salidas: ninguna
    Precondiciones: el fichero debe existir
    Postcondiciones: se ejecutan los comandos del fichero
    */

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

            processCommand(commandNumber, command[0], param1, param2);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    /*
    Objetivo: Función principal
    Entradas: argumentos de ejecución
    Salidas: código de finalización
    Precondiciones: ninguna
    Postcondiciones: se procesan las operaciones del fichero
    */

    char *file_name = "new.txt";

    createEmptyList(&projectList);

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}





