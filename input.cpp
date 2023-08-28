#include <stdio.h>
#include <assert.h>
#include "input.h"
#include "values.h"
#include "compare.h"
#include <string.h>

int GetRoots(double *a, double *b, double *c) {

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int correct = 0;
    do {
    int col = 0;
        correct = 1;
        if ((col = scanf("%lg %lg %lg", a, b, c)) != 3 || getchar() != '\n') {
            correct = 0;
            if (col != EOF) {
                printf("Input ERROR. Try again: ");
                clear();
            }
            else {
                printf("\nEnd of input");
                return 0;
            }
        }
    } while (!correct);
    return 1;
}

void clear() {
    while (getchar() != '\n')
        ;
}

int GetArgs(int argc, char *argv[], int *test, int *file, int *numfile) {

    assert(test != NULL);
    assert(file != NULL);
    assert(numfile != NULL);

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0)
            *test = 1;
        else if (strcmp(argv[i], "--file") == 0) {
            if (++i == argc) {
                printf("File name expected");
                return 0;
            }
            else {
                *numfile = i;
                *file = 1;
            }
        }
        else printf("Invalid argument %s\n", argv[i]);
    }
    return 1;
}
