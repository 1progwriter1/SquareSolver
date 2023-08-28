#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve.h"
#include "output.h"
#include "compare.h"
#include "values.h"

NumOfRoots Solve(double a, double b, double c, double *x1, double *x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    return IsEqual(a, zero) ? SolveLinear(b, c, x1) : SolveSquare(a, b, c, x1, x2);
}
NumOfRoots SolveLinear(double b, double c, double *x1) {

    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);

    if (IsEqual(b, zero)) {
        return IsEqual(c, zero) ? INFROOTS : NOROOTS;
    }
    else {
        *x1 = IsEqual(c, zero) ? 0 : -c / b;
        return ONEROOT;
    }
}

NumOfRoots SolveSquare(double a, double b, double c, double *x1, double *x2) {

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
    double root = sqrt(d);
    *x1 = (-b + root) / (2 * a);
    *x2 = (-b - root) / (2 * a);
    return TWOROOTS;
}
