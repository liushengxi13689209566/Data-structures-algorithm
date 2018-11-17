/*************************************************************************
	> File Name: Reverse_Integer.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月10日 星期二 22时02分10秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
/*###问题描述：
#### 反转数字的整数。

Example1： x = 123，return 321 
Example2： x = -123，return -321

注意：
输入假定为32位有符号整数。当反转的整数溢出时，您的函数应返回0。-2147483648    ~   +2147483647*/

int reverse(int x) {
    int result= 0;
    int temp = 0 ;
    while(1)
    {
        temp = x % 10 ;
        result = result *10 + temp ;
        printf("temp== %d\n",temp);
        printf("result == %d \n",result);  //输入为-2147483412 时，刚好不会越界，那么就要先判断所输入的整数，是否已经处理完所有的位数
        x=x/10;
        printf("x== %d \n",x);
        if(!x)  break;

        if(result*10/10  !=  result )   //反转的时候，只要乘上10就会越界，那么就直接返回0
            return 0 ;
    }
    return  result;
}
int main(void)
{
    int x;
    int y ;
    scanf("%d",&x);
    y=reverse(x);
    printf("y== %d\n",y);
    return 0;
}




