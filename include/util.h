#ifndef UTIL_INCLUDE
#define UTIL_INCLUDE
#include "solve.h"

enum Modes
{
    TEST            = 0,
    START           = 1,
};

// bash script; main на функции;

/*
Input -

    coeff - coeffient of square equation

return: coeff
*/

int                Input (double* coeff);
void               Itog(Solution answer);
void               CleanBuf();
void                ModeSwitch(Modes* Mode, char* argv[], int argc);
#endif
