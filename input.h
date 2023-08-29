#ifndef SQSOLVER_INPUT_H
#define __input__

/**
 * Gets roots from user
 *
 * @param [in] a Pointer to the a-coefficient
 * @param [in] b Pointer to the b-coefficient
 * @param [in] c Pointer to the c-coefficient
 *
 */

int GetRoots(double *a, double *b, double *c);
int GetArgs(int argc, char *argv[], struct MainArgs *maindata);
void clear();

#endif
