#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i][j]的值表示从i到j是否为回文串，若是则存储长度，否则为-1
        vector <vector <int>> dp(s.size(), vector<int>(s.size(), -1));
        int maxL = 0, maxI = 0;
        for (int l = 0; l < (int)s.size(); l++)
        {
            for (int i = 0; i < (int)s.size(); i++)
            {
                int j = i + l;
				if (j < (int)s.size())
                {
                    if (l == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else if (l == 1 && s[i] == s[j])
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        if (dp[i + 1][j - 1] > 0 && s[i] == s[j])
                        {
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                        else
                        {
                            dp[i][j] = -1;
                        }

                    }
                    if (dp[i][j] > maxL)
                    {
                        maxL = dp[i][j];
                        maxI = i;
                    }
                }
            }
        }
        return s.substr(maxI, maxL);
    }

    string manacher(string s)
    {

    }
};

int main()
{
    Solution s;
    string str = "cbbd";
    cout << s.longestPalindrome(str);
	return 0;
}