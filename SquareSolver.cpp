#include <stdio.h>
#include "solve.h"
#include "input.h"
#include "output.h"
#include "tests.h"
#include <string.h>
#include "fileinput.h"
#include "values.h"

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

    MainArgs maindata = {0, 0, 0};
    if (!GetArgs(argc, argv, &maindata))
        return MainArgs_error;

    if (maindata.test) {
        if (!TestAll())
            return tests_error;
        printf("\n");
    }

    double a = 0, b = 0, c = 0;
    if (maindata.file) {
        if (!FileInput(&a, &b, &c, argv[maindata.numfile]))
            return FileInput_error;
    }
    else {
        printf("# Enter a, b, c: ");

        if (!GetRoots(&a, &b, &c))
            return GetRoots_error;
    }

    double x1 = 0, x2 = 0;
    NumOfRoots nRoots = NOROOTS;
    nRoots = Solve(a, b, c, &x1, &x2);
    PrintRoots(nRoots, x1, x2);

    return success;
}
