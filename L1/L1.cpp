#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSumSlow(vector<int>& nums, int target) {
        vector <int> res;
        for (size_t i = 0; i < nums.size(); i++)
        {
            auto it = find(nums.begin(), nums.end(), target - nums[i]);
            if (it != nums.end() && it - nums.begin() != i)
            {
                res.push_back(i);
                res.push_back(it - nums.begin());
                break;
            }
        }
        return res;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        //使用hash方法加速
        unordered_map <int, int> hash;
        vector <int> res(2);
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(nums[i]) != hash.end())
            {
                res[0] = hash[nums[i]];
                res[1] = i;
            }
            hash[target - nums[i]] = i; //先检查再保存target-nums[i]对应的下标，不能一开始就保存，以免重复用同一个数
        }
        return res;
    }

};

int main()
{
    vector <int> v = { 2, 7, 11, 15 };
    Solution s;
    s.twoSum(v, 9);
	return 0;
}