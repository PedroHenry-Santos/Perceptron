/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Defines types and definitions.
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

// Application definitions
#define USERNAME_SIZE 30
#define FILE_NAME 30
#define PATH_NAME_SIZE 100
#define TABLE_TITLE 256
#define SECONDS 5
#define ZERO 0
#define ONE 1
#define TWO 2

// Types

/*
* Data for the response generated by the
* perceptron.
*/
typedef struct perceptron {
    char username[USERNAME_SIZE];
    int size, era, grupOne, grupTwo;
    float *w_current, *w_init;
} TPcpt;

/*
* Data related to the behavior of the
* section.
*/
typedef struct section{
    bool std;
    bool std_init;
    bool std_finish;
} TSection;

/*
* Data used in the creation and use of
* samples.
*/
typedef union samplesTypes {
   float *samples, **smaplesList;
} TSamples;

/*
* Data used in the training and execution of
* the perceptron.
*/
typedef struct valuesForPerceptron {
    int generatedResponse, nOfSamples, nOfFeatures, *realResponses;
    float analysis, learningRate;
    TSamples *data;
    bool error;
} TVFPcpt;

/*
* Data to store information
* of directories.
*/
typedef struct directories {
    unsigned char **list;
    unsigned char *file;
    unsigned char *aux;
    int fileSize;
} TDir;

/*
* State data of the main block of the
* application.
*/
typedef struct stateMain {
    bool isBegin;
    bool isPreviousSection;
    TSection *newSection;
    TSection *previousSection;
    TSection *executionSection;
    TSection *checkSection;
    TVFPcpt *dataPerceptron;
    TDir *dataDirectories;
    int input;
} TStateMain;

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


