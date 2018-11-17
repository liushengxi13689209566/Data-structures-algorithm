/*问题描述：
青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
Input
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
Output
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。*/

## 个人见解：输入输出并不重要，重要的是计算的方法和思考问题的角度 ！！！！！！！！！！！

#include <stdio.h>
int main(void)
{
    int n, i;
    double min, max;
    double x, y;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%lf", &x);
        min = max = x;
        for (i = 1 ; i < n ; i++)  //不要想着排序，也不要想着先遍历一遍数组找到最大，最小值
          {
             scanf("%lf", &y);
             x += y;
             if (y > max) max = y;
             if (y < min) min = y;
          }

        printf("%.2lf\n", (x - min - max) / (n - 2));
     }
    return 0;
}

