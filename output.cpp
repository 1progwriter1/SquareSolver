#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "output.h"
#include "values.h"

void PrintRoots(int colRoots, double x1, double x2) {

    /**
     * Prints roots
     *
     * @param [in] colRoots Number of roots
     * @param [in] x1 Value of the first root
     * @param [in] x2 Value of the second root
     *
     */

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
