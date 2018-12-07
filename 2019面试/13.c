/*************************************************************************
	> File Name: 13.c
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年12月03日 星期一 11时03分48秒
 ************************************************************************/
/*13．请简单叙述两种字节序（大端、小端）的概念，你的机器是什么字节序？
 * 试着写一个 C 语言程序来验证，如果你没有思路，你可以尝试着使用联合体或者指针。*/

#include<stdio.h>
union node{
    int num ;
    char  ptr;
}test;

int main(void){
    test.num = 0x12345678 ;//从高到低
    //ptr 指向低地址
    if(test.ptr= 0x78){
        printf("小端\n");
    }
    else{ 
        printf("大端\n");
    }


    int number = 0x12345678;
    char *p = (char *)&number;
    if(*p= 0x78){
        printf("小端\n");
    }
    else{ 
        printf("大端\n");
    }
}
//小端：低存低，高存高
