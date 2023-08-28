#include <stdio.h>
#include "tests.h"
#include "compare.h"
#include "solve.h"
#include "output.h"
#include "values.h"

const int NumOfTests = 4;

TestData data[NumOfTests] = {
    {1, 5, 4, -1, -4, TWOROOTS},
    {1, 2, 1, -1, 0, ONEROOT},
    {1, 3, 5, 0, 0, NOROOTS},
     {0 , 0 , 0, 0, 0, INFROOTS}};

int TestAll() {
    int ok = 0;
    for (int i = 0; i < NumOfTests; i++)
        ok += Test(&data[i], i + 1);
    return (ok == NumOfTests);
}

int Test(const struct TestData *data, int NumTest) {

    double x1 = 0, x2 = 0;
    int nRoots;
    nRoots = Solve(data->a, data->b, data->c, &x1, &x2);

    if (!IsEqual(x1, data->x1ref) || !IsEqual(x2, data->x2ref) || nRoots != data->nRootsref) {
        printf("Test №%d FAILED; Expected: x1 = %lg, x2 = %lg, nRoots = %u; Received: x1 = %lg, x2 = %lg, nRoots = %u\n",
            NumTest, data->x1ref, data->x2ref, data->nRootsref, x1, x2, nRoots);
        return 0;
    }
    else {
        printf("Test №%d Succeed\n", NumTest);
        return 1;
    }
}
