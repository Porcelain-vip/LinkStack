#include"stack.h"

bool Ismatch(const string & str);

int main()
{
	string str;
	cout << "������һ���ַ�����";
	cin >> str;
	if (Ismatch(str))
		cout << "Well Done" << endl;
	else
		cout << "Wrong";
	return 0;
}

bool Ismatch(const string & str)                                               //�ж������Ƿ�ƥ��
{
	char tmp;
	LinkStack one;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			one.Push(str[i]);

		else if (str[i] == ')')
		{
			if (one.Top(tmp), tmp == '(')
				one.Pop(tmp);
			else if (one.Empty())
				return false;
			else
				return false;
		}

		else if (str[i] == ']')
		{
			if (one.Top(tmp), tmp == ']')
				one.Pop(tmp);
			else if (one.Empty())
				return false;
			else
				return false;
		}

		else if (str[i] == '}')
		{
			if (one.Top(tmp), tmp == '}')
				one.Pop(tmp);
			else if (one.Empty())
				return false;
			else
				return false;
		}
	}

	if (one.Empty())
		return true;
	else
		return false;
}