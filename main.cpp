#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

enum Roots
{
    NO_SOLUTIONS    = 0,
    ONE_ROOT        = 1,
    TWO_ROOTS       = 2,
    INFINITE_ROOTS  = 3,
};

struct Quadr
{
  double a;
  double b;
  double c;
};

struct Solution
{
    double x1;
    double x2;
    Roots num_roots;
};

int input (double* coeff);
void Itog(Solution answer);
Roots Solver(Quadr coefs, Solution* answer);
Roots SolveLinear (Quadr coefs, Solution* answer);
Roots SolveSquare (Quadr coefs, Solution* answer);

int main()
{
    Quadr coefs = {0, 0, 0};
    Solution answer = {0, 0, NO_SOLUTIONS};

    input (&coefs.a);
    input (&coefs.b);
    input (&coefs.c);

    answer.num_roots = Solver (coefs, &answer);
    Itog (answer); // naming

    // testing (1, 0, 0, 0, 0, 0, 3);
    // testing (2, 1, 0, 0, 0, 0, 1);
    // testing (3, 0, 2, -1, 0.5, 0, 1);
    // testing (4, 1, 2, 1, -1, 0, 1);
    // testing (5, 0, 1, 0, 0, 0, 1);
    // testing (6, 0, 0, 1, 0, 0, 0);
    // testing (7, 4, 3, 2, 0, 0, 0);
    // testing (8, 4, 3, -1, 0.25, -1, 2);
    // testing (9, 1, 2, 3, 0, 0, 0);

}

int input (double* coeff)
{
    assert (coeff);

    while (scanf("%lf", coeff) != 1)
    {
        int ch = 0;
        while ((ch = getchar()) != '\n')
            {
            }

        printf("#Print correct coeff\n");

    }

    return NO_SOLUTIONS;
}

void Itog(Solution answer)
{
    switch(answer.num_roots)
    {
        case NO_SOLUTIONS:      printf("# No solutions");
            break;
        case ONE_ROOT:          printf("# x1 = %lf\n", answer.x1);
            break;
        case TWO_ROOTS:         printf("# x1 = %lf, x2 = %lf \n", answer.x1, answer.x2);
            break;
        case INFINITE_ROOTS:    printf("# All real numbers");
            break;
    }
}

Roots Solver(Quadr coefs, Solution* answer)
{
    assert(answer);

    if (coefs.a == 0)
    {
        return SolveLinear (coefs, answer);
    }
    else
    {
        return SolveSquare (coefs, answer);
    }
}

Roots SolveLinear (Quadr coefs, Solution* answer)
{
    assert(answer);

    if (coefs.b == 0)
    {
        if (coefs.c == 0)
        {
            return INFINITE_ROOTS;
        }
        else
        {
            return NO_SOLUTIONS;
        }
    }
    else
    {
        answer -> x1 = -coefs.c / coefs.b;
        return ONE_ROOT;
    }
}

Roots SolveSquare (Quadr coefs, Solution* answer)
{
    assert (answer);

    double D = coefs.b * coefs.b - 4 * coefs.a * coefs.c;

    if (D < 0)
    {
        return NO_SOLUTIONS;
    }
    else if (D == 0)
    {
        answer -> x1 = -coefs.b / (2 * coefs.a);
        return ONE_ROOT;
    }
    else
    {
        answer -> x1 = (-coefs.b + sqrt(D)) / (2 * coefs.a);
        answer -> x2 = (-coefs.b - sqrt(D)) / (2 * coefs.a);
        return TWO_ROOTS;
    }
}

//int testing (int TestNum, double a, double b, double c, double x1right, double x2right, int numsolright)
//{
//    double x1 = 0, x2 = 0;
//    int numsol = Solver (a, b, c, &x1, &x2);
//    if (numsol != numsolright || x1 != x1right || x2 != x2right)
//    {
//        printf("Test N %d Failed: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, numsol = %d\n"
//        "Right Test: x1right = %lf, x2right = %lf, numsolright = %d \n", TestNum, a, b, c, x1, x2, numsol, x1right, x2right, numsolright);
//        return 0;
//    }
//    else
//    {
//        printf("Test N %d correct: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, numsol = %d\n", TestNum, a, b, c, x1, x2, numsol);
//        return 1;
//    }
//}
