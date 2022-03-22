#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

/********* Begin *********/
//自定义的类和者其他内容
class student
{
public:
	string name;
	int score;
};
int n = 0;
student stu[10];
void create()
{
	student a;
	int f = 0;
	cin >> a.name >> a.score;
	int i;
	for (i = 0; i < n; i++)
		if (a.name == stu[i].name)
		{
			f = 1; break;
		}
	if (f == 0)
	{
		stu[i+1] = a;
		n++;
	}
	else
	{
		stu[i] = a;
	}
}
void dele()
{
	student a;
	int f = 0;
	cin >> a.name >> a.score;
	int i;
	for (i = 0; i < n; i++)
		if (a.name == stu[i].name)
		{
			f = 1; break;
		}
	if (f == 1)
	{
		stu[i] = stu[n]; n--;
	}
}
void disp()
{
	for (int i = 1; i <= n; i++)
		cout << stu[i].name << " " << stu[i].score << endl;
}
void dissort()
{
	for (int i = 0; i < n; i++)
	{
		int end = i;
		student tem = stu[end + 1];
		while (end >= 0)
		{
			if (tem.score < stu[end].score)
			{
				stu[end + 1] = stu[end];
				end--;
			}
			else
			{
				break;
			}
		}
		stu[end+1] = tem;
	}
}
/********* End *********/

int main()
{
	/********* Begin *********/
	//读取输入数据，执行动作
	char str;
	do {
		cin >> str;
		switch (str)
		{
		case 'A':create(); break;
		case 'R':dele(); break;
		case 'P':disp(); break;
		case 'S':dissort(); break;
		default:break;
		}
	} while (true);
	return 0;
	/********* End *********/
}