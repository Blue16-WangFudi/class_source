#include "operation.h"
int main() {
	char a;
	operation list;
	list.InPut();//��������

	//�û����������ַ�
	std:: cout << "����0�������̲���ʾ���" << '\n' << "������abcdef�������ַ�" << endl;
	while (1) {
		cin >> a;
		//�ж��ַ��Ƿ�Ϲ�
		if (a == '0')
			break;//��������
		else {
			switch (a) {
			case 'a':
				list.locate('a');
				break;
			case 'b':
				list.locate('b');
				break;
			case 'c':
				list.locate('c');
				break;
			case 'd':
				list.locate('d');
				break;
			case 'e':
				list.locate('e');
				break;
			case 'f':
				list.locate('f');
				break;
			}
		}
	}
	std::cout << "չʾ�������ݣ�" << endl;
	list.OutPut();

	return 0;
}