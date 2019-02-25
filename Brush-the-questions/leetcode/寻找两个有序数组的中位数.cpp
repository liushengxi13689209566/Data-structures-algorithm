/*************************************************************************
	> File Name: 寻找两个有序数组的中位数.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年02月24日 星期日 22时24分42秒
 ************************************************************************/

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &t1, vector<int> &t2)
    {
        if (t1.size() <= 0)
            return findMedianNumber(t2);
        if (t2.size() <= 0)
            return findMedianNumber(t1);
        int len = (t1.size() + t2.size()) / 2;
        int index1 = 0, index2 = 0;
        int count = 0;
        double result[3] = {0};

        while (index1 < t1.size() && index2 < t2.size() && count < len)
        {
            cout << "into loop" << endl;
            if (t1[index1] <= t2[index2])
            {
                result[1] = t1[index1];
                result[2] = t2[index2];
                index1++;
            }
            else
            {
                result[2] = t1[index2];
                result[1] = t2[index1];
                index2++;
            }
            cout << result[1] << endl;
            cout << result[2] << endl;
            cout << count << endl;
            count++;
        }
        while ()
        {
        }
        while ()
        {
        }
        return len % 2 ? result[2] : (result[1] + result[2]) / 2;
    }

  private:
    double findMedianNumber(vector<int> &vec)
    {
        int len = vec.size();
        return len % 2 ? vec[len / 2] : (vec[len / 2] + vec[len / 2 - 1]) / 2;
    }
};
