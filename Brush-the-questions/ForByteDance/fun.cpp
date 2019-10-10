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
private:
    int dir[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    bool check(const char *matrix, const int rows, const int cols,
               const char *str, const int pathLength, int rr, int cc)
    {
        if (rr < 0 || rr > rows - 1)
            return false;
        if (cc < 0 || cc > cols - 1)
            return false;
        if (matrix[rr * rows + cc] != str[pathLength])
            return false;
        return true;
    }
    bool dfs(const char *matrix, const int rows, const int cols,
             const char *str, int pathLength, int r, int c,
             vector<vector<int>> &visted)
    {
        if (str[pathLength] == '\0')
            return true;

        for (int i = 0; i < 4; i++)
        {
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            printf("&&&&^^^^^^&&&&&&&&  rr= %d,cc=%d,matrix[rr * rows + cc]= %c,pathLength == %d \n", rr, cc, matrix[rr * rows + cc], pathLength);

            if (check(matrix, rows, cols, str, pathLength, rr, cc) && visted[rr][cc] != 1)
            {
                printf("rr= %d,cc=%d,matrix[rr * rows + cc]= %c,pathLength == %d \n", rr, cc, matrix[rr * rows + cc], pathLength);

                visted[rr][cc] = 1;

                if (dfs(matrix, rows, cols, str, pathLength + 1, rr, cc, visted))
                    return true;

                visted[rr][cc] = 0;
            }
        }
        return false;
    }

public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (!str || !matrix || rows < 1 || cols < 1)
            return false;
        vector<vector<int>> visted(rows, vector<int>(cols, 0));

        int pathLength = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i * rows + j] == str[0])
                {
                    visted[i][j] = 1;

                    if (dfs(matrix, rows, cols, str, pathLength + 1, i, j, visted))
                        return true;

                    visted[i][j] = 0;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s1;
    cout << s1.hasPath("ABCESFCSADEE", 3, 4, "ABCCED") << endl;
    
    return 0;
}