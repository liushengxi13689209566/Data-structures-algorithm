/*************************************************************************
	> File Name: Heap_sorting.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月12日 星期二 22时48分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class HEAP {
    public :
    void HeapAdjust(vector<int>  &vec, int parent, int size) {
        int temp = vec[parent]; // temp保存当前父节点
        int child = 2 * parent + 1; // 先获得左孩子
        while (child < size ){
            // 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
            if (child + 1 < size  && vec[child] < vec[child + 1]) {
                child++;
            }
            // 如果父结点的值已经大于孩子结点的值，则直接结束
            if (temp >= vec[child])
                break;

            // 把孩子结点的值赋给父结点
            vec[parent] = vec[child];
            // 选取孩子结点的左孩子结点,继续向下筛选
            parent = child;
            child = 2 * child + 1;
        }
        vec[parent] = temp;
    }
    void heapSort(vector<int> &list) {

        // 循环建立初始堆

        for (int i = list.size() / 2; i >= 0; i--) {
            HeapAdjust(list, i, list.size());
        }
        // 进行n-1次循环，完成排序
        for (int i = list.size() - 1; i > 0; i--) {
            // 最后一个元素和第一元素进行交换
            int temp = list[i];
            list[i] = list[0];
            list[0] = temp;

            // 筛选 R[0] 结点，得到i-1个结点的堆

            HeapAdjust(list, 0, i);
            cout << ("第 %d 趟: \t", list.size() - i) << endl ;
            printPart(list, 0, list.size() - 1);
        }
    }
    // 打印序列
    void printPart(vector<int> &list, int begin, int end) {
        for (int i = begin; i <= end; i++) {
            cout << list[i] << "   "  ;
        }
        cout << endl ;
    }
};
int  main(void) 
{

        // 初始化一个序列
        vector<int> vec{ 1, 3, 4, 5, 2, 6, 9, 7, 8, 0 };
        // 调用堆排序方法

        HEAP heap ;

        cout << "排序前 : " << endl ;

        heap.printPart(vec, 0, vec.size() - 1);

        heap.heapSort(vec);

        cout << "排序后 :  " << endl ;

        heap.printPart(vec, 0, vec.size() - 1);
}

