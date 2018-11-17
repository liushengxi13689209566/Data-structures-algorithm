/*************************************************************************
	> File Name: 5-2.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月21日 星期五 12时32分55秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
 

int main(void)
{
    int n ,i ,j ,temp ;
    char str[5000];
    while(scanf("%d",&n) != EOF)
    {
        while(n--)
        {
            scanf("%s",str);
            j=temp=strlen(str)-1;
            for(i= 0 ;i< temp ;i++,j--)
            {
                if(str[i] != str[j])
                    break;
            }
            if(i != temp) printf("no\n");
            else printf("yes\n");

        
        }
    }
}
