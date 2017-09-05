#include <stdio.h>  
  void create_btree(int list[], int bt[], int n) /*n表示list数组中元素的个数*/  
  {  
      int i, order;  
    
      bt[1] = list[0];  
      for(i = 1; i < n; i++)  
      {  
            order = 1; /*每次进来从根结点开始比较*/  
            while(bt[order] != 0)  
            {  
                    if(list[i] < bt[order])  
                        order *= 2;  
                    else  
                        order = order*2 + 1;  
            }  
            bt[order] = list[i];  
    }  
  }  
  void outpit(int bt[] )
  {
    
  }
    int main()  
    {  
        int list[7] = {30, 18, 16, 25, 34, 7, 31};  
        int bt[16] = {0};  
        int i;  
        create_btree(list, bt, 7);  
        for(i = 0; i < 16; i++)   /*按层输出*/  
                printf("%4d", bt[i]);  
        printf("\n");  
      
        return 0;  
    }  
