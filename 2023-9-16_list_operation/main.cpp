#include <iostream>
#include <cmath>
#include "operation.h"

using namespace std;

int main() {
	Student list;
	
	//list.InPut();
	//list.insert();


	//�㷨˼·���Ȱ�һ��������һ����Ȼ��ת�������������⣺insert()ò��û�в���ɹ���
	// inversion()���ִ���
	list.InPut_1();
	//cout << "1st" << endl;
	list.insert();
	//cout << "2rd" << endl;
	list.inversion();
	//cout << "3th" << endl;
	cout << "���" << endl;
	list.OutPut();
	//cout << "4th" << endl;
	

    return 0;

}
