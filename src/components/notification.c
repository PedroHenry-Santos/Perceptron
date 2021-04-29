/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Application notifications screens.
* Language: C.
*/

/*
* Render the training screen successfully performed.
*
* This function has no return.
*/
void displaysSuccessTraining (void) {
    smallLine();
    printf(ANSI C_GREEN END"\n                       ✔ -"RESET);
    printf(ANSI BOLD END" Treinamento comcluido com sucesso!                        \n"RESET);
    smallLine();
}

/*
* Render the successful reading screen.
*
* This function has no return.
*/
void displaysSuccessRead (void) {
    smallLine();
    printf(ANSI C_GREEN END"\n                         ✔ -"RESET);
    printf(ANSI BOLD END" Leitura realizada com sucesso!                        \n"RESET);
    smallLine();
}

/*
* Render the read failure screen
*
* This function has no return.
*/
void displaysFailedRead (void) {
    smallLine();
    printf(ANSI C_RED END"\n                       ✖ -"RESET);
    printf(ANSI BOLD END" Houve um erro na leitura!                        \n"RESET);
    smallLine();
}

/*
* Render the screen of success in creating the CSV.
*
* This function has no return.
*/
void displaysSuccessCreatedCSV (void) {
    smallLine();
    printf(ANSI C_GREEN END"\n                             ✔ -"RESET);
    printf(ANSI BOLD END" CSV criado com sucesso!                        \n"RESET);
    smallLine();
}

/*
* Render the CSV creation failure screen.
*
* This function has no return.
*/
void displaysFailedCreatedCSV (void) {
    smallLine();
    printf(ANSI C_RED END"\n                       ✖ -"RESET);
    printf(ANSI BOLD END" Falha na criação do CSV!                        \n"RESET);
    smallLine();
}

/*
* Render the training notices screen.
*
* This function has no return.
*/
void displaysTrainingWarning () {
    printf(" ");
    printf(ANSI C_YELLOW AND BOLD END"AVISO:"RESET);
    printf(" O arquivo contendo as amostras do treinamento de ser colocado no diretório \n");
    printf(" ");
    printf(ANSI BOLD END"[input]"RESET);
    printf(" na raiz do programa (no formato ");
    printf(ANSI C_BLUE AND BOLD END"CSV"RESET);
    printf(" com separação por vírgula ");
    printf(ANSI BOLD AND C_BLUE END"','"RESET);
    printf(").\n");
    bigLine();
    printf("\n\n\n\n\n\n");
}

/*
* Render the warning screen that there is no database.
*
* This function has no return.
*/
void displaysNoFile () {
    smallLine();
    printf(ANSI BOLD AND C_RED END"\n             Não há nenhum arquivo" RESET);
    printf(" dentro do diretorio " RESET);
    printf(ANSI BOLD END"[input]"RESET);
    printf(", coloque          \n");
    printf("             o arquivo com as amostras que serão utilizadas antes de          \n");
    printf("             tentar novamente.          \n");
    smallLine();
    printf("\n\n\n\n                            Aperte ");
    printf(ANSI BOLD END"ENTER"RESET);
    printf(" para finalizar.");
}
