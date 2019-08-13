/*************************************************************************
	> File Name: 牛牛找工作.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  8/ 8 22:03:53 2019
 ************************************************************************/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct TT
{
	int nan = 0;
	int money = 0;
	TT(int a, int b) : nan(a), money(b) {}
	/* 
	bool operator<(const TT &t)
	{
		return this->nan > t.nan;
	}
	*/
};
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<TT> vv;
	int a, b;
	int start = 0, end = 0;
	int ret = 0;
	while (n--)
	{
		cin >> a >> b;
		vv.push_back(TT(a, b));
	}

	sort(vv.begin(), vv.end(), [](const TT &a, const TT &b) {
		return a.nan > b.nan;
	});
	int idx = vv.size() >> 1;
	auto it = vv[idx];

	while (m--)
	{
		cin >> a;
		if (it.nan < a)
			start = idx - 1, end = vv.size();
		else
			start = 0, end = idx + 1;
			
		cout << "start == " << start;
		cout << "  ,  end  == " << end << endl;

		for (int i = start; i <= end; i++)
		{
			if (a >= vv[i].nan && ret < vv[i].money)
				ret = vv[i].money;
		}
		cout << ret << endl;
		ret = 0;
	}
	return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// struct TT
// {
// 	int nan = 0;
// 	int money = 0;
// 	TT(int a, int b) : nan(a), money(b) {}
// };
// int main(void)
// {
// 	int n, m;
// 	cin >> n >> m;
// 	vector<TT> vv;
// 	int a, b;
// 	while (n--)
// 	{
// 		cin >> a >> b;
// 		vv.push_back(TT(a, b));
// 	}
// 	int ret = 0;
// 	while (m--)
// 	{
// 		cin >> a;
// 		for (auto j : vv)
// 		{
// 			if (a >= j.nan && ret < j.money)
// 				ret = j.money;
// 		}
// 		cout << ret << endl;
// 		ret = 0;
// 	}
// 	return 0;
// }