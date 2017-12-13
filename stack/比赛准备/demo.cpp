/*************************************************************************
	> File Name: demo.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月13日 星期三 16时59分00秒
 ************************************************************************/
//#define MAXSIZE  4   会出错
#define MAXSIZE  10000 
//每次读取到内存中的最大字节数 
#include<iostream>
#include<string.h>
#include<stack>

using namespace std;
void   fun(char *str,int LineCount ,const char *temp)
{
    if(str[strlen(str)-1] == '\n')
    //str[strlen(str)-1]   就是最后一个有效字符
    //考虑数据行太长，刚刚好读取完的情况
        str[strlen(str)-1] = '\0';
    printf("%d,”%s“,%s\n",LineCount,str,temp);
}
bool IsValidParentheses(char *str,int LineCount )  //判断是否合法
{
    /*
    * 要求：
    * 输出结果为标准输出，每一行的内容为：“行号,源字符串,结果”，
    * 其中结果为“OK”或者“NOK”，表示合法或不合法。*/
        stack<char> paren;
        char c ;
        for (int i= 0 ;str[i] != '\n' ; ++i ) {
            c = str[i];
            switch ( c  ) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') {fun(str,LineCount,"NOK");return true;}
                          else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') {fun(str,LineCount,"NOK"); return true;}
                            else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') {fun(str,LineCount,"NOK"); return true ;}
                            else paren.pop(); break;
                default:  ;     // pass
            }
        }
        if(  ! paren.empty() )
            fun(str,LineCount,"NOK");
        else 
            fun(str,LineCount,"OK");
    return true ;
}
int main(void)
{
    FILE *fp ;  
    fp  =  fopen("test", "r");    // 如果文件不存在，不进行创建 
    if(  !fp  ){
        cout << "\t\t\t\t 打开文件失败 \n\n";
        return -1 ;    //打开文件失败码
    }

    char str[MAXSIZE];  //临时存储数组
    memset(str,0,sizeof(str));
    int LineCount = 0 ;  //行号
    /*要求1 ：
     * 输入的字符串来自于一个文本文件，每行文本代表一个字符串。字符串长度不限。*/

    while(fgets(str,MAXSIZE,fp) != NULL )    //得到一行数据
    {
        LineCount++ ;
        //cout << "str == " << str << endl ;
        if(IsValidParentheses(str,LineCount ) == false )  //判断是否合法,在这个函数中输出结果
        {
            cout << "       调用IsValidParentheses 函数出错"    << endl  ; 
            return -2 ;    //调用函数 IsValidParentheses 出错
        }
    }
    fclose(fp); //记得关闭文件
    return 0 ; //成功返回 0  
}
