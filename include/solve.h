/*!
\file
\brief Заголовочный файл с описанием классов,
 используемых для обработки квадратного уравнения

Данный файл содержит в себе определения стуктур, необходимых для задания
коэффицентов и решений квадратного уравнения, используемых в solve.cpp.
*/

#ifndef SOLVE_INCLUDE
#define SOLVE_INCLUDE

enum Roots
{
    NO_SOLUTIONS    = 0,
    ONE_ROOT        = 1,
    TWO_ROOTS       = 2,
    INFINITE_ROOTS  = 3,
};


struct Quadr
{
  double a;
  double b;
  double c;
};

struct Solution
{
    double x1;
    double x2;
    Roots num_roots;
};

Roots Solver       (Quadr coefs, Solution* answer);
Roots SolveLinear  (Quadr coefs, Solution* answer);
Roots SolveSquare  (Quadr coefs, Solution* answer);
#endif
