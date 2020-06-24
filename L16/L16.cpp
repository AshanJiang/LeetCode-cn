#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, minDist = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int k = nums.size() - 1;
                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    int dist = sum - target;
                    if (dist == 0)
                    {
                        return sum;
                    }
                    else if (dist < 0)
                    {
                        if (labs(dist) < minDist)
                        {
                            minDist = labs(dist);
                            res = sum;
                        }
                        break;
                    }
                    else // dist > 0
                    {
                        if (dist < minDist)
                        {
                            minDist = dist;
                            res = sum;
                        }
                        k--;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> nums = { -1, 2, 1, -4 };
    int target = 1;
    cout << ans.threeSumClosest(nums, target);
	return 0;
}