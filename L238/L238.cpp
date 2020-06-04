#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // left[i]表示从第0项乘到第i-1项的积，其中left[0] = 1。
        // right[i]表示从最后一项乘到i+1项的积，其中right[nums.size-1] = 1。
        vector <int> left(nums.size()), right(nums.size());
        left[0] = 1;
        right[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
            int j = nums.size() - 1 - i;
            right[j] = right[j + 1] * nums[j + 1];
        }
        vector <int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(left[i] * right[i]);
        }
        return res;
    }
};

int main()
{
    vector <int> v = { 1,2,3,4 };
    Solution ans;
    ans.productExceptSelf(v);
	return 0;
}