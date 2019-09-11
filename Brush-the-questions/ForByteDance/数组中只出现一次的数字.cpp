class Solution
{
public:
    unsigned int FindFristBitIs1(int res)
    {
        unsigned int index = 0;
        //一字节八位，求出 int 所占的字节 （& 判断是不是1 ）
        while ((res & 1) == 0 && (index < 8 * sizeof(int)))
        {
            res = res >> 1;
            index++;
        }
        return index;
    }
    bool IsBit1(int data, int index)
    {
        data = data >> index;
        return (data & 1);
    }
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        //O(n)
        if (data.size() < 2)
            return;
        int res = 0;
        for (auto i : data)
        {
            res = res ^ i; //得到两个不同数字的异或 的结果
        }
        auto indexOf1 = FindFristBitIs1(res);
        *num1 = *num2 = 0;

        for (unsigned int i = 0; i < data.size(); i++)
        {
            if (IsBit1(data[i], indexOf1))
                *num1 = *num1 ^ data[i];
            else
                *num2 = *num2 ^ data[i];
        }
        return;
    }
};
