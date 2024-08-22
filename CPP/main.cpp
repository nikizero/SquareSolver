#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/solve.h"
#include "../include/tester.h"
#include "../include/util.h"

enum Modes
{
    TEST            = 0,
    START           = 1,
};

int main(int argc, char* argv[])
{
    Modes Mode;
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
    size_t numtests = sizeof(etalon)/sizeof(etalon[0]);

    if (argc == 2)
    {
        if (strcmp(argv[1], "--Help") == 0)
        {
            fprintf(stderr, "if you want start programm in test mode use \"--Test\" \n"); //Как тут сделать вывод двух строк нормальный
            printf("if you want start programm in SolveSquare mode use \"--Start\" \n"); // stderr, stdin, stdout
            return 1;
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
            return 1;
        }
    }
    else
    {
        printf("EROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--Hellp\" \n");
        return 1;
    }

    if (Mode == START)
    {
        struct Quadr coefs = {0, 0, 0};                                         //Можно было задать как Quadr coefs = {.a = 0,.b = 0,.c = 0}
        struct Solution answer = {0, 0, NO_SOLUTIONS};
        Input (&coefs.a);
        Input (&coefs.b);
        Input (&coefs.c);
        answer.num_roots = Solver (coefs, &answer);
        Itog (answer); // naming

    }
    if (Mode == TEST)
    {
        for (size_t i = 0; i < numtests; i++)
        {
            Testing (etalon[i]);
        }
    }

    return 0;
}

