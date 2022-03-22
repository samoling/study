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
		cout << "栈不为空。" << endl;
	else
		cout << "栈为空。" << endl;
}
void est(stack& str)
{
	Elemtype n,temp;
	do {
		cout << "请输入括号。" << endl;
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
					cout << "括号匹配成功！当前括号为：" << str.top->data << n << endl;
				str.top = str.top->next;
				str.size--;
				break;
			}
			else
				cout << "栈为空！" << endl; break;
		}
		else
			cout << "错误符号！" << endl;
	} while (true);
}
void main()
{
	stack str;
	str.size = 0;
	str.top = nullptr;
	int x;
	do {
		cout << "请选择选项进行操作。" << endl
			<< "[1]括号入栈" << endl
			<< "[2]判断栈是否为空" << endl
			<< "[0]退出" << endl;
		cin >> x;
		switch (x)
		{
		case 1:est(str); break;
		case 2:print(Judge(str)); break;
		case 0:break;
		default:cout << "请输入正确的序号。" << endl; break;
		}
	} while (x != 0);
}