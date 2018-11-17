/*问题描述：
求n个数的最小公倍数。
Input
输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。
Output
为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。
Sample Input
2 4 6
3 2 5 7*/

#include<stdio.h>
int fun(int x,int y)   //返回 x 和 y 的最小公倍数
{
    int k ;
    for(k=x>y?x:y ; ;k++)
    {
        if(k%x== 0 && k%y == 0)
        break;
    }
    return k;
}
int main(void)
{
    int   n ,y,temp,num ;
    while(scanf("%d",&n) != EOF)
    {
        temp= n;
        while(n--)
        {
            scanf("%d",&y);
            if(temp == (n + 1))
                num=fun(1,y);
            else num=fun(num,y);
        }
            printf("%d\n",num );
    }
}

/*更好的方法是：两个数的情况:设两个数分别为a,b先用辗转相除法求gcd(a,b)，
也就是a,b的最大公约数然后lcm(a,b)=a*b/gcd(a,b)n个数的情况:
设n个数分别为a1,a2,……an则先求b1=lcm(a1,a2)
再求b2=lcm(b1,a3)b3=lcm(b2,a4)b4=lcm(b3,a5)……
最后求到b[n-1]就是答案
复杂度接近O(n)

