/*!
\file
\brief Заголовочный файл с описанием классов, используемых для тестисрования программы

Данный файл содержит в себе определения необходимых классов для задания
парметров UNIT тестирования программы. используемых в tester.cpp.
*/

#ifndef TESTER_INCLUDE
#define TESTER_INCLUDE
#include "solve.h"

enum Res_Test
{
    FAIL        = 0,
    PASS        = 1,
};

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

Res_Test           Testing (Test etalon);
void               StartTest ();
#endif
