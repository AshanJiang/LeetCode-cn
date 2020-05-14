#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{ 0 };
        for (int x : nums) {
            res ^= x;
        }
        return res;
    }
};

int main()
{
    vector <int> v1{ 4,1,2,1,2 };
    Solution s;
    cout << s.singleNumber(v1) << "\n";
	return 0;
}