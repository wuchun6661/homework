//作者：wcy
//时间：2021/12/23
#include "my_math.h"

//Options类的方法定义
void Options::show(){
    printf("a\t%f\n  b\t%f\n  x0\t%f\n  error_limit\t%f\n  cycle_limit\t%d\n  ", a, b, x0, error_limit, cycle_limit);
}

double my_dichotomy(Options &opt, func_p func){
    double a = opt.a;
    double b = opt.b;
    double error_limit = opt.error_limit;
    int cycle_limit = opt.cycle_limit;
    double middle;
    double last_middle;
    int i = 0;

    if (func(a) * func(b) < 0) {
        middle = (a + b) / 2;
        last_middle = a;
        while (fabs(middle - last_middle) > error_limit) {
             func(middle)* func(a) > 0 ? a = middle : b = middle;
             last_middle = middle;
             middle = (a + b) / 2;
             i++;
             if (i > cycle_limit) {
                 return -1.0;
             }
         }
         return middle;
    }
}

double my_iteration(Options &opt, func_iteration_p func_interation) {
    double x0 = opt.x0;
    double error_limit =opt.error_limit;
    int cycle_limit = opt.cycle_limit;
    int i = 0;
    double x;

    while (i < cycle_limit) {
        x = func_interation(x0);
        if (fabs(x - x0) < error_limit) {
            return x;
        }
        i++;
        x0 = x;
     }
    return -1.0;
}

double my_newton(Options &opt, func_p func){
    double error_limit = opt.error_limit;
    int cycle_limit = opt.cycle_limit;
    double x0 = opt.x0;
    double h = opt.h;
    int i = 0;
    double x;

    while (i < cycle_limit) {
        x = x0 - func(x0) / (func(x0 + h) - func(x0 - h)) / 2*h;
        if (fabs(x - x0) < error_limit) {
            return x;
        }
        i++;        
        x0 = x;
    }    
    return -1.0;
}