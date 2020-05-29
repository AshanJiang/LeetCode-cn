#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int nsize = nums.size();
        if (nsize == 0)
            return 0;
        if (nsize == 1)
            return nums[0];
        vector <int> dp; //dp[i]表示到第i项可获得的最大值
        int res = max(nums[0], nums[1]);
        dp.push_back(nums[0]);
        dp.push_back(res);
        for (int i = 2; i < nsize; i++)
        {
            int total = dp[i - 2] + nums[i];
            if (total > res)
            {
                res = total;
            }
            dp.push_back(res);
        }
        return res;
    }
};

int main()
{
    vector <int> v = { 2,7,9,3,1 };
    Solution ans;
    cout << ans.rob(v);
	return 0;
}