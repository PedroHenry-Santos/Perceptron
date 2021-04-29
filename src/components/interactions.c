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

void clickToContinue () {
    printf("\n\n\n\n                            Aperte ");
    printf(ANSI BOLD END"ENTER"RESET);
    printf(" para continuar.");
    getchar();
}
