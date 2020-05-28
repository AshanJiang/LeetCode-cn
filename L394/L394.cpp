#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string repeat(string s, int n) {
        ostringstream os;
        for (int i = 0; i < n; i++)
            os << s;
        return os.str();
    }

    string decodeString(string s) {
        stack <string> stack;
        string res = "";
        string digit = "";
        for (char c : s)
        {
            if (isdigit(c))
            {
                digit += c;
                continue;
            }
            if (c == '[')
            {
                stack.push(digit);
                digit.clear();
                stack.push("[");
                continue;
            }
            if (c == ']')
            {
                string code = "";
                while (stack.top() != "[")
                {
                    code.insert(0, stack.top());
                    stack.pop();
                }
                stack.pop();
                int product = stoi(stack.top());
                stack.pop();
                stack.push(repeat(code, product));
                continue;
            }
            stack.push(string(1, c));
        }
        while (!stack.empty())
        {
            res.insert(0, stack.top());
            stack.pop();
        }
        return res;
    }
};

int main()
{
    Solution ans;
    string s = "2[a2[bc]]";
    cout << ans.decodeString(s);
	return 0;
}