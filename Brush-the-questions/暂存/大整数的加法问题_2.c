#include <stdio.h>
#include <string.h>
#define N 10000
void main(void)
{
	char s1[N],s2[N];
	int s[N],i,j,k ,t,cp;
    int n ,num ,temp;
    while(scanf("%d",&n) != EOF)
    {
        getchar() ;
        num = 0;
        temp = n;
        while(n--)
        {
            t= N- 1;
            cp= 0;
            k= 0;
            num ++ ;
            scanf("%s%s",s1,s2);
            getchar() ;
	        i=strlen(s1)-1;
	        j=strlen(s2)-1;
	        while(i>=0 || j>=0)
	        {
		        if(i>=0 && j>=0)
			        k=s1[i--]-'0'+s2[j--]-'0'+cp;
		        else
			        if(i>=0 && j<0)
				        k=s1[i--]-'0'+cp;
			        else
				        k=s2[j--]-'0'+cp;
		        cp=k/10;
		        s[t--]=k%10;
	        }
	        if(cp)
		    s[t--]= 1;
            printf("Case %d :\n",num );
            printf("%s + %s = ",s1,s2);
	        for(i=t+1;i< N;i++)
		            printf("%d",s[i]);
            if(num != temp)
                  printf("\n\n");
          
        }
    }

}


