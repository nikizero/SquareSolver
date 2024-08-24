/*!
\file
\brief Заголовочный файл с описанием типов данных и функций,
 используемых для утилитных функций

Данный файл содержит в себе определения необходимых типов данных и функций
для задания цвета вывода, режима работы и тд. используемых в util.cpp.
*/

#ifndef UTIL_INCLUDE
#define UTIL_INCLUDE

#include <unistd.h>
#include "solve.h"
#include <ncurses.h>

#define RED_COLOR               "\033[31m"
#define NO_COLOR                "\033[0m"
#define GREEN_COLOR             "\033[32m"
#define YELOW_COLOR             "\033[43m"
#define BLUE_COLOR              "\033[44m"
#define FIOLET_COLOR            "\033[45m"

/*!
	\brief enum, содержащий режим работы программы
*/

enum Modes
{
    TEST                 = 0,
    START                = 1,
};

/*!
	\brief enum, содержащий результат сравнения двух чисел
*/

enum CompareResult
{
    NON_EQUAL    = 0,
    EQUAL        = 1,
};


void                Input (double* coeff, const int number_coeff);
void                Itog(Solution answer);
void                ModeSwitch(Modes* Mode, const char* argv[], int argc);
CompareResult       compare(double a, double b);
#endif
