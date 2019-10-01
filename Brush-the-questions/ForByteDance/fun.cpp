#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <utility>
#include <queue>
#include <bitset>
#include <stack>
#include <list>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    template <typename T> //摘自 std::reverse
    void reverseFun(T frist, T last)
    {
        while ((frist != last) && (frist != --last))
        {
            std::iter_swap(frist++, last);
        }
    }
    string LeftRotateString(string str, int n)
    {
        if (str.size() <= 0)
            return str;
        if (n == 0)
            return str;
        reverseFun(str.begin(), str.begin() + n);
        reverseFun(str.begin() + n, str.end());
        reverseFun(str.begin(), str.end());

        return str;
    }
};