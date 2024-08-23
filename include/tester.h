#ifndef TESTER_INCLUDE
#define TESTER_INCLUDE
#include "solve.h"

enum CompareResult
{
    NON_EQUAL    = 0,
    EQUAL        = 1,
};

struct Test
{
    int TestNum;
    double a;
    double b;
    double c;
    double x1right;
    double x2right;
    Roots numsolright;
};

int                Testing (Test etalon);
void               StartTest ();
CompareResult      compare(double a, double b);
#endif
