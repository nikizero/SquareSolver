#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int solver(double a, double b, double c, double* x1, double* x2);
int resultolis(int numsol, double x1, double x2);
int input (double* a, double* b, double* c);

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    input (&a, &b, &c);
    int numsol = solver (a, b, c, &x1, &x2);
    resultolis (numsol, x1, x2);
}

int input (double* a, double* b, double* c)
{
    int x = scanf ("%lf %lf %lf", a, b, c);
    if (x!=3)
    {
        printf("#Print correct a, b and c");
        return
    }
}

int resultolis(int numsol, double x1, double x2)
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

int solver(double a, double b, double c, double* x1, double* x2)
{
    if (a==0)
    {
        if (b==0)
        {
            if (c==0)
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
            *x1 = -c/b;
            return 1;
        }
    }
    else
    {
        double D = b*b - 4*a*c;
        if (D<0)
        {
            return 0;
        }
        if (D == 0)
        {
            *x1 = -b/2/a;
            return 1;
        }
        else
        {
            *x1 = (-b + sqrt(D))/2/a;
            *x2 = (-b - sqrt(D))/2/a;
            return 2;
        }
    }
}
