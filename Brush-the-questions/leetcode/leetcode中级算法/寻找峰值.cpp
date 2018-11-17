/*峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
说明:

*/
/*通过代码1*/
class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        auto len = nums.size();
        switch(len){
            case 1: return 0;break;
            case 2: if(nums[1] > nums[0])
                        return 1;
                    else 
                        return 0;
                    break;
            default: break;
        }
        nums.push_back(INT_MIN);
        len =  nums.size();
        for (int i = 1; i < len - 1; ++i)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i+1])
                return i;
        }
        return 0;
    }
};
/*通过代码 2*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(), INT_MIN);

        auto len = nums.size();
        for (int i = 1; i < len - 1; ++i)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                return i - 1;
        }
        return 0;
    }
};
// int main(void)
// {
//     Solution s1;
//     vector<int> VV = {1, 2, 1, 3, 5, 6, 4};
//     cout << s1.findPeakElement(VV) << endl;
//     return 0;
// }