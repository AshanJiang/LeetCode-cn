#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> res(T.size(), 0);
        stack <int> stack; // 存储的是不增温度的下标
        for (int i = 0; i < T.size(); i++)
        {
            if (stack.empty())
            {
                stack.push(i);
            }
            else
            {
                int current = T[i];
                int old = T[stack.top()];
                if (current <= old)
                {
                    stack.push(i);
                }
                else
                {
                    while (current > old)
                    {
                        res[stack.top()] = i - stack.top();
                        stack.pop();
                        if (stack.empty())
                            break;
                        old = T[stack.top()];
                    }
                    stack.push(i);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
    ans.dailyTemperatures(T);
	return 0;
}