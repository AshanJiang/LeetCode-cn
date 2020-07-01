#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector <vector <int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int res = 0;
        // 初始化，从后往前dp
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == B[B.size() - 1])
            {
                dp[i][B.size() - 1] = 1;
                //cerr << "dp(" << i << ", " << B.size() - 1 << ")=" << dp[i][B.size() - 1] << "\n";
            }
        }
        for (int j = B.size() - 2; j >= 0; j--)
        {
            for (int i = A.size() - 1; i >= 0; i--)
            {
                if (A[i] == B[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                //cerr << "dp(" << i << ", " << j << ")=" << dp[i][j] << "\n";
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> A = { 0,1,1,1,0 };
    vector <int> B = { 1,1,1,1,1 };
    cout << ans.findLength(A, B);
	return 0;
}