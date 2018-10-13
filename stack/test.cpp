/*************************************************************************
	> File Name: test.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年10月13日 星期六 21时43分09秒
 ************************************************************************/

#include <stack>
#include <iostream>

int main()
{
	std::stack<int> s;

	s.push(2);
	s.push(6);
	s.push(51);

	std::cout << s.size() << " elements on stack\n";
	std::cout << "Top element: "
			  << s.top() // 保留元素在 stack 上
			  << "\n";
	std::cout << s.size() << " elements on stack\n";
	s.pop();
	std::cout << s.size() << " elements on stack\n";
	std::cout << "Top element: " << s.top() << "\n";

	return 0;
}
