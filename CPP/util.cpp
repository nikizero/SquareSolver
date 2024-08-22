#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/util.h"



void Itog(Solution answer)
{
    switch(answer.num_roots)
    {
        case NO_SOLUTIONS:      printf("# No solutions \n");
            break;
        case ONE_ROOT:          printf("# x1 = %lf \n", answer.x1);
            break;
        case TWO_ROOTS:         printf("# x1 = %lf, x2 = %lf \n", answer.x1, answer.x2);
            break;
        case INFINITE_ROOTS:    printf("# All real numbers \n");
            break;
    }
}

void CleanBuf ()
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
}

int Input (double* coeff)
{
    assert (coeff);

    while (scanf("%lf", coeff) != 1)
    {
        CleanBuf();

        printf("#Print correct coeff\n");

    }

    return NO_SOLUTIONS;
}
