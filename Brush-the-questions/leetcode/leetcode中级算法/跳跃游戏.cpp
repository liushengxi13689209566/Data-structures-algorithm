/*************************************************************************
	> File Name: 跳跃游戏.cpp
	> Author: Liu Shengxi
	> Mail: 13689209566@163.com
	> Created Time: 2018年07月22日 星期日 09时33分56秒
 ************************************************************************/
/*给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/


思路
遍历记录下当前能到达的最远的位置，如果能到达n，则一定能达到<n的任何位置
如果当前能到达的位置小于当前的下标，则说明走不下去了，提前中断退出。

这里说一下，假如序列是[1,0,1,0]，那到第一个零的时候canArrive=1,这时能到达的位置==当前的下标，条件不成立，继续下一个循环，
下一个下标为2,而canArrive还是1,所以退出，


第一个点时起点，一定可以达到，先加入进去。
遍历完成之后，看能到达的位置是否覆盖了末节点的位置。

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int TT =  nums.size();
		int canArrive = 0 ,k ;
		for (int i = 0; i < TT - 1 ; ++i)
		{
			if (canArrive < i ) 
				return false ;
			k =  i+nums[i];
			if(k > canArrive )
				canArrive = k ;
		}
		return canArrive >= TT-1;
	}
};
int main(void) {
	Solution s1;
	vector<int> v{2, 3, 1, 1, 4};
	if (s1.canJump(v))
		cout <<  "true" << endl ;
	else
		cout << "false" << endl;

	vector<int> v1{1, 0, 1, 0};
	if (s1.canJump(v1))
		cout <<  "true" << endl ;
	else
		cout << "false" << endl;
	return 0 ;
}

