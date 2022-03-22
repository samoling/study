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
	cout << "请输入入栈的数据(9999退出)：" << endl;
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
	cout << "删除的数据为：" << str.data[size] << endl;
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
	cout << "请输入需要弹出栈的个数："; cin >> n;
	do {
		if (n > size+1)
		{
			cout << "请输入正确的个数。目前共有" << size+1 << "个数据" << endl;
			cin >> n;
		}
		else
		{
			cout << "弹出的数据为：" << endl;
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
		cout << "栈不为空。" << endl;
	else
		cout << "栈为空。" << endl;
}
void main()
{
	stack str;
	str.top = nullptr;
	int x;
	do {
		cout << "请选择选项进行操作。" << endl
			<< "[1]向顺序栈中插入值" << endl
			<< "[2]删除栈顶元素" << endl
			<< "[3]判断栈是否为空" << endl
			<< "[4]弹出链栈元素" << endl
			<< "[5]求栈长" << endl
			<< "[0]退出" << endl;
		cin >> x;
		switch (x)
		{
		case 1:str = Insert(str); break;
		case 2:str = Delete(str); break;
		case 3:print(Judge(str)); break;
		case 4:str = Jump(str); break;
		case 5:cout << "栈长为：" << length(str) + 1 << endl; break;
		case 0:break;
		default:cout << "请输入正确的序号。" << endl; break;
		}
	} while (x != 0);
}