#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 保证时间复杂度O(n)空间复杂度O(1)
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            // 将非正数和超范围数转换为超范围数
            if (nums[i] > nums.size() || nums[i] < 1)
            {
                nums[i] = nums.size() + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (labs(nums[i]) >= 1 && labs(nums[i]) <= nums.size())
            {
                if(nums[labs(nums[i]) - 1] > 0) // 用负数标记位置
                    nums[labs(nums[i]) - 1] = -nums[labs(nums[i]) - 1];
            }
        }
        int res = 1;
        while (res <= nums.size())
        {
            if (nums[res - 1] >= 0)
            {
                break;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> nums = { 1,1 };
    cout << ans.firstMissingPositive(nums);
	return 0;
}