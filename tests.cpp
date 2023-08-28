#include <stdio.h>
#include "tests.h"
#include "compare.h"
#include "solve.h"
#include "output.h"
#include "values.h"

TestData data[] = {
    {1, 5, 4, -1, -4, TWOROOTS},
    {1, 2, 1, -1,  0, ONEROOT},
    {1, 3, 5,  0,  0, NOROOTS},
    {0, 0, 0,  0,  0, INFROOTS}};

const int NumOfTests = sizeof(data) / sizeof(data[0]);

int TestAll() {
    int ok = 0;
    for (int i = 0; i < NumOfTests; i++)
        ok += Test(&data[i], i + 1);
    return (ok == NumOfTests);
}

int Test(const struct TestData *refdata, int NumTest) {

    double x1 = 0, x2 = 0;
    int nRoots;
    nRoots = Solve(refdata->a, refdata->b, refdata->c, &x1, &x2);

    if (!IsEqual(x1, refdata->x1ref) || !IsEqual(x2, refdata->x2ref) || nRoots != refdata->nRootsref) {
        printf("Test №%d FAILED; Expected: x1 = %lg, x2 = %lg, nRoots = %u; Received: x1 = %lg, x2 = %lg, nRoots = %u\n",
            NumTest, refdata->x1ref, refdata->x2ref, refdata->nRootsref, x1, x2, nRoots);
        return 0;
    }
    else {
        printf("Test №%d Succeed\n", NumTest);
        return 1;
    }
}
