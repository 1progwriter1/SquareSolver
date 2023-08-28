#include <stdio.h>
#include "fileinput.h"
#include <assert.h>
#include <errno.h>

int FileInput(double *a, double *b, double *c, char *filename) {

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    errno = 0;
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        perror("");
        return 0;
    }
    int status = 1;
    if (fscanf(f, "%lg %lg %lg", a, b, c) != 3 || getc(f) != '\n') {
        printf("FileInput ERROR");
        status = 0;
    }

    if (fclose(f) != 0) {
        fprintf(stderr, "File not closed\n");
    }
    return status;
}
