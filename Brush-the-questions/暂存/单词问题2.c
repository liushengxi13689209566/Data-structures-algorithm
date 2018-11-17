#include <stdio.h>
#include <string.h>
#include<stdlib.h>
char* strlwr(char *str)
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
int main (void)
{  char s[132],words[5001][205],word[30];
   int i, len,n=0, k=0,j=0,l,p  ,wordnumb[5001];
    memset(words,0,sizeof(words));
   gets(s) ;  /* 读第一行 */
   len=strlen(s);
   if(len>0) {s[len]=' ';s[len+1]='\0'; }
   while(1)
   { 
       for (i=0; s[i]; i++)
       { 
          if(s[i] == ',' || s[i] == '.'|| s[i] == '?' || s[i] == ':' || s[i]== '"' || s[i] == '!')
          continue ;
          if ( s[i]== ' ')
                     {  k=0;
                         if(j>0) /* 单词结束 */
                           {
                                 word[j]='\0';
                                 strlwr(word); //转为小写
                     //寻找插入位置
                     l=0; while(strcmp(word,words[l])>0 && l<n) l++;
                     /*if (strcmp(word,words[l])==0) wordnumb[l]++;*/
                       if (strcmp(word,words[l])<0)
                             { for(p=n-1;p>=l;p--)
                                               {
                                  strcpy(words[p+1],words[p]);
                                 /* wordnumb[p+1]=wordnumb[p];*/
                                }
                                wordnumb[l]=0;
                                strcpy(words[l],word); /*wordnumb[l]++;*/
                                n++;
                             }
                     if(l==n) {
                         strcpy(words[n],word);
                         /*wordnumb[n]++;*/
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
/*      gets(s);*/
      if(scanf("%s",s)== EOF)  break;
       len=strlen(s);
       if(len>0) {s[len]=' ';s[len+1]='\0'; }
          k=0;
   }
   for(i=0;i<n;i++)       printf("%s\n",words[i]);
}

