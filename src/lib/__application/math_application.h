/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Mathematical operations performed in the application.
* Language: C.
*/

// Libraries
#include <stdio.h>
#include <stdlib.h>

#ifndef __MATH_APP__
#define __MATH_APP__
#endif

#ifndef ZERO && ONE
#define ZERO 0
#define ONE 1
#endif

/*
* Sum of the multiplication of the vector elements.
*
* This function returns the sum.
*/
float vmult (float *__vetOne, float *__vetTwo, int __size) {
    float __sum = ZERO;
    for (int i = ONE; i < __size; i++) {
        __sum += __vetOne[i] * __vetTwo[i];
    }
    return __sum;
}

/*
* Activation function using Heaviside.
*
* This function returns the corresponding group.
*/
int atcf (float __analysis, int __grupOne, int __grupoTwo) {
    if (__analysis >= ZERO) return __grupOne;
    else return __grupoTwo;
}
