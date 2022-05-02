#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getnext(string& str) 
{
	if (str.size() == 1) 
		return{ -1 };
	vector<int> next;
	next.resize(str.size());
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int cn = 0;
	while (i < next.size())
	{
		if (str[i - 1] == str[cn]) 
		{
			cn++;
			next[i] = cn;
			i++;
		}
		else if (cn > 0) 
		{
			cn = next[cn];
		}
		else 
		{
			next[i] = 0;
			i++;
		}
	}
	return next;
}
int KMP(string& s1, string& s2) {
	if (s1.empty() || s2.empty() || s1.size() < s2.size()) 
		return -1;
	vector<int> next = getnext(s2);
	int i = 0;
	int j = 0;
	while (i < s1.size() && j < s2.size()) 
	{
		if (s1[i] == s2[j]) 
		{
			i++;
			j++;
		}
		else if (j != 0) 
		{
			j = next[j];
		}
		else {
			i++;
		}
	}
	return j == s2.length() ? i - j : -1;
}
void main() 
{
	string str1, str2;
	cout << "ÇëÊäÈë×Ö·û´®s£º" << endl;
	cin >> str1;
	cout << "ÇëÊäÈë×Ö·û´®t£º" << endl;
	cin >> str2;
	while (true)
	{
		int location = KMP(str1, str2);
		if (location == -1)
		{
			break;
		}
		else 
		{
			str1.erase(location,str2.length());
		}
	}
	cout << "½á¹ûÎª£º" << endl << str1 << endl;
}