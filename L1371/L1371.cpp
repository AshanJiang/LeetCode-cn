#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0;
        //(00000)2 <= status <= (11111)2 每一位表示为对应元音的奇偶性
        vector <int> statusPos(32, -1); //状态位置数组statusPos[status] = i表示前i个字符的状态为status
        statusPos[0] = 0;
        int status = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == 'a')
            {
                status = status ^ (1 << 0);
            }
            else if (ch == 'e')
            {
                status = status ^ (1 << 1);
            }
            else if (ch == 'i')
            {
                status = status ^ (1 << 2);
            }
            else if (ch == 'o')
            {
                status = status ^ (1 << 3);
            }
            else if (ch == 'u')
            {
                status = status ^ (1 << 4);
            }
            if (statusPos[status] >= 0)
            {
                //取每一种状态的最长子串的最大值
                res = max(res, i + 1 - statusPos[status]);
            }
            else
            {
                //第一次碰到这个状态
                statusPos[status] = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "eleetminicoworoep";
    cout << s.findTheLongestSubstring(str);
	return 0;
}