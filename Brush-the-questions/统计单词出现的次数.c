/*题目描述：给一堆字符，求里面可以组成单词 “Bulbasaur” 的个数！！！！！

此题统计需要找的单词出现的次数，由于可以任意排序
只需要用数组记录下单词中每个字母出现的次数
然后找到组成单词的字母中最少的那个。*/
#include<stdio.h>
int main(void)
{
    char str[1000000]; //数组要开的足够大
    int a[7]={0};
    int i,min;
    while(scanf("%s",str) !=EOF)
     {   for(i = 0;str[i] ;i++) //遍历整个字符串
        {
            switch(str[i])
            {
                case 'a':a[0]++ ;break;
                case 'b':a[1]++ ;break;
                case 'B':a[5]++ ;break;
                case 'u':a[2]++ ;break;
                case 'l':a[3]++ ;break;
                case 's':a[4]++ ;break;
                case 'r':a[6]++ ;break;
                default :break;
              }
        }
        a[2]/=2;
        a[0]/=2;//要记得将a 和 u ， 除以二！！！！这是重点///
        min =a[0];
        for(i= 0;i< 7 ;i++)
        {
            if(a[i]< min)
               min =a[i];
            a[i] = 0; //赋值为0 。为下次做准备
        }
        printf("%d\n",min);
       }
    return 0;
}

/*
总结一下ACM刷题坑点：
1.数组要开的足够大 ！！
2.while(scanf("***",***) != EOF)  要写上！！
3.各种初始化！！
4.输入输出格式！！*/
