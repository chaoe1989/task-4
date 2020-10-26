#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "task.h"
const int MAXSIZE = 100;
const double Max = 10 ^ -6;
using namespace std;

/*----------------函数定义-------------*/
//斐波那契数列
int Fib(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}

void Sequence(int argc, char const *argv[])
{
	for (int i = 1; i <= argc; i++)
	{
		cout << "Fib(" << i << ")" << "=" << Fib(i) << endl;
	}
}

//二分法求根
float Value(int m, float *e, float x)
{
	float v = 0;
	for (int i = 0; i < m + 1; i++)
	{
		v += e[i] * pow(x,i);
	}
	return v;
}

void Dichotomy(int m,float *e,float low, float high)
{
	float mid=(high+low)/2.0;
	
	while (fabs(low-high)>=1e-6)
	{
		mid = (high + low) / 2.0;
		cout << low <<" "<< mid <<" "<< high << endl;
		if (Value(m, e, mid)*Value(m,e,low) < 0)
			high = mid;
		else if (Value(m,e,mid)*Value(m,e,high)<0)
			low = mid;
	}
	if (Value(m, e, low) == 0)
		mid = low;
	if (Value(m, e, high) == 0)
		mid = high;
	cout << "the root is:" << mid << endl;
}

//猜数字游戏
void GuessNum(int num)
{
	int count = 1;
	int n;
	while (num>=0&&num<=100)
	{
		cout << "Guess a number:" << endl;
		cin >> n;
		if (n == num)
			break;
		    else if (n > num)
			    cout << "it is bigger than the answer!" << endl;
		    else
			   cout << "it is smaller than the answer!" << endl;
		    count++;
	} 
	cout << "you take " << count << " times to get the correct number" << endl;
}

//输入不符合规范时抛出异常
float checkAgeScore(int age, float score)
{
	if (age > 25 || age < 16)
		throw age;
	if (score < 0 || score > 5)
		throw score;
	return score * 20;
}