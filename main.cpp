#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

enum roots
{
    NO_SOLUTIONS    = 0,
    ONE_ROOT        = 1,
    TWO_ROOTS       = 2,
    INFINITE_ROOTS  = 3
}; //C большой

int solver(double a, double b, double c, double* x1, double* x2);
void resultolis(int numsol, double x1, double x2);
int input (double* coeff);
int solvesquare (double a, double b, double c, double* x1, double* x2);
int solvelinear (double a, double b, double c, double* x1, double* x2);
int testing (int TestNum, double a, double b, double c, double x1right, double x2right, int numsolright);


int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, t = 1; // assert, enum
    input (&a);
    input (&b);
    input (&c);

    roots var = NO_SOLUTIONS;

    int numsol = solver (a, b, c, &x1, &x2);
    resultolis (numsol, x1, x2);

    // t = testing (1, 0, 0, 0, 0, 0, 3);
    // t = testing (2, 1, 0, 0, 0, 0, 1);
    // t = testing (3, 0, 2, -1, 0.5, 0, 1);
    // t = testing (4, 1, 2, 1, -1, 0, 1);
    // t = testing (5, 0, 1, 0, 0, 0, 1);
    // t = testing (6, 0, 0, 1, 0, 0, 0);
    // t = testing (7, 4, 3, 2, 0, 0, 0);
    // t = testing (8, 4, 3, -1, 0.25, -1, 2);
    // t = testing (9, 1, 2, 3, 0, 0, 0);

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

void resultolis(int numsol, double x1, double x2)
{
    switch(numsol)
    {
        case NO_SOLUTIONS: printf("# No solutions");
            break;
        case ONE_ROOT: printf("# x1 = %lf\n", x1);
            break;
        case TWO_ROOTS: printf("# x1 = %lf, x2 = %lf \n", x1, x2);
            break;
        case INFINITE_ROOTS: printf("# All real numbers");
            break;
    }
}

int solver(double a, double b, double c, double* x1, double* x2) // разбить на 2 функции, одна из которых будет решать квадратное уравнение, второе линейное, enum
{
    assert(x1); // assert(x1 != nullptr)
    assert(x2);

    if (a == 0)
    {
        return solvelinear (a, b, c, x1, x2);
    }
    else
    {
        return solvesquare (a, b, c, x1, x2);
    }
}

roots solvelinear (double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);
    if (b == 0)
    {
        if (c == 0)
        {
            return 3;
        }
        else
        {
            return NO_SOLUTIONS;
        }
    }
    else
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}

roots solvesquare (double a, double b, double c, double* x1, double* x2)
{
    assert (x1);
    assert (x2);
    double D = b * b - 4 * a * c;


    if (D < 0)
    {
        return NO_SOLUTIONS;
    }
    if (D == 0)
    {
        *x1 = -b / (2 * a);
        return ONE_ROOT;
    }
    else
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return TWO_ROOTS;
    }
}

int testing (int TestNum, double a, double b, double c, double x1right, double x2right, int numsolright)
{
    double x1 = 0, x2 = 0;
    int numsol = solver (a, b, c, &x1, &x2);
    if (numsol != numsolright || x1 != x1right || x2 != x2right)
    {
        printf("Test N %d Failed: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, numsol = %d\n"
        "Right Test: x1right = %lf, x2right = %lf, numsolright = %d \n", TestNum, a, b, c, x1, x2, numsol, x1right, x2right, numsolright);
        return 0;
    }
    else
    {
        printf("Test N %d correct: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, numsol = %d\n", TestNum, a, b, c, x1, x2, numsol);
        return 1;
    }
}
