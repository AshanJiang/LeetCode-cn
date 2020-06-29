#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

int main()
{
	vector <int> nums = { 3,2,3,1,2,4,5,5,6 };
	int k = 4;
	Solution ans;
	cout << ans.findKthLargest(nums, k);
	return 0;
}