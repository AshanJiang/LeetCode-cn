#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t n = triangle.size();
        vector<int> dp(n);
        for (size_t j = 0; j < n; j++)
        {
            dp[j] = triangle[n - 1][j];
        }
        for (size_t i = n - 1; i > 0; i--)
        {
            for (size_t j = 0; j < i; j++)
            {
                dp[j] = triangle[i - 1][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution ans;
    vector<vector<int>> triangle = { {} };
    cout << ans.minimumTotal(triangle);
	return 0;
}