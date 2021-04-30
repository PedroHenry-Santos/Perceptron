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
        displaSelectFilePreviousSectionysSelectFilePreviousSection(state);

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
        if (!state->executionSection->std_init) goto Header;
        printf(" Estamos prontos!\n\n");
        printf(" Informe as %d amostras a serem utilizadas:\n", data->size - ONE);
        runPerceptron(data, state);
        printf("\n A amostra pertence ao grupo %d.", state->dataPerceptron->generatedResponse);
        clickToContinue();

        state->checkSection->std_init = false;
        state->executionSection->std_finish = true;
        goto UserChoice;


    UserChoice:

    EndApplication: ;

    if (state != NULL) free(state);
    if (data != NULL) free(data);

    displaysClosing();
    getchar();
    sclean();
}

