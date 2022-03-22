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
	cout << "��������Ҫ��������ݣ�9999�˳�����" << endl;
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
	cout << "��ɾ����ջ��Ԫ��Ϊ��" << p->data << endl;
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
	cout << "�����뵯�����ٸ�Ԫ�أ�����9999ȫ��������" << endl;
	do {
		cin >> x;
		if (x == 9999)
		{
			x = str.size; break;
		}
		else if (x > str.size)
			cout << "��������ȷ�ĸ�����Ŀǰһ����" << str.size << "��Ԫ�ء�" << endl;
		else
			break;
	} while (true);
	cout << "������Ԫ��Ϊ��" << endl;
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
	cout << "ջ�ĳ���Ϊ��" << str.size<<endl;
}
void print(bool s)
{
	if (s)
		cout << "ջ��Ϊ�ա�" << endl;
	else
		cout << "ջΪ�ա�" << endl;
}
void main()
{
	stack str;
	str.size = 0;
	str.top = nullptr;
	int x;
	do {
		cout << "��ѡ��ѡ����в�����" << endl
			<< "[1]����ջ�в���ֵ" << endl
			<< "[2]ɾ��ջ��Ԫ��" << endl
			<< "[3]�ж�ջ�Ƿ�Ϊ��" << endl
			<< "[4]������ջԪ��" << endl
			<<"[5]��ջ��"<<endl
			<<"[0]�˳�"<<endl;
		cin >> x;
		switch (x)
		{
		case 1:str=Insert(str); break;
		case 2:str=Delete(str); break;
		case 3:print(Judge(str)); break;
		case 4:str=Jump(str); break;
		case 5:length(str); break;
		case 0:break;
		default:cout << "��������ȷ����š�" << endl; break;
		}
	} while (x!=0);
}