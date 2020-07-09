#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        unordered_set<string> uset;
        for (const string& s : dictionary)
        {
            if (sentence.find(s) != string::npos)
            {
                uset.insert(s);
            }
        }
        vector<int> dp(sentence.size() + 1, 0);
        for (int i = 1; i <= sentence.size(); i++)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j <= i; j++)
            {
                string tmp = sentence.substr(i - j, j);
                //cerr << tmp << "\n";
                if (uset.find(tmp) != uset.end()) // 找到
                {
                    //cerr << "i=" << i << "j=" << j << "\n";
                    dp[i] = min(dp[i], dp[i - j]);
                }
            }
            //cerr << "dp(" << i << ")=" << dp[i] << "\n";
        }
        return dp[sentence.size()];
    }
};

int main()
{
    Solution ans;
    vector<string> dictionary = { "looked","just","like","her","brother" };
    string sentence = "jesslookedjustliketimherbrother";
    cout << ans.respace(dictionary, sentence);
	return 0;
}