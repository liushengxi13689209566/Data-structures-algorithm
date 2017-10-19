/*************************************************************************
	> File Name: Maze_solution_with_stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月15日 星期日 15时31分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define  MAXSTACKSIZE  100  //栈的大小
#define      N          10     //二维迷宫大小
#define  Entrance_row   0
#define  Entrance_col   1
#define  Exit_row   8
#define  Exit_col   9
typedef struct position{   //坐标   
    int x;
    int y;
}position ;
typedef struct SElement {
    position p;  //记录此通道块在矩阵当中的位置 
    int di;  //记录下一次测试这一路径的临近路径的位置 
}SElement ; 
typedef struct Mystack{
    SElement  *top;
    SElement  *base;
    int stackSize ;
}Mystack ;

int Maze[N][N]={
    {2,0,2,2,2,2,2,2,2,2},//1
    {2,0,0,2,0,0,0,2,0,2},//2
    {2,0,0,2,0,0,0,2,0,2},//3
    {2,0,0,0,0,2,2,0,0,2},//4
    {2,0,2,2,2,0,0,0,0,2},//5
    {2,0,0,0,2,0,0,0,0,2},//6
    {2,0,2,0,0,0,2,0,0,2},//7
    {2,0,2,2,2,0,2,2,0,2},//8
    {2,2,0,0,0,0,0,0,0,0},//9
    {2,2,2,2,2,2,2,2,2,2} //10
};

int IsEmptyStack(Mystack *path);

int InitStack(Mystack *path)   // top ,base  ,size 
{
    path->top = path->base =(SElement *)malloc(sizeof(SElement)*MAXSTACKSIZE);
    if(path->top == NULL )
    {
        printf("Init  stack is failed !!! \n");
        return -1;
    }
    path->stackSize = MAXSTACKSIZE;
    return 0;
}


int pop(Mystack *path ,SElement *t)  //从path 中出一个元素给t 
{
    if(IsEmptyStack(path) == 1)
        return 0;
    *t = *(path->top-1);
    path->top-- ;
    return 1;
}

int push(Mystack *path ,SElement p)
{
    *(path->top) = p ;
    path->top++;
}

int IsEmptyStack(Mystack *path)
{
    if(path->top == path->base )   return 1;  //空栈返回 1  
    else return 0 ;
}
int print_MAZE(int Maze[N][N])
{
    int i,j;
    for(i= 0 ;i< N;i++)
    {
        for(j= 0 ;j< N ;j++)
        {
            if(Maze[i][j] == 10)    printf("\033[31m  *  \033[0m") ;
            else  printf("  %d  ",Maze[i][j]);
        }
        printf("\n\n");
    }

}
int check(position now_try)
{
    if(Maze[now_try.x][now_try.y]  ==  0)  //0  代表走的通
        return 1;
    else 
        return 0;
}

position   NextPosition(position  now_try ,int direction)  //获得下一个位置的坐标 x,y
{
    position next ;
    next.x= now_try.x;
    next.y  = now_try.y;
    switch(direction)
    {
        case 4:next.y+=1;break; //东
        case 3:next.x+=1;break;   //南
        case 1:next.x-=1;break;//西
        case 2:next.y-=1;break;//北
    }
    return next ;
}

int main(void)
{
    print_MAZE(Maze) ;
    printf("---------------------------------------------------------------------------------------------\n");
    Mystack  path ;
    InitStack(&path);
    position  now_try ; //所尝试的位置
    now_try.x= Entrance_row;
    now_try.y= Entrance_col;
    do{
        if(check(now_try))
        {
            Maze[now_try.x][now_try.y]  =10 ;
            SElement temp ;
            //temp.di = 1;
            temp.p.x= now_try.x;
            temp.p.y= now_try.y;
            push(&path,temp);

            if(now_try.x == Exit_row && now_try.y == Exit_col )
                break;
            now_try  = NextPosition(now_try,1);  //先向东探索
        }
        else     //这个点为 1 ,不能走，那么就取出它的上一个（即栈顶元素），寻找其他方向
        {
            if(IsEmptyStack(&path) !=  1)  //栈不空
            {
                SElement t ;
                pop(&path,&t);    //要在被调函数中改变t
                while(t.di == 4 && IsEmptyStack(&path) !=  1){
                    Maze[t.p.x][t.p.y] = 0 ;
                    pop(&path,&t);
                }
                if(t.di < 4)
                {
                    now_try = NextPosition(t.p,t.di+1);
                    t.di++;
                    push(&path,t);
                }
            }
        }
    }while( IsEmptyStack(&path) ==  0  );  //0 就是有元素
    print_MAZE(Maze);
    return 0;
}


