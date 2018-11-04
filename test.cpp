/*************************************************************************
	> File Name: test.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年11月04日 星期日 16时50分54秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template <typename T> //常量参数
void display(vector<T> t)
{
	T ttt;
	vector<T>::iterator low, mid, high;
	cout << "t" << endl;
}
int main()
{
	vector<int> vv;
	display<int>(vv); //模板函数
	return 0;
}
