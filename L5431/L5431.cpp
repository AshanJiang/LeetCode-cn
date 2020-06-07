#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//TODO::动态规划还是太弱
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[105][25];
        int n[105][25];
        for (int i = 1; i <= m; i++)
        {
            if (houses[i] == 0)
            {
                for (int j = 1; j <= n; j++)
                {

                }
            }
        }
    }
};

int main()
{
    Solution ans;
    vector<int> houses = { 0,2,1,2,0 };
    vector<vector<int>> cost = { {1,10} ,{10,1},{10,1},{1,10},{5,1} };
    int m = 5;
    int n = 2;
    int target = 3;
    ans.minCost(houses, cost, m, n, target);
	return 0;
}