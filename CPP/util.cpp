/*!
\file
\brief файл с описанием функций,
 используемых во вспомогательных операциях внутри функции main и др.

Под вспомогательными операциями имеется ввиду обработка ввода,
очистка буфера, выбор режима работы программы
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../include/util.h"

static void CleanBuf ();

/*!
Формирует вывод после решения уравнения о его конях
\param[in] answer структурная переменная, содержащая корни и количество решений
*/

void Itog(Solution answer)
{
    switch(answer.num_roots)
    {
        case NO_SOLUTIONS:      printf(FIOLET_COLOR"# No solutions \n" NO_COLOR);
            break;
        case ONE_ROOT:          printf(YELOW_COLOR "# x1 = %lf \n" NO_COLOR, answer.x1);
            break;
        case TWO_ROOTS:         printf(YELOW_COLOR "# x1 = %lf," BLUE_COLOR " x2 = %lf \n" NO_COLOR, answer.x1, answer.x2);
            break;
        case INFINITE_ROOTS:    printf(FIOLET_COLOR "# All real numbers \n" NO_COLOR);
            break;
    }
}

/*!
Очищает буфер до enter или конца файла
*/

static void CleanBuf ()
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
}

/*!
Обрабатывает ввод коэффицента уравнения. Если ввод неправильный,
очищает буфер, делает повторный запрос и вывод ошибку.
\param[out] x адресс поля структурной переменой, содержащей очередной коэффицент уравнения
*/

void Input (double* coeff, const int number_x)
{
    assert (coeff);

    int ch = 0;

    while (scanf("%lf", coeff) != 1 || (ch = getchar()) != '\n'|| ch == EOF)
    {
        CleanBuf();
        printf(RED_COLOR "#Print correct coeff\n" NO_COLOR);
    }

    if (number_x != 3)
    {
        printf(GREEN_COLOR "#Print next coeff\n" NO_COLOR);
    }
}

/*!
В зависимости от введеной командной переменной определяет режим работы и делает вывод
\param[in] argv массив строк, являющихся командными переменными
\param[in] argc количество командных перменных
\param[out] Mode адрес переменно, хранящей режим работы программы
*/

void ModeSwitch (Modes* Mode, const char** argv, int argc)
{
    assert(Mode);
    assert(argv);

    if (argc == 2)
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            printf(GREEN_COLOR "# if you want start programm in test mode use \"--test\" \n" NO_COLOR);
            printf(GREEN_COLOR "# if you want start programm in SolveSquare mode use \"--start\" \n" NO_COLOR);
        }
        else if (strcmp(argv[1],  "--test") == 0)
        {
            *Mode = TEST;
             printf("# Test mode acivated \n");
        }
        else if (strcmp(argv[1],  "--start") == 0)
        {
            *Mode = START;
            printf(GREEN_COLOR "# Print coef a, b and c in format: \na \nb \nc  \n" NO_COLOR);
        }
        else
        {
            fprintf(stderr, RED_COLOR "# ERROR: UNEXPECTED COMMAND \n if you want get all useful command use \"--help\" \n" NO_COLOR);
        }
    }
    else
    {
        fprintf(stderr, RED_COLOR "# ERROR: UNEXPECTED COMMAND \n #if you want get all useful command use \"--help\" \n" NO_COLOR);
    }
}

/*!
Сравнивает два double числа, также NAN методом сравнивания модули разности с
допустимой погрешностью эпсилон e
\param[in] a, b сравниваемые числа
\return возвращает результат сравнения
*/

CompareResult compare(double a, double b)
{
    const double epsilon = 1e-6;
    int StatNan_a = isnan(a);
    int StatNan_b = isnan(b);

    if (fabs(a - b) < epsilon || (StatNan_a == 1 && StatNan_b == 1))
    {
        return EQUAL;
    }
    else
    {
        return NON_EQUAL;
    }
}

void printing(char* strings[])
{
   double row = 0;
   double col = 0;

   initscr();
   getmaxyx(stdscr, row, col);
   Coord coord_ukaz = {0, row - 1, 0, 0};

   for (int i = 10; i >= 0; i--)
   {
        move(coord_ukaz.y_test, coord_ukaz.x_test);
        insnstr(strings[i], -1);
        move(coord_ukaz.y_progres, coord_ukaz.x_progres);
        printw("=");
        refresh();
        sleep(1);
        if (coord_ukaz.y_test <= coord_ukaz.y_progres - 3)
        {
            coord_ukaz.y_test++;
        }
        else
        {
            while (coord_ukaz.y_test>=0)
            {
                clrtoeol();
                move(coord_ukaz.y_test, coord_ukaz.x_test);
                coord_ukaz.y_test --;
            }
            coord_ukaz.y_test = 0;
            move(coord_ukaz.y_test, coord_ukaz.x_test);
            clrtoeol();
            refresh();
        }
   coord_ukaz.x_progres ++;
   };
   getch();
   endwin();
}
