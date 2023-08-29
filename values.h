#ifndef __values__
#define __values__

struct MainArgs {
    int test, file, numfile;
};

struct TestData {
    double a, b, c;
    double x1ref, x2ref;
    int nRootsref;
};

enum NumOfRoots {
    NOROOTS,
    ONEROOT,
    TWOROOTS,
    INFROOTS
};

const int zero = 0; //Genious!

const int success = 0;
const int GetRoots_error = 1;
const int FileInput_error = 2;
const int tests_error = 3;
const int MainArgs_error = 4;

#endif
