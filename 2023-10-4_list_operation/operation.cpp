#include "operation.h"

operation::operation()
{
	head = new Node;
	head->next = nullptr;
	head->data = NULL;
}

operation::~operation()
{
	//释放
	Node* p = head;
	while (p) {
		Node* q = p;
		p = p->next;
		delete q;
	}
}

void operation::locate(char x)
{
	//遍历寻找位置,并使频度加一
	Node* temp = head;
	for (int i = 0; i <=count; i++) {
		//这里你也写错了，是小于等于，要不然f根本搜不到
		//为什么？因为你忘记了还有个头节点head
		//??我没理解你这么写的原因，你操作的是temp，怎么还用到temp->next了？
		/*
		if (temp->next->data == x) {
			temp->next->rate++;
			temp = temp->next;
			cout << "找到了" << endl;
		}
		else
			continue;
		*/
		
		if (temp->data == x)
		{
			temp->rate++;
			//cout << "找到了"<<"@"<<temp->rate << endl;
			//OutPut();
			break;//此时让temp停在找到了的位置，然后一直往前遍历
		}
		temp = temp->next;
	}
	


	//进行结点交换（根据频度重新排序）
	//我是这样理解你写的：每访问一次，就排一次序
	/*这个不对，我试着推出你的思路，但没完全推出来，看我下面写的
	while (temp != nullptr) {
		Node* temp_1 = temp->prior;//temp1=B，temp1->prior=A
		if (temp_1 == nullptr)//所寻字符处于第一位
			break;
		else if (temp->next != nullptr)//所寻字符位于中间
		{
			if(temp->rate >= temp_1->rate){//temp比它前一个更大
			//更新A，让A指向temp
			temp_1->prior->next = temp;
			//更新temp，让temp前指向A
			temp->prior = temp_1->prior;
			//更新B，让B后指向temp的下一个
			temp_1->next = temp->next;
			//更新temp后一个元素，让其前指向B
			temp->next->prior = temp_1;
			//更新temp,让temp后指向B
			temp->next = temp_1;
			//更新B，让B前指向temp
			temp_1->prior = temp;
			//移动指针，往前走
			temp = temp->prior; 
			
			}
		}
		else//所寻字符位于最后一位
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
	head->rate = 999;//定义一个非常大的数，这样方便
	while (true)
	{
		if (cur->prior == nullptr)//cur打头，不太可能，因为有head在
			break;
		if (cur->prior->prior == nullptr)//head cur这种情况
			break;
		else// head A cur这种情况,这样刚好能读取出三个元素比较
		{
			while (true)
			{
				if (cur->prior->rate >= cur->rate)
				{
					break;
				}
				if (cur->prior->rate <= cur->rate)
				{
					swap_node(cur->prior, cur);//注意封装函数，不然写着写着你就乱了
					//cout << "完成一次交换" << endl;
					//move_ahead(cur->prior);
				}

			}

		}
		cur = cur->prior;//向前搜索
	}
	//我再说一句，你的注释要写在点子上，比如你指针的操作是在干什么。简单的就不用写了，看一下就能明白。
	// 然后要有条理，不然你隔一段时间，你自己都看不懂了。
}

void operation::swap_node(Node* A, Node* B)
{
	//方法作用：交换两个相邻节点A与B的位置
	// 修改前：A_prior A B B_next
	// 修改后：A_prior B A B_next
	Node* A_prior = A->prior;
	Node* B_next= B->next;
	//先修改A_prior
	A_prior->next = B;
	//然后修改A
	A->prior = B;
	A->next = B_next;
	//然后是B
	B->prior = A_prior;
	B->next = A;
	//最后是B_next
	if (B_next != nullptr)
		B_next->prior = A;
	else
		A->next = nullptr;

}


void operation::InPut()
{
	Node* work = head;
	char group[] = {'a','b','c','d','e','f'};//修改：不用写数目，编译器会自动计算
	for (int i = 0; i < 6; i++) {//储存链表
		Node* store = new Node;
		//储存数据
		store->data = group[i];
		//链接数据结点
		//修改：store->next = work->next;
		store->next = nullptr;
		work->next = store;
		store->prior = work;
		//工作指针顺移
		work = work->next;
		count++;
	}
}
