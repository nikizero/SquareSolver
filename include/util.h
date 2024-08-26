/*!
\file
\brief Заголовочный файл с описанием типов данных и функций,
 используемых для утилитных функций

Данный файл содержит в себе определения необходимых типов данных и функций
для задания цвета вывода, режима работы и тд. используемых в util.cpp.
*/

#ifndef UTIL_INCLUDE
#define UTIL_INCLUDE

#include "solve.h"
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

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
    UNExPECTED_COMMAND   = 3
};

/*!
	\brief enum, содержащий результат сравнения двух чисел
*/

enum CompareResult
{
    NON_EQUAL    = 0,
    EQUAL        = 1,
};

struct Coord
{
    double x_progres;
    double y_progres;
    double x_test;
    double y_test;
};

void                Input (double* x, const int number_x);
void                Itog(Solution answer);
void                printing(char* strings[]);
void                ModeSwitch(Modes* Mode, const char* argv[], int argc);
CompareResult       compare(double a, double b);
#endif
