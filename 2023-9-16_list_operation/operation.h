#include <iostream>
using namespace std;
//定义结点
struct Node {
    int data;
    Node* next;
};

class Student {
public:
    Student();
    ~Student();
    
    void InPut();
    void InPut_1();
    void OutPut();
    void order();
    void insert();
    void inversion();
    
private:
    Node* head=nullptr;
    Node* head_1 = new Node;
    float count=0;
    float count1 = 0;
};