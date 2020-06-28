#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int res = INT_MAX;
        int left = 0, right = 0;
        int sum = nums[0];
        while (true)
        {
            if (sum >= s)
            {
                int length = right - left + 1;
                res = min(res, length);
                if (res == 1)
                    break;
                sum -= nums[left++];
            }
            else
            {
                right++;
                if (right >= nums.size())
                    break;
                sum += nums[right];
            }
        }
        if (res == INT_MAX)
            res = 0;
        return res;
    }
};

int main()
{
    Solution ans;
    int s = 7;
    vector <int> nums = { 2,3,1,2,4,3 };
    cout << ans.minSubArrayLen(s, nums);
	return 0;
}