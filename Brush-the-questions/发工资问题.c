/*************************************************************************
	> File Name: 发工资问题.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月03日 星期四 11时13分33秒
 ************************************************************************/
/*题目描述：
最近在财务打工的HJL同学在考虑一个问题：如果每个员工的工资额都知道，最少需要准备多少张人民币，才能在给每位员工发工资的时候都不用找零呢？ 
这里假设所有员工的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。 
Input
输入数据包含多个测试实例，每个测试实例的第一行是一个整数n（n<100），表示员工的人数，然后是n个员工的工资。 
n=0表示输入的结束，不做处理。 
Output
对于每个测试实例输出一个整数x,表示至少需要准备的人民币张数。每个输出占一行。 
Sample Input
3
1 2 3
0
Sample Output
4*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int b[6]={100,50,10,5,2,1};
int main(void)
{
    int n ;
    int a[1000];
    int i ,j ;
    int num ;
    int temp ;
    while(scanf("%d",&n) != EOF)
    {
        memset(a,0,sizeof(a));
        i= 0;
        temp = n ;
        num = 0  ;
        if( !n)
          break;
        while(temp--)
        {
            scanf("%d",&a[i]);
            i++ ;
        }
        for(i= 0;i< n;i++)    /*拿一个数出来处理*/
        {
            for(j = 0;j< 6  ;j++)
            {
                    num =num + a[i]/b[j];
                    a[i]= a[i]%b[j];
            }
        }
        printf("%d\n",num );
    }
    return 0;
}

