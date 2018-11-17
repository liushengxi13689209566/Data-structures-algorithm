/*************************************************************************
	> File Name: Implement_Queue_using_Stacks.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 23时02分33秒
 ************************************************************************/

#include<iostream>
#include<stack>
/*以栈顶为对头，以栈底为对尾*/
using namespace std;
class MyQueue {
    private:
        stack<int> S ;
    public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {   //递归，入对需要入到对尾
        push_temp(x);
    }
    void push_temp(int x)
    {
        if(S.empty()){    //先搞定特殊情况
            S.push(x);
            return ;
        }
        int data = S.top();  //先取出来
        S.pop();
        push_temp(x);
        S.push(data);
        return ;   
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {  //直接出队  
        int temp = S.top();
        S.pop();
        return temp ;
    } 
    /** Get the front element. */
    int peek(){
        return S.top();   
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return S.empty();
        //return (S.size()== 0);
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
