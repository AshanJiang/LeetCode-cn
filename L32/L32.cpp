#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		stack <int> stack; // 左括号位置栈
		vector <int> v(s.size(), 0); // 存储字符串对应位置是否匹配上，匹配上为1否则为0
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stack.push(i);
			}
			else
			{
				if (!stack.empty())
				{
					v[stack.top()] = 1;
					v[i] = 1;
					stack.pop();
				}
			}
		}
		int res = 0;
		int tmp = 0;
		for (const int& x : v)
		{
			if (x == 0)
			{
				res = max(res, tmp);
				tmp = 0;
			}
			else
			{
				tmp += 1;
			}
		}
		res = max(res, tmp);
		return res;
    }
};

int main()
{
	Solution ans;
	string s = "(()";
	cout << ans.longestValidParentheses(s);
	return 0;
}