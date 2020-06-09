#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr auto MAX_COST = 1000005;

//L1473
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //三维dp,dp[i][j][k] 值表示第i个房子，涂成j颜色，构成 k 个街区的最小花费，最后找k=target即可
        vector <vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, MAX_COST)));
        //初始化
        if (houses[0] != 0) {
            dp[0][houses[0]][1] = 0;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                dp[0][i][1] = cost[0][i - 1];
            }
        }
        //状态转移
        for (int i = 1; i < m; i++)
        {
            if (houses[i] != 0) // 第i号房已经涂色，对未涂色的特化
            {
                for (int k = 1; k <= target; k++)
                {
                    for (int oldj = 1; oldj <= n; oldj++)
                    {
                        // dp[i][houses[i]][k]最小值，要么是本身，要么从之前的状态转移而来
                        if (oldj != houses[i])
                        {
                            // 其他颜色转移
                            dp[i][houses[i]][k] = min(dp[i][houses[i]][k], dp[i - 1][oldj][k - 1]); // 无cost
                        }
                        else
                        {
                            // 同色转移
                            dp[i][houses[i]][k] = min(dp[i][houses[i]][k], dp[i - 1][oldj][k]);
                        }
                    }
                }
            }
            else // 第i号房未涂色
            {
                for (int j = 1; j <= n; j++) // 相当于每次循环固定一种颜色，就退化成上方已涂色的状态
                {
                    for (int k = 1; k <= target; k++)
                    {
                        for (int oldj = 1; oldj <= n; oldj++)
                        {
                            if (oldj != j)
                            {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][oldj][k - 1] + cost[i][j - 1]); // 有cost
                            }
                            else
                            {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][oldj][k] + cost[i][j - 1]);
                            }
                        }
                    }
                }
            }
        }
        // 返回答案
        int res = MAX_COST;
        for (int j = 1; j <= n; j++)
        {
            if (dp[m - 1][j][target] < res)
                res = dp[m - 1][j][target];
        }
        if (res == MAX_COST)
            return -1;
        else
            return res;
    }
};

int main()
{
    Solution ans;
    vector<int> houses = { 0,2,1,2,0 };
    vector<vector<int>> cost = { {1,10} ,{10,1},{10,1},{1,10},{5,1} };
    int m = 5;
    int n = 2;
    int target = 3;
    cout << ans.minCost(houses, cost, m, n, target);
	return 0;
}