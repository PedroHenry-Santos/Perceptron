/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Defines types.
* Language: C.
*/

// Deflib
#ifndef __STARTUP__
#define __STARTUP__
#endif

// Boolean type
#define true 1
#define false 0
typedef int bool;

// Libraries
#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
    #include <unistd.h>
    #include <stdio_ext.h>
#elif defined(_WIN32) || defined(WIN32)
   #include <windows.h>
#endif

/*
* Flush STREAM, or all streams if STREAM is NULL.
*
* For WIN32 or UNIX.
*/
void fclean (FILE *__fp) {
    #ifdef __unix__
        __fpurge(__fp);
    #elif
        fflush(__fp);
    #endif
}

/*
* Clears the shell command screen.
*
* This function is a cancellation point and therefore not marked with
* __THROW.
*
* For WIN32 or UNIX.
*/
void sclean(void) {
    #ifdef __unix__
        system("clear"); //GNU/Linux
    #else
        system("cls");
    #endif
}


