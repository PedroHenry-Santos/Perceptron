/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Perceptron training with data entered.
* Language: C.
*/

// Imports components
#include "./utils/PerceptronTrainigBlockTools.c"

void trainPerceptron () {
    FILE *fp;
    TPcpt *data = malloc(sizeof(TPcpt));
    TStateTPerc *state = malloc(sizeof(TStateTPerc));
    clock_t t;

    state->flag = 'U';

    Header:
        sclean();
        displaysTrainingWarning();
        fclean(stdin);

        if (state->flag == 'U') goto RequestUsername;
        else if (state->flag == 'F') goto RequestFileName;
        else if (state->flag == 'S') goto RequestSamples;
        else if (state->flag == 'C') goto RequestFeature;
        else if (state->flag == 'R') goto RequestRate;
        else if (state->flag == 'E') goto ReadCSVFromSamples;

    RequestUsername:
        printf(ANSI C_BLUE END" ☛ "RESET);
        printf("Quem está realizando o treinamento? ");
        printf( ANSI BOLD END"(Max. 100 caracteres)"RESET);
        printf(ANSI C_GREEN END"\n ❯ "RESET);
        fgets(data->username, USERNAME_SIZE, stdin);
        if (data->username[ZERO] != '\n') {
            state->flag = 'F';
            goto Header;
        } else {
            displaysPerceptronWarning();
            clickToContinue();
            goto Header;
        }

    RequestFileName:
        fillPreviousPerceptronTrainingValues("../public/uploads", state);

        if (state->dataDirectories->list != NULL) {
            if (state->input < ONE || state->input > state->dataDirectories->fileSize) {
                displaysPerceptronWarning();
                clickToContinue();
                goto Header;
            }
            else {
                if (strlen ( *(state->dataDirectories->list + (state->input - ONE)) ) > __MAX_CHARAC_FILENAME) printf ("O nome do arquivo é maior que o suportando");
                else {
                    state->dataDirectories->file = *(state->dataDirectories->list + (state->input - ONE));
                    printf(ANSI C_GREEN END"\n * O arquivo escolhido foi o ");
                    printf(ANSI BOLD END"%s"RESET, state->dataDirectories->file);
                    printf(ANSI C_GREEN END" *"RESET);
                    clickToContinue();
                    state->flag = 'S';
                    goto Header;
                }
            }
        } else goto End;

    RequestSamples:

    RequestFeature:

    RequestRate:

    ReadCSVFromSamples:

    MidReadCSVOptions:

    PrintSamplesCSVValues:

    RunTraining:

        data->era = 0;

    SaveData:

    MidOptionsAfterSave:

    CreateCSV:

    End: ;

    if (state != NULL) {
        free(state);
    }
    if (data != NULL) {
        free(data);
    }
}
