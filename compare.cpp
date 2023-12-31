#include "compare.h"
#include <math.h>

const double Compare_Precision = 1e-9;

int IsEqual(double a, double b) {
    return fabs(a - b) < Compare_Precision;
}
