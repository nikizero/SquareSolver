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
        {2, 1, 0,  0,  0,     0,   ONE_ROOT},
        {3, 0, 2, -1,  0.5,   0,   ONE_ROOT},
        {4, 1, 2,  1, -1,     0,   ONE_ROOT},
        {5, 0, 1,  0,  0,     0,   ONE_ROOT},
        {6, 0, 0,  1,  NAN,   NAN, NO_SOLUTIONS},
        {7, 4, 3,  2,  NAN,   NAN, NO_SOLUTIONS},
        {8, 4, 3, -1,  0.25, -1,   TWO_ROOTS},
        {9, 1, 2,  3,  NAN,   NAN, NO_SOLUTIONS}
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
    Quadr coefs = {etalon.a, etalon.b, etalon.c};
    int compare_numroots = compare (answer.num_roots,talon.numsolright);
    int compare_x1 = compare (answer.x1, etalon.x1right);
    int compare_x2 = compare (answer.x2, etalon.x2right);

    answer.num_roots = Solver (coefs, &answer);

    if (compare_numroots == 0 || compare_x1 == 0 || compare_x2 == 0)
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

CompareResult compare(duble a, duble b)
{
    duble e = 0.000001;

    if(fabs(a-b) < e)
    {
        return EQUAL;                                        //ЗАМЕНИТЬ НА ENUM
    }
    else
    {
        return NON_EQUAL;
    }
}
