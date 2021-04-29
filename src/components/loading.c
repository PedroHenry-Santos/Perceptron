/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Application loading screens.
* Language: C.
*/

/*
* Render the data loading screen.
*
* This function has no return.
*/
void displaysDtLoading (void) {
    smallLine();
    printf("\n                    Buscando algum treinamento já realizado . . .                    \n");
    smallLine();
}

/*
* Render the loading screen for reading the file.
*
* This function has no return.
*/
void displaysFileOp (void) {
    smallLine();
    printf("\n                       Lendo arquivo e trazendo os dados . . .                          \n");
    smallLine();
}

/*
* Render the save loading screen.
*
* This function has no return.
*/
void displaysDtRecord (void) {
    smallLine();
    printf("\n                        Salvando dados do treinamentro . . .                         \n");
    smallLine();
}

/*
* Render the CSV creation loading screen.
*
* This function has no return.
*/
void displaysCSVcreation (void) {
    smallLine();
    printf("\n                          Criando arquivo CSV aguarde . . .                          \n");
    smallLine();
}

/*
* Render the training loading screen.
*
* This function has no return.
*/
void displaysTrainingRzt (void) {
    smallLine();
    printf("\n                             Realizando treinamento . . .                              \n");
    smallLine();
}
