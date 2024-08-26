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
Сравнивает два double числа методом сравнивания модули разности с
допустимой погрешностью эпсилон e, также выдает равенство, если оба NAN
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

/*!
Управляет печатью проведённых тестов, запускает progress bar
\param[in] all_tests[] список с результатами всех тестов
\param[in] numtests вводит количество тестов
\return возвращает результат сравнения
*/

void printing(Test all_tests[], size_t numtests)
{
   double row = 0;
   double col = 0;

   initscr();
   getmaxyx(stdscr, row, col);
   Coord coord_ukaz = {0, row - 1, 0, 0};

   move(coord_ukaz.y_progres, coord_ukaz.x_progres);
   printw("[");
   move(coord_ukaz.y_progres, coord_ukaz.x_progres + numtests + 1);
   printw("]");
   coord_ukaz.x_progres = 1;

   for (size_t i = numtests; i > 0; i--)
   {
        int num_test_printing = numtests - i;

        move(coord_ukaz.y_test, coord_ukaz.x_test);

        if (all_tests[num_test_printing].result_of_test == PASS)
        {
            right_printing(all_tests[num_test_printing]);
        }
        else
        {
            failed_printing(all_tests[num_test_printing]);
            refresh();
            sleep(3);
            coord_ukaz.y_test = coord_ukaz.y_test + 3 ;
        }

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
            sleep(1);
            while (coord_ukaz.y_test>=0)
            {
                move(coord_ukaz.y_test, coord_ukaz.x_test);
                coord_ukaz.y_test --;
                clrtoeol();
            }
            coord_ukaz.y_test = 0;
            move(coord_ukaz.y_test, coord_ukaz.x_test);
            refresh();
        }
        coord_ukaz.x_progres ++;
   }
   getch();
   endwin();
}

/*!
Распечатывает заданный правильный тест
\param[in] etalon один из тестов из списка
*/

void failed_printing(Test etalon)
{
    if (etalon.TestNum > 9)
    {
        char probel_opt = ' ';
    }
    else
    {
        char probel_opt = '';
    }

    printw("----------------------------------------------------------------------------------------------------------------------\n"
           "Test N %d Failed:  a = %+lf, b = %+lf, c = %+lf, x1      = %+lf, x2      = %+lf, num_roots   = %d\n"
           "Right Test:                                             %c       x1right = %+lf, x2right = %+lf, numsolright = %d \n"
           "----------------------------------------------------------------------------------------------------------------------\n",
            etalon.TestNum, etalon.a, etalon.b, etalon.c, etalon.res_of_solving.x1, etalon.res_of_solving.x2,
            etalon.res_of_solving.num_roots, probel_opt,etalon.x1right,
            etalon.x2right, etalon.numsolright);
}

/*!
Распечатывает заданный неправильный тест
\param[in] etalon один из тестов из списка
*/

void right_printing(Test etalon)
{
    printw("Test N %d correct \n", etalon.TestNum);
}
