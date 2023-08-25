#include <stdio.h>
#include "solve.h"
#include "input.h"
#include "output.h"
#include "tests.h"

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

int main() {
    printf("# Square equation solver a[x2] + b[x] + c = 0\n"
           "# (c) VLI, 2023\n\n");

    if (!TestAll())
        return 0;
    else
        printf("\n");

    printf("# Enter a, b, c: ");

    double a = 0, b = 0, c = 0;
    GetRoots(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int nRoots = 0;
    nRoots = Solve(a, b, c, &x1, &x2);
    PrintRoots(nRoots, x1, x2);
    return 0;
}
