/*!
\file
\brief файл с описанием функций,
 используемых для решения заданных уравнений

В этом файле описаны функции для получения решений квадратного
или линейного уравнения, а также для распознования типа заданного уравнения
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../include/solve.h"
#include "../include/util.h"

static Roots SolveSquare (Quadr coefs, Solution* answer);
static Roots SolveLinear (Quadr coefs, Solution* answer);


/*!
Проверяет введеные коэффиценты уравнения, определяет тип введеного уравнения.
 В зависимости от типа уравнения, запускает функцию по его решению
\param[in] coefs структурная переменная, содержащая коэффиценты уравнения
\param[out] answer структурная переменная, в которую запишется решение
\return возвращает количество решений
*/

Roots Solver(Quadr coefs, Solution* answer)
{
    assert(answer);
    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    answer -> x1 = NAN;
    answer -> x2 = NAN;

    if (coefs.a == 0)
    {
        return SolveLinear (coefs, answer);
    }
    else
    {
        return SolveSquare (coefs, answer);
    }
}

/*!
Решает линейное уравнеиние
\param[in] coefs структурная переменная, содержащая коэффиценты уравнения
\param[out] answer структурная переменная, в которую запишется решение
\return возвращает количество решений
*/

static Roots SolveLinear (Quadr coefs, Solution* answer)
{
    assert(answer);

    if (compare (coefs.b, 0) == EQUAL)
    {
        if (compare (coefs.c, 0) ==  EQUAL)
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

/*!
Решает квадратное уравнеиние через дискриминант
\param[in] coefs структурная переменная, содержащая коэффиценты уравнения
\param[out] answer структурная переменная, в которую запишется решение
\return возвращает количество решений
*/

static Roots SolveSquare (Quadr coefs, Solution* answer)
{
    assert (answer);

    double D = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
    double Sqrt_D = sqrt(D);

    if (D < 0)
    {
        return NO_SOLUTIONS;
    }
    else if (compare(D, 0) == EQUAL)
    {
        answer -> x1 = -coefs.b / (2 * coefs.a);
        return ONE_ROOT;
    }
    else
    {
        answer -> x1 = (-coefs.b + Sqrt_D) / (2 * coefs.a);
        answer -> x2 = (-coefs.b - Sqrt_D) / (2 * coefs.a);
        return TWO_ROOTS;
    }
}

