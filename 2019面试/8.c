/*8．下面代码段的输出结果是什么？输出该结果的原因是？*/
#include <stdio.h>

//#define X (a + b)
#define X a + b

int main(int argc, char *argv[])

{

    int a = 1, b = 2;

    printf("%d\n", X * X); // 3

    return 0;
}
/*
这个我也不知道咋拓展了
*/