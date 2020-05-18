#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int maxProduct = nums[0], minProduct = nums[0];
        int dummyMax, dummyMin;
        int res = maxProduct;
        //maxProduct[i]表示以第i位为结尾的子序列乘积的最大值，minProduct[i]同理
        //maxProduct[i] = max(nums[i],maxProduct[i-1]*nums[i],minProduct[i-1]*nums[i])
        //minProduct[i] = min(nums[i],maxProduct[i-1]*nums[i],minProduct[i-1]*nums[i])
        for (size_t i = 1; i < nums.size(); i++)
        {
            //有两个变量，必须用临时变量纪录，不然先改变maxProduct会导致错误
            dummyMax = maxProduct;
            dummyMin = minProduct;
            maxProduct = max({ nums[i], dummyMax * nums[i], dummyMin * nums[i] });
            if (maxProduct > res)
            {
                res = maxProduct;
            }
            minProduct = min({ nums[i], dummyMax * nums[i], dummyMin * nums[i] });
        }
        return res;
    }
};

int main()
{
    vector <int> nums = { 2,-1,1,1 };
    Solution s;
    cout << s.maxProduct(nums);
	return 0;
}