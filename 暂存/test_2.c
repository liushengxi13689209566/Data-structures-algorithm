#include <stdio.h>
#include <string.h>
char preord[100],inord[100];
void rebuild(int preleft,int preright,int inleft,int inright)
{
    int root,leftsize,rightsize;
    if(preleft<=preright && inleft<=inright)
    {
        //在中序遍历中寻找根节点
        for(root=inleft;root<=inright;root++)
        {
            if(preord[preleft]==inord[root]) break;
        }
        //计算左右子树大小
        leftsize=root-inleft;
        rightsize=inright-root;
        //如果有左子树则递归重建左子树
        if(leftsize>0)
        {
            rebuild(preleft+1,preleft+leftsize,inleft,root-1);
        }
        //如果有右子树则递归重建右子树
        if(rightsize>0)
        {
            rebuild(preleft+leftsize+1,preright,root+1,inright);
        }
        //如果无子树则打印根节点
        printf("%c",inord[root]);
    }
}
int main()
{
    int length;
    scanf("%s%s",preord,inord);
    length=strlen(preord)-1;
    rebuild(0,length,0,length);
    return 0;
}
