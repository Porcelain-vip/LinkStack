#include"stack.h"

LinkStack::LinkStack()  
{
	top = NULL;
}

LinkStack::~LinkStack()
{
	Clear();
}

void LinkStack::Clear()
{
	for (Node * tmptr = top; tmptr != NULL; tmptr = tmptr->next)                           //删除指针
		delete tmptr;
}
/*                                                        //Clear()函数的另一种表示
while( !Empty())          //删除指针                                                            Item data;                         //删除元素
{                                                                                                                       while(!Empry())
     Node * tmptr = top ->next;                                                                      Pop(data);
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
		e = tmptr->data;
		delete top;
		top = tmptr;
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
		top = newtop;
		top->data = e;
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
		top == NULL;
	else
	{
		top = new Node{ copy.top->data };
		for (Node * tmptr = copy.top->next; tmptr != NULL; tmptr = tmptr->next)
		{
			tmptr->next = new Node{ tmptr->data };
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
			top = new Node(copy.top->data);
			for (Node* tmptr = copy.top->next; tmptr != NULL; tmptr = tmptr->next)
			{
				tmptr->next = new Node(tmptr->data);
				top = top->next;
			}
		}
	}
	return *this;
}