#include <stdio.h>
#include "fileinput.h"

int FileInput(double *a, double *b, double *c) {
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }
    if (fscanf(fp, "%lg %lg %lg", a, b, c) != 3 || getc(fp) != '\n') {
        printf("FileInput ERROR");
        return 0;
    }
    else {
        return 1;
    }
    int data[3] = {};
    if (fclose(fp) != 0) {
        printf("File not closed\n");
        return 0;
    }
}
