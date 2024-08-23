#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/solve.h"
#include "../include/tester.h"
#include "../include/util.h"

int main(int argc, char* argv[])
{
    Modes Mode;

    ModeSwitch(&Mode, argv[1], argc);

    if (Mode == START)
    {
        struct Quadr coefs = {0, 0, 0};                                         //Можно было задать как Quadr coefs = {.a = 0,.b = 0,.c = 0}
        struct Solution answer = {0, 0, NO_SOLUTIONS};                          //Что делать, если я хочу передать что-то из другой функции в main?
        Input (&coefs.a);
        Input (&coefs.b);
        Input (&coefs.c);
        answer.num_roots = Solver (coefs, &answer);
        Itog (answer); // naming
    }
    if (Mode == TEST)
    {
        StartTest();
    }

    return 0;
}

