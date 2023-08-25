#include "compare.h"
#include <math.h>

const double Compare_Equation = 1e-20;

int IsEqual(double a, double b) {
    return fabs(a - b) < Compare_Equation;
}
