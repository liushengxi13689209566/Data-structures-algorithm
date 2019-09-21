#include "head.h"

// class A
// {
// public:
//     virtual void func(int val = 0)
//     {
//         cout << "A-> val== " << val << endl;
//     }
//     virtual void test()
//     {
//         func();
//     }
// };
// class B : public A
// {
// public:
//     virtual void func(int val = 666)
//     {
//         cout << "B-> val== " << val << endl;
//     }
// };
// int main()
// {
//     B *p = new B;
//     p->test();
// }
// class Shape
// {
//     virtual drow() const = 0; //纯虚函数
//     virtual printError();     //虚函数
//     int fun();                //普通函数
// };
// class Base
// {

// public:
//     Base() {}
//     ~Base() {}
//     virtual void f() { cout << "Base::f" << endl; }

//     virtual void g() { cout << "Base::g" << endl; }

//     virtual void h() { cout << "Base::h" << endl; }
// };
// class Derived : public Base
// {
// public:
//     Derived() {}
//     ~Derived() {}
//     virtual void f()
//     {
//         cout << "Derived::f" << endl;
//     }

//     virtual void g1() { cout << "Base::g" << endl; }

//     virtual void h1() { cout << "Base::h" << endl; }
// };
// int main()
// {
//     Base *b = new Derived();
//     b->f();

// }

// class Empty
// {
// };
class Test
{
public:
    Test(int tt) : i(tt), j(0) {}

    int i;
    int j;
};
//要有一个拆解包输出的终点函数调用
void print()
{
    cout << "OKOKOKOK " << endl;
}
template <typename T, typename... Types>
void print(const T &fristArg, const Types &... args)
{
    cout << "1+n-1" << endl;
    cout << fristArg << endl;
    print(args...);
}
template <typename... Types>
void print(const Types &... args)
{
    cout << "nnnnnnn" << endl;
    //cout << fristArg << endl;
    print(args...);
}

int main()
{
    print(7.5, bitset<16>(377), 42);
    // cout << sizeof(Empty) << endl;
    // vector<Test> vv{4, 7, 8, 2, 3, 4, 5, 7, 78, 8, 9, 0, 0, 2, 12, 4, 5, 5, 6, 7, 7};
    // sort(vv.begin(), vv.end(), [](const Test &lhs, const Test &rhs) {
    // return lhs.i < rhs.i;
    // });
    // for (auto i : vv)
    // cout << " i== " << i.i << " j == " << i.j << endl;
    // return 0;
}