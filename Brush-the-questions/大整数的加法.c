/*题目描述：
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B. 
Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000. 
Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases. 
Sample Input
2
1 2
112233445566778899 998877665544332211
Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110*/

//这道题没过，但我说一下大整数的加法 */

#include <stdio.h>
#include <string.h>
#define N 100
void main(void)
{
	char s1[N],s2[N];
	int s[N],i,j,k=0,t=N-1,cp=0;
	printf("请输入两个整数:\n");
	gets(s1);
	gets(s2);
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
		s[t--]=1;
	for(i=t+1;i<N;i++)
		printf("%d",s[i]);
	printf("\n");
}
