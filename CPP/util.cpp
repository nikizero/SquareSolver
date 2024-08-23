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
void ModeSwitch (Modes* Mode,  char* argv[1], int argc)
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "--Help") == 0)
        {
            fprintf(stderr, "if you want start programm in test mode use \"--Test\" \n"); //Как тут сделать вывод двух строк нормальный
            printf("if you want start programm in SolveSquare mode use \"--Start\" \n"); // stderr, stdin, stdout
        }
        else if (strcmp(argv[1],  "--Test") == 0)
        {
            *Mode = TEST;
        }
        else if (strcmp(argv[1],  "--Start") == 0)
        {
            *Mode = START;
        }
        else
        {
            printf("EROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--Hellp\" \n");
        }
    }
    else
    {
        printf("EROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--Hellp\" \n");
    }
}
