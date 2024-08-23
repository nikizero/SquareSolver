#ifndef UTIL_INCLUDE
#define UTIL_INCLUDE
#include "solve.h"

#define RED_COLOR               "\033[31m"
#define NO_COLOR                "\033[0m"
#define GREEN_COLOR             "\033[32m"

enum Modes
{
    TEST                 = 0,
    START                = 1,
    INITIALIZE           = 3,
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
void                ModeSwitch(Modes* Mode, const char* argv[], int argc);
#endif
