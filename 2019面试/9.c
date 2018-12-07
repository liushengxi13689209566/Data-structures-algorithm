
/*9．执行下列程序段，并输入“Xiyou Linux”（不含引号），那么程序的输出结果是什么？请解释其原因。该程序中有一处隐患，请找出并说明。*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  char *p = (char *)malloc(sizeof(char) * 20);

  char *q = p;

  scanf("%s %s", p, q); //会自动加入结束符

  printf("%s %s\n", p, q);

  return 0;
}
/*　
　1.　free  危害　－＞　写时复制（一直malloc很快，但是 malloc 并　write　就会变得很慢了）
  2.  scanf 工作原理(键盘缓冲区等等)　
  3.　如果改为xiyouyouyouyouyou 　linux 　会不会有变化　（不会）
  4.　如果输入多于20个字符的话，会产生缓冲区溢出（溢出指数据被添加到分配给该缓冲区的内存块之外）
  当向缓冲区里写入的数据超过了为其分配的大小时，就会发生缓冲区溢出。
  攻击者可以利用缓冲区溢出来窜改进程运行时栈，从而改变程序的正常流向。
*/
