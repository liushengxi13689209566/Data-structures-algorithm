/*************************************************************************
	> File Name: gcd_算法.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月24日 星期一 12时02分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
long long  gcd(long long  a,long long b)
{  
    return a%b ?gcd(b,a%b):b;
}
int main(void)
{
    long long  a,b,c,d ;
    long  long y,x;
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%lld/%lld",&a,&b);
        scanf("%lld/%lld",&c,&d);
        x=gcd(a,b);
        a/=x;
        b/=x;
        x=gcd(c,d);
        c/=x;
        d/=x;
        x=(a*c)/gcd(a,c);
        y=gcd(b,d);
        if(x%y) printf("%lld/%lld\n",x,y);
        else printf("%lld\n",x/y);
    }
}


