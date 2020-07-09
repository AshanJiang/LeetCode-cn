#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int left = 0, right = 0;
        int res = 0;
        if (s.empty())
            return res;
        while (true)
        {
            char letter = s[right];
            if (uset.find(letter) != uset.end()) // right指向的字母已经在窗口里了
            {
                uset.erase(uset.find(s[left]));
                left++;
            }
            else
            {
                res = max(res, right - left + 1);
                uset.insert(letter);
                right++;
                if (right >= s.size())
                    break;
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    string s = " *^&";
    cout << ans.lengthOfLongestSubstring(s);
	return 0;
}