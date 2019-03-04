/*************************************************************************
	> File Name: Heap.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2019年03月04日 星期一 15时50分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>

using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    while (true)
    {
        int maxPos = i;
        if (i * 2 <= n && a[i] < a[i * 2])
            maxPos = i * 2;
        if (i * 2 + 1 <= n && a[maxPos] < a[i * 2 + 1])
            maxPos = i * 2 + 1;
        if (maxPos == i)
            break;
        swap(a[i], a[maxPos]);
        i = maxPos;
    }
}

void buildHeap(vector<int> &a, int n)
{
    for (int i = n / 2; i >= 1; --i)
    {
        heapify(a, n, i);

        for (auto i : a)
            cout << i << "  ";
        cout << endl;
        sleep(1);
    }
    for (auto i : a)
        cout << i << "  ";
    cout << endl;
    sleep(1);
}

// n 表示数据的个数，数组 a 中的数据从下标 1 到 n 的位置。
void sort(vector<int> &a, int n)
{
    buildHeap(a, n);
    int k = n;
    while (k > 1)
    {
        swap(a[1], a[k]);
        --k;
        heapify(a, k, 1);
    }
}

int main(void)
{
    vector<int> nums({0, 7, 5, 19, 8, 4, 1, 20, 13, 16});

    sort(nums, nums.size() - 1);
}
