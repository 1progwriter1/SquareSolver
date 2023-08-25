#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve.h"
#include "output.h"
#include "compare.h"
#include "values.h"

int Solve(double a, double b, double c, double *x1, double *x2) {

    /**
     * Finds roots of square equation.
     *
     * @param [in] a a-coefficient
     * @param [in] b b-coefficient
     * @param [in] c c-coefficient
     * @param [out] x1 Pointer to the first root
     * @param [out] x2 Pointer to the second root
     *
     * @return SolveLinear or SolveSquare functions
     */
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (IsEqual(a, zero)) {
        return SolveLinear(b, c, x1);
    }
    else {
        return SolveSquare(a, b, c, x1, x2);
    }
}
int SolveLinear(double b, double c, double *x1) {

    /**
     * Finds roots of linear equation.
     *
     * @param [in] b b-coefficient
     * @param [in] c c-coefficient
     * @param [out] x1 Pointer to the root
     *
     * @returns Root and ONEROOT or INFROOTS or NOROOTS
     */

    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);

    if (IsEqual(b, zero)) {
        return c == 0 ? INFROOTS : NOROOTS;
    }
    else {
        *x1 = IsEqual(c, zero) ? 0 : -c / b;
        return ONEROOT;
    }
}

int SolveSquare(double a, double b, double c, double *x1, double *x2) {

    /**
     * Finds roots of square equation.
     *
     * @param [in] a a-coefficient
     * @param [in] b b-coefficient
     * @param [in] c c-coefficient
     * @param [out] x1 Pointer to the first root
     * @param [out] x2 Pointer to the second root
     *
     * @returns Roots and number of roots or message NOROOTS
     */

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double d = b * b - 4 * a * c;
    if (d < 0) {
        return NOROOTS;
    }
    if (IsEqual(d, zero)) {
        *x1 = IsEqual(b, zero) ? 0 : -b / (2 * a);
        return ONEROOT;
    }
    *x1 = (-b + sqrt(d)) / (2 * a);
    *x2 = (-b - sqrt(d)) / (2 * a);
    return TWOROOTS;
}
