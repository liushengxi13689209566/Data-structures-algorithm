/*************************************************************************
	> File Name: 死锁.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  8/ 9 09:18:44 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*题目描述
试判断一个消息队列是否可能死锁。
消息队列的缓冲区长度为L单位，读操作为每次从缓冲区读取R单位，写操作为每次写入缓冲区W单位。
消息队列会持续进行读写操作。具体为写操作会在缓冲区还剩余大于等于W单位空间时保持进行，当缓冲区内空间小于W时，
写操作停止，等待读操作进行；类似的，
读操作会在缓冲区可读内容大于等于R时保持进行，当可读内容小于R时，读操作停止，等待写操作进行。读写都是原子操作。
若读写操作均无法进行，定义此时状态为死锁。
给定L,R,W，问消息队列是否可能进入死锁状态，若能，输出YES，否则输出NO
输入描述:
第1行输入N(N<=10)表示数据组数。
从第2行到第N+1行，每行三个整数L,R,W。
输出描述:
输出N行，每行输出'YES'或'NO'
示例1
输入
复制
2
5 2 3
5 3 4
输出
复制
NO
YES
说明
备注:
50% L,R,W<=10^5
50% L,R,W<=10^18 */

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, l, r, w;
	cin >> n;
	while (n--)
	{
		cin >> l >> r >> w;
		

	}
}