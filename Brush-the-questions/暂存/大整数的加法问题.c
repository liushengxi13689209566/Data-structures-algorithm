#include <stdio.h>
#include <string.h>
#define N 10000
void main(void)
{
	char s1[N],s2[N];
    char  s[N];
    int i,j,k=0,t=N-1,cp= 0;
    int n ,num ;
    while(scanf("%d",&n)  !=  EOF)
    {
        getchar();
        num = 0 ;
        while(n--)
        {
            num++ ;
            scanf("%s%s",s1,s2);
	        i=strlen(s1)-1;
	        j=strlen(s2)-1;
	        while(i>= 0 || j>= 0)
	        {
		        if(i>=0 && j>=0)
			        k=s1[i--]+s2[j--]+ cp ;
		        else
			        if(i>=0 && j< 0)
				        k=s1[i--]+cp;
			        else
				        k=s2[j--]+cp;
		        cp=k/10;
		        s[t--]= k%10+ '0' ;
	        }
	        if(cp)
		        s[t--]= '1';
            printf("Case %d:\n",num );
            printf("%s + %s = %s\n",s1,s2,s);
	      
        }
    }
}


		
