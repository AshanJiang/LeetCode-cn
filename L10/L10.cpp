#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] 字符串前i项和模式前p项是否匹配
        vector <vector <bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        int i, j;
        // 初始化
        dp[0][0] = true;
        for (i = 1; i <= s.size(); i++)
        {
            dp[i][0] = false;
        }
        for (j = 1; j <= p.size(); j++)
        {
            if (p[j - 1] != '*')
            {
                dp[0][j] = false;
            }
            else
            {
                dp[0][j] = dp[0][j - 2];
            }
        }
        // 转移
        for (i = 1; i <= s.size(); i++)
        {
            char schar = s[i - 1];
            for (j = 1; j <= p.size(); j++)
            {
                char pchar = p[j - 1];
                if (pchar == '.')
                {
                    // .匹配任意字符，所以dp(i,j)和dp(i-1,j-1)相同
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pchar == '*')
                {
                    // * 匹配0次到无穷多次，分别处理
                    char prePchar = p[j - 2];
                    if (prePchar == '.' || prePchar == schar)
                    {
                        // *前字符和匹配字符相同
                        if (dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j])
                        {
                            // 分别对应删除*项,*匹配0次，*匹配1次及以上，任意一项匹配上，就是匹配上了
                            // 例qqb和qqbb*     qqb,qqb*   qqbbbbb,qqb*
                            dp[i][j] = true;
                        }
                        else
                        {
                            dp[i][j] = false;
                        }
                    }
                    else
                    {
                        // *前字符没匹配上，尝试删除*和之前一个字符，进行匹配(例如qq和qqb*进行匹配dp(2,4)的情况)
                        dp[i][j] = dp[i][j - 2];
                    }
                }
                else
                {
                    if (pchar == schar)
                    {
                        // 模式字符和字符串字符一样，和匹配到.时情况一样
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        // 模式字符和字符串字符不同，匹配失败
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main()
{
    Solution ans;
    string s = "aab";
    string p = "c*a*b";
    cout << ans.isMatch(s, p) << "\n";
	return 0;
}