/*************************************************************************
	> File Name: chrome.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年10月13日 星期六 21时31分43秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
class url
{
  public:
	url(std::string _tmp) : page(_tmp) {}
	std::string get_url()
	{
		return page;
	}
	std::string set_url(std::string _tmp)
	{
		page = _tmp;
	}

  private:
	std::string page;
};
int main(void)
{
	std::stack<url> now_page;
	std::stack<url> dump_page;
	std::string temp_page;
	int chose = -100;
	char chose_behavior;

	do
	{
		cout << "\n\n\t\t\t当前所处的页面为：";
		if (now_page.size() > 0)
			cout << now_page.top().get_url() << "\n\n";
		else
			cout << "空 \n\n";

		printf("\t\t\t前进：1\n\n");
		printf("\t\t\t后退：2\n\n\n");
		cout << "\t\t\t请输入你的下一步操作：";
		cin >> chose;
		switch (chose)
		{
		case 1:
			cout << "是否要进入新的页面:yes[y]  no[n]";
			cin >> chose_behavior;
			if (chose_behavior == 'n')
			{
				if (dump_page.size() > 0)
				{
					now_page.push(dump_page.top());
					dump_page.pop();
				}
				else
					cout << "Sorry!!!! 没有你要进入的页面啦啦啦 \n\n";
			}
			else if (chose_behavior == 'y')
			{
				cout << "请输入你要新进入的页面的url : ";
				cin >> temp_page;
				now_page.push(url(temp_page));
				while (!dump_page.empty())
					dump_page.pop();
			}
			break;
		case 2:
			if (now_page.size() <= 1)
				cout << "后退的页面为空!!!!" << endl;
			else
			{
				dump_page.push(now_page.top());
				now_page.pop();
			}
			break;
		default:
			break;
		}
	} while (chose == 1 || chose == 2);

	return 0;
}
