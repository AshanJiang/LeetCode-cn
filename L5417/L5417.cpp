#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int num = 0;
        if (k > s.size())
            return res;
        int i = 0; k = i + k - 1;
        for (int j = 0; j <= k; j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                num += 1;
            }
        }
        res = num;
		while (k < s.size() - 1)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                num -= 1;
            }
            i += 1;
            k += 1;
            if (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u')
            {
                num += 1;
            }
            if (num > res)
            {
                res = num;
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    string s = "leetcode";
    int k = 3;
    cout << ans.maxVowels(s, k);
    return 0;
}