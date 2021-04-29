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
        if (!state->newSection->std_init) goto Header;
        displaysNewSection(state);

        switch (state->input) {
            case 0:
                goto EndApplication;

            case 1:
                printf("\n\nRealiza treinamento!\n\n");
                goto EndApplication;

            default:
                displaysWarning(state->isBegin);
                clickToContinue();
                state->newSection->std_init = false;
                goto NewTrainingSection;
        }

    PreviousSectionSaved:
        if (!state->previousSection->std_init) goto Header;
        displaysPreviousSection(state);

        switch (state->input) {
            case 0:
                goto EndApplication;

            case 1:
                state->executionSection->std_init = false;
                state->previousSection->std_finish = true;
                goto SelectFilePreviousSection;

            case 2:
                state->previousSection->std_finish = true;
                state->isPreviousSection = false;
                goto Header;

            default:
                displaysWarning(state->isBegin);
                clickToContinue();
                state->previousSection->std_init = false;
                goto PreviousSectionSaved;
        }

    SelectFilePreviousSection:

    RunPerceptron:

    UserChoice:

    EndApplication: ;

    if (state != NULL) free(state);

    displaysClosing();
    getchar();
    sclean();
}

