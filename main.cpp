#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solver(double a, double b, double c, double* x1, double* x2);
void resultolis(int numsol, double x1, double x2);
int input (double* coeff);
int solvesquare (double a, double b, double c, double* x1, double* x2);
int solvelinear (double a, double b, double c, double* x1, double* x2);


int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    input (&a);
    input (&b);
    input (&c);

    int numsol = solver (a, b, c, &x1, &x2);
    resultolis (numsol, x1, x2);
}

int input (double* coeff)
{
    while (scanf("%lf", coeff) != 1)
    {
        int ch = 0;
        while ((ch = getchar()) != '\n')
            {
            }

        printf("#Print correct coeff\n");

    }

    return 0;
}

void resultolis(int numsol, double x1, double x2)
{
    switch(numsol)
    {
        case 0: printf("# No solutions");
            break;
        case 1: printf("# x1 = %lf\n", x1);
            break;
        case 2: printf("# x1 = %lf, x2 = %lf \n", x1, x2);
            break;
        case 3: printf("# All real numbers");
            break;
    }
}

int solver(double a, double b, double c, double* x1, double* x2) // разбить на 2 функции, одна из которых будет решать квадратное уравнение, второе линейное, enum

{   if (a == 0)
    {
        return solvelinear (a, b, c, x1, x2);
    }
    else
    {
        return solvesquare (a, b, c, x1, x2);
    }
}

int solvelinear (double a, double b, double c, double* x1, double* x2)
{
    if (b == 0)
    {
        if (c == 0)
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        *x1 = -c / a;
        return 1;
    }
}

int solvesquare (double a, double b, double c, double* x1, double* x2)
{
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        return 0;
    }
    if (D == 0)
    {
        *x1 = -b / (2 * a);
        return 1;
    }
    else
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return 2;
    }
}
