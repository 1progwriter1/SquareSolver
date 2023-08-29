#ifndef __solve__
#define __solve__
#include "values.h"

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

NumOfRoots Solve(double a, double b, double c, double *x1, double *x2);

#endif
