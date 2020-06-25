#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 预处理，方便查询
        unordered_set <string> dict;
        for (const string& word : wordDict)
        {
            dict.insert(word);
        }
        vector <bool> dp(s.size() + 1, false); // dp(i)表示s的前i个字符是否可以被拆分为字典内的单词
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            string substr = s.substr(0, i);
            for (int j = substr.size() - 1; j >= 0; j--)
            {
                string dummystr = substr.substr(j, substr.size() - j);
                if (dict.find(dummystr) != dict.end())
                {
                    if (dp[i - (substr.size() - j)]) // 带上新字符的字符串在字典里，且去除掉这个字符串剩下的字符依然满足要求，则前i个字符可以被拆分
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution ans;
    string s = "catsandog";
    vector <string> wordDict = { "cats", "dog", "sand", "and", "cat" };
    cout << ans.wordBreak(s, wordDict);
	return 0;
}