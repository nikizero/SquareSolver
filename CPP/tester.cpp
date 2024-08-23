#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/tester.h"
#include "../include/solve.h"

int                Testing (Test etalon);

Test etalon[] =
    {
        {1, 0, 0,  0,  0,     0, INFINITE_ROOTS},
        {2, 1, 0,  0,  0,     0, ONE_ROOT},
        {3, 0, 2, -1,  0.5,   0, ONE_ROOT},
        {4, 1, 2,  1, -1,     0, ONE_ROOT},
        {5, 0, 1,  0,  0,     0, ONE_ROOT},
        {6, 0, 0,  1,  0,     0, NO_SOLUTIONS},
        {7, 4, 3,  2,  0,     0, NO_SOLUTIONS},
        {8, 4, 3, -1,  0.25, -1, TWO_ROOTS},
        {9, 1, 2,  3,  0,     0, NO_SOLUTIONS}
    };

void StartTest ()
{
    size_t numtests = sizeof(etalon)/sizeof(etalon[0]);

    for (size_t i = 0; i < numtests; i++)
        {
            Testing (etalon[i]);
        }
}

int Testing (Test etalon)
{
    Solution answer = {0, 0, NO_SOLUTIONS};
    Quadr coefs = {etalon.a, etalon.b, etalon.c};
    answer.num_roots = Solver (coefs, &answer);
    if (answer.num_roots != etalon.numsolright || answer.x1 != etalon.x1right || answer.x2 != etalon.x2right)
    {
        printf("Test N %d Failed: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, num_roots = %d\n"
        "Right Test: x1right = %lf, x2right = %lf, numsolright = %d \n", etalon.TestNum, etalon.a, etalon.b, etalon.c, answer.x1, answer.x2, answer.num_roots, etalon.x1right, etalon.x2right, etalon.numsolright);
        return 0;
    }
    else
    {
        printf("Test N %d correct \n", etalon.TestNum);
        return 1;
    }
}

