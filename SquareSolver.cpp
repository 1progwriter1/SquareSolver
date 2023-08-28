#include <stdio.h>
#include "solve.h"
#include "input.h"
#include "output.h"
#include "tests.h"
#include <string.h>
#include "fileinput.h"

/**
 * Solves a square equation ax2 + bx + c = 0
 *
 * @param [in] a a-coefficient
 * @param [in] b b-coefficient
 * @param [in] c c-coefficient
 * @param [out] x1 Pointer to the first root
 * @param [out] x2 Pointer to the second root
 *
 * @return Number of roots
 *
 * @note In case of infinite number of roots, returns SS_INF_ROOTS
 */

int main(int argc, char *argv[]) {
    printf("# Square equation a[x2] + b[x] + c = 0 solver\n"
           "# (c) VLI, 2023\n\n");

    int file = 0, test = 0, numfile = 0;
    if (!GetArgs(argc, argv, &test, &file, &numfile))
        return 0;

    if (test) {
        if (!TestAll())
            return 0;
        printf("\n");
    }

    double a = 0, b = 0, c = 0;
    if (file) {
        if (!FileInput(&a, &b, &c, argv[numfile]))
            return 0;
    }
    else {
        printf("# Enter a, b, c: ");

        if (!GetRoots(&a, &b, &c))
            return 0;
    }

    double x1 = 0, x2 = 0;
    NumOfRoots nRoots = NOROOTS;
    nRoots = Solve(a, b, c, &x1, &x2);
    PrintRoots(nRoots, x1, x2);

    return 0;
}
