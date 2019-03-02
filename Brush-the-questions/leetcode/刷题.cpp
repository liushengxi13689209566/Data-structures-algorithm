#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701
范例：
class Solution {
public:
    int titleToNumber(string s) {
        long sum = 0;
        for (int i = 0; i < s.size() - 1; i++) 
            sum = (sum + s[i] - 64) * 26;
        sum += s[s.size() - 1] - 64;
        return sum;
    }
};
*/
class Solution
{
  public:
    int titleToNumber(string s)
    {
        unordered_map<int, int> mmap;

        for (int i = 1; i < 27; i++)
        {
            mmap.insert({64 + i, i});
        }
        int len = s.size();
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result += mmap[s[i]] * pow(26, --len);
        }
        return result;
    }
};
class Solution
{
  public:
    int titleToNumber(string s)
    {
        int len = s.size();
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            result += (s[i] - 64) * pow(26, --len);
        }
        return result;
    }
};
/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/
class Solution
{
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();
        int result = 0;
        int i, j, k, l;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
            {
                for (k = 0; k < len; k++)
                {
                    for (l = 0; l < len; l++)
                    {
                        if (A[i] + B[j] + C[k] + D[l] == 0)
                            result++;
                    }
                }
            }
        }
        return result;
    }
};