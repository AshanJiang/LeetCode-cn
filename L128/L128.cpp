#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> uset; // 用uset去重并且可以快速查找数以达到算法时间复杂度
        int length = 0, longest = 0;
        for (int& x : nums)
        {
            uset.insert(x);
        }
        for (int& n : nums)
        {
            if (!uset.count(n - 1)) // 对没有前驱的数找后继(n+1)，直到找不到后继为止
            {
                length = 1;
                while (true)
                {
                    if (uset.count(++n))
                    {
                        length++;
                    }
                    else
                    {
                        if (length > longest)
                        {
                            longest = length;
                        }
                        break;
                    }
                }
            }
            else // 对有前驱(n-1)的数，不计算
            {
                continue;
            }
        }
        return longest;
    }
};

int main()
{
    Solution ans;
    vector <int> v = { 100, 4, 200, 1, 3, 2 };
    cout << ans.longestConsecutive(v);
	return 0;
}