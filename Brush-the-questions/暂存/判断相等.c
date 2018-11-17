/*************************************************************************
	> File Name: 判断相等.c
	> Author: Linuxer_liu
	> Mail: 
	> Created Time: 2017年08月03日 星期四 10时37分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    double a,b; 
    double temp ;
    while(scanf("%lf%lf",&a,&b) != EOF)
    {
        temp = a-b ;
        if((temp >= -0.000001) && (temp <= 0.000001) )/*判断temp是否是0 */
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
