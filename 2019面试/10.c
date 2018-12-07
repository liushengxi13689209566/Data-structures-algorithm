/*10．执行下面的程序段，整理并解释输出结果。*/
#include<stdio.h>
#if(0)
int main(int argc, char *argv[])
{

    int a[4] = {2, 0, 1, 9};

    printf("%p, %p\n", a, &a);

    printf("%p, %p\n", a + 1, &a + 1);

    return 0;
}
#endif
//  a ==  &a[0] :数组首元素的地址
//  &a : 数组首地址
#if(1)
    int main(void){
        int a[5]={1,2,3,4,5};
        int *ptr= (int *)(&a+1);
        printf("%d,%d\n",*(a+1),*(ptr-1));
    }
#endif  
