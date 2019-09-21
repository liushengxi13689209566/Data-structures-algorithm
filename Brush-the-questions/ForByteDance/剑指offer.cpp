#include "head.h"
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
}
