// #include <iostream>
// using namespace std;

// class base
// {
// public:
//     base() {}
//     ~base()
//     {
//         cout << "~ base" << endl;
//     }
// };
// class derived : public base
// {
// public:
//     derived() {}
//     ~derived()
//     {
//         cout << "~ derived" << endl;
//     }
// };
// int main()
// {
//     base *pb = new derived();

//     delete pb;
// }
#include <iostream>
using namespace std;

class base
{
public:
    base()
    {
    }
    virtual void fun()
    {
        cout << " base  fun () 的普通虚函数 " << endl;
    }
    ~base()
    {
        cout << "~ base" << endl;
    }
};
class B : public base
{
public:
    B() {}
    void fun()
    {
        cout << " B 的普通虚函数 " << endl;
    }
    ~B()
    {
        cout << "~ B" << endl;
    }
};
class C : public base
{
public:
    C() {}
    void fun()
    {
        cout << " C 的普通虚函数 " << endl;
    }
    ~C()
    {
        cout << "~ C" << endl;
    }
};
int do_something(base *bb)
{
    bb->fun();
}
int main()
{
    B bb;
    do_something(&bb);

    C cc;
    do_something(&cc);
    return 0;
}