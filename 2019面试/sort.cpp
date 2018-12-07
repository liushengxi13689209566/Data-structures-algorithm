
#include <iostream>
#include <vector>
using namespace std;

vector<int> TT{4,
               8,
               9,
               0,
               545,
               45,
               6,
               5,
               7,
               8,
               9999,
               5,
               1,
               2,
               4,
               564,
               43,
               1,
               64,
               4};

void InsertSort(vector<int> &a)
{
    int len = a.size();
    if (len <= 1)
        return;
    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;
        /*查找插入的位置*/
        for (; j >= 0; j--)
        {
            if (a[j] > key)
                a[j + 1] = a[j]; /*数据移动*/
            else
                break;
        }
        a[j + 1] = key; //数据插入
    }
}
/*在这个函数中会改变原数组，见下图：*/
/*从头到尾迭代，和支点比较，大的不管，小的换。换了才往后看。最后支点戳中间，算是分界线*/
int partition(vector<int> &a, int l, int r)
{
    int k = l, pivot = a[r];
    int temp = 0;
    for (int i = l; i < r; i++)
    {
        if (a[i] <= pivot) /*相等的元素要么放右边，要么放左边*/
        {
            std::swap(a[i], a[k++]);
        }
    }
    std::swap(a[k], a[r]);
    return k;
}
/*快速排序递归函数*/
void quick_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int q = partition(a, l, r); /*获取分区点*/
    quick_sort(a, l, q - 1);
    quick_sort(a, q + 1, r);
}

void QuickSortWithRecursive(vector<int> &a)
{
    quick_sort(a, 0, a.size() - 1);
}
void Print(const vector<int> &vv)
{
    for (auto t : vv)
        cout << t << " ";
    cout << endl;
}
void BubbleSort(vector<int> a)
{
    int len = a.size();
    if (len <= 1)
        return;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j + 1] < a[j])
                std::swap(a[j], a[j + 1]);
        }
    }
    for (auto t : a)
        cout << t << " ";
    cout << endl;
}
void SelectSort(vector<int> a)
{
    int len = a.size();
    if (len <= 1)
        return;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[i])
                std::swap(a[j], a[i]);
        }
    }
    for (auto t : a)
        cout << t << " ";
    cout << endl;
}
int main(void)
{

    vector<int> test(TT);
    BubbleSort(test);
    SelectSort(test);
    //2
    // test = TT;
    InsertSort(test);
    Print(test);

    //3
    test = TT;
    QuickSortWithRecursive(test);
    Print(test);
}
