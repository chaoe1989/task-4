#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include "task.h"
const int MAXSIZE = 100;
const double Max = 10 ^ -6;
using namespace std;

int main()
{
	cout << "please choose the function you want:" << endl;
	cout << "1:Output Fibonacci Sequence;" << endl;	
	cout << "2:Use the dichotomy to evaluate the root of the function;" << endl;
	cout << "3:Guess a number between 0 and 100;" << endl;
	cout << "4:Check the age and score then output the hundred-mark score;" << endl;
	int flag;
	cin >> flag;  //选择想要实现的功能
	switch (flag)
	{
	case 1:
	{   //采用动态内存分配空间的方法,计算斐波那契数列的前N项,并将其存储在动态分配空间中。
		int n;
		cout << "please input the N(<=100) you want, we will show you all the numbers before it:" << endl;
		cin >> n;
		int argc = n;
		int *foo;
		foo = new int[MAXSIZE];
		char const* argv[MAXSIZE];
		Sequence(argc, argv);
		delete []foo;
		break;
	}
	case 2:
	{   //采用二分方法计算函数f(x) = 0的根, 要求采用指针或引用实现, 精度误差控制在10^-6。
		int m;
		cout << "input the highest order of the function:" << endl;
		cin >> m;
		float *e = new float[m + 1];//指向各阶系数
		cout << "now,input all the coefficient of it(from x^0 to x^m):" << endl;
		for (int i = 0; i < m+1; i++)
			cin >> e[i];
		cout << "input the upper and lower limits:" << endl;
		float x1,x2;
		cin >> x1 >> x2;
		Dichotomy(m, e, x1, x2);
		break;
	}
	case 3:
	{   //猜数字游戏
		cout << "we have a number in the range of 0~100,guess it!" << endl;
		srand(time(0)); //time(0)返回值作种子
		int num;
		num = rand() % 100;
		GuessNum(num);
		break;
	}
	case 4:
	{   //检验输入的年龄和五级制成绩是否符合规范，并输出百分制成绩
		char name[MAXSIZE];
		int age;
		float score;
		cout << "input the name, age and the score of a student:" << endl;
		cin >> name;
        cin >> age >> score;
		try
		{
			cout << "the hundred-mark score is:" << checkAgeScore(age, score) << endl;
		}
		catch (int)
		{
			cout << "the age is not allowed!" << endl;
		}
		catch (float)
		{
			cout << "the score is not allowed!" << endl;
		}
	}
	}
		
	system("pause");
	return 0;
}