
/*给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using Iterator = vector<int>::iterator ;
using VV = vector<vector<int> > ;
class Solution {
public:
	void resove(VV  &intVec, vector<int> &nums , Iterator be , Iterator &ed  ) {
		if (be == ed ) {
			intVec.push_back(nums);
		}
		else {
			for (auto it = be ; it != ed ; ++it )
			{
				swap(*it, *be);
				resove(intVec, nums , be + 1 , ed );
				swap(*it, *be);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		VV  intVec  ; // 前面一个参数表示向量个数，后面参数表示是怎样的几个向量
		Iterator  be = nums.begin() , ed = nums.end() ;
		resove(intVec, nums , be, ed  ) ;  // 3
		return intVec ;
	}
} ;
/*int main(void) {
	Solution s1 ;
	std::vector<int> v = {1, 2, 3};
	VV  tmp = s1.permute(v) ;
	for (int i = 0; i < tmp.size() ; ++i )
	{
		for ( Iterator it = tmp[i].begin() ; it != tmp[i].end() ; it++)
		{
			cout << *it << "  " ;
		}
		cout << endl ;
	}
	return 0;
}
*/
