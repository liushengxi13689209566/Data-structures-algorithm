/*************************************************************************
	> File Name: Polynomial_calculator.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月22日 星期日 13时33分57秒
 ************************************************************************/

#include<stdio.h>
#define MAX  1000
int level(char p)
{
    int temp ;
    switch(p)
    {
        case '*';
        case '/':temp = 3;
        case '+':
        case '-':temp = 2;
        case '(':temp = 1;
        case '@':temp = -1;
    }
    )
    returnn temp ;
}

float fun(char str[])
{
    float Symbol[MAX],SymbolTop= -1;
    float number[MAX],numberTop= -1;
    float y=0; //计算数值
    int i= 0;
    Symbol[++SymbolTop]='@'; //先把 @ 入到符号栈中
    while(str[i]){
        y= 0;
        if(str[i] <= '9' && str[i] >= '0'){
            while(str[i] <= '9' && str[i] >= '0'){
                y= y*10+str[i]-'0';
                    i++;
            }
        }
        number[++numberTop]=y ; //入栈数值
        else if(str[i] > '9' && str[i] < '0' ){
            while(level[str[i] < level[Symbol[SymbolTop]]])
            {
                op=

            }
        }
    }
}

int main(void)
{
    char str[MAX];
    float result ;
    printf("Please input the str (please sure it right)\n");
    gets(str);
    printf("You input is %s \n",str);
    result=fun(str);
    printf("result = %f \n",result);
    return 0;
}
