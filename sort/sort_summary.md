### 一、冒泡排序

通过与`相邻元素的比较和交换`来把小的数交换到最前面。这个过程类似于水泡向上升一样，因此而得名

原地，稳定，冒泡排序时间复杂度最好的情况为O(n),最坏的情况是O(n^2)

改进思路1：设置标志位，明显如果有一趟没有发生交换（flag = false)，说明排序已经完成

```cpp
void buddySort(vector<int> &vv)
{
    auto count = vv.size();
    bool  tag  =  false;
    for (int i = 0; i < count; i++)
    {
        tag  =  false;//提前退出冒泡的标志位
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
```


### 二、插入排序
数组中的数据分为两个区间，已排序区间和未排序区间。初始已排序区间只有一个元素，就是数组的第一个元素。插入算法的核心思想是取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，并保证已排序区间数据一直有序。重复这个过程，直到未排序区间中元素为空，算法结束。

原地，稳定
时间复杂度也为O(n^2), 比冒泡法和选择排序的性能要更好一些
在排好序时，复杂度会为O(n)

```cpp
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

```

### 三、简单选择排序

分已排序区间和未排序区间。但是选择排序每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾。

原地，不稳定
O(n^2),但简单选择排序的性能要略优于冒泡排序 

```cpp
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
```

### 四、希尔排序(不清楚)

### 五、归并排序

先分后合

`分治是一种解决问题的处理思想，递归是一种编程技巧`

`不是原地排序`，稳定，时间复杂度为O(nlogn)－＞比较稳定
空间复杂度为O(n+logn)　
如果非递归实现归并,则避免了递归时深度为logn的栈空间 空间复杂度为O(n)

```cpp
// 归并排序算法, A 是数组，n 表示数组大小
merge_sort(A, n) {
  merge_sort_c(A, 0, n-1)
}

// 递归调用函数
merge_sort_c(A, p, r) {
  // 递归终止条件
  if p >= r  then return

  // 取 p 到 r 之间的中间位置 q
  q = (p+r) / 2
  // 分治递归
  merge_sort_c(A, p, q)
  merge_sort_c(A, q+1, r)
  // 将 A[p...q] 和 A[q+1...r] 合并为 A[p...r]
  merge(A[p...r], A[p...q], A[q+1...r])
}


merge(A[p...r], A[p...q], A[q+1...r]) {
  var i := p，j := q+1，k := 0 // 初始化变量 i, j, k
  var tmp := new array[0...r-p] // 申请一个大小跟 A[p...r] 一样的临时数组
  while i<=q AND j<=r do {
    if A[i] <= A[j] {
      tmp[k++] = A[i++] // i++ 等于 i:=i+1
    } else {
      tmp[k++] = A[j++]
    }
  }
  
  // 判断哪个子数组中有剩余的数据
  var start := i，end := q
  if j<=r then start := j, end:=r
  
  // 将剩余的数据拷贝到临时数组 tmp
  while start <= end do {
    tmp[k++] = A[start++]
  }
  
  // 将 tmp 中的数组拷贝回 A[p...r]
  for i:=0 to r-p do {
    A[p+i] = tmp[i]
  }
}

```

### 六、堆排序（完全二叉树）

两步：建堆与排序

时间复杂度为 O(nlogn)

### 七、快速排序

找到一个分区点，然后将小的放在前面，大的放在后面，分区点放在中间．最后发现待排序的区间变为1时停止．

原地，不稳定，O(nlgn)　

```cpp
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
```

优化：三数取中法,随机法，
- qsort函数:
1. qsort() 会优先使用归并排序来排序输入数据
2. 要排序的数据量比较大的时候，qsort() 会改为用快速排序算法来排序。
3. qsort() 是通过自己实现一个堆上的栈，手动模拟递归来解决的
4. qsort() 并不仅仅用到了归并排序和快速排序，它还用到了插入排序。在快速排序的过程中，当要排序的区间中，元素的个数小于等于 4 时，qsort() 就退化为插入排序，不再继续用递归来做快速排序，因为我们前面也讲过，在小规模数据面前，O(n2) 时间复杂度的算法并不一定比 O(nlogn) 的算法执行时间长

### 八：计数排序

### 九：桶排序
核心思想是将要排序的数据分到几个有序的桶里，每个桶里的数据再单独进行排序。桶内排完序之后，再把每个桶里的数据按照顺序依次取出
组成的序列就是有序的了

`适合用于在外部排序中`

### 十：基数排序

从方法的稳定性来比较，基数排序是稳定的内排方法，

所有时间复杂度为O(n^2)的简单排序也是稳定的。
快速排序、堆排序、希尔排序等时间性能较好的排序方法都是不稳定的。稳定性需要根据具体需求选择。





