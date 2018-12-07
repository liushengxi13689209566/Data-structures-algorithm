

/*2．下面的代码段将打印出多少个“=”？运用相关知识解释该输出。*/

#include <stdio.h>
int main(int argc, char *argv[])
{
    for (unsigned int i = 3; i >= 0; i--)
    {
        printf("    i==%u\n", i);
        putchar('=');
        /*缓冲区的问题*/
    }
    return 0;
}

/*无符号最小值为0，0－1变为最大值(这是为什么？) 

变为-1，-1的补码是（11．．．11），就是 unsigned int 的最大值哦

1.　如何输出 unsigned int数值类型 ?
2.　unsigned int 范围: 0~2^32-1(4294967295) 

*/