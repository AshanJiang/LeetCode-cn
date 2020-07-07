#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false)); // dp(i,j)表示s前i项和p前j项是否匹配
        unordered_map<int, bool> checkRol; // 检查第i列里是否有true
        // 初始化
        dp[0][0] = true;
        checkRol[0] = true;
        for (int j = 1; j <= pLen; j++)
        {
            if (p[j - 1] == '*')
            {
                if (checkRol[j - 1])
                {
                    dp[0][j] = 1;
                    checkRol[j] = true;
                }
                else
                    checkRol[j] = false;
            }
            else
            {
                checkRol[j] = false;
            }
        }
        for (int i = 1; i <= sLen; i++)
        {
            for (int j = 1; j <= pLen; j++)
            {
                if (p[j - 1] == '*')
                {
                    // 更巧妙的一种做法是dp[i][j]=dp[i][j−1]∨dp[i−1][j]
                    // 如果我们不使用这个星号，那么就会从 dp[i][j−1] 转移而来
                    // 如果我们使用这个星号，那么就会从 dp[i−1][j] 转移而来，这就是在一列上传递，a*可以看作a,a*,a**,a***.... 
                    if (checkRol[j - 1]) // 匹配到*时，由于*可以退化任意长度，若在前一列中有1，则可以直接退化到那个状态，也就是s缩短任意值吼，匹配上
                    {
                        dp[i][j] = true;
                    }
                }
                else if (p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 匹配到问号，直接把问号和字符都删了，退化成dp(i-1,j-1)
                }
                else // 模式字符串第j-1位为字母
                {
                    if (s[i - 1] == p[j - 1]) // 当字符和模式相同时，与匹配到问号一致
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                if (dp[i][j])
                {
                    checkRol[j] = true;
                }
            }
        }
        return dp[sLen][pLen];
    }
};


int main()
{
    Solution ans;
    string s = "aa";
    string p = "a";
    cout << ans.isMatch(s, p);
	return 0;
}