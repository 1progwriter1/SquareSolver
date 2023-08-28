#ifndef input_h
#define input_h

/**
 * Gets roots from user
 *
 * @param [in] a Pointer to the a-coefficient
 * @param [in] b Pointer to the b-coefficient
 * @param [in] c Pointer to the c-coefficient
 *
 */

int GetRoots(double *a, double *b, double *c);
int GetArgs(int argc, char *argv[], int *test, int *file, int *numfile);
void clear();

#endif
