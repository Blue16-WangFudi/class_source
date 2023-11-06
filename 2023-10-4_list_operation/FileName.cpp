#include "operation.h"
int main() {
	char a;
	operation list;
	list.InPut();//输入数据

	//用户输入所需字符
	std:: cout << "输入0结束进程并显示结果" << '\n' << "请输入abcdef中任意字符" << endl;
	while (1) {
		cin >> a;
		//判断字符是否合规
		if (a == '0')
			break;//结束进程
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
	std::cout << "展示最终数据：" << endl;
	list.OutPut();

	return 0;
}