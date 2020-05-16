//5.16双周赛第一题
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int maxLength = 0, length = 0;
        char a, b;
        size_t i = 0;
        while (i < s.size())
        {
            length = 0;
            a = s[i];
            b = s[i];
            while (a == b)
            {
                length++;
                i++;
                if (i == s.size())
                    break;
                b = s[i];
            }
            if (length > maxLength)
            {
                maxLength = length;
            }
        }
        return maxLength;
    }
};

int main()
{
    Solution s;
    string str = "hooraaaaaaaaaaay";
    cout << s.maxPower(str);
	return 0;
}
