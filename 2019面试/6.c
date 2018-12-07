/**6．执行下面的代码段，会输出什么？请试着解释其原因，并叙述相关知识。*/

#include <stdio.h>

int main(int argc, char *argv[])
{

    char ch = 255;

    int d = ch + 1;

    printf("%d %d", ch, d); //-1,0

    return 0;
}
/*

 8位　0～255　1111　1111（正数原码即补码）　
 ％d 打印，将255　的补码　转换为　原码，即　-1　
  ch+1 溢出　

*/