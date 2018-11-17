/*************************************************************************
	> File Name: 4-2.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月20日 星期四 13时23分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

void fun(char a[],int start,int end)  //从start 到end 逆置
{
    int i,j;
    char temp;
    for(i=start,j=end;i< j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int main(void)
{
    char str[1000];
    int m,i,t,n;
    while(scanf("%d",&t) != EOF)
    {
        getchar();
        while(t--)
        {
            n= 0 ;
            gets(str);
            for(i= 0;str[i] ;i++)
            {
                if(str[i]==' ' && str[i + 1] == ' ')  //处理前面有多个空格的情况
                    continue;
                if(str[i]== ' ' &&  str[i+ 1] != ' ')  //找到start
                        n= i + 1;
                if(str[i] !=' '&&str[i+ 1] == ' '|| str[i + 1]== 0) //找到end 
                {
                    m= i ;
                    fun(str,n,m);//反转字符
                }
            }
            printf("%s\n",str);
        }
    }
}

