#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<ctime> 
using namespace std;

int main(){
	int i;
	int cases = 10;
	
	srand(time(0)); 
	freopen("data.txt","w",stdout);
	
	while( cases-- ){
		int len = rand()%15+1; 
		for(i=1;i<=len;i++){
			int opt = rand()%4;
			if( opt==0 )	printf("(");
			else if( opt==1 )	printf(")");
			else if( opt==2 )	printf("*");
			else
				printf("%c",rand()%26+'a');
		} 
		printf("\n");
	}
	
		
	return 0;
}
