/*************************************************************************
	> File Name: 二进制.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年08月03日 星期五 11时59分31秒
 ************************************************************************/
/*Given a positive integer n, write a program to find out a nonzero multiple m of n whose decimal representation contains only the digits 0 and 1. You may assume that n is not greater than 200 and there is a corresponding m containing no more than 100 decimal digits.
Input
The input file may contain multiple test cases. Each line contains a value of n (1 <= n <= 200). A line containing a zero terminates the input.
Output
For each value of n in the input print a line containing the corresponding value of m. The decimal representation of m must not contain more than 100 digits. If there are multiple solutions for a given value of n, any one of them is acceptable.
Sample Input
2
6
19
0*/
// BFS  必须用G++才能过
#include <iostream>
#include <queue>
using namespace std;
long long n; //输入的 n
queue<long long> QQ; //rtm，刚开始一直不过，把queue提出来一下就过了，草
long long BFS(long long start)
{
	QQ.push(start);
	long long Vnow;
	while (!QQ.empty())
	{
		Vnow = QQ.front();
		QQ.pop();
		if (Vnow % n == 0)
			return Vnow;
		if ((Vnow*10) % n == 0)
			return Vnow * 10;
		if ((Vnow*10+1) % n == 0)
			return Vnow * 10 + 1 ;
		QQ.push(Vnow * 10);
		QQ.push(Vnow * 10 + 1);
	}
	return 0;
}
int main(void)
{
	while (cin >> n && n )
	{
		while (!QQ.empty())
		{
			QQ.pop();
		}
		cout << BFS(1) << endl;
	}
	return 0;
}
