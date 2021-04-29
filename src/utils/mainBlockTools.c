/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Methods for the operation of the main block.
* Language: C.
*/

/*
* Checks whether files exist within 'data'.
*
* This function returns a boolean.
*/
bool checkDirectory ();

bool checkDirectory () {
    int check = ctfp("./data");

    if (check > 0) return true;
    else {
        printf(ANSI C_YELLOW END"\n\n                        * Nao foi encontrado nenhum arquivo *"RESET);
        return false;
    }
}
