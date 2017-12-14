/*************************************************************************
	> File Name: jccs1_pre_刘生玺.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 23时05分46秒
 ************************************************************************/

#include"myhead.h"
using namespace std;
Solution::Solution(char *argv)
{
    fp  =  fopen(argv, "r");    // 如果文件不存在，不进行创建 
    if(  !fp  ){
        cout << "\t\t\t\t 打开文件失败 \n\n";
        exit(-1) ;   //打开文件失败码
    }
    memset(str,0,sizeof(str));
    LineCount = 0 ;  //行号置零
}
Solution::~Solution()
{
    fclose(fp);
}

bool Solution::readFile()  //读取字符串的函数
{
    /*要求1 ：
     * 输入的字符串来自于一个文本文件，每行文本代表一个字符串。字符串长度不限。*/

    while(fgets(str,MAXSIZE,fp) != NULL )    //得到一行数据
    {
        LineCount++ ;
        //cout << "str == " << str << endl ;
        if(IsValidParentheses() == false )  //判断是否合法,在这个函数中输出结果
        {
            cout << "       调用IsValidParentheses 函数出错"    << endl  ; 
            return false ;    //调用函数 IsValidParentheses 出错
        }
        memset(str,0,sizeof(str));
    }
    return true ; //成功返回
}

void Solution::print(const char *temp)
{
    if(str[strlen(str)-1] == '\n')
    //str[strlen(str)-1]   就是最后一个有效字符
    //考虑数据行太长，刚刚好读取完的情况
        str[strlen(str)-1] = '\0';
    printf("%d,”%s“,%s\n",LineCount,str,temp);
}
bool Solution::IsValidParentheses()  //判断是否合法
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
                case ')': if (paren.empty() || paren.top()!='(') {print("NOK");return true;}
                          else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') {print("NOK"); return true;}
                            else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') {print("NOK"); return true ;}
                            else paren.pop(); break;
                default:  ;     // pass
            }
        }
        if(  ! paren.empty() )
            print("NOK");
        else 
            print("OK");
    return true ;
}

