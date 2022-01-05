#ifndef __MY__MATH__H
#define __MY__MATH__H

#include <cstdio>
#include <cmath>

/********Options参数详解************
    a                   左区间
    b                   右区间
    x0                 x的初始值
    error_limit    误差限  
    cycle_limit    最大循环次数
    h                   求导时的步长
    show()          参数显示
******************************/
class Options {
public:
    double a = 0, b = 1;
    double x0 = 0;
    double error_limit = 0.000000001;
    double h = 0.0000001;
    int cycle_limit = 1000;

    void show();
};

typedef double (*func_p)(double x);//定义原函数指针 类型
typedef double (* func_iteration_p)(double x);//定义迭代函数指针 类型

//函数名：二分法
//   功能：在给定区间【a，b】上通过二分法求出近似解
//   输入：参数opt, 原函数func（必须设置opt.a和opt.b的值）
//   输出：最终的近似解x
double my_dichotomy(Options &opt, func_p func);

//函数名：一般迭代法
//   功能：通过给定的迭代公式和初值x0，不断迭代求取近似解x
//   输入：参数opt, 迭代函数func_interation（必须设置opt.x0的值）
//   输出：最终的近似解x
double my_iteration(Options &opt, func_iteration_p func_interation);

//函数名：牛顿迭代法
//   功能：通过给定的原函数和初始值x0，自动计算牛顿迭代公式，并不断迭代求取近似解x
//   输入：参数opt, 原函数func（必须设置opt.x0的值）
//   输出：最终的近似解x
double my_newton(Options &opt, func_p func);

#endif 
