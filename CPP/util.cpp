/*!
\file
\brief Исполняемый файл с описанием функций,
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

/*!
Формирует вывод после решения уравнения о его конях
\param[in] answer структурная переменная, содержащая корни и количество решений
*/

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

/*!
Очищает буфер до enter или конца файла
*/

void CleanBuf ()
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
}

/*!
 Обрабатывает ввод коэффицента уравнения. Если ввод неправильный,
очищает буфер, делает повторный запрос и вывод ошибку.
\param[in] coeff адресс поля структурной переменой, содержащей очередной коэффицент уравнения
*/

void Input (double* coeff)
{
    assert (coeff);

    while (scanf("%lf", coeff) != 1)
    {
        CleanBuf();
        printf(RED_COLOR "#Print correct coeff\n" NO_COLOR);
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
    if (argc == 2)
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            printf(GREEN_COLOR "# if you want start programm in test mode use \"--test\" \n" NO_COLOR); //Как тут сделать вывод двух строк нормальный
            printf(GREEN_COLOR "# if you want start programm in SolveSquare mode use \"--start\" \n" NO_COLOR); // stderr, stdin, stdout, прочитать про логи и перенаправление потоков вывода
        }
        else if (strcmp(argv[1],  "--test") == 0)
        {
            *Mode = TEST;
             printf("# Test mode acivated \n");
        }
        else if (strcmp(argv[1],  "--start") == 0)
        {
            *Mode = START;
            printf(GREEN_COLOR "# Print coef a, b and c in format \"a b c\" \n" NO_COLOR);
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
\param[out] Mode адрес переменно, хранящей режим работы программы
\return возвращает результат сравнения
*/

CompareResult compare(double a, double b)
{
    double e = 0.0000001;
    int StatNan_a = isnan(a);
    int StatNan_b = isnan(b);

    if (fabs(a - b) < e || (StatNan_a == 1 && StatNan_b == 1))
    {
        return EQUAL;
    }
    else
    {
        return NON_EQUAL;
    }
}
