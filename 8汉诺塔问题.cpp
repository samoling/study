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
		cout << "第" << sum + 1 << "步，将" << n << "号圆盘从" << x <<"移至" << y << endl;
		sum++;
		hanoi(n - 1, z, y, x);
		return 0;
	}
}
void main()
{
	do {
		int n;
		cout << "请输入汉诺塔层数。" << endl;
		cin >> n;
		if (n == 0)
			break;
		hanoi(n, 'A', 'B', 'C');
		cout << "共移动了" << sum << "次" << endl;
	} while (true);
}