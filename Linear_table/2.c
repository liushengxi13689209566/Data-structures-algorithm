//对于这题，贪心的策略是，用cur_sum记录，以当前数组的第i个元素为求和子数组最后一个元素，所能取得的最大和。
//进一步的，如果cur_sum + tar[i] < 0，则将cur_sum设置为0，说明这个i元素，不应该出现在后面的求和子数组中（换句话说，以tar[i]结尾的最大和是负值，那么后面的字数组没有贡献）
//如果cur_sum + tar[i] > 0 那么就把cur_sum 设置为cur_sum + tar[i]

#include<stdio.h> 
int get_max(int *tar, int num, int *idx)
{                            //这里idx要修改为指针，因为要在函数中改变下标值。
    int max_sum = 0;
    int cur_sum = 0;
    for(int i = 0; i < num; i++)
    {
        if(cur_sum + tar[i] > 0)
        { //
            cur_sum += tar[i];
            if(cur_sum > max_sum)
            {//update max_sum
                max_sum = cur_sum;
                *idx = i; //相应于指针的修改
            }
        }
        else
        {     
           cur_sum = 0;
        }
    }
    return max_sum;
}
  
int main()
{
    int a[10] = {-1,2,3,4,-3,7,-7};
    int tar_idx = 0;//保存最大字数组和的最后一个元素的下标
    printf("%d\n", get_max(a, 7, &tar_idx));
    printf("最后一个元素的下表是 ： %d \n",tar_idx) ;
    return 0;
}
