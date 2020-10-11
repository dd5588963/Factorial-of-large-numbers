#include"class.h"
int main()
{
	Factorial test;
	int temp;
	cout << "请输入阶乘参数n：" << endl;
	cin >> temp;
	test.mul(temp);
	test.output();
	return 0;
}