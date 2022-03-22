#include <iostream>
#include <string>
using namespace std;
typedef string Elemtype;
typedef struct stack{
	Elemtype data;
};
void main()
{
	stack str;
	char temp[100];
	char str1[50],str2[50];
	int n = 0, m = 0;
	cin >> str.data;
	strcpy_s(temp, str.data.c_str());
	for (int i = 0; i < str.data.length(); i++)
	{
		if (temp[i]<='9'&&temp[i]>='0')
		{
			str1[n] = temp[i]; n++;
		}
		else
		{
			str2[m] = temp[i];
			m++;
		}
	}
	str1[n] = '\0';
	str2[m] = '\0';
	temp[0] = str1[0];
	int j = 1, k = 0;
	for (int i = 1; i < str.data.length(); i+=2)
	{
		if (j != n && k != m)
		{
			if (str2[k] == '*' || str2[k] == '/')
			{
				temp[i] = str1[j];
				temp[i + 1] = str1[j + 1];
				temp[i + 2] = str2[k];
				k++; j += 2; i++;
			}
			else
			{
				temp[i] = str1[j];
				temp[i + 1] = str2[k];
				j++; k++;
			}
		}
		else
		{
			temp[i] = str2[k];
			k++;
		}
	}
	temp[str.data.length()] = '\0';
	cout << temp << endl;
}