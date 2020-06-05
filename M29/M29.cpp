#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> res = {};
        if (matrix.empty())
            return res;
        int hLen = matrix[0].size();
        int vLen = matrix.size();
        int i = 0, j = -1, k;
        while (true)
        {
            //1.→
            int h1 = hLen;
            if (h1 <= 0)
                break;
            for (k = 0; k < h1; k++)
            {
                j += 1;
                //cout << matrix[i][j] << " ";
                res.push_back(matrix[i][j]);
            }
            //2.↓
            int v1 = vLen - 1;
            if (v1 <= 0)
                break;
            for (k = 0; k < v1; k++)
            {
                i += 1;
                //cout << matrix[i][j] << " ";
                res.push_back(matrix[i][j]);
            }
            //3.←
            int h2 = hLen - 1;
            if (h2 <= 0)
                break;
            for (k = 0; k < h2; k++)
            {
                j -= 1;
                //cout << matrix[i][j] << " ";
                res.push_back(matrix[i][j]);
            }
            //4.↑
            int v2 = vLen - 2;
            if (v2 <= 0)
                break;
            for (k = 0; k < v2; k++)
            {
                i -= 1;
                //cout << matrix[i][j] << " ";
                res.push_back(matrix[i][j]);
            }
            hLen -= 2;
            vLen -= 2;
        }
        return res;
    }
};

int main()
{
    vector <vector <int>> v = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    Solution ans;
    ans.spiralOrder(v);
	return 0;
}