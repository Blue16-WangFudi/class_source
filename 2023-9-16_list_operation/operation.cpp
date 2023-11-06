#include "operation.h"

Student::Student()
{
	head = new Node;
	head->next = nullptr;
	head->data = 0;

	//�޸�1:head_1δ��ʼ���������ȳ�ʼ��
	head_1 = new Node;
	head_1->next = nullptr;
	head_1->data = 0;
}

Student::~Student()
{
	delete head;//�޸�2:������ͷ��е�ˮ�ˣ�ֱ��ɾ��ͷ�ڵ㣬�������������ˣ���ᵼ���ڴ�й¶��
	//�޸�2��дһ��ѭ����ֱ���ͷ���������
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
		//��������
		store->data = i;
		//�������ݽ��
		store->next = work->next;
		work->next = store;
		//����ָ��˳��
		work = work->next;
		count++;
	}
}

void Student::InPut_1()//ʵ�ʵ��õ������
{
	Node* work = head;
	Node* work_1 = head_1;
	int a[] = { 1,21,35,46,54,127 };
	int b[] = { 2,3,3,35,35,64,128,259};//�޸ģ�����д��Ŀ�����������Զ�����
	for (int i = 0; i < 6;i++) {//�����һ������
		Node* store = new Node;
		//��������
		store->data = a[i];
		//�������ݽ��
		store->next = work->next;
		work->next = store;
		//����ָ��˳��
		work = work->next;
		count++;
	}
	for (int i = 0; i < 8; i++) {//����ڶ�������
		Node* store = new Node;
		//��������
		store->data = b[i];
		//�������ݽ��
		store->next = work_1->next;
		work_1->next = store;
		//����ָ��˳��
		work_1 = work_1->next;
		count1++;
	}
}

void Student::OutPut()//���ȫ������
{
	Node* work = head;
	//for (int i = 0; i < count; i++) {
	//	work = work->next;
	//	cout <<work->data << endl;
	//}
	//�Ƽ���д����
	while (work->next != nullptr)
	{
		work = work->next;
		cout << work->data << "\t";
	}
	cout << endl;
}

void Student::insert()//��head_1���뵽head�У���Ϊ�������head����
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
	//����ֱ�Ӳ��룬����׷�ӵ�������
	Node *work=head;//��ű����Ľڵ㣬ֱ�����һ��
	while (work->next != nullptr)//���ҵ�head��������һ���ڵ��ָ��
	{
		work = work->next;
	}
	work->next = head_1->next;
	*/
	//��ʽ�Ĳ���,��ʵ��һֱ�ڶ���Ĵ��룬������û�ҵ���Щ������������ҵ�˼·��һ������
	// �������д��һ���㷨���㿴���в�����Ҳ��ѧ���ݽṹ���㷨��Ҳ���Ǻܾ�ͨ�����Ʋ������Ž⣩
	Node* work=head;
	Node* work_1 = head_1;
	work_1 = work_1->next;
	cout << "��ʼ����:" << endl;
	OutPut();
	while (work_1 != nullptr)//����head_1��һ��һ�����뵽head�У�O(n^2)
	{
		work = head;//����head�����ȡλ��
		while (work->next != nullptr)//��һ��ѭ���Ǳ���head�������бȽ�
		{
			work = work->next;
			if (work_1->data >= work->data )
			{
				if (work->next == nullptr || work_1->data <= work->next->data)
				{
					cout << "�������Ԫ��:" << work_1->data << endl;
					Node* temp = work->next;//��������ڵ�workָ�����һ���ڵ��ָ��
					Node* temp_2 = work_1->next;//����work_1ָ�����һ���ڵ��ָ��

					work->next = work_1;//��work��nextָ��work_1
					work_1->next = temp;//��work_1ָ��work֮ǰָ�����һ���ڵ��ָ��

					work_1 = temp_2;//��work_1���head_1�е���һ���ڵ�
					OutPut();
					break;//������ɣ�����head�ı���
				}

			}
				
		}
	}
}

void Student::inversion()//��ת����
{
	/*
	Node* temp = head;
	Node* work ;//��ǰ���ڴ����node
	for (int i = 0; i < count1;i++) {
		if (head_1->next == nullptr)//��ȡ������β��
			break;
		work = head_1->next;
		head_1->next = head_1->next->next;//����һ�����ӵ���һ��
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
	//Ŀǰ�Ҵ�С������������ˣ�������������ת��������ĿҪ��ֱ�Ӹĵ�ַ
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

