/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Implement a perceptron application with an interactive interface.
* Language: C.
*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/__application/startup.h"

// Imports components
#include "./components/main.c"
#include "./utils/stateMain.c"

void main(int argc, char const *argv[]) {
    srand(time(NULL));

    TStateMain *state = malloc(sizeof(TStateMain));
    startState(state);

    Header:
        sclean();
        checkState(state);
        displaysHeader(state->isBegin);

        if (state->isBegin) goto ChecksPreviousFiles;
        else if (state->newSection->std) ;
        else if (state->previousSection->std) ;
        else if (state->checkSection->std) ;
        else if (state->executionSection->std) ;

    ChecksPreviousFiles:

    NewTrainingSection:

    PreviousSectionSaved:

    SelectFilePreviousSection:

    RunPerceptron:

    UserChoice:

    EndApplication: ;

    if (state != NULL) free(state);

    displaysClosing();
    getchar();
    sclean();
}

