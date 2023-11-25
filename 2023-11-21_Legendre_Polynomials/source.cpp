#include<iostream>
using namespace std;
int main() {
	double irt(int,double);
	int n,x;
	cin >> n;
	cin >> x;
	cout << irt(n,x)<<endl;
	return 0;
}
double irt(int n, double x) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	else {
		x = ((2 * n - 1) * x *irt(n - 1, x) - (n - 1) * irt(n - 2, x) / n);
		return x;
	}
}
