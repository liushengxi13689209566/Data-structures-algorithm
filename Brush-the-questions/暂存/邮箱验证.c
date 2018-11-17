
/*问题描述：
POJ 注册的时候需要用户输入邮箱，验证邮箱的规则包括： 
1)有且仅有一个'@'符号 
2)'@'和'.'不能出现在字符串的首和尾 
3)'@'之后至少要有一个'.'，并且'@'不能和'.'直接相连 
满足以上3条的字符串为合法邮箱，否则不合法， 
编写程序验证输入是否合法*/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[100];
    int i ,j ,flag,flag2;
    while(scanf("%s",str)  !=  EOF)
    {
        flag=0;
        flag2= 0;
        if(str[0]== '.' || str[0] == '@' ||str[strlen(str)-1] == '.' || str[strlen(str) - 1] == '@' )  //判断首尾
        {
            printf("NO\n");
            continue;
        }
        for(i= 0;str[i] ;i++) //统计 @  个数
        {
            if(str[i] == '@')
            flag2++ ;
        }
        if(flag2 != 1)    {printf("NO\n"); continue ;}  //大于1 ，退出
        for(i= 0;str[i] != '@' ;i++ )    //找到@ 的位置
            ;
        if(str[i+ 1] == '.' || str[i -1]== '.'  ) //判断 . 与 @  是否相连
        {
            printf("NO\n");
            continue;
        }
        for(j= i+ 2;str[j] ;j++)  //必须出现一个 .
        {
            if(str[j] == '.')
                flag++ ;
        }
        if(flag  == 0) printf("NO\n");
        else        printf("YES\n");
    }
}
