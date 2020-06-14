#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector <int> res;
        for (int i = 0; i < prices.size(); i++)
        {
            int tmp = prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[i] >= prices[j])
                {
                    tmp -= prices[j];
                    break;
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> prices = { 8,4,6,2,3 };
    ans.finalPrices(prices);
	return 0;
}