#include <iostream>
#include <stack>

using namespace std;

class CQueue {
    stack <int> s1, s2;
public:
    CQueue() {
        while (!s1.empty()) {
            s1.pop();
        }
        while (!s2.empty()) {
            s2.pop();
        }
    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        int res = -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty())
        {
            res = s2.top();
            s2.pop();
        }
        return res;
    }
};

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(3);
    cout << obj->deleteHead() << "\n";
    cout << obj->deleteHead() << "\n";
    return 0;
}