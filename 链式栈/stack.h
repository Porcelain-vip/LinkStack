#ifndef STACK_H_
#define STACK_H_
#include<iostream> 
#include<string>
#include<iomanip>
using namespace std;
typedef char Item;

class LinkStack
{
private:
	struct Node{
	Item data;
	Node * next;
	Node() { next = NULL; }                                                                                      //Ĭ�Ϲ��캯��
	Node(Item dt, Node * link = NULL) :data(dt), next(link) {}};                    //һ�㹹�캯��
	Node * top;  
public:
	LinkStack();
	~LinkStack();
	void Clear();
	int Count() const;
	bool Empty() const;
	bool Top(Item & e) const;
	bool Pop(Item & e);
	bool Push(const Item & e);
	void Traverse() const;
	LinkStack(const LinkStack & copy);
	LinkStack & operator=(const LinkStack & copy);
};

#endif