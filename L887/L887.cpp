#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        // K个鸡蛋，N层楼
        vector <vector <int>> dp(N + 1, vector<int>(K + 1, 0)); // dp(i, j)表示在第i层楼，有K个鸡蛋确定临界值需要的次数
        // 初始化
        for (int i = 1; i <= N; i++)
        {
            dp[i][1] = i; // 只有一个鸡蛋
        }
        for (int j = 1; j <= K; j++)
        {
            dp[1][j] = 1; // 只有1层dp(1,...) = 1不管有多少个蛋，次数都为1
        }
        // j：鸡蛋数，i：楼层数
        for (int j = 2; j <= K; j++)
        {
            for (int i = 2; i <= N; i++)
            {
                int dp_i_j = INT_MAX; // dp(i, j)的值
                // k：对于i层楼j个鸡蛋的情况，第一次在第k层扔
                for (int k = 1; k <= i; k++)
                {
                    // 第一次扔在第k层时，最坏需要多少次找到临界楼层
                    // dp[k-1][j-1]表示，如果碎了，退化成在k-1层中有j-1个鸡蛋的情况
                    // dp[i-k][j]表示，如果没碎，退化成在i-k层中有j个鸡蛋的情况
                    // 最后加上本身这一次
                    int dp_k = max(dp[k - 1][j - 1], dp[i - k][j]) + 1;
                    // 枚举第一次所有可能的楼层后，找到dp_k最小值，即位i层j个鸡蛋的最优解
                    // 表示第一次在最优解k层仍鸡蛋，找到临界楼层的次数最少
                    if (dp_k < dp_i_j)
                    {
                        dp_i_j = dp_k;
                    }
                }
                dp[i][j] = dp_i_j;
            }
        }
        return dp[N][K];
    }
};

int main()
{
    Solution ans;
    cout << ans.superEggDrop(5, 2000);
	return 0;
}