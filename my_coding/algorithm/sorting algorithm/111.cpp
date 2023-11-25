#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int x, a=1;
    double b=0.0;
	cout << "input the x:";
	cin >> x;
		for (int n=1 ; n <= 10; n+=2)
		{
			for (int i =1; i <= n; i++)
			{
				a *= i;//a为阶乘
			}
			double p = pow(-1, (n - 1)/2), q = pow(x,n);//p为符号
            double mid=p * q / (double)a;
			b += mid;
		}
		cout << "the sinx is:" <<setprecision(3)<< b;
}
