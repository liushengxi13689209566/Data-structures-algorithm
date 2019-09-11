/*
统计一个数字在排序数组中出现的次数。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    //1.查找第一个值等于给定值的元素
    int BinSearch(vector<int> data, int k)
    {
        int low = 0;
        int high = data.size() - 1;
        int mid = low + ((high - low) >> 1);
        while (low <= high)
        {
            if (data[mid] == k)
            {
                if (mid == 0 || data[mid - 1] != k)
                    return mid;
                else
                    high = mid - 1;
            }
            else if (data[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
            mid = low + ((high - low) >> 1);
        }
        return -1;
    }
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() <= 0)
            return -1;
        // 二分找到
        // 然后遍历
        int index = BinSearch(data, k);
        if (index < 0)
            return -1; //表示不存在
        int res = 0;
        for (auto it = data.begin() + index + 1; it != data.end(); it++)
        {
            if (*it == k)
                res++;
            else
                break;
        }
        return res + 1;
    }
};
int main(void)
{
    vector<int> vv{22, 33, 33, 33, 55, 66};
    Solution ss;
    cout << ss.GetNumberOfK(vv, 33) << endl;
}

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> vv;
        for (int i = 0; i < ; i++)
        {
            for (int j = 0; j < ; j--)
            {
            }
        }
        return res;
    }
};

