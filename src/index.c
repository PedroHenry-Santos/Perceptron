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
#include "lib/__application/math_application.h"

// Imports components
#include "./components/main.c"
#include "./utils/stateMain.c"
#include "./utils/mainBlockTools.c"

// Train perceptron
#include "perceptron.c"

void main(int argc, char const *argv[]) {
    srand(time(NULL));
    TPcpt *data = NULL;
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
            case ZERO:
                goto EndApplication;

            case ONE:
                trainPerceptron();
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
            case ZERO:
                goto EndApplication;

            case ONE:
                state->executionSection->std_init = false;
                state->previousSection->std_finish = true;
                goto SelectFilePreviousSection;

            case TWO:
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
        displaysSelectFilePreviousSection(state);

        if (state->input < ONE || state->input > state->dataDirectories->fileSize) {
            displaysWarning(state->isBegin);
            clickToContinue();
            goto SelectFilePreviousSection;
        } else {
            if (strlen ( *(state->dataDirectories->list + (state->input - ONE)) ) > FILE_NAME) {
                printf ("O nome do arquivo é maior que o suportando");
                clickToContinue();
                goto SelectFilePreviousSection;
            } else {
                state->dataDirectories->file = *(state->dataDirectories->list + (state->input - ONE));
                state->dataDirectories->aux = malloc(strlen(state->dataDirectories->file) * sizeof(unsigned char));
                strcpy(state->dataDirectories->aux, state->dataDirectories->file);
                state->dataDirectories->aux[strcspn(state->dataDirectories->aux, "\n")] = ZERO;
                strcat(state->dataDirectories->aux, ".bin\0");
                displaysChosenOption(state);
                clickToContinue();
                if (data == NULL) {
                    data = malloc(sizeof(TPcpt));
                    if (fillsPreviousSectionValues(data, state)) goto EndApplication;
                }
                goto RunPerceptron;
            }
        }

    RunPerceptron:
        free(state->dataDirectories->aux);
        free(state->dataDirectories->file);
        free(state->dataDirectories->list);
        free(state->dataDirectories);
        if (!state->executionSection->std_init) goto Header;
        printf(" Estamos prontos!\n\n");
        printf(" Informe as %d amostras a serem utilizadas:\n", data->size - ONE);
        runPerceptron(data, state);
        clickToContinue();

        state->checkSection->std_init = false;
        state->executionSection->std_finish = true;
        goto UserChoice;

    UserChoice:
        displaysUserChoice(state);

        switch (state->input) {
            case ONE:
                state->executionSection->std_init = false;
                goto RunPerceptron;

            case TWO:
                state->checkSection->std_finish = true;
                free(data->w_current);
                free(data);
                goto Header;

            default:
                displaysWarning(state->isBegin);
                clickToContinue();
                state->checkSection->std_init = false;
                goto UserChoice;
        }

    EndApplication: ;

    if (state != NULL) {
        if (state->dataDirectories != NULL) {
            if (state->dataDirectories->aux != NULL) free(state->dataDirectories->aux);
            if (state->dataDirectories->file != NULL) free(state->dataDirectories->file);
            if (state->dataDirectories->list != NULL) free(state->dataDirectories->list);
            free(state->dataDirectories);
        }
        free(state->newSection);
        free(state->previousSection);
        free(state->executionSection);
        free(state->checkSection);
        free(state);
    }
    if (data != NULL) {
        if (data->w_current != NULL) free(data->w_current);
        free(data);
    }

    displaysClosing();
    getchar();
    sclean();
}

