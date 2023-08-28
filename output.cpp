#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "output.h"
#include "values.h"

void PrintRoots(NumOfRoots colRoots, double x1, double x2) {

    switch (colRoots) {
        case NOROOTS:
            printf("No roots\n");
            break;

        case ONEROOT:
            printf("x = %lg", x1);
            break;

        case TWOROOTS:
            printf("x1 = %lg, x2 = %lg", x1, x2);
            break;

        case INFROOTS:
            printf("Any number");
            break;

        default:
            printf("main(): ERROR: nROOTS = %d\n", colRoots);
    }
}
