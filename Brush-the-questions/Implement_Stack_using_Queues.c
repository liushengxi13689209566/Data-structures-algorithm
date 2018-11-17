/*************************************************************************
	> File Name: Implement_Stack_using_Queues.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月16日 星期一 17时57分26秒
 ************************************************************************/
/*
* 问题描述：
* Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.*/

//思路：这还要思路吗？？就是队列,栈的一些操作啊
typedef struct node {
    int data;
}NODE;
typedef struct  queue {
    NODE *top;
    NODE *base;
    int StackSize;
}MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *s ;
    s=(MyStack *)malloc(sizeof(MyStack));
    s->top = s->base =(NODE *)malloc(sizeof(NODE)*maxSize);
    s->StackSize = maxSize ;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->top->data = x ;
    obj->top++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    obj->top--;
    return obj->top->data;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyStack *p;
    p=(MyStack *)malloc(sizeof(MyStack));
    p->top = obj->top ;
    p->top--;
    return p->top->data;
}
/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top == obj->base)
        return true;
    else return false;
}
void myStackFree(MyStack* obj) {
    free(obj->top);
    free(obj->base);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
