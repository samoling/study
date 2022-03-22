#include <iostream>
using namespace std;
typedef char Elemtype;
typedef struct node {
	Elemtype data;
	node* next;
};
typedef struct stack {
	node* top;
	int size;
};
stack Insert(stack &str, Elemtype n)
{
	do {
		if (n == '9')
			break;
		else
		{
			if (str.size == 0)
			{
				str.top = new node;
				str.top->data = n;
				str.top->next = nullptr;
			}
			else
			{
				node* p = new node;
				p->data = str.top->data;
				p->next = str.top->next;
				str.top->data = n;
				str.top->next = p;
			}
			str.size++;
		}
	} while (true);
	return str;
}
bool Judge(stack &str)
{
	if (str.size == 0)
		return false;
	else
		return true;
}
void print(bool s)
{
	if (s)
		cout << "ջ��Ϊ�ա�" << endl;
	else
		cout << "ջΪ�ա�" << endl;
}
void est(stack& str)
{
	Elemtype n,temp;
	do {
		cout << "���������š�" << endl;
		cin >> n;
		if (n == '(' || n == '[' || n == '{')
			str = Insert(str, n);
		else if (n == ')' || n == ']' || n == '}')
		{
			switch (n)
			{
			case ')':temp = '('; break;
			case ']':temp = '['; break;
			case '}':temp = '{'; break;
			}
			if (Judge(str))
			{
				if (str.top->data == temp)
					cout << "����ƥ��ɹ�����ǰ����Ϊ��" << str.top->data << n << endl;
				str.top = str.top->next;
				str.size--;
				break;
			}
			else
				cout << "ջΪ�գ�" << endl; break;
		}
		else
			cout << "������ţ�" << endl;
	} while (true);
}
void main()
{
	stack str;
	str.size = 0;
	str.top = nullptr;
	int x;
	do {
		cout << "��ѡ��ѡ����в�����" << endl
			<< "[1]������ջ" << endl
			<< "[2]�ж�ջ�Ƿ�Ϊ��" << endl
			<< "[0]�˳�" << endl;
		cin >> x;
		switch (x)
		{
		case 1:est(str); break;
		case 2:print(Judge(str)); break;
		case 0:break;
		default:cout << "��������ȷ����š�" << endl; break;
		}
	} while (x != 0);
}