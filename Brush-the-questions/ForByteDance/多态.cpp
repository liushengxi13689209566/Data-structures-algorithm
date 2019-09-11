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
        fun();
    }
    virtual void fun()
    {
        cout << " base 的普通虚函数 " << endl;
    }
    ~base()
    {
        cout << "~ base" << endl;
    }
};
class derived : public base
{
public:
    derived() {}
    void fun()
    {
        cout << " dervied 的普通虚函数 " << endl;
    }
    ~derived()
    {
        cout << "~ derived" << endl;
    }
};
int main()
{
    derived dd;
}