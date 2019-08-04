/*************************************************************************
	> File Name: 旋转数组的最小数字.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  7/31 09:19:09 2019
 ************************************************************************/

#include <iostream>
using namespace std;
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
class Solution
{
public:
	int minNumberInRotateArray(vector<int> array)
	{
		int len = array.size();
		if (len <= 0)
			return 0;
		for (int i = 0; i < len - 1; i++)
		{
			if (array[i + 1] < array[i])
			{
				return array[i + 1];
			}
		}
		return 0;
	}
};