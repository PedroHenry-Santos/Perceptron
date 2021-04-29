/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Manipulate directory elements.
* Language: C.
*/

#ifndef __MANIP_DIREC__
#define __MANIP_DIREC__
#endif

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Definitions
#define __MAX_CHARAC_FILENAME 256
#define __BOOT_VALUE 0
#define __TYPE_FILE 8

int ctfp(char *__path);
unsigned char ** ltfp(char *__path);

/*
* Counts the files in the directory.
*
* This function returns the number of files.
*/
int ctfp(char *__path) {
    DIR *dir;
    int count = __BOOT_VALUE;
    struct dirent *lsdir;
    dir = opendir(__path);
    if (dir) while ( ( lsdir = readdir(dir) ) != NULL ) if (lsdir->d_type == __TYPE_FILE) count++;
    closedir(dir);
    return count;
}

/*
* Search the name of all files in the repository
*
* This function returns a list of names.
*/
unsigned char ** ltfp(char *__path) {
    int i = __BOOT_VALUE, numberName = ctfp(__path);
    if (!numberName) return NULL;
    unsigned char **listNames;
    listNames = (unsigned char **) malloc (numberName * sizeof(unsigned char *));
    for (int j = __BOOT_VALUE; j < numberName; j++)
        listNames[j] = (unsigned char *) malloc (__MAX_CHARAC_FILENAME * sizeof(unsigned char));
    DIR *dir = opendir(__path);
    struct dirent *drnt = NULL;
    if (dir) {
        while (drnt = readdir(dir)) if (drnt->d_type == __TYPE_FILE) strcpy(*(listNames + i++), drnt->d_name);
    }
    else printf("Can not open directory '%s'\n", __path);
    closedir(dir);
    return listNames;
}



