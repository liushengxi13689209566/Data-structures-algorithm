#include "head.h"

using namespace std;

class Solution
{
public:
    int MinFun(vector<int> &nums, int low, int high)
    {
        int ret = 0;
        for (int i = low; i < high - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                ret = i + 1;
                break;
            }
        }
        return ret;
    }
    //考虑重复
    int minNumberInRotateArray(vector<int> nums)
    {
        if (nums.size() <= 0)
            return 0;
        //处理：12345 的特殊情况
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];

        int low = 0;
        int high = nums.size() - 1;
        int mid = low + ((high - low) >> 1);
        //明显的体现出 low指向第一个递增数组最尾部，high 指向第二个递增数组最头部的特点
        while (high - low != 1)
        {
            if (nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                high = MinFun(nums, low, high);
                break;
            }
            if (nums[mid] >= nums[low])
                low = mid;
            else if (nums[mid] <= nums[high])
                high = mid;  //注意这里不能够 +-1，否则会造成死循环
            else
                break; //54321 的情况
            mid = low + ((high - low) >> 1);
        }
        return nums[high];
    }
};

int main()
{
    vector<int> vv;
    int tmp = 0;
    while (1)
    {
        cin >> tmp;
        if (tmp == 666)
            break;
        vv.push_back(tmp);
    }

    Solution s1;
    cout << s1.minNumberInRotateArray(vv) << endl;
    return 0;
}