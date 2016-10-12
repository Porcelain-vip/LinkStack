#include"stack.h"

LinkStack::LinkStack()  
{
	top = NULL;
}

LinkStack::~LinkStack()
{
	Clear();
}

void LinkStack::Clear()             //删除指针
{
	for (Node * tmptr = top; tmptr != NULL; tmptr = tmptr->next)
		delete tmptr;
	top = NULL;
}
/*
while (!Empty())                                                            //                 Item data;                                //删除指针
{                                                                                          //                 while(!Empty())
    Node * tmptr = top->next;                                     //                       Pop(data);
    delete top;
    top = tmptr;
}
*/

int LinkStack::Count() const
{
	int count = 0;
	for (Node * tmptr = top; tmptr != NULL; tmptr = tmptr->next)
		++count;
	return count;
}

bool LinkStack::Empty() const
{
	return top == NULL;
}

bool LinkStack::Top(Item & e) const
{
	if (Empty())
		return false;
	else
	{
		e = top->data;
		return true;
	}
}

bool LinkStack::Pop(Item & e)
{
	if (Empty())
		return false;
	else
	{
		Node * tmptr = top->next;
		e = top->data;
		delete top;                          //只是释放所分配内存空间，但是指针top依然依然是有效的
		top = tmptr;                       //可以继续使用
		return true;
	}
}

bool LinkStack::Push(const Item & e)
{
	Node * newtop = new Node;
	if (newtop == NULL)                                         //分配内存失败
		return false;
	else
	{
		newtop->data = e;
		newtop->next = top;
		top = newtop;
		return true;
	}
}

void LinkStack:: Traverse() const                                  //遍历栈     
{
	Node * tmptr;
	LinkStack one;
	for (tmptr = top; tmptr != NULL; tmptr = tmptr->next)
		one.Push(tmptr->data);
	for (tmptr = one.top; tmptr != NULL; tmptr = tmptr->next)
		cout << tmptr->data << setw(3);
}

LinkStack:: LinkStack(const LinkStack & copy)                      //拷贝构造函数
{
	if (copy.top==NULL)
		top = NULL;
	else
	{
		top = new Node{ copy.top->data };
		for (Node * tmptr = copy.top->next; tmptr != NULL; tmptr = tmptr->next)
		{
			top->next = new Node{ tmptr->data };
			top = top->next;
		}
	}
}

LinkStack & LinkStack:: operator=(const LinkStack &copy)
{
	if (this != &copy)
	{
		if (copy.top == NULL)
			top = NULL;
		else
		{
			Clear();
			top = new Node{ copy.top->data };
			for (Node* tmptr = copy.top->next; tmptr != NULL; tmptr = tmptr->next)
			{
				top->next = new Node{ tmptr->data };
				top = top->next;
			}
		}
	}
	return * this;
}