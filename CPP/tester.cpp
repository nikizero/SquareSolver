#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/tester.h"
#include "../include/solve.h"

int                Testing (Test etalon);


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

