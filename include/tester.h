/*!
\file
\brief Заголовочный файл с описанием типов данных и функций,
 используемых для тестирования программы

Данный файл содержит в себе определения необходимых типов данных для задания
параметров UNIT тестирования программы. используемых в tester.cpp.

\mainpage

*/

#ifndef TESTER_INCLUDE
#define TESTER_INCLUDE

#include "solve.h"

/*!
	\brief enum, содержащий результат прохождения UNIT теста
*/

enum Res_Test
{
    FAIL        = 0,
    PASS        = 1,
};

/*!
	\brief структура, содержащая данные для прохождения UNIT теста
*/

struct Test
{
    int TestNum;
    double a;
    double b;
    double c;
    double x1right;
    double x2right;
    Roots numsolright;
};

void               StartTest ();
#endif
