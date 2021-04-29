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

void clickToContinue () {
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

