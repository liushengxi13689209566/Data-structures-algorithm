/*************************************************************************
	> File Name: Valid_Parentheses.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月12日 星期四 14时24分05秒
 ************************************************************************/
/*问题描述：
* 由于只包含字符的字符串'('，')'，'{'，'}'，'['和']'，确定输入字符串是有效的。
 括号必须关闭以正确的顺序，"()"并且"()[]{}"都是有效的，但"(]"并"([)]"没有。
解题思路：括号匹配问题！！

*/
typedef struct link{
    char a;
    struct link *next;
}LinkList ;

LinkList*  InitLink( )
{
    LinkList *head ;
    head =(LinkList *)malloc(sizeof(LinkList));
    head->next = NULL ;
    return head ;
}

int InStack(LinkList *head,char p)  //链栈不需要判断栈满
{
    LinkList *temp ;
    temp =(LinkList *)malloc(sizeof(LinkList));
    temp->a = p;
    temp->next = head->next ;
    head->next = temp ;
    return 0;
}
char OutStack(LinkList *head)  //判断栈空
{
    char temp ;
    LinkList *t ;
    t= head->next ;
    temp=head->next->a ;
    head->next = t->next ;
    free(t);
    return temp;
}
bool isValid(char* s) {
    int i;
    char temp;
    LinkList *head;
    head =InitLink() ;
    for(i =0 ;*(s+i) ;i++)
    {
        if( (*(s+i) == '(' ) || (*(s+i) == '{' ) || (*(s+i) == '['  ))
            InStack(head,*(s+i));
        if(*(s+i) == ')')
        {
            if(head->next == NULL ) 
                return false;
            temp  = OutStack(head);
            if(temp != '(')
               return false;
        }
        if(*(s+i) == '}')
        {
            if(head->next == NULL ) 
                return false;
            temp  = OutStack(head);
            if(temp != '{')
               return false;
        }
        if(*(s+i) == ']')
        {
            if(head->next == NULL ) 
                return false;
            temp  = OutStack(head);
            if(temp != '[')
               return false;
        }
    }
    if(head->next != NULL ) 
        return false;
    else 
        return true;
}

