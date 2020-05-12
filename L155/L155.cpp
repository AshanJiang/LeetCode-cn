#include <iostream>
#include <stack>
#include <limits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> s;
    //用一个辅助栈来保存最小值
    stack <int> sMin;
    MinStack() {
        sMin.push(INT_MAX);
    }

    void push(int x) {
        s.push(x);
        if (x < sMin.top())
        {
            sMin.push(x);
        }
        else
        {
            sMin.push(sMin.top());
        }
    }

    void pop() {
        s.pop();
        sMin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sMin.top();
    }
};


int main()
{
	MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << "\n";
    minStack.pop();
    cout << minStack.top() << "\n";
    cout << minStack.getMin() << "\n";
    return 0;
}