#include<iostream>
#include"my_math.h"

using namespace std;

int choose() {
	int num=0;
	cout << "��ѡ������һ���㷨��\n���ַ���1\n��������2\nţ�ٷ���3\n";
	cin >> num;
	return num;
}

double my_func(double x) { return x * x - 2 * x - 3; }//ԭ���� f(x);
double func_iteration(double x) { return 2 + 3 / x; }//�������� g(x);

int main() {
	int mode = 0;
	double x_final;
	Options my_opt;

	mode = choose();//�㷨ѡ��

	//���ַ�
	if (mode == 1) {
		cout << "������߽�a,b" << endl;
		cin >> my_opt.a >> my_opt.b;
		x_final = my_dichotomy(my_opt,my_func);
	}
	//������
	if (mode == 2) {
		cout << "�������ֵX0" << endl;
		cin >> my_opt.x0;
		x_final = my_iteration(my_opt, func_iteration);
	}
	//ţ�ٷ�
	if (mode == 3) {
		cout << "�������ֵX0" << endl;
		cin >> my_opt.x0;
		x_final =my_newton(my_opt, my_func);
	}
	cout << "���ս⣺" << x_final;
	
	return 0;
}