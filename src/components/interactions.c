/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Components responsible for user interactions.
* Language: C.
*/

/*
* Pause the screen until the user interacts.
*
* This function returns nothing.
*/
void clickToContinue ();
/*
* Print user options when starting a new training.
*
* This function returns nothing.
*/
void displaysNewSection (TStateMain *__state);
/*
* Warns if user enters invalid option.
*
* This function returns nothing.
*/
void displaysWarning (bool __state);
/*
* Warns if user enters invalid option in training.
*
* This function returns nothing.
*/
void displaysPerceptronWarning ();
/*
* Print user options when resuming a previous section.
*
* This function returns nothing.
*/
void displaysPreviousSection (TStateMain *__state);
/*
* Print the name of all files in the 'data' directory and provides
* the user as an option.
*
* This function returns nothing.
*/
void displaysSelectFilePreviousSection (TStateMain *__state);
/*
* Imprime opções ao usuarios e registra sua escolha.
*
* Esta função não retorna nada.
*/
void displaysUserChoice (TStateMain *__state);
/*
* Formats the string for printing.
*
* This function returns nothing.
*/
unsigned char *formatsText (unsigned char *__text);

void clickToContinue () {
    fclean(stdin);
    printf("\n\n\n\n                            Aperte ");
    printf(ANSI BOLD END"ENTER"RESET);
    printf(" para continuar.");
    getchar();
}

void displaysNewSection (TStateMain *__state) {
    printf(ANSI C_BLUE END"\n\n ☛ "RESET);
    printf("Gostaria de iniciar um treinamento---?\n");
    printf(ANSI C_BLUE_LIGTH END"    ( 1 ) - Sim.\n");
    printf(ANSI C_BLUE_LIGTH END"    ( 0 ) - Não, encerrar o programa.\n");
    printf(ANSI C_BLUE END"      ❯     "RESET);
    scanf("%d", &__state->input);
    fclean(stdin);
    sclean();
}

void displaysWarning (bool __state) {
    sclean();
    displaysHeader(__state);
    printf(ANSI C_RED END"  ✖ "RESET);
    printf("Escolha invalida.");
}

void displaysPerceptronWarning () {
    sclean();
    displaysTrainingWarning();
    printf(ANSI C_RED END"  ✖ "RESET);
    printf("Escolha invalida.");
}

void displaysPreviousSection (TStateMain *__state) {
    printf(ANSI C_BLUE END"\n\n ☛ "RESET);
    printf("Foram encontrados treinamentos anteriores.\n\n");
    printf(" Gostaria de utilizar algum?\n\n");
    printf(ANSI C_RED AND BOLD END" IMPORTANTE:"RESET);
    printf(" Caso comece outro treinamento o atual será descartado!\n");
    printf(ANSI C_BLUE_LIGTH END"    ( 1 ) - Sim, mostre-me eles.\n");
    printf("    ( 2 ) - Não, começar novo.\n");
    printf("    ( 0 ) - Encerrar programa.\n"RESET);
    printf(ANSI C_BLUE END"      ❯     "RESET);
    scanf("%d", &__state->input);
    fclean(stdin);
    sclean();
}

unsigned char *formatsText (unsigned char *__text) {
    int i, size = strcspn(__text, ".bin");
    unsigned char *tmp = malloc((size + 1) * sizeof(unsigned char));
    for (i = 0; i < size; i++) {*(tmp + i) = *(__text + i);}
    tmp[i] = '\0';
    return tmp;
}

void displaysSelectFilePreviousSection (TStateMain *__state) {
    __state->dataDirectories = malloc(sizeof(TDir));
    __state->dataDirectories->list = ltfp("./data");

    sclean();
    displaysHeader(__state->isBegin);
    printf(ANSI C_BLUE END"\n\n ☛ "RESET);
    printf("Foi encontrado os seguintes treinamentos realizados:\n\n");
    __state->dataDirectories->fileSize = ctfp("./data");

    for (int i = ZERO; i < __state->dataDirectories->fileSize; i++) {
        printf("    (%d) - ", i + ONE);
        printf(ANSI C_BLUE_LIGTH AND UNDERLINE END"Realizado por %s"RESET, formatsText(*(__state->dataDirectories->list + i)));
        printf("\n");
    }
    printf(ANSI C_GREEN END"      ❯  "RESET);
    scanf("%d", &__state->input);
    fclean(stdin);
}

void displaysUserChoice (TStateMain *__state) {
    printf(ANSI C_BLUE END"\n\n ☛ "RESET);
    printf("O que gostaria de fazer?\n");
    printf(ANSI C_BLUE_LIGTH END"    ( 1 ) - Verificar outra amostra.\n");
    printf(ANSI C_BLUE_LIGTH END"    ( 2 ) - Voltar menu inicial.\n");
    printf(ANSI C_BLUE END"      ❯     "RESET);
    scanf("%d", &__state->input);
    fclean(stdin);
    sclean();
}

