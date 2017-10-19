/*************************************************************************
	> File Name: Decimal_conversion.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月17日 星期二 21时03分06秒
 ************************************************************************/
/*输出正整数 x 的二进制数值*/

#include<stdio.h>
void fun(int x)
{
    if(x == 0 ) return ; //递归出口
    else {
        fun(x/2);  //先调后处理
        printf("%2d",x%2);
        //fun(x/2);  //先处理后调
    }
}
int main(void)
{
    int x ;
    printf("Please inout the \nX :");
    scanf("%d",&x);
    fun(x);
    printf("\n\n");
    return  0;
}
