#ifndef solve_h
#define solve_h
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

/**
 * Finds roots of linear equation.
 *
 * @param [in] b b-coefficient
 * @param [in] c c-coefficient
 * @param [out] x1 Pointer to the root
 *
 * @returns Root and ONEROOT or INFROOTS or NOROOTS
 */

NumOfRoots SolveLinear(double b, double c, double *x1);

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

NumOfRoots SolveSquare(double a, double b, double c, double *x1, double *x2);

#endif
