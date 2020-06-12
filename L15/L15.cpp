#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // 必须先排序，才不会重复计算
        unordered_map <int, vector<int>> umap; // 存储数字和对应位置
        unordered_set <int> usetx; // x去重
        unordered_set <int> usetyz; // y,z去重
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(nums[i]))
            {
                umap[nums[i]].push_back(i);
            }
            else
            {
                vector <int> tmp;
                tmp.push_back(i);
                umap[nums[i]] = tmp;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (usetx.count(nums[i])) // 已经找过的x就不再找了，防重复
                continue;
            int twoSum = 0 - nums[i]; // 固定住x,退化为找两数和
            usetyz.clear();
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                if (usetyz.count(nums[j]))
                    continue;
                usetyz.insert(nums[j]);
                if (umap.count(twoSum - nums[j]))
                {
                    vector <int> vindex = umap[twoSum - nums[j]];
                    int count = 0;
                    while (count < vindex.size())
                    {
                        int index = vindex[count];
                        // 找z时，i前的所有组合都找过了，且不能找自己本身
                        if (index > i && index != j)
                        {
                            usetyz.insert(twoSum - nums[j]);
                            break;
                        }
                        count++;
                    }
                    if (count < vindex.size())
                    {
                        vector <int> tmp = { nums[i], nums[j], twoSum - nums[j] };
                        res.push_back(tmp);
                    }
                }
            }
            usetx.insert(nums[i]);
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> nums = { -1, 0, 1, 2, -1, -4 };
    ans.threeSum(nums);
	return 0;
}