/*************************************************************************
	> File Name: binary_search.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年11月04日 星期日 11时59分58秒
 ************************************************************************/

#include <iostream>
#include <vector>
//#include <algorithm>
#include <iterator>
using namespace std;
/* C++ STL binary_search 的使用
int main(void)
{
	vector<int> a{1, 3, 5, 7, 9};
	vector<int> dst{1, 7, 10};
	for (auto tmp : dst)
	{
		cout << "search for " << tmp << endl;
		if (binary_search(a.begin(), a.end(), tmp))
		{
			cout << "founnd" << endl;
		}
		else
		{
			cout << "not founnd" << endl;
		}
	}
}*/

/* template <typename T>
int binary_search(const vector<T> &set, const T &value)
{
	auto low = set.begin();
	auto high = set.end();
	auto high_dump = high;
	auto low_dump = low;

	auto mid = low + ((high - low) >> 1);
	while ((low <= high) && (mid != high_dump))
	{
		if (*mid == value)
			return mid - low_dump;
		if (*mid < value)
			low = mid + 1;
		else
			high = mid - 1;
		mid = low + ((high - low) >> 1);
	}
	return -1;
} */
using Iter = vector<int>::iterator;

/* template <typename ForwardIt, class T>
bool binary_search(ForwardIt frist, ForwardIt last, const T &value)
{
	if (frist > last)
		return false;
	auto mid = frist + ((last - frist) >> 1);
	if (*mid == value)
		return true;
	if (*mid < value)
		binary_search(mid + 1, last, value);
	else
		binary_search(frist, mid - 1, value);
} */

/*  1.查找第一个值等于给定值的元素
[1,3,4,5,6,8,8,8,11,18]
找到返回下标，找不到返回　－1　*/
/*template <typename ForwardIt, class T>
int binary_search(ForwardIt low, ForwardIt high, const T &value)
{
	auto low_dump = low;
	auto mid = low + ((high - low) >> 1);
	while (low <= high)
	{
		if (*mid < value)
			low = mid + 1;
		else if (*mid > value)
			high = mid - 1;
		else
		{
			if ((mid == low_dump) || (*(mid - 1) != value))
				return mid - low_dump;
			else
				high = mid - 1;
		}
		mid = low + ((high - low) >> 1);
	}
	return -1;
}*/

/*3.查找第一个大于等于给定值的元素
[1,3,4,5,6,8,8,8,11,18]
找到返回下标，找不到返回 -1
*/
/* template <typename ForwardIt, class T>
int binary_search(ForwardIt low, ForwardIt high, const T &value)
{
	auto low_dump = low;
	auto high_dump = high;
	auto mid = low + ((high - low) >> 1);
	while ((low <= high) && (mid != high_dump))
	{
		if (*mid < value)
			low = mid + 1;
		else if (*mid >= value)
		{
			if ((mid == low_dump) || (*(mid - 1) < value))
				return mid - low_dump;
			else
				high = mid - 1;
		}
		mid = low + ((high - low) >> 1);
	}
	return -1;
} */
/*4. 查找最后一个小于等于给定值的元素
[1,3,4,5,6,8,8,8,11,18]
找到返回下标，找不到返回 -1
*/
/* template <typename ForwardIt, class T>
int binary_search(ForwardIt low, ForwardIt high, const T &value)
{
	auto low_dump = low;
	auto high_dump = high;
	auto mid = low + ((high - low) >> 1);
	while ((low <= high) && (mid != high_dump))
	{
		if (*mid <= value)
		{
			if ((mid == high_dump - 1) || (*(mid + 1) > value))
				return mid - low_dump;
			else
				low = mid + 1;
		}
		else if (*mid > value)
			high = mid - 1;
		mid = low + ((high - low) >> 1);
	}
	return -1;
}
 */
int main(void)
{
	vector<int> a{0, 1, 3, 4, 5, 6, 8, 8, 8, 11, 18};
	vector<int> dst{8, 1, 2, 5, 3, 88, 0, 18, 45};
	int ret = 0;
	for (auto tmp : dst)
	{
		cout << "search for " << tmp << endl;
		ret = binary_search<Iter, int>(a.begin(), a.end(), tmp);
		if (ret == -1)
			cout << "not founnd" << endl
				 << endl;
		else
			cout
				<< "found it at index == " << ret << " value == " << a[ret] << endl
				<< endl;
	}
}
