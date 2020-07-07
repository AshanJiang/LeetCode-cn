#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        set<int> uset;
        for (int s = k; s >= 0; s--)
        {
            int l = k - s;
            uset.insert(s * shorter + l * longer);
        }
        vector<int> res;
        if (k == 0)
            return res;
        copy(uset.begin(), uset.end(), back_inserter(res));
        return res;
    }
};

int main()
{
    Solution ans;
    ans.divingBoard(1, 2, 3);
    return 0;
}