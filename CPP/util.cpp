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
    return 0;
}

void ModeSwitch (Modes* Mode, const char** argv, int argc)
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            fprintf(stderr, "if you want start programm in test mode use \"--test\" \n"); //Как тут сделать вывод двух строк нормальный
            printf("if you want start programm in SolveSquare mode use \"--start\" \n"); // stderr, stdin, stdout, прочитать про логи и перенаправление потоков вывода
        }
        else if (strcmp(argv[1],  "--test") == 0)
        {
            *Mode = TEST;
        }
        else if (strcmp(argv[1],  "--start") == 0)
        {
            *Mode = START;
        }
        else
        {
            printf("ERROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--help\" \n");
        }
    }
    else
    {
        printf("ERROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--help\" \n");
    }
}
