#include <stdio.h>
#include <assert.h>
#include "input.h"
#include "values.h"
#include "compare.h"

int GetRoots(double *a, double *b, double *c) {

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
    int col = 0;
        correct = 0;
        if ((col = scanf("%lg %lg %lg", a, b, c)) != 3 || getchar() != '\n') {
            correct = 1;
            if (col != -1) {
                printf("Input ERROR. Try again: ");
                clear();
            }
            else {
                printf("\nEnd of input");
                return 0;
            }
        }
    } while (correct);
    return 1;
}

void clear() {
    while (getchar() != '\n');
}
