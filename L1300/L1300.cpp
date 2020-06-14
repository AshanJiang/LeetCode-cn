#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        vector <int> preSum(size + 1, 0); // 前缀和，加速计算
        for (int i = 1; i <= size; i++)
        {
            preSum[i] = preSum[i - 1] + arr[i - 1];
        }
        int maxBound = *max_element(arr.begin(), arr.end()); // 确定枚举的上界,下界一定为0
        int res = 0;
        int deviation = target;
        for (int i = 1; i <= maxBound; i++)
        {
            int lowerPosition = lower_bound(arr.begin(), arr.end(), i) - arr.begin(); // 二分法在arr中查找大于等于i的第一个位置
            int currentSum = preSum[lowerPosition] + i * (size - lowerPosition); // 排序数组求和，前缀+i*所有大于等于他的值的数量
            if (abs(target - currentSum) < deviation)
            {
                deviation = abs(target - currentSum);
                res = i;
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> arr = { 4,9,3 };
    int target = 10;
    cout << ans.findBestValue(arr, target);
	return 0;
}