#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};

int main()
{
    int n = 3;
    vector <int> nums = { 2,5,1,3,4,7 };
    Solution ans;
    ans.shuffle(nums, n);
	return 0;
}