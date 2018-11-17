/*2007年3月26日，在中俄两国元首的见证下，中国国家航天局局长孙来燕与俄罗斯联邦航天局局长别尔米诺夫共同签署了《中国国家航天局和俄罗斯联邦航天局关于联合探测火星-火卫一合作的协议》，确定中俄双方将于2009年联合对火星及其卫星“火卫一”进行探测。 

而卫星是进行这些探测的重要工具，我们的问题是已知两颗卫星的运行周期，求它们的相遇周期。 
Input
输入数据的第一行为一个正整数T, 表示测试数据的组数. 然后是T组测试数据. 每组测试数据包含两组正整数，用空格隔开。每组包含两个正整数，表示转n圈需要的天数(26501/6335，表示转26501圈要6335天)，用'/'隔开。 
Output
对于每组测试数据, 输出它们的相遇周期，如果相遇周期是整数则用整数表示，否则用最简分数表示。 
Sample Input
2
26501/6335 18468/42
29359/11479 15725/19170
Sample Output
81570078/7
5431415  */

//不要问我题目意思是什么，因为我也不知道 。还是那句话，题目是什么不重要！重要的是其中包含的gcd算法！！！*/


#include<stdio.h>
#include<stdlib.h>
long long  gcd(long long  a,long long b)
{  
    return a%b ?gcd(b,a%b):b;  //gcd算法。这是重点！！！！！
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
/*所谓的gcd就是辗转相除法，就是欧几里得算法。*/


