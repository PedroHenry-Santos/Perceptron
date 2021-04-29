/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Application header.
* Language: C.
*/

/*
* Render header in the terminal.
*
* 'true' - to activate delay
* 'false' - not to activate
*
* This function has no return.
*/
void displaysHeader (bool __state) {
    printf(ANSI BOLD AND C_RED END"-------------------------------------------------------------------------------------\n");
    printf("|   ____    _____   ____     ____   _____   ____    _____   ____     ___    _   _   |\n");
    printf("|  |  _ \\  | ____| |  _ \\   / ___| | ____| |  _ \\  |_   _| |  _ \\   / _ \\  | \\ | |  |\n");
    if (__state) sleep(1);
    printf(ANSI C_YELLOW END"|  | |_) | |  _|   | |_) | | |     |  _|   | |_) |   | |   | |_) | | | | | |  \\| |  |\n");
    printf("|  |  __/  | |___  |  _ <  | |___  | |___  |  __/    | |   |  _ <  | |_| | | |\\  |  |\n");
    if (__state) sleep(1);
    printf(ANSI C_BLUE END"|  |_|     |_____| |_| \\_\\  \\____| |_____| |_|       |_|   |_| \\_\\  \\___/  |_| \\_|  |\n");
    printf("|                                                                                   |\n");
    printf("-------------------------------------------------------------------------------------\n"RESET);
    printf("\n\n\n");
    if (__state) sleep(1);
}
