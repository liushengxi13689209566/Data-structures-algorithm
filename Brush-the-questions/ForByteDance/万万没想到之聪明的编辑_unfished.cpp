/*************************************************************************
	> File Name: 万万没想到之聪明的编辑.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/ 4 21:28:03 2019
 ************************************************************************/

#include <iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	while (n--)
	{
		cin >> str;
		int len = str.size();
		for (int i = 0; i < len;)
		{
			if (i + 1 < len && i + 2 < len)
			{
				if (str[i] == str[i + 1] && str[i] == str[i + 2])
				{
					for (int j = i; j < len; j++)
					{
						str[j] = str[j + 1];
					}
				}
			}
			if (i + 1 < len && i + 2 < len && i + 3 < len)
			{
				if (str[i] == str[i + 1] && str[i + 2] == str[i + 3])
				{
					for (int j = i + 2; j < len; j++)
					{
						str[j] = str[j + 1];
					}
				}
			}
			i++;
		}
		cout << str << endl;
	}
}
