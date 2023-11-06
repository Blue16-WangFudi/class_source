#include "operation.h"

operation::operation()
{
	Node* head = nullptr;
}

operation::~operation()
{
	delete head;
}

void operation::Build()
{
	/* 修改：直接提交head
	Node* temp = new Node;
	temp = head;
	*/

	//保存输入结果，绘制二叉树
	PreInPut(head,"head");
}
//那个msg是我调试用的，可以删掉
void operation::PreInPut(Node* work,string msg="")
{
	cout << "msg = " << msg<<endl;
	//获取键盘输入
	char b;
	cin >> b;

	if ( b == '#') {
		work=nullptr;
		return;//递归注意返回条件
	}
	else {
		work->data = b;

		/*
		//这里你应该先创建一个节点，然后把地址传过去
		
		//先复现一下原来的代码，看看执行过程(你没有创建节点，就直接用指针？传下去的是nullptr)
		work->left = new Node;
		work->right = new Node;
		//你这里写的就很疑惑，一直递归左子树，你让右子树怎么办？
		PreInPut(work->left,"left");//创建左子树
		PreInPut(work->right,"right");//创建右子树
		*/
		//先判断那边是空的，就往哪边填。我用队列写一下


		return;
	}
}

void operation::Create_Tree()
{
	//先检查根节点是否有数据,没有根节点就创建一个
	if (head == nullptr)
	{
		head = new Node;
		char i;
		cin >> i;
		head->data = i;
	}
		
	//用队列实现一个一个取出
	queue<Node*> q;
	q.push(head);
	while (true)
	{
		char i;
		cin >> i;
		if (i == '#')
			break;
		Node* work = q.front();
		q.pop();
		if (work->left == nullptr)
		{
			work->left = new Node;
			work->left->data = i;
			q.push(work->left);

		}
		else if (work->right == nullptr)
		{
			work->right = new Node;
			work->right->data = i;
			q.push(work->right);
		}
	}
}

void operation::Build_1()
{
	//Node* temp = new Node;
	//temp = head;
	PreOrder(head);
}


void operation::PreOrder(Node* work)
{
	//cout << msg << "\t";
	if (work!=nullptr) {
		cout << work->data << endl;
		PreOrder(work->left);
		PreOrder(work->right);
	}
	return;
}

Node* operation::getRoot()
{
	return head;
}
Node::Node()
{
	//写一个构造，先初始化Node，以免出现乱七八糟的数据
	this->data = 'a';
	this->left = nullptr;
	this->right = nullptr;
}
