/*************************************************************************
	> File Name: 3-2.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年07月19日 星期三 14时20分52秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    int k ;
    int x,y;
    scanf("%d%d",&x,&y);
    for(k=x>y?x:y ; ;k++)
    {
        if(k%x== 0 && k%y == 0)
        break;
    }
    printf("%d\n",k);

}

