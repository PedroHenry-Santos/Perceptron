/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Methods for the operation of the percetron training block.
* Language: C.
*/

/*
* Search for sample data in the upload directory.
*
* This function returns nothing.
*/
void fillPreviousPerceptronTrainingValues (char *, TStateTPerc *);

void fillPreviousPerceptronTrainingValues (char * __path, TStateTPerc *__state) {
    __state->dataDirectories = malloc(sizeof(TDir));
    __state->dataDirectories->list = ltfp(__path);
    if (__state->dataDirectories->list == NULL) displaysThereNothingDirectory();
    else {
        printf(ANSI C_BLUE END" ☛ "RESET);
        printf("Escolha um dos arquivos de amostra da lista:\n\n");
        __state->dataDirectories->fileSize = ctfp(__path);
        for (int i = 0; i < __state->dataDirectories->fileSize; i++) {
            printf("    (%d) - ", i + 1);
            printf(ANSI C_BLUE_LIGTH AND UNDERLINE END"%s"RESET, *(__state->dataDirectories->list + i));
            printf("\n");
        }
        printf(ANSI C_GREEN END"      ❯  "RESET);

        scanf("%d", &__state->input);
        fclean(stdin);
    }
}
