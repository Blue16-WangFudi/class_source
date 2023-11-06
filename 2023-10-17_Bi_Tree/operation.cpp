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
	/* �޸ģ�ֱ���ύhead
	Node* temp = new Node;
	temp = head;
	*/

	//���������������ƶ�����
	PreInPut(head,"head");
}
//�Ǹ�msg���ҵ����õģ�����ɾ��
void operation::PreInPut(Node* work,string msg="")
{
	cout << "msg = " << msg<<endl;
	//��ȡ��������
	char b;
	cin >> b;

	if ( b == '#') {
		work=nullptr;
		return;//�ݹ�ע�ⷵ������
	}
	else {
		work->data = b;

		/*
		//������Ӧ���ȴ���һ���ڵ㣬Ȼ��ѵ�ַ����ȥ
		
		//�ȸ���һ��ԭ���Ĵ��룬����ִ�й���(��û�д����ڵ㣬��ֱ����ָ�룿����ȥ����nullptr)
		work->left = new Node;
		work->right = new Node;
		//������д�ľͺ��ɻ�һֱ�ݹ���������������������ô�죿
		PreInPut(work->left,"left");//����������
		PreInPut(work->right,"right");//����������
		*/
		//���ж��Ǳ��ǿյģ������ı�����ö���дһ��


		return;
	}
}

void operation::Create_Tree()
{
	//�ȼ����ڵ��Ƿ�������,û�и��ڵ�ʹ���һ��
	if (head == nullptr)
	{
		head = new Node;
		char i;
		cin >> i;
		head->data = i;
	}
		
	//�ö���ʵ��һ��һ��ȡ��
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
	//дһ�����죬�ȳ�ʼ��Node������������߰��������
	this->data = 'a';
	this->left = nullptr;
	this->right = nullptr;
}
