#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> res;
        int maxCandy = *(max_element(candies.begin(), candies.end()));
        for (int c : candies)
        {
            if (c + extraCandies >= maxCandy)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};

int main()
{
    vector <int> candies = { 2,3,5,1,3 };
    int extraCandies = 3;
    Solution ans;
    ans.kidsWithCandies(candies, extraCandies);
	return 0;
}