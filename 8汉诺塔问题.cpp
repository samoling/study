#include <iostream>
using namespace std;
int sum = 0;
int hanoi(int n, char x, char y, char z)
{
	if (n == 0)
		return 0;
	else
	{
		hanoi(n - 1, x, z, y);
		cout << "��" << sum + 1 << "������" << n << "��Բ�̴�" << x <<"����" << y << endl;
		sum++;
		hanoi(n - 1, z, y, x);
		return 0;
	}
}
void main()
{
	do {
		int n;
		cout << "�����뺺ŵ��������" << endl;
		cin >> n;
		if (n == 0)
			break;
		hanoi(n, 'A', 'B', 'C');
		cout << "���ƶ���" << sum << "��" << endl;
	} while (true);
}