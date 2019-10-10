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
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        if (length < 1)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] < 0 || numbers[i] > length - 1)
                return false;
        }

        for (int i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[numbers[i]] == numbers[i])
                {
                    *duplication = numbers[i];
                    return true;
                }
                else
                {
                    std::swap(numbers[i], numbers[numbers[i]]);
                }
            }
        }
        return false;
    }
};
