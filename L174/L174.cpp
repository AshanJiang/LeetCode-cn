#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX)); // dp(i,j)从(i,j)出发所需的最少血量
        dp[m - 1][n] = 1;
        dp[m][n - 1] = 1;
        // 从终点往起点走
        // 如果从起点往终点走，由于会受到当前血量和最小总血量的双重影响，有可能选不到全局最优解
        // 即下一个状态会受之前选择路径的影响，比如
        // 0  -2  3
        // -1  0  0
        // -3  -3 -2
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution ans;
    vector<vector<int>> dungeon = { {-2, -3, 3}, {-5, -10, 1}, {10, 30, -5} };
    cout << ans.calculateMinimumHP(dungeon);
	return 0;
}