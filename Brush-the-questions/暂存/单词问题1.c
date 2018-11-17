#include <stdio.h>
#include <string.h>
char* strlwr_str(char *str)
{
    if(str == NULL)
        return NULL;
         
    char *p = str;
    while (*p != '\0')
    {
        if(*p >= 'A' && *p <= 'Z')
            *p = (*p) + 0x20;
        p++;
    }
    return str;
}
int main ( )
{  char s[205],words[5001][205],word[30];
   int i, len,n=0, k=0,j=0,l,p ;
   memset(word,0,sizeof(char)*5001*205);
   scanf("%s",s); /* 读第一行 */
   len=strlen(s);
   if(len>0) {s[len]=' ';s[len+1]='\0'; }
   while(strlen(s)>0)
   {  for (i=0; s[i]; i++)
      {
          if(s[i] == ',' || s[i] == '.'|| s[i] == '?' || s[i] == ':' || s[i]== '"' || s[i] == '!')
          continue ;
          if ( s[i]== ' ')
                     {  k=0;
                         if(j>0) /* 单词结束 */
                           {
                                 word[j]='\0';
                                 strlwr_str(word); //转为小写
                     //寻找插入位置
                     l=0; while(strcmp(word,words[l])>0 && l<n) l++;
                     if (strcmp(word,words[l]) != 0) 
                          if (strcmp(word,words[l])<0)
                             { for(p=n-1;p>=l;p--)
                                {
                                  strcpy(words[p+1],words[p]);
                                }
                                strcpy(words[l],word);
                                n++;
                             }
                     if(l==n) {
                         strcpy(words[n],word);
                         n++;
                     }
                                 j=0;
                           }
                   }
          else if (k ==0)  /* 新词开始 */
                {  k=1; 
                               j=0;word[j]=s[i];j++; 
                            }
               else 
                        {
                          word[j]=s[i];j++;
                        }
      }
      scanf("%s",s); /* 读第一行 */
       len=strlen(s);
       if(len>0) {s[len]=' ';s[len+1]='\0'; }
          k= 0;
   }
   for(i= 0;i< n;i++)       printf("%s\n",words[i]);
}

