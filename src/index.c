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
#include "lib/__application/manipulate_directories.h"

// Imports components
#include "./components/main.c"
#include "./utils/stateMain.c"
#include "./utils/mainBlockTools.c"

void main(int argc, char const *argv[]) {
    srand(time(NULL));

    TStateMain *state = malloc(sizeof(TStateMain));
    startState(state);

    Header:
        sclean();
        checkState(state);
        displaysHeader(state->isBegin);

        if (state->isBegin) goto ChecksPreviousFiles;
        else if (state->newSection->std) goto NewTrainingSection;
        else if (state->previousSection->std) goto PreviousSectionSaved;
        else if (state->checkSection->std) goto UserChoice;
        else if (state->executionSection->std) goto RunPerceptron;

    ChecksPreviousFiles:
        displaysDtLoading();
        sleep(SECONDS);

        state->isPreviousSection = checkDirectory();
        state->newSection->std = !state->isPreviousSection ? true : false;
        state->previousSection->std = state->isPreviousSection ? true : false;

        checkState(state);
        clickToContinue();
        goto Header;

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

