#include <iostream>
using namespace std;
typedef int Elemtype;
#define Max 100
typedef struct stack {
	Elemtype data[Max];
	Elemtype *top;
};
int length(stack &str)
{
	int i = 0;
	if (str.top == nullptr)
		return 0;
	else
	{
		while (str.data[i] != *str.top)
		{
			i++;
		}
		return i;
	}
}
stack Insert(stack &str)
{
	int size = length(str);
	Elemtype temp;
	cout << "��������ջ������(9999�˳�)��" << endl;
	do {
		cin >> temp;
		if (temp == 9999)
			break;
		str.data[size] = temp;
		str.top = &str.data[size];
		size++;
	} while (true);
	return str;
}
stack Delete(stack &str)
{
	int size = length(str);
	cout << "ɾ��������Ϊ��" << str.data[size] << endl;
	str.top = &str.data[size - 1];
	return str;
}
bool Judge(stack &str)
{
	if (length(str) == 0)
		return false;
	else
		return true;
}
stack Jump(stack &str)
{
	int n;
	int size = length(str);
	cout << "��������Ҫ����ջ�ĸ�����"; cin >> n;
	do {
		if (n > size+1)
		{
			cout << "��������ȷ�ĸ�����Ŀǰ����" << size+1 << "������" << endl;
			cin >> n;
		}
		else
		{
			cout << "����������Ϊ��" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << *str.top << "     ";
				str.top =&str.data[size-1];
			}
			cout << endl;
			if (n == size + 1)
				str.top = nullptr;
			break;
		}
	} while (true);
	return str;
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
	str.top = nullptr;
	int x;
	do {
		cout << "��ѡ��ѡ����в�����" << endl
			<< "[1]��˳��ջ�в���ֵ" << endl
			<< "[2]ɾ��ջ��Ԫ��" << endl
			<< "[3]�ж�ջ�Ƿ�Ϊ��" << endl
			<< "[4]������ջԪ��" << endl
			<< "[5]��ջ��" << endl
			<< "[0]�˳�" << endl;
		cin >> x;
		switch (x)
		{
		case 1:str = Insert(str); break;
		case 2:str = Delete(str); break;
		case 3:print(Judge(str)); break;
		case 4:str = Jump(str); break;
		case 5:cout << "ջ��Ϊ��" << length(str) + 1 << endl; break;
		case 0:break;
		default:cout << "��������ȷ����š�" << endl; break;
		}
	} while (x != 0);
}