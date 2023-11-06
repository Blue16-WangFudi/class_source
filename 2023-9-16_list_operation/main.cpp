#include <iostream>
#include <cmath>
#include "operation.h"

using namespace std;

int main() {
	Student list;
	
	//list.InPut();
	//list.insert();


	//算法思路：先把一个插入另一个，然后反转，最后输出。问题：insert()貌似没有插入成功。
	// inversion()出现错误
	list.InPut_1();
	//cout << "1st" << endl;
	list.insert();
	//cout << "2rd" << endl;
	list.inversion();
	//cout << "3th" << endl;
	cout << "结果" << endl;
	list.OutPut();
	//cout << "4th" << endl;
	

    return 0;

}
