#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& v1, vector<int>& v2)
    {
        vector<int> res;
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size())
        {
            if (i == v1.size())
            {
                res.push_back(v2[j++]);
                continue;
            }
            if (j == v2.size())
            {
                res.push_back(v1[i++]);
                continue;
            }
            if (v1[i] < v2[j])
            {
                res.push_back(v1[i++]);
            }
            else
            {
                res.push_back(v2[j++]);
            }
        }
        return res;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> res = {};
        for (int i = 0; i < matrix.size(); i++)
        {
            res = merge(res, matrix[i]);
        }
        return res[k - 1];
    }
};

int main()
{
    vector<vector<int>> matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15} };
    Solution ans;
    int k = 8;
    cout << ans.kthSmallest(matrix, k);
}