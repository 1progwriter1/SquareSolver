#ifndef values_h
#define values_h

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

#endif
