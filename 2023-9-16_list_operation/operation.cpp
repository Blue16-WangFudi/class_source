#include "operation.h"

Student::Student()
{
	head = new Node;
	head->next = nullptr;
	head->data = 0;

	//修改1:head_1未初始化，必须先初始化
	head_1 = new Node;
	head_1->next = nullptr;
	head_1->data = 0;
}

Student::~Student()
{
	delete head;//修改2:你这个释放有点水了，直接删除头节点，不管其他东西了？这会导致内存泄露。
	//修改2：写一个循环，直接释放整个链表
}

void Student::InPut()
{
	Node* work=head;
	while (1) {
		Node* store = new Node;
		int i = 0;
		cin >> i;
		if (i == 0) {
			delete store;
			break;
		}
		//储存数据
		store->data = i;
		//链接数据结点
		store->next = work->next;
		work->next = store;
		//工作指针顺移
		work = work->next;
		count++;
	}
}

void Student::InPut_1()//实际调用的是这个
{
	Node* work = head;
	Node* work_1 = head_1;
	int a[] = { 1,21,35,46,54,127 };
	int b[] = { 2,3,3,35,35,64,128,259};//修改：不用写数目，编译器会自动计算
	for (int i = 0; i < 6;i++) {//储存第一个链表
		Node* store = new Node;
		//储存数据
		store->data = a[i];
		//链接数据结点
		store->next = work->next;
		work->next = store;
		//工作指针顺移
		work = work->next;
		count++;
	}
	for (int i = 0; i < 8; i++) {//储存第二个链表
		Node* store = new Node;
		//储存数据
		store->data = b[i];
		//链接数据结点
		store->next = work_1->next;
		work_1->next = store;
		//工作指针顺移
		work_1 = work_1->next;
		count1++;
	}
}

void Student::OutPut()//输出全局链表
{
	Node* work = head;
	//for (int i = 0; i < count; i++) {
	//	work = work->next;
	//	cout <<work->data << endl;
	//}
	//推荐的写法：
	while (work->next != nullptr)
	{
		work = work->next;
		cout << work->data << "\t";
	}
	cout << endl;
}

void Student::insert()//将head_1插入到head中，因为输出的是head链表
{
	/*
	Node* temp = head->next;
	Node* temp_1;

	for (int i = 0; i < round(count / 2) - 1; i++) {
		Node* store = head->next;
		temp_1 = temp;
		for (int m = 1; m < count - 1; m++) {
			store = store->next;
		}
		Node* store_1 = store->next;
		temp = temp->next;
		store->next = nullptr;
		temp_1->next = store_1;
		store_1->next = temp;

	}
	*/
	/*
	//试试直接插入，就是追加到后面了
	Node *work=head;//存放遍历的节点，直到最后一个
	while (work->next != nullptr)//先找到head链表的最后一个节点的指针
	{
		work = work->next;
	}
	work->next = head_1->next;
	*/
	//正式的插入,其实我一直在读你的代码，但是我没找到有些操作（或许和我的思路不一样），
	// 因此我重写了一个算法，你看看行不（我也在学数据结构与算法，也不是很精通，估计不是最优解）
	Node* work=head;
	Node* work_1 = head_1;
	work_1 = work_1->next;
	cout << "初始链表:" << endl;
	OutPut();
	while (work_1 != nullptr)//遍历head_1，一个一个插入到head中；O(n^2)
	{
		work = head;//重置head链表读取位置
		while (work->next != nullptr)//这一层循环是遍历head链表，进行比较
		{
			work = work->next;
			if (work_1->data >= work->data )
			{
				if (work->next == nullptr || work_1->data <= work->next->data)
				{
					cout << "链表插入元素:" << work_1->data << endl;
					Node* temp = work->next;//保存操作节点work指向的下一个节点的指针
					Node* temp_2 = work_1->next;//保存work_1指向的下一个节点的指针

					work->next = work_1;//让work的next指向work_1
					work_1->next = temp;//让work_1指向work之前指向的下一个节点的指针

					work_1 = temp_2;//让work_1变成head_1中的下一个节点
					OutPut();
					break;//插入完成，跳出head的遍历
				}

			}
				
		}
	}
}

void Student::inversion()//倒转？？
{
	/*
	Node* temp = head;
	Node* work ;//当前正在处理的node
	for (int i = 0; i < count1;i++) {
		if (head_1->next == nullptr)//读取到链表尾部
			break;
		work = head_1->next;
		head_1->next = head_1->next->next;//把下一个链接到上一个
		while(1) {
			if (temp->next->data >= work->data) {
				work->next = temp->next;
				temp->next = work;
			}
			else {
				temp = temp->next;
			}
			if (temp == nullptr)
				break;
		}
	}
	Node* t = head->next;
	Node* t1;
	head->next = nullptr;
	while (t != nullptr) {
		t1 = t;
		t = t->next;
		t1->next = head->next;
		head->next = t1;
	}
	*/
	//目前我从小到大排序完成了，现在是让它反转：根据题目要求，直接改地址
	Node* pre = nullptr;
	Node* cur = head;
	while (cur)
	{
		Node* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	Node* temp = new Node;
	temp->next = pre;
	head = temp;
	
}
void Student::order()
{
	int i = 0;
	Node* loacte = head->next;
	Node* temp = head->next;
	Node* temp_1;
	head->next = nullptr;
	while (temp != nullptr) {
		temp_1 = temp;

		if (temp_1->next == nullptr)
			break;
		else
			temp_1 = temp_1->next;

		if (temp_1->data > 0) {
			temp = temp->next;
		}
		else {
			temp->next = temp->next->next;
			temp_1->next = head->next;
			head->next = temp_1;
			i++;
		}
	}
	Node* newtemp = head;
	for (int m = 0; m < i; m++) {
		newtemp = newtemp->next;
	}
	newtemp->next = loacte;
}

