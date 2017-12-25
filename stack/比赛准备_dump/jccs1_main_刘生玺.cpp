/*************************************************************************
	> File Name: jccs1_main_刘生玺.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 23时28分11秒
 ************************************************************************/
#include"myhead.h"
using namespace std;
int main(int argc ,char *argv[] )
{
    if( argc !=  2 ){
        cout << "    格式错误！！请这样输入“ 执行程序名 输入数据文件名 ” " <<  endl ;
        return -1;
    }
    Solution S1(argv[1]);
    if( !S1.readFile()){
        cout << "        执行readFile 函数出错" << endl ;
        return -2;
    }
    return 0;
}
