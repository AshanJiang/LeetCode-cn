#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid)
                    cnt += 1;
            }
            if (cnt <= mid) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

int main()
{
    Solution ans;
    vector <int> v = { 1,3,4,2,2 };
    ans.findDuplicate(v);
	return 0;
}