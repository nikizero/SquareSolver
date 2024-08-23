#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../include/tester.h"
#include "../include/solve.h"
#include "../include/util.h"


void StartTest ()
{
    Test etalon[] =
    {
        {1, 0, 0,  0,  NAN,   NAN, INFINITE_ROOTS},
        {2, 1, 0,  0,  0,     NAN,   ONE_ROOT},
        {3, 0, 2, -1,  0.5,   NAN,   ONE_ROOT},
        {4, 1, 2,  1, -1,     NAN,   ONE_ROOT},
        {5, 0, 1,  0,  0,     NAN,   ONE_ROOT},
        {6, 0, 0,  1,  NAN,   NAN, NO_SOLUTIONS},
        {7, 4, 3,  2,  NAN,   NAN, NO_SOLUTIONS},
        {8, 4, 3, -1,  0.25, -1,   TWO_ROOTS},
        {9, 1, 2,  3,  NAN,   NAN, NO_SOLUTIONS},
        {10, 1, 0, -4, 2,   -2,    TWO_ROOTS},
        {11, 0, 0, -4,  NAN, NAN,  NO_SOLUTIONS},
        {12, 0, 4, -4,  1,   NAN,  ONE_ROOT},
        {13, 0, 1,  0,  0,   NAN,  ONE_ROOT},
        {14, 1, 0,  0,  0,   NAN,  ONE_ROOT},
        {15, 1, 1,  0, 0,   -1,    TWO_ROOTS},
        {16, 1, 1, -2, 1,   -2,    TWO_ROOTS},
        {17, 1e-3, -2e-3, 1, NAN, NAN, NO_SOLUTIONS},
        {18, -1e-3, -2e-3, 1, -32.638584, 30.638584, TWO_ROOTS}
    };
    size_t numtests = sizeof(etalon)/sizeof(etalon[0]);

    for (size_t i = 0; i < numtests; i++)
        {
            if (Testing (etalon[i]) == 0)
            {
                break;
            }
        }
}

int Testing (Test etalon)
{
    Solution answer = {0, 0, NO_SOLUTIONS};
    Quadr coefs     = {etalon.a, etalon.b, etalon.c};

    answer.num_roots = Solver (coefs, &answer);
    CompareResult compare_x1_res       = compare (answer.x1, etalon.x1right);
    CompareResult compare_x2_res       = compare (answer.x2, etalon.x2right);

    if (answer.num_roots != etalon.numsolright || compare_x1_res == NON_EQUAL || compare_x2_res == NON_EQUAL)
    {
        printf(RED_COLOR "Test N %d Failed:" NO_COLOR " a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, num_roots = %d\n"
        RED_COLOR "Right Test:" NO_COLOR "      x1right = %lf, x2right = %lf, numsolright = %d \n", etalon.TestNum, etalon.a, etalon.b, etalon.c, answer.x1, answer.x2, answer.num_roots, etalon.x1right, etalon.x2right, etalon.numsolright);
        printf(RED_COLOR "Test's stoped after first failed test" NO_COLOR);
        return 0;
    }
    else
    {
        printf(GREEN_COLOR "Test N %d correct" NO_COLOR "\n", etalon.TestNum);
        return 1;
    }
}

CompareResult compare(double a, double b)
{
    double e = 0.0000001;
    int StatNan_a = isnan(a);
    int StatNan_b = isnan(b);

    if (fabs(a - b) < e || (StatNan_a == 1 && StatNan_b == 1))
    {
        return EQUAL;
    }
    else
    {
        return NON_EQUAL;
    }
}
