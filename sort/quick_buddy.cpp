/*************************************************************************
	> File Name: test.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月14日 星期四 11时04分50秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*void buddySort(vector<int> &vv)
{
    auto count = vv.size();
    bool  tag  =  false;
    for (int i = 0; i < count; i++)
    {
        tag  =  false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (vv[j] > vv[j + 1]){
                std::swap(vv[j], vv[j + 1]);
                tag = true ;// 表示有数据交换

            }
        }
        if(!tag)  break;//没有数据交换，提前退出
    }
}
void xuanSort(vector<int> &vv)
{
    auto count = vv.size();
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (vv[i] > vv[j])
                std::swap(vv[j], vv[i]);
        }
    }
}
*/
int partion(vector<int> &vv, int l, int r)
{
    int k = l;
    int mid = vv[r];
    for (int i = l; i < r; i++)
    {
        if (vv[i] <= mid)
            std::swap(vv[i], vv[k++]);
    }
    std::swap(vv[k], vv[r]);
    return k;
}
void fun(vector<int> &vv, int l, int r)
{
    if (l >= r)
        return;
    int q = partion(vv, l, r);
    fun(vv, l, q - 1);
    fun(vv, q + 1, r);
}
void quickSort(vector<int> &vv)
{
    fun(vv, 0, vv.size() - 1);
}
int main(void)
{
    vector<int> vv{5, 2, 1, 8, 9, 4, 6, 11, 5};
    // buddySort(vv);
    // xuanSort(vv);
    quickSort(vv);
    for (auto i : vv)
        cout << i << endl;
}
