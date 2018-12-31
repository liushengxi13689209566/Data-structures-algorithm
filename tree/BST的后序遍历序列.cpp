class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int sz = sequence.size();
        if (sz == 0)
            return false;
        return IsBST(sequence, 0, sz - 1);
    }
    //第一部分是左子树结点的值，它们都比根结点的值小
    bool IsBST(const vector<int> &sequence, int left, int right)
    {
        if (left >= right)
            return true;
        int mid, tp = left;
        int root = sequence.at(right);
        /*先找左子树*/
        while (tp < right && sequence.at(tp) < root)
        {
            tp++;
        }
        if (tp < right)
        {
            mid = tp;
            //第二部分是右子树结点的值，它们都比根结点的值大
            // 查找右子树是否符合要求
            while (tp < right)
            {
                if (sequence.at(tp) < root)
                {
                    return false;
                }
                tp++;
            }
        }
        // 递归的判断左右子树是否符合要求
        return IsBST(sequence, left, mid - 1) && IsBST(sequence, mid, right - 1);
    }
};