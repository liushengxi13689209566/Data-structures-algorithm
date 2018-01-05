/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 17时09分17秒
 ************************************************************************/

#include<iostream>
#include<sstream>
using namespace std;
template <class Type>  
Type stringToNum(const string& str){  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  

int main(int argc, char* argv[])  {  
    string str("00801");  
    cout << stringToNum<int>(str) << endl;  

    return 0;  
}  
