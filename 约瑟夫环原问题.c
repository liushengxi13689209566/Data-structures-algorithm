#include<stdio.h>
int main(){  
    int n,m;  
    while(scanf("%d %d",&n,&m)==2&&n&&m){  
        int ans = 0;  
        for(int i = 1;i <= n;++i){  
            ans = (ans + m) % i;  
        }  
        printf("总人数:%d 每次出列的人喊的号数:%d 最后一个出列的人的序号:%d\n",n,m,ans+1);  
    }  
    return 0;  
}  
