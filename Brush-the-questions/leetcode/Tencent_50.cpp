/*
136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度O(n)。 你可以不使用额外空间来实现吗？O(1)

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

*/
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, short> mmp;

        for (auto t : nums)
        {
            if (mmp.find(t) == mmp.end())
                mmp.insert({t, 1});
            else
                mmp.erase(t);
        }
        return mmp.begin()->first;
    }
};
/*
//先排序，再比较的方法
static auto x = []() {
		std::ios::sync_with_stdio( false );
		std::cin.tie( 0 );
		return 0;
}( );
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() -1; i+=2)
        {
            if(nums[i] != nums[i+1])
            {
                return nums[i];
            }
        }
        return nums[nums.size() -1];
    }
};
//位运算的方法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
 return accumulate(nums.begin(), nums.end(),0,bit_xor<int>());
    }
};
*/
/*
217. 存在重复元素
*/

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, short> mmp;

        for (auto t : nums)
        {
            if (mmp.find(t) == mmp.end())
                mmp.insert({t, 1});
            else
                return true;
        }
        return false;
    }
};
/*
                78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
//  某位大神的思路，但是实在是不想写了，留给以后吧
*/
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.push_back(path);

        dfs(0, nums);

        return result;
    }

  private:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(int index, const vector<int> &nums)
    {
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(i + 1, nums);
            path.pop_back();
        }
    }
};