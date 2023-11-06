#include "operation.h"

operation::operation()
{
	head = new Node;
	head->next = nullptr;
	head->data = NULL;
}

operation::~operation()
{
	//�ͷ�
	Node* p = head;
	while (p) {
		Node* q = p;
		p = p->next;
		delete q;
	}
}

void operation::locate(char x)
{
	//����Ѱ��λ��,��ʹƵ�ȼ�һ
	Node* temp = head;
	for (int i = 0; i <=count; i++) {
		//������Ҳд���ˣ���С�ڵ��ڣ�Ҫ��Ȼf�����Ѳ���
		//Ϊʲô����Ϊ�������˻��и�ͷ�ڵ�head
		//??��û�������ôд��ԭ�����������temp����ô���õ�temp->next�ˣ�
		/*
		if (temp->next->data == x) {
			temp->next->rate++;
			temp = temp->next;
			cout << "�ҵ���" << endl;
		}
		else
			continue;
		*/
		
		if (temp->data == x)
		{
			temp->rate++;
			//cout << "�ҵ���"<<"@"<<temp->rate << endl;
			//OutPut();
			break;//��ʱ��tempͣ���ҵ��˵�λ�ã�Ȼ��һֱ��ǰ����
		}
		temp = temp->next;
	}
	


	//���н�㽻��������Ƶ����������
	//�������������д�ģ�ÿ����һ�Σ�����һ����
	/*������ԣ��������Ƴ����˼·����û��ȫ�Ƴ�������������д��
	while (temp != nullptr) {
		Node* temp_1 = temp->prior;//temp1=B��temp1->prior=A
		if (temp_1 == nullptr)//��Ѱ�ַ����ڵ�һλ
			break;
		else if (temp->next != nullptr)//��Ѱ�ַ�λ���м�
		{
			if(temp->rate >= temp_1->rate){//temp����ǰһ������
			//����A����Aָ��temp
			temp_1->prior->next = temp;
			//����temp����tempǰָ��A
			temp->prior = temp_1->prior;
			//����B����B��ָ��temp����һ��
			temp_1->next = temp->next;
			//����temp��һ��Ԫ�أ�����ǰָ��B
			temp->next->prior = temp_1;
			//����temp,��temp��ָ��B
			temp->next = temp_1;
			//����B����Bǰָ��temp
			temp_1->prior = temp;
			//�ƶ�ָ�룬��ǰ��
			temp = temp->prior; 
			
			}
		}
		else//��Ѱ�ַ�λ�����һλ
		{
			temp->prior = temp_1->prior;
			temp->next = temp_1;
			temp_1->prior->next = temp;
			temp_1->prior = temp;
			temp_1->next = nullptr;
			temp = temp->prior;
		}
	}
	*/
	//OutPut();
	move_ahead(temp);

}

void operation::OutPut()
{
	Node* work = head;
	
	while (work->next != nullptr)
	{
		work = work->next;
		cout << work->data <<"@" << work->rate << "\t";
	}
	cout << endl;
}

void operation::move_ahead(Node* cur)
{
	head->rate = 999;//����һ���ǳ����������������
	while (true)
	{
		if (cur->prior == nullptr)//cur��ͷ����̫���ܣ���Ϊ��head��
			break;
		if (cur->prior->prior == nullptr)//head cur�������
			break;
		else// head A cur�������,�����պ��ܶ�ȡ������Ԫ�رȽ�
		{
			while (true)
			{
				if (cur->prior->rate >= cur->rate)
				{
					break;
				}
				if (cur->prior->rate <= cur->rate)
				{
					swap_node(cur->prior, cur);//ע���װ��������Ȼд��д���������
					//cout << "���һ�ν���" << endl;
					//move_ahead(cur->prior);
				}

			}

		}
		cur = cur->prior;//��ǰ����
	}
	//����˵һ�䣬���ע��Ҫд�ڵ����ϣ�������ָ��Ĳ������ڸ�ʲô���򵥵ľͲ���д�ˣ���һ�¾������ס�
	// Ȼ��Ҫ��������Ȼ���һ��ʱ�䣬���Լ����������ˡ�
}

void operation::swap_node(Node* A, Node* B)
{
	//�������ã������������ڽڵ�A��B��λ��
	// �޸�ǰ��A_prior A B B_next
	// �޸ĺ�A_prior B A B_next
	Node* A_prior = A->prior;
	Node* B_next= B->next;
	//���޸�A_prior
	A_prior->next = B;
	//Ȼ���޸�A
	A->prior = B;
	A->next = B_next;
	//Ȼ����B
	B->prior = A_prior;
	B->next = A;
	//�����B_next
	if (B_next != nullptr)
		B_next->prior = A;
	else
		A->next = nullptr;

}


void operation::InPut()
{
	Node* work = head;
	char group[] = {'a','b','c','d','e','f'};//�޸ģ�����д��Ŀ�����������Զ�����
	for (int i = 0; i < 6; i++) {//��������
		Node* store = new Node;
		//��������
		store->data = group[i];
		//�������ݽ��
		//�޸ģ�store->next = work->next;
		store->next = nullptr;
		work->next = store;
		store->prior = work;
		//����ָ��˳��
		work = work->next;
		count++;
	}
}
