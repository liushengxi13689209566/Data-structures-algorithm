
#include <iostream>    
#include <algorithm>   
using namespace std ;   
  
#define MAX 101    
  
int D[MAX][MAX];     
int n;    
int maxSum[MAX][MAX];   
int main(){  
    int i,j ,count ;      
	while(cin >> count && count ){
		cin >> n;      
		for(i=1;i<=n;i++)    
			for(j=1;j<=i;j++)          
				cin >> D[i][j];     
		// for(i=1;i<=n;i++){ //打印 D 数组
		//     for(j=1;j<=i;j++){
		//         cout <<  D[i][j] << "  ";   
		// 	}
		// 	cout << endl ;
		// }
		// cout << endl;  


		for( int i = 1;i <= n; ++ i )       
			maxSum[n][i] = D[n][i];
		// for(i=1;i<=n;i++){  //打印  maxSum  数组
		//     for(j=1;j<=i;j++){
		//         cout << maxSum[i][j] << "  ";   
		// 	}
		// 	cout << endl ;
		// }
		// cout << endl;  
		for( int i = n-1; i >= 1;  --i ){     
			for( int j = 1; j <= i; ++j ){           
				maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j];      
			}
		}
		cout << maxSum[1][1] << endl;    
	}
}  