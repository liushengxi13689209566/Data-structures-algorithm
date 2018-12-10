/*************************************************************************
	> File Name: reverse_list.cpp
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年12月09日 星期日 21时51分31秒
 ************************************************************************/

#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    Node(T t)
    {
        data = t;
    }
    T data;
    Node *next;
};

template <typename T>
class List
{
  public:
    List()
    {
        CreatList();
    }
    ~List()
    {
        Node<T> *start = head;
        Node<T> *end = start->next;
        while (end)
        {
            delete start;
            start = end;
            end = end->next;
        }
        delete start;
    }
    void CreatList()
    {
        head = new Node<T>(-100);
        Node<T> *temp = nullptr;
        rear = head;
        for (int i = 0; i < 10; i++)
        {
            temp = new Node<T>(i);
            temp->next = nullptr;
            rear->next = temp;
            rear = temp;
        }
        rear->next = nullptr;
    }
    void ReverseList()
    {
        Node<T> *curr, *beh;
        curr = head->next;
        rear = head->next;
        beh = curr->next;

        while (beh)
        {
            curr->next = head->next;
            head->next = curr;

            curr = beh;
            beh = beh->next;
        }
        curr->next = head->next; /*处理`curr`指向最后一个节点*/
        head->next = curr;
        /*处理链表的尾部 nullptr */
        rear->next = nullptr;
    }
    void Print()
    {
        Node<T> *temp = head->next;
        while (temp)
        {
            std::cout << temp->data << "  ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

  private:
    Node<T> *head;
    Node<T> *rear;
};

int main(void)
{
    List<int> list;
    list.Print();

    list.ReverseList();
    list.Print();
}