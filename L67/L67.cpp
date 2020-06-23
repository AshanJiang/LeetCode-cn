#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int biggerLen = max(a.size(), b.size());
        int size_a = a.size();
        int size_b = b.size();
        int carryFlag = 0;
        for (int i = 1; i <= biggerLen; i++)
        {
            int digit1, digit2;
            if (size_a - i < 0)
                digit1 = 0;
            else
                digit1 = a[size_a - i] - '0';
            if (size_b - i < 0)
                digit2 = 0;
            else
                digit2 = b[size_b - i] - '0';
            int bit = digit1 + digit2 + carryFlag;
            // cerr << "d1 = " << digit1 << " d2 = " << digit2 << " bit = " << bit << "\n";
            if (bit >= 2)
            {
                bit -= 2;
                carryFlag = 1;
            }
            else
            {
                carryFlag = 0;
            }
            res.insert(0, to_string(bit));
        }
        if (carryFlag)
            res.insert(0, "1");
        return res;
    }
};

int main()
{
    Solution ans;
    string a = "1010", b = "1011";
    cout << ans.addBinary(a, b);
}