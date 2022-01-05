#ifndef __MY__MATH__H
#define __MY__MATH__H

#include <cstdio>
#include <cmath>

/********Options�������************
    a                   ������
    b                   ������
    x0                 x�ĳ�ʼֵ
    error_limit    �����  
    cycle_limit    ���ѭ������
    h                   ��ʱ�Ĳ���
    show()          ������ʾ
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

typedef double (*func_p)(double x);//����ԭ����ָ�� ����
typedef double (* func_iteration_p)(double x);//�����������ָ�� ����

//�����������ַ�
//   ���ܣ��ڸ������䡾a��b����ͨ�����ַ�������ƽ�
//   ���룺����opt, ԭ����func����������opt.a��opt.b��ֵ��
//   ��������յĽ��ƽ�x
double my_dichotomy(Options &opt, func_p func);

//��������һ�������
//   ���ܣ�ͨ�������ĵ�����ʽ�ͳ�ֵx0�����ϵ�����ȡ���ƽ�x
//   ���룺����opt, ��������func_interation����������opt.x0��ֵ��
//   ��������յĽ��ƽ�x
double my_iteration(Options &opt, func_iteration_p func_interation);

//��������ţ�ٵ�����
//   ���ܣ�ͨ��������ԭ�����ͳ�ʼֵx0���Զ�����ţ�ٵ�����ʽ�������ϵ�����ȡ���ƽ�x
//   ���룺����opt, ԭ����func����������opt.x0��ֵ��
//   ��������յĽ��ƽ�x
double my_newton(Options &opt, func_p func);

#endif 
