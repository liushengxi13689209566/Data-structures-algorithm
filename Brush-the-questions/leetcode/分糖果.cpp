/*************************************************************************
	> File Name: 分糖果.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年01月28日 星期一 15时43分02秒
 ************************************************************************/

/*题目描述：
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。 */

/**
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int candy(vector<int> &rat)
    {
        //贪心
        int len = rat.size();
        vector<int> candy(len, 1);
        candy[0] = 1;
        for (int i = 0; i < len - 1; i++)
        {
            if (rat[i + 1] > rat[i])
                candy[i + 1] = candy[i] + 1;
        }
        //逆着贪心
        for (int i = len - 1; i > 0; i--)
        {
            if (rat[i - 1] > rat[i] && candy[i - 1] <= candy[i])
                candy[i - 1] = candy[i] + 1;
        }
        int result = 0;
        for (auto i : candy)
            result += i;
        return result;
    }
};

int main(void)
{
    Solution s1;
    vector<int> v{1, 2, 3, 4, 3, 2, 1, 0};
    std::cout << s1.candy(v) << std::endl;
    return 0;
}
*/
