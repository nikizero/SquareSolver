/*!
\file
\brief файл с функцией,
 управляющей взаимной работой всех остальных функций,
в зависимости от режима работы программы
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../include/solve.h"
#include "../include/tester.h"
#include "../include/util.h"

/*!
Управляет ходом прогрммы, в зависимости от консольных параметров (тестового режима или режима решения)
\param[in] argс Количество консольных параметров
\param[in] argv Массив консольных параметров, массив указателей на первый символ строк (массив строк).
argv[1] используется для выбора режима запуска --test или --start
*/

int main(int argc, const char** argv)
{
    Modes Mode = TEST;
    ModeSwitch(&Mode, argv, argc);

    if (Mode == START)
    {                                                                           // stderr, stdin, stdout, прочитать про логи и перенаправление потоков вывода
        struct Quadr coefs = {0, 0, 0};                                         // Можно было задать как Quadr coefs = {.a = 0,.b = 0,.c = 0}
        struct Solution answer = {0, 0, NO_SOLUTIONS};

        Input (&coefs.a);
        Input (&coefs.b);
        Input (&coefs.c);
        answer.num_roots = Solver (coefs, &answer);
        Itog (answer);
    }
    else if (Mode == TEST)
    {
        StartTest();
    }

    return 0;
}
