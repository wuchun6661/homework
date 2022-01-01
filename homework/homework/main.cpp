#include<iostream>
#include"my_math.h"

using namespace std;

int choose() {
	int num=0;
	cout << "请选择其中一种算法：\n二分法：1\n迭代法：2\n牛顿法：3\n";
	cin >> num;
	return num;
}

double my_func(double x) { return x * x - 2 * x - 3; }//原函数 f(x);
double func_iteration(double x) { return 2 + 3 / x; }//迭代函数 g(x);

int main() {
	int mode = 0;
	double x_final;
	Options my_opt;

	mode = choose();//算法选择

	//二分法
	if (mode == 1) {
		cout << "请输入边界a,b" << endl;
		cin >> my_opt.a >> my_opt.b;
		x_final = my_dichotomy(my_opt,my_func);
	}
	//迭代法
	if (mode == 2) {
		cout << "请输入初值X0" << endl;
		cin >> my_opt.x0;
		x_final = my_iteration(my_opt, func_iteration);
	}
	//牛顿法
	if (mode == 3) {
		cout << "请输入初值X0" << endl;
		cin >> my_opt.x0;
		x_final =my_newton(my_opt, my_func);
	}
	cout << "最终解：" << x_final;
	
	return 0;
}