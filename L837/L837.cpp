#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        //K下界，N上界，W抽卡范围[1,W]
        vector <double> dp(N+W, 0.0); // dp[i]表示从点数为i开始游戏，获胜的概率
        for (int i = K; i <= min(N, K - 1 + W); i++)
        {
            dp[i] = 1;
        }
        if (K - 1 < 0)
            return dp[0];
        dp[K - 1] = (1.0 * N - K + 1) / W > 1.0 ? 1.0 : (1.0 * N - K + 1) / W;
        for (int j = K - 2; j >= 0; j--)
        {
            dp[j] = dp[j + 1] - (dp[j + 1 + W] - dp[j + 1]) / W;
        }
        return dp[0];
    }
};

int main()
{
    int N, K, W;
    N = 0, K = 0, W = 1;
    Solution ans;
    cout << ans.new21Game(N, K, W);
	return 0;
}