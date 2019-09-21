#include "head.h"

/*思路：题目要求是最少需要的天数，这种题可以看成是股票类型的题目 也就是第一想法是贪心算法

对于题目给出的例子          4 1 8 2 5

我们仔细考虑一下   ：① 3  0  7  1  4 ②  3  0  6  0  3

                                    结果就是3 + 6 + 3   + 2

我们可以看到 每个数就是找出右边比他小的第一个数即可，特殊情况就是最后一个数 那他的大小无关紧要 他一定是自身的大小

因为无论左边的数有比他大 比他小还是一样大 最后加的结果都是他自身

按照贪心的思想 每一步都取到最小 */
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vv(n);
    for (int i = 0; i < n; i++)
        cin >> vv[i];

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (vv[i] > vv[i + 1])
            sum += vv[i] - vv[i + 1];
        cout << sum << endl;
    }
    cout << sum + vv[n - 1] << endl;
    return 0;
}