// /*#include<iostream>
// using namespace std;
// const int TT = 3 ;
// int arr[TT]={1,2,3};
// void swap(int x,int y) //用于交换数组的两个数
// {
//     int temp=arr[x];
//     arr[x]=arr[y];
//     arr[y]=temp;
// }
// int resove(int n)//递归函数
// {
//         if(n==TT)//当尝试对不存在的数组元素进行递归时，标明所有数已经排列完成，输出。
//         {
//             for(int i=0;i<TT;i++)
//             cout<<arr[i];
//             cout<<endl;
//             return 0;
//         }
//         for(int i=n;i<TT;i++)//循环实现交换和之后的全排列
//         {
//             //i是从n开始 i=n;
//             //swap(n,i)相当于固定当前位置，在进行下一位的排列。
//             swap(n,i);
//             resove(n+1);
//             swap(n,i);
//         }
// }
// int main()
// {
//     resove(0);
// }
// */
// #include <functional>
// #include <queue>
// #include <vector>
// #include <iostream>
// #include<utility>
// using namespace std;
// template<typename T> void print_queue(T& q) {
//     while(!q.empty()) {
//         std::cout << q.top() << " ";
//         q.pop();
//     }
//     std::cout << '\n';
// }
// struct cmp{
//     template<typename T>
//     bool  operator()(const T &left,const T &right){
//         if(left.second > right.second )
//             return true ;
//         else
//             return false ;
//     }
//     private:
//     pair<int,int> p;
// };
// int main() {
//     std::priority_queue<pair<int,int>,cmp> q;
//     int index = 1 ;
//     for(int n : {1,8,5,5,5,4,0,9,7,2})
//         q.push(make_pairs(n,index++));

//     print_queue(q);
// }
// #include <iostream>
// #include <sstream>
// using namespace std;
// int main(void)
// {
//     double num = 32.0100;
//     std::ostringstream oss;
//     oss << num;
//     std::cout << oss.str() << std::endl;
//     string str = oss ;
//     cout << "string str =="<< str <<  endl;
// }
#include <string>
#include <iostream>
using namespace std;
int main()
{
  std::string foo("liulvrvbhkw");
  auto pos  =  foo.rfind("l");
  std::string temp = foo.substr(pos);
  std::cout <<temp  <<   std::endl ; 
}
