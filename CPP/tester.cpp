/*!
\file
\brief файл с описанием функций и типов данных,
 тестирующих программу
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../include/tester.h"
#include "../include/solve.h"
#include "../include/util.h"

static Res_Test Testing (Test* etalon);

/*!
Задает массив структурных перменных, содержащих данные UNIT теста.
Определяет количесвто переменных, отправляет в функцию тестинга Testing
*/

void StartTest ()
{

    Test etalon[] =
    {
        {1,   0,     0,    0,  NAN,       NAN,       INFINITE_ROOTS, FAIL, {0, 0, NO_SOLUTIONS}},
        {2,   1,     0,    0,  0,         NAN,       ONE_ROOT,       FAIL, {0, 0, NO_SOLUTIONS}},
        {3,   0,     2,   -1,  0.5,       NAN,       TWO_ROOTS,       FAIL, {0, 0, NO_SOLUTIONS}},
        {4,   1,     2,    1, -1,         NAN,       ONE_ROOT,       FAIL, {0, 0, NO_SOLUTIONS}},
        {5,   0,     1,    0,  0,         NAN,       TWO_ROOTS,       FAIL, {0, 0, NO_SOLUTIONS}},
        {6,   0,     0,    1,  NAN,       NAN,       NO_SOLUTIONS,   FAIL, {0, 0, NO_SOLUTIONS}},
        {7,   4,     3,    2,  NAN,       NAN,       NO_SOLUTIONS,   FAIL, {0, 0, NO_SOLUTIONS}},
        {8,   4,     3,   -1,  0.25,      -1,        TWO_ROOTS,      FAIL, {0, 0, NO_SOLUTIONS}},
        {9,   1,     2,    3,  NAN,       NAN,       NO_SOLUTIONS,   FAIL, {0, 0, NO_SOLUTIONS}},
        {10,  1,     0,   -4,  2,        -2,         TWO_ROOTS,      FAIL, {0, 0, NO_SOLUTIONS}},
        {11,  0,     0,   -4,  NAN,       NAN,       NO_SOLUTIONS,   FAIL, {0, 0, NO_SOLUTIONS}},
        {12,  0,     4,   -4,  1,         NAN,       ONE_ROOT,       FAIL, {0, 0, NO_SOLUTIONS}},
        {13,  0,     1,    0,  0,         NAN,       ONE_ROOT,       FAIL, {0, 0, NO_SOLUTIONS}},
        {14,  1,     1,    0,  0,         -1,        TWO_ROOTS,      FAIL, {0, 0, NO_SOLUTIONS}},
        {15,  1,     1,   -2,  1,         2,         TWO_ROOTS,      FAIL, {0, 0, NO_SOLUTIONS}},
        {16,  1e-3, -2e-3, 1,  NAN,       NAN,       NO_SOLUTIONS,   FAIL, {0, 0, NO_SOLUTIONS}},
        {17, -1e-2, -2e-3, 3, -17.330511, 17.39051, TWO_ROOTS,      FAIL, {0, 0, NO_SOLUTIONS}}
    };

    size_t numtests = sizeof(etalon) / sizeof(etalon[0]);

    for (size_t i = 0; i < numtests; i++)
    {
        Testing (&etalon[i]);
    };

    printing (etalon, numtests);
}

/*!
Проводит UNIT тест, сверяет эталон и вычисленное программой решение, выводит результат.
\param[in] etalon структурная переменная, содержащая правильные корни и количество решений, заданные UNIT тестом
\return возвращает результат теста
*/

static Res_Test Testing (Test* etalon)
{
    Quadr coefs     = {(*etalon).a, (*etalon).b, (*etalon).c};

    etalon -> res_of_solving.num_roots   = Solver (coefs, &(etalon -> res_of_solving));
    CompareResult compare_x1_res = compare (etalon -> res_of_solving.x1, (*etalon).x1right);
    CompareResult compare_x2_res = compare (etalon -> res_of_solving.x2, (*etalon).x2right);

    if (etalon -> res_of_solving.num_roots != (*etalon).numsolright || compare_x1_res == NON_EQUAL || compare_x2_res == NON_EQUAL)
    {
        etalon -> result_of_test = FAIL;
        return FAIL;
    }
    else
    {
        etalon -> result_of_test = PASS;
        return PASS;
    }
}
