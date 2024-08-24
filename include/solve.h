/*!
\file
\brief Заголовочный файл с описанием типов данных и функций,
 используемых для обработки квадратного уравнения

Данный файл содержит в себе определения стуктур, необходимых для задания
коэффицентов и решений квадратного уравнения, используемых в solve.cpp.
*/

#ifndef SOLVE_INCLUDE
#define SOLVE_INCLUDE

/*!
	\brief enum, содержащий количество корней заданного уравнения
*/
enum Roots
{
    NO_SOLUTIONS    = 0,
    ONE_ROOT        = 1,
    TWO_ROOTS       = 2,
    INFINITE_ROOTS  = 3,
};

/*!
	\brief структура, содержащая коэффиценты заданного уравнения
*/

struct Quadr
{
  double a;
  double b;
  double c;
};

/*!
	\brief структура, содержащая решения заданного уравнения и количество его решений
*/
struct Solution
{
    double x1;
    double x2;
    Roots num_roots;
};

Roots Solver       (Quadr coefs, Solution* answer);
#endif
