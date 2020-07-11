#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        // f(i)表示第i天 “结束后” 的最大收益
        // f0表示，第i天结束后，持有股票（前一天持有且不在冷冻期当天买入，或前一天持有当天不操作）
        // f1表示，第i天结束后，处于冷冻期（当天卖出）
        // f2表示，第i天结束后，不在冷冻期（当天不操作，前一天卖出或者前一天就不持有）
        int f0, f1, f2;
        int newf0, newf1, newf2;
        f0 = -prices[0];
        f1 = 0;
        f2 = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            newf0 = max(f0, f2 - prices[i]);
            newf1 = f0 + prices[i];
            newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        // 最后一天本应是max(f0,f1,f2)，由于最后一天买入没有意义，所以可以去掉f0
        return max(f1, f2);
    }
};

int main()
{
    Solution ans;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << ans.maxProfit(prices);
	return 0;
}