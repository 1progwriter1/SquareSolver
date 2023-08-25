#include <stdio.h>
#include <assert.h>
#include "input.h"

void GetRoots(double *a, double *b, double *c) {

    /**
     * Gets roots from user
     *
     * @param [in] a Pointer to the a-coefficient
     * @param [in] b Pointer to the b-coefficient
     * @param [in] c Pointer to the c-coefficient
     *
     */
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int correct = 0;
    do {
        correct = 0;
        if (scanf("%lg %lg %lg", a, b, c) != 3 || getchar() != '\n') {
            correct = 1;
            printf("Input ERROR. Try again: ");
            clear();
        }
    } while (correct);
}

void clear() {
    while (getchar() != '\n') ;
}
