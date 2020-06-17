#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // 评分 = A[i]+A[j]+i-j = A[i]+i+A[j]-j 其中A[j]-j在每次循环中为定值，只要找出A[i]+i的最大值就行
        // 一定要用O(n)的原地算法
        int mx = A[0];
        int ans = A[0];
        for (int j = 1; j < A.size(); j++)
        {
            int score = mx + A[j] - j;
            if (score > ans)
                ans = score;
            mx = max(mx, A[j] + j);
        }
        return ans;
    }
};

int main()
{
    Solution ans;
    vector <int> A = { 8,1,5,2,6 };
    cout << ans.maxScoreSightseeingPair(A);
	return 0;
}