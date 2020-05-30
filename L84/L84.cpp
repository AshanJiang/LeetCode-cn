#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        stack <int> stack; //存放高度的下标，这些高度单调递增的
        int res = 0;
        heights.push_back(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!stack.empty() && heights[i] < heights[stack.top()])
            {
                int right, left, height;
                right = i;
                height = heights[stack.top()];
                stack.pop();
                if (stack.empty())
                    left = -1;
                else
                    left = stack.top();
                int area = (right - left - 1) * height;
                if (area > res)
                    res = area;
            }
            stack.push(i);
        }
        return res;
    }
};

int main()
{
    vector <int> v = { 2,1,5,6,2,3 };
    Solution ans;
    cout << ans.largestRectangleArea(v);
	return 0;
}