//5.16双周赛第四题
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, -9999); //dp[i]代表target为i时，最多能放入多少个数字
        dp[0] = 0; // 初始化所有值为很大的负数，保证不是从dp[0]推出来的值都为负数，也就是不能保证正好用完target的选法为负数
        for (int t = 1; t <= target; t++)
        {
            for (int i = 0; i < 9; i++)
            {
                if (t - cost[i] >= 0)
                {
                    //完全背包
                    dp[t] = max(dp[t], dp[t - cost[i]] + 1);
                }
            }
        }
        string res = "";
        if (dp[target] <= 0)
        {
            res = "0";
        }
        else
        {
            //倒推找最大值
            int dummyTarget = target;
            for (int i = 0; i < dp[target]; i++)
            {
                for (int num = 8; num >= 0; num--)
                {
                    if (dummyTarget - cost[num] >= 0)
                    {
                        if (dp[dummyTarget - cost[num]] == (dp[dummyTarget] - 1))
                        {
                            res += to_string(1 + num);
                            dummyTarget -= cost[num];
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector <int> cost{6,10,15,40,40,40,40,40,40};
    int target = 47;
    //vector <int> cost{ 4,3,2,5,6,7,2,5,5 };
    //int target = 9;
    cout << s.largestNumber(cost, target);
    return 0;
}
