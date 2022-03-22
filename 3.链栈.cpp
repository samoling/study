#include <iostream>
using namespace std;
typedef int Elemtype;
typedef struct node {
	Elemtype data;
	node* next;
};
typedef struct stack {
	node* top;
	int size;
};
stack Insert(stack str)
{
	int n;		
	cout << "请输入需要插入的数据（9999退出）：" << endl;
	do {
		cin >> n;
		if (n == 9999)
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
				node* p=new node;
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
stack Delete(stack str)
{
	node* p = str.top;
	str.top = str.top->next;
	cout << "所删除的栈顶元素为：" << p->data << endl;
	delete p;
	str.size--;
	return str;
}
bool Judge(stack str)
{
	if (str.size == 0)
		return false;
	else
		return true;
}
stack Jump(stack str)
{
	int x;
	cout << "请输入弹出多少个元素（输入9999全弹出）。" << endl;
	do {
		cin >> x;
		if (x == 9999)
		{
			x = str.size; break;
		}
		else if (x > str.size)
			cout << "请输入正确的个数。目前一共有" << str.size << "个元素。" << endl;
		else
			break;
	} while (true);
	cout << "弹出的元素为：" << endl;
	for(int i=0;i<x;i++)
	{
		cout << str.top->data<<"   ";
		node* p = str.top;
		str.top = str.top->next;
		delete p;
	}
	cout << endl;
	str.size -= x;
	return str;
}
void length(stack str)
{
	cout << "栈的长度为：" << str.size<<endl;
}
void print(bool s)
{
	if (s)
		cout << "栈不为空。" << endl;
	else
		cout << "栈为空。" << endl;
}
void main()
{
	stack str;
	str.size = 0;
	str.top = nullptr;
	int x;
	do {
		cout << "请选择选项进行操作。" << endl
			<< "[1]向链栈中插入值" << endl
			<< "[2]删除栈顶元素" << endl
			<< "[3]判断栈是否为空" << endl
			<< "[4]弹出链栈元素" << endl
			<<"[5]求栈长"<<endl
			<<"[0]退出"<<endl;
		cin >> x;
		switch (x)
		{
		case 1:str=Insert(str); break;
		case 2:str=Delete(str); break;
		case 3:print(Judge(str)); break;
		case 4:str=Jump(str); break;
		case 5:length(str); break;
		case 0:break;
		default:cout << "请输入正确的序号。" << endl; break;
		}
	} while (x!=0);
}