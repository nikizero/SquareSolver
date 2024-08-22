#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

enum Roots
{
    NO_SOLUTIONS    = 0,
    ONE_ROOT        = 1,
    TWO_ROOTS       = 2,
    INFINITE_ROOTS  = 3,
};

enum Modes
{
    TEST            = 0,
    START           = 1,
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
int                Input (double* coeff);
void               Itog(Solution answer);
Roots Solver       (Quadr coefs, Solution* answer);
Roots SolveLinear  (Quadr coefs, Solution* answer);
Roots SolveSquare  (Quadr coefs, Solution* answer);
void                CleanBuf();
// void                AskMode(char* argv[1]);
Modes Mode;

int main(int argc, char* argv[])
{
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
    size_t numtests = sizeof(etalon)/sizeof(etalon[0]); // sizeof() тип данных

    if (argc == 2)
    {
        if (strcmp(argv[1], "--Hellp") == 0)
        {
            printf("if you want start programm in test mode use \"--Test\" \n");                 //Как тут сделать вывод двух строк нормальный
            printf("if you want start programm in SolveSquare mode use \"--Start\" \n");
            exit(1);
        }
        else if (strcmp(argv[1],  "--Test") == 0)
        {
            Mode = TEST;
        }
        else if (strcmp(argv[1],  "--Start") == 0)
        {
            Mode = START;
        }
        else
        {
            printf("EROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--Hellp\" \n");
            exit(1);
        }
    }
    else
    {
        printf("EROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--Hellp\" \n");
        exit(1);
    }

    if (Mode == START)
    {
        struct Quadr coefs = {0, 0, 0};                                         //Можно было задать как Quadr coefs = {.a = 0,.b = 0,.c = 0}
        struct Solution answer = {0, 0, NO_SOLUTIONS};
        Input (&coefs.a);
        Input (&coefs.b);
        Input (&coefs.c);

    }
    if (Mode == TEST)
    {
        for (int i = 0; i <= numtests; i++)
        {
            Testing (etalon[i]);
        }
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

void CleanBuf ()
{
    int ch = 0;
    while ((ch = getchar()) != '\n')
        {
        }
}

