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

int GetArgs(int argc, char *argv[], struct MainArgs *maindata) {

    maindata->test = 0;
    maindata->file = 0;
    maindata->numfile = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0)
            maindata->test = 1;
        else if (strcmp(argv[i], "--file") == 0) {
            if (++i == argc) {
                printf("File name expected\n");
                return 0;
            }
            else {
                maindata->numfile = i;
                maindata->file = 1;
            }
        }
        else printf("Invalid argument %s\n", argv[i]);
    }
    return 1;
}
